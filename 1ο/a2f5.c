#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

main()
{
    long tax=0, income;

    printf("Dwse to poso twn ethsiwn apodoxwn:");
    income = GetLong();
    if (income < 10001)
        tax = 0;
    else if (income < 39001)
        tax = income*0.18;
    else if (income < 49001)
        tax = 5220 + (income - 39000)*0.21;
    else if (income < 59001)
        tax = 7320 + (income - 49000)*0.24;
    else if (income < 85001)
        tax = 9720 + (income - 59000)*0.28;
    else if (income < 100001)
        tax = 17000 + (income - 85000)*0.33;
    else if (income < 120001)
        tax = 21950 + (income - 100000)*0.38;
    else if (income < 150001)
        tax = 29550 + (income - 120000)*0.43;
    else if (income < 170001)
        tax = 42450 + (income - 150000)*0.49;
    else tax = 52250 + (income - 170000)*0.50;
    printf("To poso forou einai:%lu", tax);


}

