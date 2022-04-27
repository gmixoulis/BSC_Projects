#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define size 7

void  RegularPluralForm(char words[][21]);
main()
{
    int i;
    char words [size][21]={"box","less","coach","fish","city","boy" ,"girl"};
    RegularPluralForm(words);

   for (i=0;i<size;i++)

       printf("%s \n" , words[i]);


}

void  RegularPluralForm(char words[][21])
{
    int i,l,j,len[7];
    char endwords[3][21]={"es", "ies" , "s"};



     for (i=0;i<size;i++)
          len[i]= strlen(words[i]);

     for (i=0;i<size;i++)
        { for (j=len[i]-1;words[i][j]!='\0';j++)
              {if(words[i][j]=='s' || words[i][j]=='x' || ((words[i][j-1]=='c') && (words[i][j]=='h')) || ((words[i][j-1]=='s') && (words[i][j]='h')) )
                  {strcat(words[i],endwords[0]); break;}
               else if ( words[i][j]=='y'  && words[i][j-1]!='a' && words[i][j-1]!='e' && words[i][j-1]!='i' &&& words[i][j-1]!='o' && words[i][j-1]!='u' )
                         {words[i][j]='\0' ;
                         strcat(words[i],endwords[1]);
                         break;}
               else
                    {strcat(words[i],endwords[2]); break;}


        }}




}
