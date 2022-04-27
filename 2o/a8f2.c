/* askhsh 8 fylladio 2 */

#include <stdio.h>
#include <stdlib.h>

#define StackLimit 50

typedef char StackElementType;
typedef struct {
        int Top;
        StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);


main(){
    
    int i=0,j,k,t,p=0 ;
    StackType lexi[StackLimit],anapodi[StackLimit];
    
    StackElementType gramma[0],gramma2[0];
    
    CreateStack( &lexi);
    
    printf("Enter string:\n");
    
    
    do{
    
        scanf("%c", gramma);
    
        fflush(stdin);
    
        Push( &lexi, gramma[0]);
        
        p++;
        
   }while( gramma[0] != '\n');
    
    Pop( &lexi,&gramma);
    Pop( &lexi,&gramma);
   
    CreateStack( &anapodi);
    
    while( gramma[0] != 'C' && i!=p ){
        
        Pop( &lexi, &gramma);
        
        Push( &anapodi, gramma[0]);
        
        i++;
        
    }
     Pop( &anapodi, &gramma);
     
     i=i-2;
     j=0;
     k=0;
     while( j<i ){
            
        Pop( &lexi, &gramma);
        
        Pop( &anapodi, &gramma2);
        
        if(gramma[0] == gramma2[0])
          k++;

        j++;
     }

     if(k==j)
       printf("TRUE\n");
     else
       printf("FALSE\n");


     system("pause");
}


void CreateStack(StackType *Stack)
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}


boolean EmptyStack(StackType Stack)
{
    return (Stack.Top == -1);
}


boolean FullStack(StackType Stack)
{
    return (Stack.Top == (StackLimit - 1));
}


void Push(StackType *Stack, StackElementType Item)
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } //else
      //  printf("Full Stack...");
}


void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } //  else
      //  printf("Empty Stack...");
}


