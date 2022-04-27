#include <stdio.h>
#include "genlib.h"

int maxarray();
void printarray();
void calculateSales(int salesPerson[],int sales[4][5], int Aarray[]);
main()
{

    int array[]={250, 150, 320, 210,920};
    int sales[4][5]={10 ,4,5,6,7,7,0,12,1,3,4,19,5,0,8,3,2,1,5,6};
    int salesPerson[4]={0};
    calculateSales(salesPerson,sales,array);


}


void calculateSales(int salesPerson[],int sales[4][5], int Aarray[])
{
int i,j;
for(i=0;i<4;i++)
  {for(j=0;j<5;j++)
       {
           salesPerson[i]=sales[i][j]*Aarray[j];
       }
      printf("%d",salesPerson);

  }
}
