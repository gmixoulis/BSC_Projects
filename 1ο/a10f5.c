#include <stdio.h>
#include "simpio.h"

main()

{
int i;
long plhthos, kibwtia;
long p[4];
printf("Dwse to plhthos twn syskeuwn:");
plhthos = GetLong();
p[0] = plhthos / 50;
plhthos = plhthos - p[0] * 50;
p[1] = plhthos / 20;
plhthos = plhthos - p[1] * 20;
p[2] = plhthos / 5;
plhthos = plhthos - p[2] * 5;
p[3] = plhthos / 1;
for(i=0;i<=3;i++)
    printf("%ld\n",p[i]);
system("pause");
}
