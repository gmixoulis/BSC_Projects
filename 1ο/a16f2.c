#include <stdio.h>
#include "simpio.h"

main()

{
    int sms;
    double cost;
    printf("Dwse plithos sms: ");
    sms=GetInteger();
    if (sms<=10)
        cost=sms*0.02;
    else if (sms>10 && sms<=60)
        cost=10*0.02+(sms-10)*0.015;
    else if (sms>60 && sms<=160)
        cost=10*0.02+50*0.015+(sms-60)*0.012;
    else
        cost=10*0.02+50*0.015+100*0.012+(sms-160)*0.01;
    printf("Synoliko poso se euro: %f\n", cost);
    system("pause");
}
