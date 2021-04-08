#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#define MAX_BUFFER_LINE 2048

// char *read_line();
char lower_alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int flag = 0;

void gotoDirec(char *s);
void gotoFile(char *s);
void removeExtra(char *s);

void checkmajor(char *input)
{
  if(strstr(input,"directory") )
  {
    char *extra1=strstr(input,"directory");
    for(int i=0;i<9;i++)
    {
      *extra1=' ';
      extra1++;
    }
    gotoDirec(input);
  }

  if(strstr(input,"directories"))
  {
    char *extra1=strstr(input,"directories");
    for(int i=0;i<10;i++)
    {
      *extra1=' ';
      extra1++;
    }
    gotoDirec(input);
  }

  if(strstr(input,"dir"))
  {
    char *extra1=strstr(input,"dir");
    for(int i=0;i<3;i++)
    {
      *extra1=' ';
      extra1++;
    }
    gotoDirec(input);
  }

  if(strstr(input,"file"))
  {
    char *extra1=strstr(input,"file");
    for(int i=0;i<4;i++)
    {
      *extra1=' ';
      extra1++;
    }
    gotoFile(input);
  }
  if(strstr(input,"folder"))
  {
    char *extra1=strstr(input,"folder");
    for(int i=0;i<6;i++)
    {
      *extra1=' ';
      extra1++;
    }
    gotoDirec(input);
  }
  if(strstr(input,"folders"))
  {
    char *extra1=strstr(input,"folders");
    for(int i=0;i<6;i++)
    {
      *extra1=' ';
      extra1++;
    }
    gotoDirec(input);
  }
}

void gotoDirec(char *input)
{

  if(strstr(input,"list"))
  {
    char *extra1=strstr(input,"list");
    for(int i=0;i<4;i++)
    {
      *extra1=' ';
      extra1++;
    }
    printf("\nExpected command: ls\n");
    flag = 1;
  }
  if(strstr(input,"show"))
  {
    char *extra1=strstr(input,"show");
    for(int i=0;i<4;i++)
    {
      *extra1=' ';
      extra1++;
    }
    printf("\nExpected command: ls\n");
    flag = 1;
  }
  if(strstr(input,"display"))
  {
    char *extra1=strstr(input,"display");
    for(int i=0;i<6;i++)
    {
      *extra1=' ';
      extra1++;
    }
    printf("\nExpected command: ls\n");
    flag = 1;
  }
  if(strstr(input,"give"))
  {
    char *extra1=strstr(input,"give");
    for(int i=0;i<4;i++)
    {
      *extra1=' ';
      extra1++;
    }
    printf("\nExpected command: ls\n");
    flag = 1;
  }
  
  if(strstr(input,"change")||strstr(input,"goto")||strstr(input,"go to"))
  {
    char *extra1=strstr(input,"change");
    for(int i=0;i<6;i++)
    {
      *extra1=' ';
      extra1++;
    }

    //printf("input after removing change is %s\n",input);
    printf("\nExpected command: cd\n");
    flag = 1;
  }
  if(strstr(input,"goto"))
  {
    char *extra1=strstr(input,"goto");
    for(int i=0;i<4;i++)
    {
      *extra1=' ';
      extra1++;
    }

    //printf("input after removing change is %s\n",input);
    printf("\nExpected command: cd");
    flag = 1;
  }
  if(strstr(input,"go to"))
  {
    char *extra1=strstr(input,"go to");
    for(int i=0;i<5;i++)
    {
      *extra1=' ';
      extra1++;
    }

    //printf("input after removing change is %s\n",input);
    printf("\nExpected command: cd\n");
    flag = 1;
  }

  if(strstr(input,"make"))
  {
    char *extra1=strstr(input,"make");
    for(int i=0;i<4;i++)
    {
      *extra1=' ';
      extra1++;
    }

    //printf("input after removing change is %s\n",input);
    
    printf("\nExpected command: mkdir\n");
    flag = 1;
  }
  if(strstr(input,"create"))
  {
    char *extra1=strstr(input,"create");
    for(int i=0;i<4;i++)
    {
      *extra1=' ';
      extra1++;
    }
    printf("\nExpected command: mkdir\n");
    flag = 1;
  }

  removeExtra(input);
}

