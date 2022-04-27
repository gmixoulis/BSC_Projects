#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

#define rate 0.07

main()
{

    long cars=80000 ,eth=0 ;

    while(cars<=160000)
    {
         cars=ceil(cars*(1+rate));
         eth ++;
    }
    printf ("%ld \n",eth);
    printf("%ld ",cars);







}
