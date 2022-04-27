#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include <string.h>
#include <strlib.h>

typedef struct{
char name[40];
long ypoloipo;
float ep;
int date;} bank_katatheseis;


void SaveClients(int c2,bank_katatheseis person2[],FILE *outfile);
long FindSum(int c,bank_katatheseis person[]);
int FindMax(int c,bank_katatheseis person[]);
int RefreshCatalog(FILE *file,bank_katatheseis person[100]);
int PrintNames(int i,int c1,int clients2,bank_katatheseis person[],bank_katatheseis person2[]);
main(){
    FILE *infile,*infile2,*outfile;
    int c1,c2,i,maxpos,maxpos2;
    long sum1,sum2;
    bank_katatheseis person1[100],person2[100];
    infile=fopen("bank_old.dat","r");
    infile2=fopen("bank_new.dat","r");
    outfile=fopen("mztfgm.dat","w");
    c1=RefreshCatalog(infile,person1);
    c2=RefreshCatalog(infile2,person2);
    for(i=0;i<c2;i++){
        if(PrintNames(i,c1,c2,person1,person2)!=1)
            printf("%s\n",person2[i].name);
    }
    SaveClients(c2,person2,outfile);

    sum1=FindSum(c1,person1);
    printf("40%% apo to bank_old.dat to synolko poso %ld\n",sum1);
    sum2=FindSum(c2,person2);
    printf("40%% apo bank_new.dat to synoliko poso %ld\n",sum2);
    maxpos2=FindMax(c2,person2);
    printf("megisto poso apo to bank_new.dat einai %ld\n",maxpos2);
    maxpos=FindMax(c1,person1);
    printf("megisto poso apo to bank_old.dat einai %ld\n",maxpos);
    fclose(infile);
    fclose(infile2);
    fclose(outfile);

}

int RefreshCatalog(FILE* file,bank_katatheseis person[]){
    int i=0, nscan;
    char termch;
    while(TRUE){
        if(i>=100) break;
        nscan=fscanf(file,"%40[^,], %ld, %g, %d%c",person[i].name,
                     &person[i].ypoloipo,&person[i].ep,&person[i].date,&termch);
        if(nscan==EOF) break;
        if(nscan!=5 || termch!='\n'){
            printf("Error");
            break;
        }
        i++;
    }
    return i;
}

int PrintNames(int i,int c1,int c2,bank_katatheseis person1[],bank_katatheseis person2[])
{
    int j,flag=0;
    for(j=0;j<c1;j++){
        if(strcmp(person1[j].name,person2[i].name)==0){
            flag=1;
            break;
        }
    }
    return flag;
}

void SaveClients(int c2,bank_katatheseis person2[],FILE *outfile)
{
    int i;
    for(i=0;i<c2;i++)
    {
        if(person2[i].date>=2000)
        {
            fprintf(outfile,"%s,%ld,%g,%d\n",person2[i].name,person2[i].ypoloipo,person2[i].ep,person2[i].date);
        }
    }
}

long FindSum(int c,bank_katatheseis person[])
{
    int i;
    long sum=0;
    for(i=0;i<c;i++)
    {
        sum+=person[i].ypoloipo;
    }
    return sum;
}

int FindMax(int c,bank_katatheseis person[])
{
    int i;
    long maxpos=person[0].ypoloipo;
    for(i=1;i<c;i++)
    {
        if(person[i].ypoloipo>maxpos)
            maxpos=person[i].ypoloipo;
    }
    return maxpos;
}
