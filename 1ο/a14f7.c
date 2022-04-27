#include <stdio.h>
#include <string.h>
#include <ctype.h>



main()
{
    char name1[20];
    float j;
    int temp,len,i,s[20];
    printf("dwse enan alfarithmitiko\n");
    gets(name1);
    printf("Word to shuffle %s \n",name1);
    len=strlen(name1);


      for (i=0;i<(len/2);i++)
           {temp=name1[i];
           name1[i]=name1[len-i-1];
           name1[len-i-1]=temp;}

           temp=name1[len-2];
           name1[len-2]=name1[len-1];
           name1[len-1]=temp;

    printf("%s \n",name1);


}
