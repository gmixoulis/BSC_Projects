#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
 long a[20]={10,4,5,6, 7 ,7,0,12,1, 3,4,9,5,0,8,3,2,1,5,6};
 long n[5]={25000,15000,32000,21000,9200};
 int i,j,x;
 long sum[4];

for(j=0;j<=4;j++)
   {for (i=j*4;i<=j+5;i++)
      sum[j]=n[i]*a[i];}


for (i=0;i<=4;i++)
    printf("%ld ",sum[i]);


}

