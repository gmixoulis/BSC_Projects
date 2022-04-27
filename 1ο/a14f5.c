#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

int ReadData();
void Readpinaka(int size,long pinakas[size] );
void Printpinaka(int size,long pinakas[size]);
int FindMaxsPos(int size, long pinakas[size], int index[]);


int main()
{
  int size,i,maxtimes,index[maxtimes];
  printf("dwse to plithos twn stoixeiwn, ews kai 50 stoixeia:");
  size=ReadData();
  if(size!=0)
 {

  long pinakas[size];
  Readpinaka(size,pinakas);
  Printpinaka(size,pinakas);
  maxtimes=FindMaxsPos(size,pinakas,index);
  printf("to megisto emfanizete %d fores \n",maxtimes);
  printf("to megisto emfanizete stis theseis");
  for (i=1;i<=maxtimes;i++)
    printf(" %d ",index[i]);
 }
}

int ReadData()
{
    int number;
    number=GetInteger();
    if (number >50)
        {printf("kseperases to epitrepomeno orio plithous");
        return 0;}
    else
        {return number;}
}
void Readpinaka(int size,long pinakas[size] )
{
   long i;
    for (i=0;i<size;i++)
    {pinakas[i]=GetLong();}
}
void Printpinaka(int size,long pinakas[size])
{
int i;
    for (i=0;i<size;i++)
    {
      if(i==(size-1))
            printf("%ld\n",pinakas[i]);
      else


        printf("%ld ",pinakas[i]);
    }
}
int FindMaxsPos(int size, long a[size], int index[size])
{
    int i, pl_max, max;

    max = a[0];
    pl_max = 1;
    index[pl_max] = 0;
    for (i=1; i<size; i++)
    {
        if(max == a[i])
        {
            pl_max = pl_max + 1;
            index[pl_max] = i;
        }
        if (a[i] > max)
        {
            max = a[i];
            pl_max = 1;
            index[pl_max] = i;
        }

    }

    printf("maximum %d\n", max);
    return pl_max;
}