void gotoFile(char *input)
{
  if(strstr(input,"copy"))
  {
    char *extra1=strstr(input,"copy");
    for(int i=0;i<4;i++)
    {
      *extra1=' ';
      extra1++;
    }
    printf("\nExpected command: cp\n");
    flag = 1;
  }
  if(strstr(input,"remove"))
  {
    char *extra1=strstr(input,"remove");
    for(int i=0;i<5;i++)
    {
      *extra1=' ';
      extra1++;
    }
    printf("\nExpected command: rm\n");
    flag = 1;
  }
  if(strstr(input,"delete"))
  {
    char *extra1=strstr(input,"delete");
    for(int i=0;i<6;i++)
    {
      *extra1=' ';
      extra1++;
    }
    printf("\nExpected command: rm\n");
    flag = 1;
  }

  if(strstr(input,"move"))
  {
    char *extra1=strstr(input,"move");
    for(int i=0;i<4;i++)
    {
      *extra1=' ';
      extra1++;
    }
    printf("\nExpected command: mv\n");
    flag = 1;
  }
  if(strstr(input,"rename"))
  {
    char *extra1=strstr(input,"rename");
    for(int i=0;i<6;i++)
    {
      *extra1=' ';
      extra1++;
    }
    printf("\nExpected command: mv\n");
    flag = 1;
  }


  if(strstr(input,"make"))
  {
    char *extra1=strstr(input,"make");
    for(int i=0;i<4;i++)
    {
      *extra1=' ';
      extra1++;
    }
    
    printf("\nExpected command: touch\n");
    flag = 1;
  }
  if(strstr(input,"create"))
  {
    
    char *extra1=strstr(input,"create");
    for(int i=0;i<6;i++)
    {
      *extra1=' ';
      extra1++;
    }
    
    printf("\nExpected command: touch\n");
    flag = 1;
  }

  if(strstr(input,"search"))
  {
    
    char *extra1=strstr(input,"search");
    for(int i=0;i<6;i++)
    {
      *extra1=' ';
      extra1++;
    }
    printf("\nExpected command: locate\n");
    flag = 1;
  }
  if(strstr(input,"find"))
  {
    
    char *extra1=strstr(input,"find");
    for(int i=0;i<4;i++)
    {
      *extra1=' ';
      extra1++;
    }
    printf("\nExpected command: locate\n");
    flag = 1;
  }
  if(strstr(input,"look"))
  {
    
    char *extra1=strstr(input,"look");
    for(int i=0;i<4;i++)
    {
      *extra1=' ';
      extra1++;
    }
    printf("\nExpected command: locate\n");
    flag = 1;
  }
  if(strstr(input,"locate"))
  {
    
    char *extra1=strstr(input,"locate");
    for(int i=0;i<6;i++)
    {
      *extra1=' ';
      extra1++;
    }
    printf("\nExpected command: locate\n");
    flag = 1;
  }
    
  
  if(strstr(input,"show"))
  {
    char *extra1=strstr(input,"show");
    for(int i=0;i<4;i++)
    {
      *extra1=' ';
      extra1++;
    }
    
    printf("\nExpected command: cat\n");
    flag = 1;
  }
  if(strstr(input,"show"))
  {
    char *extra1=strstr(input,"show");
    for(int i=0;i<4;i++)
    {
      *extra1=' ';
      extra1++;
    }
    
    printf("\nExpected command: cat\n");
    flag = 1;
  }
  if(strstr(input,"list"))
  {
    char *extra1=strstr(input,"list");
    for(int i=0;i<4;i++)
    {
      *extra1=' ';
      extra1++;
    }
    
    printf("\nExpected command: cat\n");
    flag = 1;
  }
  if(strstr(input,"display"))
  {
    char *extra1=strstr(input,"display");
    for(int i=0;i<6;i++)
    {
      *extra1=' ';
      extra1++;
    }
    
    printf("\nExpected command: cat\n");
    flag = 1;
  }
  if(strstr(input,"concatenate"))
  {
    char *extra1=strstr(input,"concatenate");
    for(int i=0;i<112;i++)
    {
      *extra1=' ';
      extra1++;
    }
    
    printf("\nExpected command: cat\n");
    flag = 1;
  }

  removeExtra(input);
}
  
