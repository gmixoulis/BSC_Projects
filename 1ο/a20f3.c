#include <stdio.h>
#include"simpio.h"
#include "genlib.h"

main()
{
   int max, min, i, age;
   max=0;
   min=200;
   while(TRUE)
   {
    printf("dwse hlikia:");
    age=GetInteger();
    if (age==-1) break;
    if (max<age)
      max=age;
    if(min>age)
       min=age;
    }
    printf ("megalyterh kai mikroterh hlikia einai %d,%d:",max , min);


}
