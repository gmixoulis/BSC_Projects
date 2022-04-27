#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define Null 0
typedef enum {
    FALSE, TRUE
} boolean;

typedef int ListElementType;
typedef struct ListNode *ListPointer;
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;


void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);


main()
{
    ListPointer FirstList,PredPtr, CurrPtr;
    ListElementType it ;
    CreateList(&FirstList);
    int i,d;
    char str[100];
    printf("dwse alfarithmitiko:\n ");
    gets(str);
    d=strlen(str);
    for(i=0;i<d;i++)
        LinkedInsert(&FirstList,str[i],Null);
    LinkedTraverse(FirstList);
}
void CreateList(ListPointer *List)
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
{
	return (List==NULL);
}


void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
   TempPtr->Data = Item;
	if (PredPtr==NULL) {
        TempPtr->Next = *List;
        *List = TempPtr;
    }
    else {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
    }
}

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    if (PredPtr == NULL)
        {
      	      TempPtr = *List;
              *List = TempPtr->Next;
        }
        else
        {
      	     TempPtr = PredPtr->Next;
             PredPtr->Next = TempPtr->Next;
        }
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;

         while ( CurrPtr!=NULL )
        {

             printf(" %c",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
   }
   printf("\n");
}