void removeExtra(char *input)
{
  if(strstr(input,"this"))
  {
    char *extra=strstr(input,"this");
    for(int i=0;i<4;i++)
    {
      *extra=' ';
      extra++;
    }
  }
  if(strstr(input,"to") )
  {
    char *extra1=strstr(input,"to");
    while(*extra1!='\0' && *extra1!=' ')
    {
      *extra1=' ';
      extra1++;
    }
  }

  if(strstr(input,"in"))
  {

    char *extra1=strstr(input,"in");
    for(int i=0;i<2;i++)
    {
      *extra1=' ';
      extra1++;
    }
  }
  if(strstr(input,"the"))
  {

    char *extra1=strstr(input,"the");
    for(int i=0;i<3;i++)
    {
      *extra1=' ';
      extra1++;
    }
  }
  if(strstr(input,"all"))
  {

    char *extra1=strstr(input,"all");
    for(int i=0;i<3;i++)
    {
      *extra1=' ';
      extra1++;
    }
  }
  if(strstr(input,"from"))
  {
    char *extra=strstr(input,"from");
    for(int i=0;i<4;i++)
    {
      *extra=' ';
      extra++;
    }
  }
  if(strstr(input,"new"))
  {
    char *extra=strstr(input,"new");
    for(int i=0;i<3;i++)
    {
      *extra=' ';
      extra++;
    }
  }
  if(strstr(input,"a"))
  {
    char *extra=strstr(input,"a");
    for(int i=0;i<1;i++)
    {
      *extra=' ';
      extra++;
    }
  }
  if(strstr(input,"name"))
  {
    char *extra=strstr(input,"name");
    for(int i=0;i<4;i++)
    {
      *extra=' ';
      extra++;
    }
  }
  if(strstr(input,"with"))
  {
    char *extra=strstr(input,"with");
    for(int i=0;i<4;i++)
    {
      *extra=' ';
      extra++;
    }
  }
  if(strstr(input,"everything"))
  {
    char *extra=strstr(input,"everything");
    for(int i=0;i<10;i++)
    {
      *extra=' ';
      extra++;
    }
  }
  if(strstr(input,"named"))
  {
    char *extra=strstr(input,"named");
    for(int i=0;i<5;i++)
    {
      *extra=' ';
      extra++;
    }
  }
  if(strstr(input,"files"))
  {
    char *extra=strstr(input,"files");
    for(int i=0;i<5;i++)
    {
      *extra=' ';
      extra++;
    }
  }

  while(*input!='\0')
  {
    input++; 
  }  
}

int cmpfunc (const void * a, const void * b) 
{
   return ( *(char*)a - *(char*)b );
}

char *resize(int n,char c,char *s2)
{
  char *s;
  int i;
  for(i=0; i<n; i++)
  {
    if(i>strlen(s2))
    {
      s[i]=c;
    }
    else
    {
      s[i] = s2[i];
    }
    
  }
  return s;

}

