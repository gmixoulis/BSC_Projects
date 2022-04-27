#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"
#define N 10

void

main()
{
    FILE *P, *T;
    char name1[N]={"i1f9.dat"}, name2[N]={"o1f9.dat"};
    int ch;
    P=fopen(name1, "r");
    T=fopen(name2, "w");
    while ((ch = getc(P)) != EOF)
    {
        fputc(ch, T);
        if (ch==32)
        {

            while ((ch=getc(P))==32)
            {
            }
            fputc(ch, T);
        }

    }
    fclose(P);
    fclose(T);

}
