
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NumberOfNodes 5

#define NilValue 0

typedef struct{
    char name[20];
    float bathmos;
}ListElementType;

typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;


typedef enum {
    FALSE, TRUE
} boolean;

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);
void InitializeStoragePool(NodeType Node[NumberOfNodes], ListPointer *Free);
void CreateLList(ListPointer *List);
void GetNode(ListPointer *P, ListPointer *Free, NodeType Node[NumberOfNodes]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *Free);
void Insert(ListPointer *List, NodeType Node[NumberOfNodes],ListPointer *Free, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[NumberOfNodes], ListPointer *Free, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[NumberOfNodes]);
void menu(int *choice);
boolean EmptyLList(ListPointer List);
boolean FullLList(ListPointer List);
main(){


    NodeType Node[NumberOfNodes+1];
    ListPointer Free,PredPtr,List;
    ListElementType Item;


   char g;
   int c, i;
   InitializeStoragePool(Node, &Free);
   printAll(List, Free, Node);
   do
   {
   	menu(&c);
      switch(c)
      {
      	  case 1: CreateLList(&List);
      	             break;
          case 2:	do
                    {
   	                    printf("Free %d\n",Free);
                        printf("DWSE ARI8MO GIA EISAGWGH STH LISTA: ");
                        scanf("%d", &Item);
                        PredPtr=NilValue;
                        Insert(&List, Node,&Free, PredPtr, Item);
                        printf("List=%d\n",List);
                        printf("\nContinue Y/N: ");
                        do
                        {
      	                     scanf("%c", &g);
                        } while (toupper(g)!= 'N' && toupper(g)!= 'Y');
                    } while (toupper(g)!='N');
                    printAll(List, Free, Node);
                    break;
          case 3:	printf("FreePtr=%d\n",Free);
                    TraverseLinked(List, Node);
         			break;
          case 4:   if (EmptyLList(List))
      	                 printf("Empty List\n");
      	            else
      	            {
                        printAll(List, Free, Node);
                        printf("DWSE TH 8ESH TOY PROHGOYMENO STOIXEIOY GIA DIAGRAFH: ");
                        scanf("%d", &PredPtr);
                        Delete(&List, Node, &Free, PredPtr);
                        printAll(List, Free, Node);
                    }
         			break;
          case 5:   if (EmptyLList(List))
      	                 printf("Empty List\n");
      	            else printf("Not an Empty List\n");
      	            break;
      	case 6:   if (FullLList(Free))
      	                 printf("Full List\n");
      	            else printf("Not a Full List\n");
      	            break;
      	 case 7:	printAll(List, Free, Node);
         			break;
	  }
   } while (c!=8);

	return 0;













    system("pause");
}


void InitializeStoragePool(NodeType Node[], ListPointer *Free)
{
   int i;

    for (i=1; i<NumberOfNodes;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.bathmos=-1;
        strcpy(Node[i].Data.name,"-");
    }
    Node[NumberOfNodes].Next=0;
    Node[NumberOfNodes].Data.bathmos=0;
    strcpy(Node[NumberOfNodes].Data.name,"-");
    *Free=1;
}

void CreateLList(ListPointer *List)

{
  *List=NilValue;
}

boolean EmptyLList(ListPointer List)

{
  return (List==NilValue);
}

boolean FullLList(ListPointer Free)

{
  return (Free == NilValue);
}

void GetNode(ListPointer *P, ListPointer *Free, NodeType Node[])

{
  *P = *Free;
  if (!FullLList(*Free))
    *Free =Node[*Free].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *Free)

{
  Node[P].Next =*Free;
  Node[P].Data.bathmos = -1;
  strcpy(Node[NumberOfNodes].Data.name,"-")
  ;
  *Free =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *Free, ListPointer PredPtr, ListElementType Item)

{
  ListPointer TempPtr;
  GetNode(&TempPtr,Free,Node);
  if (!FullLList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data.bathmos =Item.bathmos;
        strcpy(Node[TempPtr].Data.name,Item.name);
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data.bathmos =Item.bathmos;
        strcpy(Node[TempPtr].Data.name,Item.name);
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *Free, ListPointer PredPtr)

{
  ListPointer TempPtr ;

  if (!EmptyLList(*List))
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,Free);
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,Free);
      }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])

{
  ListPointer CurrPtr;

  if (!EmptyLList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d,%d,%s,%d) ",CurrPtr,Node[CurrPtr].Data.bathmos,Node[CurrPtr].Data.name, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Create List\n");
    printf("2. Insert an element to List\n");
    printf("3. Traverse List\n");
    printf("4. Delete an element from the List\n");
    printf("5. Check if List is empty\n");
    printf("6. Check if List is full\n");
    printf("7. Print storage pool\n");
    printf("8. Telos\n");
    printf("\nChoice 1-8 : ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>7);
}

void printAll(ListPointer List, ListPointer Free, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, Free);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=1;i<=NumberOfNodes;i++){
        printf("(%d,%d,%s,%d) ",i,Node[i].Data.bathmos,Node[i].Data.name, Node[i].Next);
    }
    printf("\n");
}

