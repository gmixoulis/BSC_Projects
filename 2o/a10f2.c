 
#include <stdio.h>
#include <stdlib.h>


#define StackLimit 6


typedef int StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
void TraverseStack(StackType Stack);
void Pop(StackType *Stack, StackElementType *Item);
void Push(StackType *Stack, StackElementType Item);
boolean StackError;
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);


main()
{
        int i;
        StackType AStack, A2Stack, A3Stack;
        StackElementType AnItem;

        CreateStack(&AStack);
        CreateStack(&A2Stack);
        CreateStack(&A3Stack);
        
         
        printf("Dwse tin stoiva: ");
        for(i=0;i<StackLimit;i++)
        {
            scanf("%c",&AStack.Element[i]);
            AStack.Top++;
        }
        printf("Stack1\n");
        TraverseStack(AStack);

        AnItem = AStack.Top;

        
        for(i=0;i<StackLimit;i++)
        {
            Pop(&AStack,&AnItem);
            Push(&A2Stack,AnItem);
        }
        printf("Stack2\n");
        TraverseStack(A2Stack);

        
        for(i=0;i<StackLimit;i++)
        {
            Pop(&A2Stack,&AnItem);
            Push(&A3Stack,AnItem);
        }
        printf("Stack3\n");
        TraverseStack(A3Stack);
        
        
        for(i=0;i<StackLimit;i++)
        {
            Pop(&A3Stack,&AnItem);
            Push(&AStack,AnItem);
        }
        printf("Stack1\n");
        TraverseStack(AStack);
        
    system("PAUSE");
}

void CreateStack(StackType *Stack)
{
    StackError = FALSE;
    Stack -> Top = -1;
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("plithos stoibas %d\n", Stack.Top+1);
    
    for(i=0;i<=Stack.Top;i++)
        printf("%c ", Stack.Element[i]);

    printf("\n");
}

void Pop(StackType *Stack, StackElementType *Item)
{

    StackError = EmptyStack(*Stack);
    
    if (!StackError) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
        }
    else
        printf("Empty Stack...\n");
}

void Push(StackType *Stack, StackElementType Item)
{
    StackError = FullStack(*Stack);
    
    if (!StackError) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...\n");
}

boolean EmptyStack(StackType Stack)
{
    StackError = FALSE;
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
{
    StackError = FALSE;
    return (Stack.Top == (StackLimit - 1));
}



