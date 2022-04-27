#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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


void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void ListUnite(ListPointer ListA,ListPointer ListB,ListPointer *LastList);

main()
{
    ListElementType it;
    ListPointer FirstList,SecondList, LastList;

    int i,nnodes;
        CreateList(&FirstList);
        CreateList(&LastList);
        CreateList(&SecondList);


    printf("vale ton arithmo tvn komvn");
    scanf("%d",&nnodes);

    for(i=0;i<nnodes;i++)
    {
        printf("vale stoixeio komvou");
        scanf("%d", &it);
        LinkedInsert(&FirstList,it,Null);
    }


    printf("2h lista\n");
    printf("vale komvous: ");
    scanf("%d",&nnodes);

    for(i=0;i<nnodes;i++)
    {
        printf("vale stoixeio komvou ");
        scanf("%d", &it);
        LinkedInsert(&SecondList,it,Null);
    }

    ListUnite(FirstList,SecondList,&LastList);
    printf("prwth lista");
    LinkedTraverse(FirstList);
    printf("deyterh lista: ");
    LinkedTraverse(SecondList);
    printf("teleytea lista");
    LinkedTraverse(LastList);

}




void CreateList(ListPointer *List)
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
{
	return (List==NULL);
}
void ListUnite(ListPointer ListA,ListPointer ListB,ListPointer *LastList)
{
    while( ListA!=Null){
        LinkedInsert(&(*LastList),(*ListA).Data,Null);
        ListA= (*ListA).Next;}
    while(ListB!=Null){
        LinkedInsert(&(*LastList),(*ListB).Data,Null);
        ListB= (*ListB).Next;
    }}

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

             printf(" %d",(*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
   }
   printf("\n");}


