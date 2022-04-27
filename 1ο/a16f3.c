#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
   float max1 , max2, i, mo, sum, grade;

   max1=0;
   max2=0;

   for (i=1 ; i<=100; i++)
   {
      printf(" dwse vathmologia foithth %ld:",i);
      grade=GetReal();
      sum+=grade;
      if (max1<grade)
        max1=grade;
      if (max2<grade && max2!=max1)
         max2 = grade;
    }
 mo = sum / 100;
 printf("o mesos oros einai %ld\n ", mo);
 printf("to max1 kai to max2 einai %d %d\n", max1 , max2);
}
