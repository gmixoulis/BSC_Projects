#include <stdio.h>
#include "genlib.h"
#include "simpio.h"



 main()
{
  long code;
  int hours ;
  double salary , wage, weekly_amount;

  printf("dwse kwdiko:");
  code = GetLong();
  if (code >= 1000)
      {
      printf(" dwse ton ethsio mistho:");
      salary = GetReal();
      weekly_amount = salary/52;
      }
    else
      {
          printf(" dwse tis wres ths evdomadieas ergasias:");
          hours = GetInteger();
          printf("dwse thn amoivh ana wra:");
          wage = GetReal();
         }if (hours < 40)

              weekly_amount = wage*hours;
          else

                  weekly_amount = 40* wage + (hours - 40) * wage *1,5;



  printf(" weekly amount is %g", weekly_amount);
      }
