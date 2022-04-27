#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

float fpa(float synoliko_poso,int kathgoria);

main()
{
int plithos,kathgoria,i;
float timh_monadas,synoliko_kostos=0.0,synoliko_fpa,synoliko_poso;


synoliko_fpa=0;
for (i=1; i<=10 ;i++)
  {
  printf("dwse plithos proiontwn %d:",i);
  plithos=GetInteger();
  printf("dwse timi gia to proion %d:",i);
  timh_monadas=GetReal();
  printf("dwse katigoria FPA gia to proion %d:",i);
  kathgoria=GetInteger();
  synoliko_poso = plithos * timh_monadas;
  synoliko_kostos += (synoliko_poso + fpa(synoliko_poso,kathgoria));
  synoliko_fpa += fpa(synoliko_poso,kathgoria) ;
  }
printf("synoliko kostos: %lf \n", synoliko_kostos );
printf("synoliko fpa: %lf\n", synoliko_fpa);
  system("pause");
}

float fpa(float synoliko_poso,int kathgoria )
{
  float foros;
  switch (kathgoria)
  {
      case 1: foros=0.0; break;
      case 2: foros=synoliko_poso * 0.06; break;
      case 3: foros=synoliko_poso * 0.13; break;
      default:foros=synoliko_poso * 0.19; break;
  }
  return foros;
}
