#include <stdio.h>
#include "simpio.h"
#include <math.h>
#include "genlib.h"

int main()
{


  float arithmos_litrwn, poso_miliwn;
  printf("dose milia kai litra:");
  poso_miliwn=GetReal();
  arithmos_litrwn= GetReal();
  if ( arithmos_litrwn/ poso_miliwn < 0.9)
    printf("poly xamili");
  else if  (arithmos_litrwn/ poso_miliwn < 1.2)
    printf("xamili");
  else if (arithmos_litrwn/ poso_miliwn < 1.8)
    printf(" kanonikh");
  else
    printf("ipsili");



}
