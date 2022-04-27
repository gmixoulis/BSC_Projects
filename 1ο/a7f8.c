#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>
#include <ctype.h>
#define n 20

typedef struct
{
    int number;
    char type[20];
    int cc;
    char name[20];
    int days;
    float daily_rate;
    float total_charge;
}car_rentalT;

typedef struct
{

    char type[20];
    int cc;
    float  amount;

}best_carT;

int get_data( car_rentalT rentals[]);
best_carT find_best(car_rentalT rentals[],int num_rentals);
float calc_totals(car_rentalT rentals[],int num_rentals);
void print_data(car_rentalT rentals[],int num_rentals,float total,best_carT best);
int get_data( car_rentalT rentals[])
{   int num_rentals,i;
    printf("dwse to plithos twn enoikiasewn: ");
    num_rentals = GetInteger();
    for (i=0;i<num_rentals;i++)
    {printf("dwse ta stoixeia ths enoikiashs %d\n",i);
    rentals[i].number=i;
    printf("dwse marka: ");
    gets(rentals[i].type);

    printf("dwse kyvika: ");
    rentals[i].cc=GetInteger();

    printf("dwse pelati: ");
    gets(rentals[i].name);

    printf("dwse timi enoikiasis: ");
    rentals[i].days=GetInteger();

    printf("dwse timi ana hmera: ");
    rentals[i].daily_rate=GetInteger();
    }
    return num_rentals;
}


float calc_totals(car_rentalT rentals[],int num_rentals)
{
    int i;
    float total=0;
    for(i=0;i<num_rentals;i++)
    {
        rentals[i].total_charge=rentals[i].days*rentals[i].daily_rate;
        total+=rentals[i].total_charge;

    }
  return total;

}

best_carT find_best(car_rentalT rentals[],int num_rentals)
{
    int i;
    best_carT best;

    strcpy(best.type,rentals[0].type);
    best.cc=rentals[0].cc;
    best.amount=rentals[0].total_charge;

    for(i=1;i<num_rentals;i++)
    {
        if(best.amount<rentals[i].total_charge)
        {
            strcpy(best.type,rentals[i].type);
            best.cc=rentals[i].cc;
            best.amount=rentals[i].total_charge;

        }
    }
    return best;
}
main()
{

car_rentalT rentals[20];
best_carT car1;
int num_rentals;
float total;

num_rentals=get_data(rentals);
total=calc_totals(rentals,num_rentals);
car1=find_best(rentals,num_rentals);
print_data(rentals,num_rentals,total,car1);
}
void print_data(car_rentalT rentals[],int num_rentals,float total,best_carT best)
{
    int i;
    printf("\n\n%-7s %-20s %-10s %-5s %-5s %-6s %-8s \n", "Number","Name","Type","CC","Days","Price","Total");
    for(i=1;i<=73;i++)
            printf("-");
    printf("\n");
    for(i=0;i<num_rentals;i++)
    {
       printf("%-7d %-20d %-10d %-5d %-5d %-6.2f %-8.2f",rentals[i].number,rentals[i].name,rentals[i].type,rentals[i].cc,rentals[i].days,rentals[i].daily_rate,rentals[i].total_charge);
    }
    for(i=1;i<=73;i++)
            printf("-");
    printf("\n");
    printf("%58s %-8.2f\n","Total",total);
    printf("Best car: %s %d rented for %.2f Euros.\n",best.type,best.cc,best.amount);
}




