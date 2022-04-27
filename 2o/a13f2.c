/* askhsh 13 fylladio 2 */

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
    
    printf("DIATHESIMES LEITOURGIES: +,-,*,/,c,s,q,u \n");
    printf(" c = clear, s = show result, q = quit, u = undo\n");
    printf("Operation:");
    
    
    
    
    
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
    } else
        printf("Full Stack...");
}


void Pop(StackType *Stack, StackElementType *Item)
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}






