/* askhsh 2 fylladio 1 */

#include <stdio.h>
#include <stdlib.h>
#define M 127

typedef int stoixeio_synolou;
typedef enum{
    FALSE, TRUE
} boolean;
typedef boolean typos_synolou[M];


boolean isValidInteger(char xrhsths[M], typos_synolou Character[M], typos_synolou Digit[M]);
boolean isValidIdentifier(char xrhsths[M], typos_synolou Letter[M], typos_synolou Digit[M]);
void Dimiourgia(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);


main(){
    
    typos_synolou CharacterSet[M];
    typos_synolou DigitSet[M];
    typos_synolou LetterSet[M];
    char epilogi[1], xrhsths[M];
    int i;
    
    Dimiourgia(CharacterSet);
    
    Dimiourgia(DigitSet);
    
    Dimiourgia(LetterSet);
    
    Eisagogi(43,CharacterSet);
    
    Eisagogi(45,CharacterSet);
    
    
    for( i=48; i<=57; i++)
    Eisagogi(i,DigitSet);
    
    for( i=65; i<=90; i++)
    Eisagogi(i,LetterSet);
   
    for( i=97; i<=122; i++)
    Eisagogi(i,LetterSet);
    
    
    printf("thes na matheis an einai akeraios arithmos auto pou tha plhkrologhseis? \n");
    
    printf("an nai pata 'y' or 'Y' = YES, an oxi 'n' or 'N' = NO \n");
    
    gets(epilogi);
    
    while( epilogi[0] =='y' || epilogi[0] == 'Y'){
        
        printf("twra plhkrologhse auto poy theleis na matheis:\n");
       
        gets(xrhsths);
       
        if(isValidInteger( xrhsths , CharacterSet , DigitSet) == TRUE)
         printf("\n Valid Integer\n");
        else
         printf("\n Not a valid integer\n");
         
        printf("\nthes na matheis kai gia allon? \n");
        
        printf("an nai pata 'y' or 'Y' = YES, an oxi 'n' or 'N' = NO \n");
        
        gets(epilogi);
    
    }
    
    
    
    
    printf("thes na matheis an einai anagnwristiko auto pou tha plhkrologhseis?\n");
    
    printf("an nai pata 'y' or 'Y' = YES, an oxi 'n' or 'N' = NO \n");
    
    gets(epilogi);
    
    while( epilogi[0] =='y' || epilogi[0] == 'Y'){

        printf("twra plhkrologhse auto poy theleis na matheis:\n");
        
        gets(xrhsths);
        
        if(isValidIdentifier( xrhsths , LetterSet , DigitSet) == TRUE)
         printf("\n Valid identifier \n");
        else
         printf("\n Not a valid identifier \n");

        printf("\nthes na matheis kai gia allo? \n");

        printf("an nai pata 'y' or 'Y' = YES, an oxi 'n' or 'N' = NO \n");

        gets(epilogi);

    } 
 
 
    system("pause");
    
}


void Dimiourgia(typos_synolou synolo)
{
    stoixeio_synolou i;

    for ( i=0 ; i <= M ; i++)
        synolo[i] = FALSE;
}


void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)

{
    synolo[stoixeio] = TRUE;
}


boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
{
    return synolo[stoixeio];
}


boolean isValidInteger(char xrhsths[100], typos_synolou Character[M], typos_synolou Digit[M])
{
  boolean result;
  
  result = TRUE;
 
  int i ;
  
  
  for(i=0;i<100;i++){
        
        
            if( Melos(xrhsths[0] ,Character ) || Melos( xrhsths[i], Digit))
              result= TRUE;
            else
              result=FALSE;  
       
        
  }
  
  return result;


}


boolean isValidIdentifier(char xrhsths[100], typos_synolou Letter[M], typos_synolou Digit[M])
{
    
    boolean result;
    
    result = TRUE;
    
    int i=0;
    
    if(Melos(xrhsths[0],Letter)){
           result=TRUE;//giati mporei na stamathsei sto prwto gramma
           for(i=1;i<100;i++){
                 
                 if( Melos(xrhsths[i],Letter) || Melos(xrhsths[i],Digit))
                       result=TRUE;
                 else
                       result=FALSE;
           
                
         } 
    }
    else 
          result=FALSE;
        
         
    return result;
}
