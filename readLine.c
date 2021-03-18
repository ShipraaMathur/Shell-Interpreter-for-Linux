#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

void display_usage()
{
	usage = "ctrl-?		Print usage\nBackspace		Deletes character\nUp arrow		See last command\n";
	write(1, usage, strlen(usage));
}

int lineLength;
int lineOffset;
int tracker = -1; //history tracker
int historyLength = 0; 

char buffer[BUFFER_SIZE];
char *history[50];

char *prevHistory()
{
	if(tracker != 0)
	{
		return history[tracker--];
	}
	else return history[tracker];
}

char *nextHistory()
{
	if(tracker < historyLength-1)
	{
		return history[++tracker];
	}
	else
	{
		tracker++;
		return (char *)"";
	}
}

void addHistory(char *s)
{
	history[historyLength++] = s;
}

char *readLine()
{
	tty_raw_mode(); //in raw mode, characters are read as-is, without being processed.

	lineLength = 0;
	lineOffset = 0;

	while(1)
	{
		char ch;
		read(0, &ch, 1);

		if(ch>=32 && ch!=127) //printable characters
		{
			if(lineLength = BUFFER_SIZE-2)break; //if line length has reached max buffer size, break out

			if(lineOffset != lineLength) //if cursor not at end of line
			{
				int i;
				char temp;
				for(i=lineOffset; i<=lineLength; i++)
				{
					temp = buffer[i];
					write(1, &ch, 1);
					buffer[i] = ch;
					ch = temp;
				}

				temp = 8; //ascii 8 is backspace
				for(i=lineOffset+1; i<=lineLength; i++)
				{
					write(1, &temp, 1);
				}
			}
			else
			{
				wrie(1, &ch, 1);
				buffer[lineLength] = ch;
			}

			lineLength += 1;
			lineOffset += 1;
		}

		else if(ch==10) //ascii 10 is linefeed or new line. We break out of loop since line has ended.
		{
			write(1, &ch, 1);
			break;
		}

		else if(ch==31)//control codes to display information
		{
			display_usage();
			buffer[0] = 0;
			break;
		}

		else if(lineLength>0 && (ch == 8|| ch == 127)) //backspace
		{
			ch = 8;
			write(1, &ch, 1);

			if(lineOffset != lineLength)//backspace in middle of text
			{
				int i;
				for(i=lineOffset; i<= lineLength; i++)//shift text to the left in buffer after deleting one character
				{
					write(1, &buffer[i], 1);
					buffer[i-1] = buffer[i];
				}
				ch = '';//write empty character
				write(1, &ch, 1);
			}
			else//backspace at end
			{
				ch = '';
				write(1, &ch, 1);
				ch = 8;
				write(1, &ch, 1);
			}

			lineLength -= 1;//both line length and cursor position reduces by 1
			lineOffset -= 1;
		}

		else if(ch == 4)//end of transmission
		{
			if(lineOffset != lineLength)
			{
				int i;
				for(i=lineOffset; i<= lineLength; i++)
				{
					write(1, &buffer[i+1], 1);
					buffer[i] = buffer[i+1];
				}
				ch = '';
				write(1, &ch, 1);

				ch = 8;
				for(i=lineOffset; i<= lineLength; i++)
				{
					write(1, &ch, 1);
				}

				lineLength -= 1;
			}
		}

		else if(ch == 27)//escape sequences, we need to read 2 characters
		{
			char ch1;
			read(0, &ch1, 1);

			char ch2;
			read(0, &ch2, 1);

			if(ch1 == 91 && ch2 == 65 && tracker > 0)//^[[A is up arrow
			{
				strcpy(buffer, prevHistory());
				lineLength = strlen(buffer);
				lineOffset = lineLength;

				write(1, buffer, lineLength);
			}

			if(ch1 == 91 && ch2 == 66 && tracker < historyLength)//down arrow
			{
				strcpy(buffer, nextHistory());
				lineLength = strlen(buffer);
				lineOffset = lineLength;

				write(1, buffer, lineLength);
			}
		}

		if(lineLength > 1)
		{
			buffer[lineLength] = '\0';//add null to end of buffer
			addHistory(strdup(buffer));//add buffer contents to history
		}
		
		buffer[lineLength] = 10;//new line
		lineLength++;
		buffer[lineLength] = 0;
		
		tracker = historyLength;//tracker placed at latest history
		tty_can_mode();

		return buffer;

	}
}