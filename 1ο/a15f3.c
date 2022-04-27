#include <stdio.h>
#include"genlib.h"
#include"simpio.h"

main()
{
    int i;
    for(i=1; i<10;i++)
        printf("%d   ",i);
    for (i=10; i<=100; i++)
    {
        if (i%10==0)
            printf("%d  \n",i);
        else
                printf("%d  ",i);




    }





}
