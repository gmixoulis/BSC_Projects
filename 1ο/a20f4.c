#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int dysekto(int i);

main()
{
 int year1,year2,i;
 printf("dwse 2 xronologies:");
 year1=GetInteger();
 year2=GetInteger();
 for(i=year1;i<=year2;i++)
   if (dysekto(i)==1)
    printf("to etos %d einai dysekto\n",i);
 system("pause");
}

int dysekto(int i)
{

  if(((i % 4 == 0) && (i % 100 !=0)) || (i % 400 ==0))
    return 1;
  else
    return 0;
}

