

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int boxno;
    char date[20];
    }StackElementType;
typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType box;
	StackElementType c;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);
void TraverseStack(StackPointer Stack);
int indexofmin(StackPointer *Warehouse1, StackPointer *Warehouse2, StackPointer *Warehouse3);
int StackSize(StackPointer Warehouse);


 main()
    {
        StackPointer Warehouse1, Warehouse2, Warehouse3;
        StackElementType Item;
        int x, min,i,z,w;
        char c[20];


        CreateStack(&Warehouse1);
        CreateStack(&Warehouse2);
        CreateStack(&Warehouse3);
        printf("Plithos fortiwn:");
        scanf("%d",&x);
        for(i=1;i<=x;i++)
        {
            printf("Arithmos kivwtiwn gia to %do fortio:",i);
            scanf("%d",&z);
            Item.boxno = z;
            printf("Imeromhnia likshs gia to %do fortio:",i);
            scanf("%d",&c);
            strcpy(Item.date,c);
            w =  indexofmin(&Warehouse1,&Warehouse2,&Warehouse3);
            if ( w == 1 )
                Push(&Warehouse1,Item);
            else if ( w == 2 )
                Push(&Warehouse2,Item);
            else
                Push(&Warehouse3,Item);
        }
        printf("Warehouse1\n");
        TraverseStack(Warehouse1);
        printf("\n");
        printf("Warehouse2\n");
        TraverseStack(Warehouse2);
        printf("\n");
        printf("Warehouse3\n");
        TraverseStack(Warehouse3);
        printf("\n");


        system("PAUSE");
    }


void CreateStack(StackPointer *Stack)
{
	*Stack = NULL;

}

boolean EmptyStack(StackPointer Stack)
{
	return (Stack==NULL);

}

void Push(StackPointer *Stack, StackElementType Item)
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);

    }
}

void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");

    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d %s\n", CurrPtr->Data.boxno, CurrPtr->Data.date
               );
             CurrPtr = CurrPtr->Next;
        }

   }
}

int indexofmin(StackPointer *Warehouse1, StackPointer *Warehouse2, StackPointer *Warehouse3)
{
    if ( StackSize( Warehouse1)<= StackSize( Warehouse2) &&  StackSize( Warehouse1)<= StackSize( Warehouse3))
        return 1;
    else if ( StackSize( Warehouse2)<= StackSize( Warehouse1) &&  StackSize( Warehouse2)<= StackSize( Warehouse3))
        return 2;
    else
        return 3;

}


int StackSize(StackPointer Warehouse);
{
    StackPointer CurrPtr;
    int count;

    count=0;
    CurrPtr = Warehouse;
         while ( CurrPtr!=NULL )
        {
      	     count = count + CurrPtr->Data.boxno;
             CurrPtr = CurrPtr->Next;
        }
        return count;
}

