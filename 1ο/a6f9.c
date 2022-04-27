#include <stdio.h>
#include "genlib.h"
#define m 10
main()
{
    FILE *infile, *outfile;
    char arr[m]={"i6f9.dat"}, arr2[m]={"o6f9.dat"};
    int charackter;

    infile=fopen(arr, "r");
    outfile=fopen(arr2, "w");
    charackter=getc(infile);
    while(charackter!=EOF)
    {
       if((charackter!=' ')&&(charackter!='\n'))
        {
            putc(charackter, outfile);
            charackter=getc(infile);
        }
        else
        {
            charackter='\n';
            putc(charackter, outfile);
        if((charackter==32)|| (charackter==10))
            {charackter=getc(infile);
            }
        }




    }
    fclose(infile);
    fclose(outfile);
}


