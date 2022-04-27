/*свокиа*/

/*
 *асйгсг ле вягсг кистас
 *еисацыцг стоивеиоу сто текос тгс кистас
 */
 
 /*бибкиохгйес*/
 
#include <stdio.h>
#include <stdlib.h>

/*еццяажес*/

typedef int ListElementType;
typedef struct ListNode *ListPointer;

struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ;

typedef enum {
    FALSE, TRUE
} boolean;

/*пяотупа сумаятгсеым*/

void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsertStart(ListPointer *List, ListElementType Item);
void LinkedInsertFinish(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);

/*йуяиыс пяоцяалла*/

main()
    {
        ListPointer List,PredPtr;
        int a,Item,i,b;
        boolean Found;

        CreateList(&List);

        printf("DWSE TO PLH8OS TWN STOIXEIWN TIS LISTAS: ");
        scanf("%d",&a);
        
        for(i=0;i<a;i++)
        {
            printf("DWSE TON ARI8MO GIA EISAGWGI STIN ARXI TIS LISTAS: ");
            scanf("%d",&Item);
            LinkedInsertStart(&List,Item);
        }
        
        LinkedTraverse(List);
        printf("\n");

        printf("DWSE TON ARI8MO GIA EISAGWGI STO TELOS THS LISTAS: ");
        scanf("%d",&b);
        
        LinearSearch(List,b,&PredPtr,&Found);
        LinkedInsertFinish(&List,b,PredPtr);
        LinkedTraverse(List);
        printf("\n");

        system("PAUSE");
     }

/*пяотупа сумаятгсеым*/

void CreateList(ListPointer *List)
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
{
	return (List==NULL);
}

void LinkedInsertStart(ListPointer *List, ListElementType Item)
{
    	
   ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
   TempPtr->Data = Item;
   TempPtr->Next = *List;
   *List = TempPtr;

}

void LinkedInsertFinish(ListPointer *List, ListElementType Item, ListPointer PredPtr)
{
    ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
   TempPtr->Data = Item;
   if (PredPtr!=NULL)
   {
        TempPtr->Next = PredPtr->Next;
        PredPtr->Next = TempPtr;
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
      	     printf("%d, ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
}

void LinearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
{
   ListPointer CurrPtr, Pred;
   boolean stop;

   CurrPtr = List;
   Pred = NULL;
   stop= FALSE;
   while (!stop && CurrPtr!=NULL )
    {
         if (CurrPtr->Data==Item )
         	stop = TRUE;
         else
         {
         	Pred = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
	*Found=stop;
	*PredPtr=Pred;
}
