#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

main()
{
    int N, n1, n2, i, temp;
    printf("Dwse to plithos twn orwn tis akolouthias fibonacci pou thes na emfanistoun: ");
    N=GetInteger();
    n1=0;
    n2=1;
    for (i=1;i<=N;i++)
    {
        if (i==1)
            printf("0\n");
        else if (i==2)
            printf("1\n");
        else
            {
            temp=n1+n2;
            n1=n2;
            n2=temp;
            printf("%d\n", n2);
            }
    }

}

