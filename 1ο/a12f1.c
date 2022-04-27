#include <stdio.h>
#include "genlib.h"
#include "simpio.h"


main()
{
    int kathara_tm, mikta_tm;
    double DT, DF

    printf("dwse ta ka8ara tm tou spitiou:");
    kathara_tm = GetInteger();
    printf("dwse ta mikta tm tou spitiou:");
    mikta_tm = GetInteger();
    DT =  kathara_tm * 1,33 * 61 / 365;
    DF = mikta_tm * 0,13 * 61/365;
    printf("Ta DT einai %g:\n, DT");
    printf("O DF einai %g:\n , DF");

}
