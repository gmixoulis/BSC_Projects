#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"
#include <stdlib.h>


void populate_data(int row, int col,int pinakas[row][col]);
void print_array(int row, int col,int pinakas[row][col]);
void change_array(int row, int col,int pinakas[row][col]);
void print_array2(int row, int col,int pinakas[row][col]);

 main()
{
int row,col;
row=col=10;
int pinakas[row][col],max[row],maxpos[row];
populate_data(row,col,pinakas);
print_array( row,  col, pinakas);
change_array( row, col, pinakas);
printf("\n");
print_array2( row,  col, pinakas);

}
void populate_data(int row, int col,int pinakas[row][col])
{
   for(row=0;row<=9;row++)
   {
       for(col=0;col<=9;col++)
        pinakas[row][col]= rand() % 100;
   }
}
void print_array(int row, int col,int pinakas[row][col])
{

     for(row=0;row<10;row++)
   {
       for(col=0;col<10;col++)
         printf("%3d",pinakas[row][col]);
   }
}

void change_array(int row, int col,int pinakas[row][col])
{
    int max[10]={0};
    int maxpos[10]={0};
     for(row=0;row<10;row++)
   {
       for(col=0;col<10;col++)
          {
              if (max[row]<pinakas[row][col])
                {
                    max[row]=pinakas[row][col];
                    maxpos[row]=row;
                }
         }
   }

     for(row=0;row<10;row++)
   {
       for(col=0;col<maxpos[row];col++)
        {
           pinakas[row][col]=max[row];
        }
   }
}
void print_array2(int row, int col,int pinakas[row][col])
{
for(row=0;row<9;row++)
   {
       for(col=0;col<9;col++)
        printf("%3d",pinakas[row][col]);
   }
}
