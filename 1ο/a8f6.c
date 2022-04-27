#include <stdio.h>
#include "genlib.h"
#include <stdlib.h>

void ReadData(int number,int mathites[number]);
void ReadFreq(int number,int mathites[number],int freq[]);
void MaxFreq(int freq[],int *max,int *maxpos);
void PrintFreq(int freq[],int *max,int *maxpos);
main()
{
int n1,n2;
int number;
number=30;
int mathites[number];
int freq[20];
ReadData(number,mathites);
ReadFreq(number,mathites,freq);
MaxFreq(freq,&n1,&n2);
PrintFreq(freq,&n1,&n2);

}
void ReadData(int number,int mathites[number])
{
int i;
for (i=0;i<number;i++)
{
printf("dwse ena vathmo");
mathites[i]=GetInteger();
}
}
void ReadFreq(int number,int mathites[number],int freq[])
{
  int i,j, times;
   times=0;

    for (i=0;i<20; i++)
   {

    for (j=0; j<number;j++)
    {

        if (mathites[j]=i)
        {
            times =times +1;
        }
    }


 freq[i]=times;
   times=0;
   }
}
void MaxFreq(int freq[],int *max,int *maxpos)
{
   int i,m,n;
   m=-1;
   n=0;
    for (i=0;i<20;i++)
    {
      if(freq[i]>m)
        m=freq[i];
        *maxpos=i;
}


*max=m;
}
void PrintFreq(int freq[],int *max,int *maxpos)
{
    int i;
    for (i=0;i<20;i++)
        printf("%d \n",freq[i]);
    printf("%d , %d",*maxpos,*max);



}
