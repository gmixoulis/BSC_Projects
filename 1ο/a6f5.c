#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

int main()
{

int A,B,i,j,sum,sum2,n,grammes,stiles;
printf("dwse 2 arithmous: ");
A=GetInteger();
B=GetInteger();
int Magic[4][4]={A,A+14,B,A+3,B-2,A+5,A+6,A+8,A+7,B-4,A+10,A+4,A+12,A+2,A+1,B+2};
grammes=0;
stiles=0;
sum2=0;
sum=0;
for (i=0;i<=3;i++)
sum+=Magic[i][i];
for (i=0;i<=3;i++);
sum2= sum2+ Magic[i][3-i];
if (sum==sum2)
  {
  printf("Magic\n");
  printf(" %d %d %d %d\n ",Magic[0][0],Magic[0][1],Magic[0][2],Magic[0][3]);
  printf("%d %d %d %d\n ",Magic[1][0],Magic[1][1],Magic[1][2],Magic[1][3]);
  printf("%d %d %d %d\n ",Magic[2][0],Magic[2][1],Magic[2][2],Magic[3][3]);
  printf("%d %d %d %d\n ",Magic[3][0],Magic[3][1],Magic[3][2],Magic[3][3]);
  for (i=0;i<=3;i++);
   {
       for(j=0;j<=3;j++)
       {grammes+=Magic[i][j];}
       printf("%d\n ",grammes);
   }
  for(j=0;j<=3;j++)
  {
      for (i=0;i<=3;i++);
      {
          stiles+=Magic[i][j];
      }
      printf("%d  ",stiles);
  }
  printf("2 diagwnioi %d ,%d\n ",sum,sum2);
  }
}



