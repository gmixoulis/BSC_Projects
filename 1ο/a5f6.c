#include <stdlib.h>
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "math.h"

int ReadData(int number);
void ReadArray(int number,int array[number]);
void ReadNumbers(int *a,int *b);
void Crowd(int *a,int *b ,int *crowd_a,int *crowd_b,int *crowd_max,int number,int array[number]);
void PrintNumbers(int *a,int *b ,int *crowd_a,int *crowd_b,int *crowd_max,int number,int array[number]);
main()
{
int number;
number=ReadData(number);
int array[number];
int c;
int d,host_a,host_b,host_max;
ReadArray(number,array);
ReadNumbers(&c,&d);
host_a=host_b=host_max=0;
Crowd(&c,&d,&host_a,&host_b,&host_max,number,array);
PrintNumbers(&c,&d,&host_a,&host_b,&host_max,number,array);


}

int ReadData(int number)
{
int i;
printf("dwse enan akeraio arithmo mikrotero tou 100:\n ");
number=GetInteger();
if (number>100)
{
   printf("dwse enan akeraio arithmo mikrotero tou 100:\n ");
   number=GetInteger();
}
return number;
}
void ReadArray(int number,int array[number])
{
    int i;
    for(i=0;i<number;i++)
     {  printf("dwse 1 arithmo\n");
         array[i]=GetInteger();}
}

void ReadNumbers(int *a,int *b)
{
     printf("dwse 2 arithmous\n");
    *a=GetInteger();
    *b=GetInteger();
}

void Crowd(int *a,int *b ,int *crowd_a,int *crowd_b,int *crowd_max,int number,int array[number])
{

 int i;
 for(i=0;i<number;i++)
 {
   if (array[i]<=*a)
     (*crowd_a)++;
   if (array[i]>=*b)
      (*crowd_b)++;
   if (array[i]>*a && array[i]<*b)
      (*crowd_max)++;
 }
}
void PrintNumbers(int *a,int *b ,int *crowd_a,int *crowd_b,int *crowd_max,int number,int array[number])
{
    int i;
    for (i=0;i<number;i++)
      printf("%d \n",array[i]);
    printf("%d ,%d ,%d, %d, %d",*a,*b,*crowd_a,*crowd_b,*crowd_max);

}
