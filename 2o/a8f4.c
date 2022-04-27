/* askhsh 8 fylladio 4 */


#include <stdio.h>
#include <stdlib.h>


typedef int QueueElementType;           /*� ����� ��� ��������� ��� ������������ �����
                                        ���������� ����� int*/
typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{   
    
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{   
    int theseis;
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef int ListElementType;           /* � ����� ��� ��������� ��� ������������ ������
                                        ���������� ����� int */
typedef struct ListNode *ListPointer;   //� ����� ��� ������� ��� ���� �������
typedef struct ListNode
{
	ListElementType Data;
    ListPointer Next;
} ListNode;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void CreateList(ListPointer *List);
boolean EmptyList(ListPointer List);
void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr);
void LinkedDelete(ListPointer *List, ListPointer PredPtr,int *item);
void LinkedTraverse(ListPointer List);
void LinearSearch(ListPointer List, ListElementType Item, boolean *Found,ListPointer *PredPtr,int *theseis);
void OrderedLimearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found);
void eyresi(ListPointer List,QueueType *Queue, int all,int plithositem,ListElementType item);
void eyresimegalyteroy(ListPointer List, ListElementType *item, ListPointer *PredPtr,int *plithos);

main(){


    ListPointer List1,PredPtr;
    int stoixeio,i,plithos,item,synolo;
    QueueType Queue1;
    boolean vrhke;
    
    PredPtr=NULL;
    CreateList(&List1);
    CreateQ(&Queue1);


    printf("Dwse to plithos twn stoixeion tis listas:");
    scanf("%d",&plithos);

    for (i=1;i<=plithos;i++)
    {
        printf("Dwse to %d stoixeio tis listas:",i);
        scanf("%d",&stoixeio);
        PredPtr=0;
        LinkedInsert(&List1,stoixeio,PredPtr);

    }

    printf("Lista:\n");
    LinkedTraverse(List1);
    
    synolo=0;
    eyresimegalyteroy( List1, &item, &PredPtr, &synolo);
    
    eyresi(List1,&Queue1,plithos,synolo,item);
    
    printf("\n\nMegalytero stoixeio: %d ,vrethike: %d fores \n",item,synolo);
    printf("\nSthn/is theseis: ");
    while(Queue1.Front!=Queue1.Rear){
        
        
        
        printf("%d  ",Queue1.Front->Data);
        
        Queue1.Front=Queue1.Front->Next;
    
    }
    printf("\n\n");   
    
    system("pause");
}

void eyresi(ListPointer List,QueueType *Queue, int all,int plithositem,ListElementType item){
    
    int i=1,theseis=0;
    ListPointer CurrPtr1,CurrPtr2,PredPtr;  
    boolean vrhke=FALSE;
    
    CurrPtr1=List;
    PredPtr=NULL;
    
    while(theseis<all){
    
        LinearSearch(CurrPtr1,item, &vrhke, &PredPtr, &theseis);
        
        if(vrhke==TRUE){
            
            AddQ(Queue,theseis);
        }
    }
    AddQ(Queue,theseis);
    
    
    
}


void eyresimegalyteroy(ListPointer List, ListElementType *item, ListPointer *PredPtr,int *plithos){
    
    
   ListPointer CurrPtr1,CurrPtr2;
   

   CurrPtr1 =CurrPtr2 = List;
    *PredPtr=NULL;
  
   *item=0;
   
   while ( CurrPtr1!=NULL )
    {
         if (CurrPtr1->Data > *item )
         	*item=CurrPtr1->Data;
         	
         
      	*PredPtr = CurrPtr1;
         CurrPtr1 = CurrPtr1->Next;
         
	}
	
    while ( CurrPtr2!=NULL )
    {
         if (CurrPtr2->Data == *item )
         	*plithos=*plithos+1;
        
        

      	*PredPtr = CurrPtr2;
         CurrPtr2 = CurrPtr2->Next;

	}
    
}

void CreateList(ListPointer *List)
/* ����������: ���������� ��� ���� ����������� �����.
  ����������:  ��� �������� ������ List
*/
{
	*List = NULL;
}

boolean EmptyList(ListPointer List)
/* �������:   ��� ����������� ����� �� ��� List �� ������� ���� ����� �����.
  ����������: ������� �� � ����������� ����� ����� ����.
  ����������: True �� � ����� ����� ���� ��� false �����������
*/
{
	return (List==NULL);
}

void LinkedInsert(ListPointer *List, ListElementType Item, ListPointer PredPtr)
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� �����,
                ��� �������� ��������� Item ��� ���� ������ PredPtr.
   ����������: ������� ���� �����, ��� �������� �� Item, ���� ����������� �����
                ���� ��� ��� ����� ��� �������������� ��� ��� PredPtr
                � ���� ����  ��� ������������ ������,
                �� � PredPtr ����� ���������(NULL).
  ����������:  ��� ������������� ����������� ����� �� ��� ����� ����� ���
                �� �������������� ��� ��� List.
