#include <stdio.h>
#include "simpio.h"
#include <math.h>

main()

{
    int real_time, predicted_time, remainder, accepted_remainder;
    printf("Dwse ton problepomeno xrono: ");
    predicted_time=GetInteger();
    printf("Dwse ton pragmatiko xrono: ");
    real_time=GetInteger();
    remainder=predicted_time-real_time;
    if (predicted_time>=0 && predicted_time<30)
            accepted_remainder=1;
    else if (predicted_time>=30 && predicted_time<60)
            accepted_remainder=2;
    else if (predicted_time>=60 && predicted_time<90)
            accepted_remainder=3;
    else if (predicted_time>=90 && predicted_time<120)
            accepted_remainder=4;
    else if (predicted_time>=120 && predicted_time<180)
            accepted_remainder=6;
    else if (predicted_time>=180 && predicted_time<240)
            accepted_remainder=8;
    else if (predicted_time>=240 && predicted_time<360)
            accepted_remainder=13;
    else
            accepted_remainder=17;
    printf("Apodekth diafora %d\n", accepted_remainder);
    printf ("Diafora eisagwmenwn timwn %d\n", remainder);
    if (accepted_remainder>=abs(remainder))
        printf("GOOD\n");
    else if (predicted_time>real_time)
        printf("BIG\n");
    else
        printf("SMALL\n");
    system("pause");
    return 0;
}