//function to show the correct spelling if arrangement of word is incorrect.
int incorrectArrangement(char *input)
{
    char line[30], Xinput[30],Ninput[30],Tinput[30],Tline[30],Nline[30],Xline[30];
    for(int i=0;i<30;i++)
  {
    Xinput[i]='\0';
  }
  for(int i=0;i<30;i++)
  {
    line[i]='\0';
  }
  for(int i=0;i<30;i++)
  {
    Tinput[i]='\0';
  }
  for(int i=0;i<30;i++)
  {
    Tline[i]='\0';
  }
  for(int i=0;i<30;i++)
  {
    Xline[i]='\0';
  }
    int found = 0;
    FILE *words;
    words = fopen("src/words.txt", "r");
    if (words)
    {
        while(fgets(line, sizeof(line), words) != NULL)
        {
          line[strlen(line)-1] = '\0';
          strcpy(Xinput,input);
          strcpy(Xline,line);
          int len = strlen(Xinput), flen = strlen(line);
          if (len == flen)
            {
                
                for(int i=0;i<30;i++)
              {
                Ninput[i]='\0';
              }
              for(int i=0;i<30;i++)
              {
                Nline[i]='\0';
              }
                for(int i=0;i<strlen(Xinput)-1;i++)
                  Ninput[i]=Xinput[i+1];
                //printf("Ninput=%s\n",Ninput);
              for(int i=0;i<strlen(Xline)-1;i++)
                  Nline[i]=Xline[i+1];
                for(int i=1;i<len;i++)
              {
                Xinput[i]='\0';
              }
              for(int i=1;i<len;i++)
              {
                Xline[i]='\0';
              }
                qsort(Nline, strlen(Nline), sizeof(char), cmpfunc);
                qsort(Ninput, strlen(Ninput), sizeof(char), cmpfunc);

                strcat(Xinput,Ninput);
                strcpy(Tinput,Xinput);

                strcat(Xline,Nline);
                strcpy(Tinput,Xline);

                if (strcmp(Tinput,Tline)==0)
                {
                    found = 1;
                    printf("%s\n",line);
                    break;
                }
            }
        }
        fclose(words);
    }
    else
    {
      printf("Unexpected error occurred...");
    }
    return found;
}


int exchangedCharacters (char  *input)
{
    char line[30], Xinput[30];
    for(int i=0;i<30;i++)
  {
    Xinput[i]='\0';
  }
  for(int i=0;i<30;i++)
  {
    line[i]='\0';
  }
    int found = 0;
    FILE *words;
    words = fopen("src/words.txt", "r");
    if (words)
    {
        while(fgets(line, sizeof(line), words) != NULL)
        {
          line[strlen(line)-1] = '\0';
            int len = strlen(input), flen=strlen(line);
            if (len == flen)
            {
                for (int i = len-1; i >= 0 ; i--)
                {
                    strcpy(Xinput,input);
                    Xinput[i] = lower_alpha[0];
                    for (int j=0; j<26; j++)
                    {
                        if (strcmp(Xinput,line)==0)
                        {
                            found = 1;
                            printf("%s\n",line);
                            break;
                        }
                        Xinput[i] = lower_alpha[j];
                    }
                    if (found == 1 ) break;
                    else continue;
                }
            }
        }
        fclose(words);
    }
    else 
      printf("Unexpected error occurred..");
    return found;
}

