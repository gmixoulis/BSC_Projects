#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

int total(int number);

int main()
{
  int number;
  printf("dwse arithmo:");
  number=GetInteger();
  printf("sum is...%d",total(number)) ;

}
int total(int number)
 {
  int sum,i;
  sum=0;
 for (i=1; i<=number; i++)
    sum+=i;
 return sum;
 }
