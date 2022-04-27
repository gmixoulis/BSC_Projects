/*свокиа*/

/*
 *асйгсг ле вягсг кистас
 *диажяажг окым тым стоивеиым стг киста
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
void LinkedDelete(ListPointer *List, ListPointer PredPtr);
void LinkedTraverse(ListPointer List);


/*йуяиыс пяоцяалла*/

main()
    {
        ListPointer List,PredPtr;
        int a,Item,i;
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
        
         for(i=0;i<=a;i++)
            LinkedDelete(&List,PredPtr);

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

void LinkedDelete(ListPointer *List, ListPointer PredPtr)
{
    ListPointer TempPtr;

    if (EmptyList(*List))
   	    printf("EMPTY LIST\n");
   else
   {
      	TempPtr = *List;
        *List = TempPtr->Next;
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
      	     printf("%d, ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
}