//function to show correct spelling when there is a missing character in the given word.
int missingCharacter (char *input)
{
  //printf("hello");
    char Xinput[30], line[30], Tinput[30], Tline[30], Xline[30];
    for(int i=0;i<30;i++)
  {
    Xinput[i]='\0';
  }
  for(int i=0;i<30;i++)
  {
    line[i]='\0';
  }
  for(int i=0;i<30;i++)
  {
    Tinput[i]='\0';
  }
  for(int i=0;i<30;i++)
  {
    Tline[i]='\0';
  }
  for(int i=0;i<30;i++)
  {
    Xline[i]='\0';
  }
  
    int found = 0;
    FILE *words;
    words = fopen("src/words.txt", "r");
    if (words)
    {
        while(fgets(line, sizeof(line), words) != NULL)
        {
          line[strlen(line)-1] = '\0';
            for (int i = 0; i < 26; i++)
            {
                int len = strlen(input), flen = strlen(line);
                strcpy(Xinput,input);
            strcpy(Xline,line);
                //printf("length of Xinput is %d\n",strlen(Xinput));
                //printf("length of Xline is %d\n",strlen(Xline));
                Xinput[len] = lower_alpha[i];
                //printf("in missing and after resize Xinput is %s\n",Xinput);
                //printf("len=%d and flen=%d",len,flen);
                len = strlen(Xinput);
                char Ninput[30], Nline[30];
                if (len == flen)
                {
                  
                  for(int i=0;i<30;i++)
                  {
                    Ninput[i]='\0';
                  }
                  for(int i=0;i<30;i++)
                  {
                    Nline[i]='\0';
                  }
                    for(int i=0;i<strlen(Xinput)-1;i++)
                      Ninput[i]=Xinput[i+1];
                    //printf("Ninput=%s\n",Ninput);
                  for(int i=0;i<strlen(Xline)-1;i++)
                      Nline[i]=Xline[i+1];
                  //printf("Nline=%s\n",Nline);
                  //printf("resize(1,'a',Xinput)=%s\n",resize(1,'a',Xinput));
                  for(int i=1;i<len;i++)
                  {
                    Xinput[i]='\0';
                  }
                  for(int i=1;i<len;i++)
                  {
                    Xline[i]='\0';
                  }
         
                    //printf("Xinput and Xline after resizing are %s and %s\n",Xinput,Xline);
                    

                    qsort(Nline, strlen(Nline), sizeof(char), cmpfunc);
                    //printf("Nline after sort is %s\n",Nline);
                    qsort(Ninput, strlen(Ninput), sizeof(char), cmpfunc);
                    //printf("Ninput after sort is %s\n",Ninput);

                    strcat(Xinput,Ninput);
                  strcpy(Tinput,Xinput);
                  //printf("Value of Tinput is %s\n",Tinput);
                  strcat(Xline,Nline);
                  strcpy(Tline,Xline);
                  //printf("Value of Tline is %s\n",Tline);
                    if(strcmp(Tinput,Tline)==0)
                    {
                        found = 1;
                        printf("%s\n",line);
                        break;
                    }
                }
                if (found == 1)
                {
                  break;
                } 
            }
            if (found == 1) break;
        }
        fclose(words);
    }
    else
    {
        printf("Unexpected error occurred..");
    }
    return found;
}


int extraCharacter (char *input)
{
  char Xinput[30], line[30];
  for(int i=0;i<30;i++)
  {
    Xinput[i]='\0';
  }
  for(int i=0;i<30;i++)
  {
    line[i]='\0';
  }
    int found = 0;
    FILE *words;
    words = fopen("src/words.txt", "r");
    if (words)
    {
        while(fgets(line, sizeof(line), words) != NULL)
        {
           line[strlen(line)-1] = '\0';
             int len = strlen(input), flen = strlen(line);
             if ((len-1) == flen)
             {
                 for (int i = 1; i < len; i++)
                 {
                     //strcpy(Xinput,input);
                  int p=0;
                     for(int j=0;j<len;j++)
                     {
                      if(i==j)
                      {
                        continue;
                      }
                      else
                      {
                        Xinput[p]=input[j];
                        p++;
                      }

                     }

                     if (strcmp(Xinput,line)==0)
                     {
                         found = 1;
                         printf("%s\n",line);
                         break;
                     }

                 }
             }
        }
        fclose(words);
    }
    else
    {
        printf("Unexpected error occurred..");
    
    }
    return found;
}