*/
{
	ListPointer TempPtr;

   TempPtr= (ListPointer)malloc(sizeof(struct ListNode));
   //printf("Insert &List %7d, List %7d,  &(*List) %7d, (*List) %7d, TempPtr %7d\n",
   //&List, List,  &(*List), (*List), TempPtr);
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

void LinkedDelete(ListPointer *List, ListPointer PredPtr,int *item)
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� ����� ���
                 ��� ���� ������ PredPtr.
   ����������: ��������� ��� �� ����������� ����� ��� ����� ��� ����
                ��� ����������� ��� ����� ���� ����� ������� � PredPtr
                � ��������� ��� ����� �����, �� � PredPtr ����� ���������,
                ����� ��� �� � ����� ����� ����.
   ����������: ��� ������������� ����������� ����� �� ��� ����� �����
                �� �������������� ��� ��� List.
   ������:     ��� ������ ����� ������ �� � ����������� ����� ���� ���� .
*/
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
        *item=TempPtr->Data;
        free(TempPtr);
    }
}

void LinkedTraverse(ListPointer List)
/* �������:    ��� ����������� ����� �� ��� List �� ������� ���� ����� �����.
   ����������: ��������� �� ����������� ����� ���
                ������������� ���� �������� ������� ��� ����.
   ����������: ��������� ��� �� ����� ��� ������������.
*/
{
	ListPointer CurrPtr;

   if (EmptyList(List))
   	    printf("EMPTY LIST\n");
   else
   {
   	    CurrPtr = List;
   	  /*  printf("%7s, %7s, %7s, %12s, %12s\n","&List","List","&(*List)","(*List).Data","(*List).Next");
   	    printf("%7d, %7d, %8d, %12d, %12d\n",&List, List, &(*List),(*List).Data, (*List).Next);
         printf("\n");
         printf("%7s, %10s\n","&CurrPtr", "&(*CurrPtr)"); */
         while ( CurrPtr!=NULL )
        {
      	 //    printf("%8d, %11d\n",&CurrPtr, &(*CurrPtr));
             printf(" %d ", (*CurrPtr).Data);
             CurrPtr = CurrPtr->Next;
        }
   }
}

void LinearSearch(ListPointer List, ListElementType Item, boolean *Found,ListPointer *PredPtr,int *theseis)
/* �������:   ��� ����������� ����� �� ��� List �� ������� ���� ����� �����.
  ����������: ������� ��� �������� ��������� ���� �� ������������ �����������
              ����� ��� ���� ����� ��� �� �������� �� �������� Item.
  ����������: �� � ��������� ����� �������� � Found ����� true, � CurrPtr �������
                ���� ����� ��� �������� �� Item ��� � PredPtr ���� ����������� ���
                � ����� nil �� ��� ������� ������������.
                �� � ��������� ��� ����� �������� � Found ����� false.
*/
{
   ListPointer CurrPtr;
   boolean stop;
    
    if(*PredPtr==NULL)
        CurrPtr = List;
    else{ 
        CurrPtr = *PredPtr;
        CurrPtr = CurrPtr->Next;
    }
   stop= FALSE;
   while (!stop && CurrPtr!=NULL )
    {
         if (CurrPtr->Data==Item ){
         	 
             stop = TRUE;
         	
         	}
         else
         {
         	
            CurrPtr = CurrPtr->Next;
         }
         *PredPtr = CurrPtr;
         *theseis=*theseis+1;
	}
	*Found=stop;
}

void OrderedLimearSearch(ListPointer List, ListElementType Item, ListPointer *PredPtr, boolean *Found)
/* �������:    ��� �������� Item ��� ��� ������������ ����������� �����,
                ��� �������� �������� ��������� �� ������� ������� ��� ���� �����
                � ������� List ������� ���� �����  �����.
   ����������: ������� �������� ��������� ��� ������������ ������������� ������
                ��� ��� ����� ����� ��� �������� �� �������� Item � ��� ��� ����
                ��� �� ������� ��� ��� ����� ��� �� �������� �� �������� Item.
   ����������: �� � ��������� ����� �������� � Found ����� true,
                � CurrPtr ������� ���� ����� ��� �������� �� Item ���
                � PredPtr ���� ����������� ��� � ����� nil �� ��� ������� ������������.
                �� � ��������� ��� ����� �������� � Found ����� false.
*/
{
   ListPointer CurrPtr;
   boolean DoneSearching;

   CurrPtr = List;
   *PredPtr = NULL;
   DoneSearching = FALSE;
   *Found = FALSE;
   while (!DoneSearching && CurrPtr!=NULL )
    {
         if (CurrPtr->Data>=Item )
         {
         	DoneSearching = TRUE;
         	*Found = (CurrPtr->Data==Item);
         }
         else
         {
         	*PredPtr = CurrPtr;
            CurrPtr = CurrPtr->Next;
         }
	}
}


void CreateQ(QueueType *Queue)
/* ����������: ���������� ��� ���� ����������� ����.
   ����������: ��� ���� ����������� ����
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����������� ����.
   ����������: ������� �� � ����������� ���� ����� ����.
   ����������: True �� � ���� ����� ����, false  �����������
*/
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* �������:    ��� ����������� ���� Queue ��� ���  �������� Item.
   ����������: ��������� �� �������� Item ��� ����� ��� ������������ ����� Queue.
   ����������: ��� ������������� ����
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* �������:    ��� ����������� ����.
   ����������: ������� �� �������� Item ��� ���  ������ ��� ������������ �����,
                �� ��� �����  ����.
   ����������: �� �������� Item ��� ��� ������������� ����������� ����.
   ������:     ������ ����� �����, �� � ���� �����  ����
*/
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}



