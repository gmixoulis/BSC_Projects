

#include <stdio.h>
#include <stdlib.h>


#define NumberOfNodes 50
#define NilValue 0

typedef int ListElementType;
typedef int ListPointer;


typedef enum {
    FALSE, TRUE
} boolean;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

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
int Search(ListPointer Free, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item);

    main()
{

        ListPointer Free;
        ListPointer PredPtr;
        NodeType Node[NumberOfNodes+1];
        ListElementType AnItem;
        ListPointer AList;

        int c, i;
        char g;

        InitializeStoragePool(Node, &Free);
        printAll(AList, Free, Node);
        do
        {
   	    menu(&c);
        switch(c)
        {
      	  case 1: CreateLList(&AList);
      	             break;
          case 2:	do
                    {
   	                    printf("Free=%d\n",Free);
                        printf("give a number ");
                        scanf("%d", &AnItem);
                        PredPtr=Search(Free,AList,Node,AnItem);
                        Insert(&AList, Node,&Free, PredPtr, AnItem);
                        printf("\nContinue Y/N: ");
                        do
                        {
      	                     scanf("%c", &g);
                        } while (toupper(g)!= 'N' && toupper(g)!= 'Y');
                    } while (toupper(g)!='N');
                    printAll(AList, Free, Node);
                    break;
            case 3:	printf("Free=%d\n",Free);
                    TraverseLinked(AList, Node);
         			break;
            case 4:   if (EmptyLList(AList))
      	                 printf("Adeia\n");
      	            else
      	                {
                        printAll(AList, Free, Node);
                        printf("Dwse to prohgoumeno stoixeio");
                        scanf("%d", &PredPtr);
                        PredPtr=Search(Free,AList,Node,AnItem);
                        Delete(&AList, Node, &Free, PredPtr);
                        printAll(AList, Free, Node);
                        }
         			break;
             case 5:   if (EmptyLList(AList))
      	                 printf("Adeia\n");
      	            else printf("Den einai giomath\n");
      	            break;
      	     case 6:	printAll(AList, Free, Node);
         			break;
	                    }
                    } while (c!=7);

	return 0;
    }




void printAll(ListPointer List, ListPointer Free, NodeType Node[])
{
    int i;
    printf("1o stoixeio =%d, 1H thesi =%d\n", List, Free);
    printf("h deksamenh exei ta ekshs stoixeia\n");
    for (i=1;i<=NumberOfNodes;i++)
        printf("(%d,%d,%d) ",i,Node[i].Data, Node[i].Next);
    printf("\n");
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
    printf("6. Print storage pool\n");
    printf("7. Telos\n");
    printf("\nChoice 1-7 : ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>7);
}

void InitializeStoragePool(NodeType Node[NumberOfNodes], ListPointer *Free)
{
   int i;

    for (i=1; i<NumberOfNodes;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data=-1;
    }
    Node[NumberOfNodes].Next=0;
    Node[NumberOfNodes].Data=0;
    *Free=1;
}

void CreateLList(ListPointer *List)
{
  *List=NilValue;
}

void GetNode(ListPointer *P, ListPointer *Free, NodeType Node[NumberOfNodes])
{
  *P = *Free;
  if (*Free!=0)
    *Free =Node[*Free].Next;
}
boolean EmptyLList(ListPointer List)
{
  return (List==NilValue);
}

boolean FullLList(ListPointer List)
{
  return (List==0);
}


void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *Free)
{
  Node[P].Next =*Free;
  Node[P].Data = -1;

  *Free=P;
}



void Delete(ListPointer *List, NodeType Node[NumberOfNodes], ListPointer *Free, ListPointer PredPtr)
{
  ListPointer TempPtr ;

  if (!EmptyLList(*List))
    if (PredPtr==(*List)-1)
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
    printf("Empty\n");
}
int Search(ListPointer Free, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item)
{
    ListPointer previous, current;

    if (EmptyLList(List))
    {
        return (previous = Free-1);
    }
    else{
        previous=0;
        current=List;
        while(current!=NilValue)
        {
            if(Node[current].Data>= Item)
            {
                break;
            }
            else
            {
                previous = current;
                current = Node[current].Next;
            }
        }
        return previous;
        }
}


void Insert(ListPointer *List, NodeType Node[NumberOfNodes],ListPointer *Free, ListPointer PredPtr, ListElementType Item)
{
  ListPointer TempPtr;
  GetNode(&TempPtr,Free,Node);
  if (!FullLList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full\n");
}

void TraverseLinked(ListPointer List, NodeType Node[NumberOfNodes])
{
  ListPointer CurrPtr;

  if (!EmptyLList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d,%d,%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty\n");
}