//function to show right spelling when given word has wrong extra character and right one is missing.
int mixedExtraMissing (char *input)
{
    char Xinput[30], line[30], Xline[30],Tline[30],Tinput[30];
    for(int i=0;i<30;i++)
  {
    Xinput[i]='\0';
  }
  for(int i=0;i<30;i++)
  {
    line[i]='\0';
  }
  for(int i=0;i<30;i++)
  {
    Xline[i]='\0';
  }
  for(int i=0;i<30;i++)
  {
    Tinput[i]='\0';
  }
  for(int i=0;i<30;i++)
  {
    Tline[i]='\0';
  }
    int found = 0;
    FILE *words;
    words = fopen("src/words.txt", "r");
    if (words)
    {
        while(fgets(line, sizeof(line), words) != NULL)
        {
          line[strlen(line)-1] = '\0';
            int len = strlen(input), flen = strlen(line);
            if (len == flen)
            {
                for (int i = 1; i < len; i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        //strcpy(Xinput,input);
                        strcpy(Xline,line);
                        int p=0;
                       for(int q=0;q<len;q++)
                       {
                          if(i==q)
                          {
                            continue;
                          }
                          else
                          {
                            Xinput[p]=input[q];
                            p++;
                          }
                       }

                        Xinput[len-1] = lower_alpha[j];
                        char Ninput[30], Nline[30];
                        for(int i=0;i<30;i++)
                        {
                          Ninput[i]='\0';
                        }
                        for(int i=0;i<30;i++)
                        {
                          Nline[i]='\0';
                        }
                        for(int i=0;i<strlen(Xinput)-1;i++)
                          Ninput[i]=Xinput[i+1];
                        for(int i=0;i<strlen(Xline)-1;i++)
                        Nline[i]=Xline[i+1];
                    for(int i=1;i<len;i++)
                    {
                      Xinput[i]='\0';
                    }
                    for(int i=1;i<len;i++)
                    {
                      Xline[i]='\0';
                    }
                    qsort(Nline, strlen(Nline), sizeof(char), cmpfunc);
                    //printf("Nline after sort is %s\n",Nline);
                    qsort(Ninput, strlen(Ninput), sizeof(char), cmpfunc);
                    //printf("Ninput after sort is %s\n",Ninput);

                    strcat(Xinput,Ninput);
                    strcpy(Tinput,Xinput);
                    //printf("Value of Tinput is %s\n",Tinput);
                    strcat(Xline,Nline);
                    strcpy(Tline,Xline);
                    //printf("Value of Tline is %s\n",Tline);
                      if(strcmp(Tinput,Tline)==0)
                      {
                          found = 1;
                          printf("%s\n",line);
                          break;
                      }

                    }
                    if (found == 1) break;
                }
                if (found == 1) break;
            }
        }
        fclose(words);
    }
    return found;
}

void read_line_print_usage()
{
  char * usage = (char *)"\n"
    " ctrl-?       Print usage\n"
    " Backspace    Deletes last character\n"
    " up arrow     See last command in the history\n";

  write(1, usage, strlen(usage));
}

int line_length;;
int line_offset;
char line_buffer[MAX_BUFFER_LINE] = {NULL};
int history_tracker = -1;
int history_length = 0;
char *history[100];

char *read_line();
void add_history(char *);
char *get_next_history();
char *get_prev_history();


