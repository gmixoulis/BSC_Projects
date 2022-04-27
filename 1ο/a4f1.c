#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

main()
{
     int rate;
     long purchaseAmount;
     double profit, saleAmount;

     printf(" Dwse thn katharh axia:");
     purchaseAmount = GetLong();
     printf(" Dwse thn katharh kerdous:");
     rate =  GetInteger();

     profit = purchaseAmount * (double)rate/100;
     saleAmount = purchaseAmount  + profit;

     printf("To kerdos einai %g\n", profit);
     printf("To synoliko poso einai %g\n", saleAmount);

}
