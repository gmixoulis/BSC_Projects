#include <stdio.h>
#include <string.h>
#include <ctype.h>

main()
{   int i,sum[25],j;
    char arr[26];


    printf("Dose ena alfarithmitiko to poly 25 charaktiron:");
    gets(arr);
    for (i=0; i<25; i++)
        sum[i]=0;
    for (i=0; arr[i]!='\0'; i++)
    {
        if (isupper(arr[i]))
            {
                for (j=0; j<25; j++)
                {
                    if (arr[i]=='A' + j)
                        sum[j] +=1;
                }
            }
    }
    for (i=0; i<25; i++)
    {
        if (sum[i]!=0)
            printf("%c=====> %d\n", 'A'+i, sum[i]);
    }


}
