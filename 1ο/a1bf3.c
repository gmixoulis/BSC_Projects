#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>



main()
{

    long cars ,eth=0 ,limit ;
    double rate;
    printf("Dwse ton arxiko arithmo autokinhtwn.");
    cars =GetLong();
    printf("Dwse ton ethsio rythmo ayxhshs.");
    rate=GetReal();
    printf("Dwse to orio.");
    limit=GetLong();

    while(cars<=limit)
    {   cars=ceil(cars*(1+rate));
        eth ++;
    }
    printf ("%ld \n",eth);
    printf("%ld ",cars);







}