char * read_line() {
// Set terminal in raw mode
tty_raw_mode();

line_length = 0;
line_offset = 0;

// Read one line until enter is typed
while (1) {

  // Read one character in raw mode.
  char ch;
  read(0, &ch, 1);

  if (ch>=32 && ch != 127) {
    // It is a printable character. 

    // Do echo

    // If max number of character reached return.
    if (line_length==MAX_BUFFER_LINE-2) break; 

    /* Begin add char to buffer */

    // If the cursor is not at the end of the word
    if (line_offset != line_length) {
      int i;
      char temp;
      for (i = line_offset; i < line_length+1; i++) {
        temp = line_buffer[i];
        write(1,&ch,1);
        line_buffer[i] = ch;
        ch = temp;
      }
      temp = 8;
      for (i=line_offset+1; i < line_length+1; i++) 
        write(1,&temp,1);
    }
    else {
      write(1,&ch,1);
      line_buffer[line_length]=ch;
    }

    line_length++;
    line_offset++;

    /* End add char to buffer */
  }
  // <Enter> was typed. Return line
  else if (ch==10) {
    // Print newline
    write(1,&ch,1);

    char nlp_input[MAX_BUFFER_LINE];
    char input[MAX_BUFFER_LINE] = {NULL};
    char line[10];

    strcpy(nlp_input, line_buffer);
    flag = 0;
    //printf("flag before: %d\n", flag);
    checkmajor(nlp_input);
    //printf("flag after: %d\n", flag);

    if(flag == 0)
    {
        int count;
        for(count=0; line_buffer[count]!=' '&&count < line_length; count++)
        {
          input[count] = line_buffer[count];
        }
    
        int len,flen,correct=0;
        
        len=strlen(input);
        for (int i=0; i < len; i++)
            input[i] = tolower(input[i]);
    
        FILE *words;
        words = fopen("src/words.txt", "r");
    
        if(words)
        {
            while(fgets(line, sizeof(line), words) != NULL)
            {
                line[strlen(line)-1] = '\0';
                flen=strlen(line);
                //printf("%s len %d...%s flen %d\n",input, len, line, flen);
                if (len==flen)
                {
                    if (strcmp(line,input)==0)
                    {
                        correct=1;
                    }
                    else continue;
                }
                else continue;
            }
            fclose(words);
            if (correct==1)
            {
                //printf("Spelling is correct. ");
            }
            if (correct==0)
            {
                int missing = 0, extra = 0, mixed = 0, incorrect = 0, exchanged = 0;
                printf("Spelling is wrong. Possible right spellings are given below:-\n ");
                missing = missingCharacter(input);
                //printf("after missing");
                extra = extraCharacter(input);
                //printf("after extra");
                mixed = mixedExtraMissing(input);
              //printf("after mixed");
                incorrect = incorrectArrangement(input);
                //printf("after incorrect");
                exchanged = exchangedCharacters(input);
                 //printf("after ex");
                if (missing == 0 && extra == 0 && mixed == 0 && incorrect == 0 && exchanged == 0)
                {
                    printf("No such word exists.\n");
                }
            }
        }
        else
        {
            perror(words);
            write(1, "Not able to open words.txt\n", strlen("Not able to open words.txt\n"));
        }
    }
    strcpy(nlp_input, "");
    break;
  }

  else if (ch == 31) {
    // ctrl-?
    read_line_print_usage();
    line_buffer[0]=0;
    break;
  }
   
  // <backspace> was typed. Remove previous character read. (127 is for mac)
  else if (ch == 8 || ch == 127 && line_length>0) {
    // Go back one character
    ch = 8;
    write(1,&ch,1);

    // Write a space to erase the last character read

    if (line_offset != line_length) {
      int i;
      // Shift all characters over one. 
      for (i = line_offset; i < line_length; i++) {
        write(1,&line_buffer[i],1);
        line_buffer[i-1] = line_buffer[i];
      }
      // replace the left over part of the line w/ empty space
      ch = ' ';
      write(1,&ch,1);
      // Move cursor back to position
      ch = 8;
      for (i = line_offset; i < line_length+1; i++)
        write(1,&ch,1);
    }
    else {
      // Write empty space to get rid of character
      ch = ' ';
      write(1,&ch,1);
      // Go back one character
      ch = 8;
      write(1,&ch,1);
    }

    // Remove one character from buffer
    line_length--;
    line_offset--;
  }

  else if (ch == 4) {
    // Write a space to erase the last character read

    if (line_offset != line_length) {
      int i;
      // Shift all characters over one. 
      for (i = line_offset; i < line_length; i++) {
        write(1,&line_buffer[i+1],1);
        line_buffer[i] = line_buffer[i+1];
      }
      // replace the left over part of the line w/ empty space
      ch = ' ';
      write(1,&ch,1);
      // Move cursor back to position
      ch = 8;
      for (i = line_offset; i < line_length; i++)
        write(1,&ch,1);

      line_length--;
      // Note that offset stays the same b/c the curser is always in the same place
    }
  }


  // Home, or go to beginning of line
  else if (ch==1) {
    int i;
    ch = 8;
    for (i = 0; i < line_offset; i++)
      write(1,&ch,1);
    line_offset -= line_offset;
  }

  else if (ch==5) {
    int i;
    for (i = line_offset; i < line_length; i++)
        write(1,&line_buffer[i],1);
    line_offset = line_length;
  }

  else if (ch==27) {
    // Escape sequence. Read two chars more
    //
    // HINT: Use the program "keyboard-example" to
    // see the ascii code for the different chars typed.
    //
    char ch1; 
    char ch2;
    read(0, &ch1, 1);
    read(0, &ch2, 1);
    if (ch1==91 && ch2==65 && history_tracker > 0) {
      // fprintf(stderr, "This is index %d\n", history_index );
    // Up arrow. Print next line in history.
    // Erase old line
    // Print backspaces
      int i = 0;
      for (i =0; i < line_length; i++) {
        ch = 8;
        write(1,&ch,1);
      }

      // Print spaces on top
      for (i =0; i < line_length; i++) {
        ch = ' ';
        write(1,&ch,1);
      }

      // Print backspaces
      for (i =0; i < line_length; i++) {
        ch = 8;
        write(1,&ch,1);
      } 

      // Copy line from history
      // fprintf(stderr, "line to copy%s\n", history[history_length-1] );
      strcpy(line_buffer, get_prev_history());
      line_length = strlen(line_buffer);
      line_offset = line_length;

      // echo line
      write(1, line_buffer, line_length);
    }

    if (ch1==91 && ch2==66 && history_tracker < history_length) {
    // Down. Print prev line in history.
    // Erase old line
    // Print backspaces
      int i = 0;
      for (i =0; i < line_length; i++) {
        ch = 8;
        write(1,&ch,1);
      }

      // Print spaces on top
      for (i =0; i < line_length; i++) {
        ch = ' ';
        write(1,&ch,1);
      }

      // Print backspaces
      for (i =0; i < line_length; i++) {
        ch = 8;
        write(1,&ch,1);
      } 
        // Copy line from history
      strcpy(line_buffer, get_next_history());
      line_length = strlen(line_buffer);
      line_offset = line_length;
      write(1, line_buffer, line_length);
    }
    // Left arrow
    else if (ch1 == 91 && ch2 == 68) {
      if(line_offset > 0){
          ch = 8;
          write(1,&ch,1);
          line_offset--;
      }
    }
    // Right arrow
    else if (ch1 == 91 && ch2 == 67) {
      if (line_offset != line_length) {
        write(1,&line_buffer[line_offset],1);
        line_offset++;
      }
    }
  }
}

if (line_length > 1) {
  line_buffer[line_length]='\0';;
  add_history(strdup(line_buffer));
}
if (line_length == 1) {
}
line_buffer[line_length]=10;
line_length++;
line_buffer[line_length]=0;
history_tracker = history_length;
tty_can_mode();
return line_buffer;
}

void add_history(char *hist_sentence) {
  history[history_length++] = hist_sentence;
}

char * get_prev_history() {
  if (history_tracker != 0)
    return history[--history_tracker];
else 
  return history[history_tracker];
}

char *get_next_history() {
  if (history_tracker < history_length-1)
    return history[++history_tracker];
  else {
    history_tracker++;
    return (char *)"";
  }
}


