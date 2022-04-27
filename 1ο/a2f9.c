#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "simpio.h"
#define m 100
typedef struct
{
    char name[30];
    int apousies;

}studentRec;
void readInput(FILE* infile,studentRec students[m],int *pApousies,int *pStudents);
void writeDutput(FILE* outfile,studentRec students[m],int mathites,int apontes);
main()
{

  char inputfilename[30];
  char outputfilename[30];
  FILE* infile;
  FILE* outfile;
  studentRec students[m];
  int studnum,apontes;
  while (TRUE)
  {
      printf("Dwse to onoma tou arxeiou eisodou");
      gets(inputfilename);
      infile =fopen(inputfilename ,"r");
      if (infile!=NULL)
        break;
      printf("cannot open file %d Try again\n",inputfilename);


  }
    printf("Dwse to onoma tou arxeiou exodou");
    gets(outputfilename);
    outfile=fopen(outputfilename,"w");
    readInput(infile,students,&apontes,&studnum);
    writeDutput(outfile,students,studnum,apontes);
}
void readInput(FILE* infile,studentRec students[m],int *pApousies,int *pStudents)
{
    char name[30],comments[68],termch;
    int apousies,nscan;
    int studcount,apousiescount; /* metrites */
    studcount=apousiescount=0;
    while (TRUE){
      nscan=fscanf(infile,"%30[^,], %d, %68[^\n]%c",name,&apousies,comments,&termch);
      if (nscan==EOF ) break;
      if(nscan!= 4 || termch!='\n')
        printf("ERROR \n");
      studcount++;
      if (apousies >100){
          strcpy(students[apousiescount].name,name);
          students[apousiescount].apousies=apousies;
           apousiescount++;      }}

*pApousies=apousiescount;
*pStudents=studcount;
}

void writeDutput(FILE* outfile,studentRec students[m],int mathites,int apontes)
{    int i;
    fprintf(outfile,"%-30s%-9s\n","ONOMATEPWNYMO","APOUSIES");
    for (i=1; i<=39;i++)
        fputc('-',outfile);
    fputc('\n',outfile);
    for(i=0;i<apontes;i++)
        fprintf(outfile,"%-30s%-9s\n",students[i].name,students[i].apousies);
for (i=1 ;i<=39;i++)
        fputc('-',outfile);
    fputc('\n',outfile);
    fprintf(outfile,"%-30s%-9s\n","SYNOLO MATHITWN:");
    fprintf(outfile,"%-30s%-9s\n","SYNOLO APONTWN:");

}











