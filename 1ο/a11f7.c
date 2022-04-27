#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 80

void removeSpaces(int n,char input[n]);

main()
{
     char str[LEN], name[LEN], server[LEN];
     int i, index, k;

     printf("Give email address: ");
     gets(str);
     removeSpaces(LEN, str);
     index = 0;
     while ( str[index] != '@')
        index++;
     strncpy(name, str, index);
     name[index] = '\0';

     index++;
     k = 0;
     for(i=index; i <= strlen(str); i++)
     {
         server[k] = str[i];
         k++;

     }
     printf("Name: %s - Length: %d\n", name, strlen(name));
     printf("Server: %s\n", server);

}

void removeSpaces(int n, char input[n])
{
    int i, k;
    k = 0;
    for (i=0; i<=strlen(input); i++)
    {
        if (input[i] != ' ')
           {
               input[k] = input[i];
               k++;
           }
    }
}

