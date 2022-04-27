#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NumberOfNodes 15
#define NilValue 0

#define StackLimit 50
typedef int StackElementType;
typedef struct
{
    int am;
    float grade;

} ListElementType;
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef int ListPointer;
typedef enum {
    FALSE, TRUE
} boolean;
typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;



void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateLList(ListPointer *List);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);
void menu(int *choice);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);
void CreateStack(StackType *Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);boolean EmptyLList(ListPointer List);
boolean FullLList(ListPointer List);
float FindMax(ListPointer FreePtr,NodeType Node[],StackType *stack1);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
main()
{

  ListPointer AList;
    NodeType Node[NumberOfNodes+1];
    ListPointer FreePtr,PredPtr;
    ListElementType AnItem;
    StackType tel;
    float max;
   int c,l;
   char character;
InitializeStoragePool(Node, &FreePtr);

   do
   {
   	menu(&c);
      switch(c)
      {
      	  case 1: CreateLList(&AList);
      	             break;
          case 2:	do
                    {
   	                    printf("FreePtr=%d\n",FreePtr);
                        printf("DWSE AM GIA EISAGWGH STH LISTA: ");
                        scanf("%d", &AnItem.am);
                         printf("DWSE VATHMO GIA EISAGWGH STH LISTA: ");
                        scanf("%f", &AnItem.grade);

                        PredPtr=NilValue;
                        Insert(&AList, Node,&FreePtr, PredPtr, AnItem);
                        printf("AList=%d\n",AList);
                        printf("\nContinue Y/N: ");
                        do
                        {
      	                     scanf("%c", &character);
                        } while (toupper(character)!= 'N' && toupper(character)!= 'Y');
                    } while (toupper(character)!='N');
                    printAll(AList, FreePtr, Node);
                    break;
          case 3:	printf("FreePtr=%d\n",FreePtr);
                    TraverseLinked(AList, Node);
         			break;
          case 4:   if (EmptyLList(AList))
      	                 printf("Empty List\n");
      	            else
      	            {
                        printAll(AList, FreePtr, Node);
                        printf("DWSE TH 8ESH TOY PROHGOYMENO STOIXEIOY GIA DIAGRAFH: ");
                        scanf("%d", &PredPtr);
                        Delete(&AList, Node, &FreePtr, PredPtr);
                        printAll(AList, FreePtr, Node);
                    }
         			break;
          case 5:   if (EmptyLList(AList))
      	                 printf("Empty List\n");
      	            else printf("Not an Empty List\n");
      	            break;
      	case 6:   if (FullLList(FreePtr))
      	                 printf("Full List\n");
      	            else printf("Not a Full List\n");
      	            break;
      	 case 7:	printAll(AList, FreePtr, Node);
         			break;
         case 8:    CreateStack(&tel);
                    if (EmptyStack(tel))
                    {
                    max=FindMax(AList,Node,&tel);
                    if (max!=-1)
                    printf("%f\n",max);



                    while (!EmptyStack(tel))
                    {
                        Pop(&tel,&l);
                        printf("%d ",l);
                    }

                    if (max!=-1)
                    TraverseStack(tel);
                    }





                    break;
	  }
   } while (c!=9);


}






void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)

{
   int i;

    for (i=1; i<NumberOfNodes;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data.grade=-1;
        Node[i].Data.am=-1;
    }
    Node[NumberOfNodes].Next=0;
    Node[NumberOfNodes].Data.grade=-1;
    Node[NumberOfNodes].Data.am=-1;
    *FreePtr=1;
}

void CreateLList(ListPointer *List)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη λίστα.
   Επιστρέφει: Έναν (μηδενικό) δείκτη που δείχνει σε κενή λίστα
*/
{
  *List=NilValue;
}

boolean EmptyLList(ListPointer List)
/* Δέχεται:    Έναν δείκτη List που δείχνει σε μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι κενή.
   Επιστρέφει: True αν η συνδεδεμένη λίστα είναι κενή και false διαφορετικά
*/
{
  return (List==NilValue);
}

boolean FullLList(ListPointer List)
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι γεμάτη.
   Επιστρέφει: True αν η συνδεδεμένηλίστα είναι γεμάτη, false διαφορετικά
*/
{
  return (List == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr.
  Λειτουργία: Αποκτά έναν "ελεύθερο" κόμβο που τον δείχνει ο δείκτης P.
  Επιστρέφει: Τον δείκτη P και τον τροποποιημένο  δείκτη FreePtr
                που δεικτοδοτεί στο πρώτο διαθέσιμο κόμβο
*/
{
  *P = *FreePtr;
  if (!FullLList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
/* Δέχεται:    Τον πίνακα Node, που αναπαριστά τη δεξαμενή των διαθέσιμων κόμβων,
                έναν δείκτη TempPtr και τον δείκτη FreePtr.
   Λειτουργία: Επιστρέφει στη δεξαμενή τον κόμβο στον οποίο δείχνει ο TempPtr.
   Επιστρέφει: Τον τροποποιημένο πίνακα Node και τον δείκτη FreePtr
*/
{
  Node[P].Next =*FreePtr;
  Node[P].Data.am = -1;
  Node[P].Data.grade=-1; /* Οχι αναγκαία εντολή, βοηθητική για να φαίνονται στην
                        εκτύπωση οι διαγραμμένοι κόμβοι */
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/* Δέχεται:    Μια συνδεδεμένη λίστα, τον πίνακα Node, τον δείκτη PredPtr και
                ένα στοιχείο Item.
  Λειτουργία: Εισάγει στη συνδεδεμένη λίστα, αν δεν είναι γεμάτη, το στοιχείο
                Item μετά από τον κόμβο στον οποίο δείχνει ο δείκτης PredPtr.
  Επιστρέφει: Την τροποποιημένη συνδεδεμένη λίστα, τον τροποποιημένο πίνακα Node
                και τον δείκτη FreePtr.
  Εξοδος:     Μήνυμα γεμάτης λίστας, αν η συνδεδεμένη λίστα είναι γεμάτη
*/
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullLList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data.am =Item.am;
         Node[TempPtr].Data.grade =Item.grade;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
       Node[TempPtr].Data.am =Item.am;
         Node[TempPtr].Data.grade =Item.grade;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
/* Δέχεται:   Μια συνδεδεμένη λίστα και τον δείκτη PredPtr που δείχνει
                στον προηγούμενο κόμβο από αυτόν που θα διαγραφεί.
  Λειτουργία: Διαγράφει από τη συνδεδεμένη λίστα, αν δεν είναι κενή,
                τον προηγούμενο κόμβο από αυτόν στον οποίο δείχνει ο PredPtr.
  Επιστρέφει: Την τροποποιημένη λίστα και το δείκτη FreePtr.
  Έξοδος:     Μήνυμα κενής λίστας, αν η συνδεδεμένη λίστα είναι κενή
*/
{
  ListPointer TempPtr ;

  if (!EmptyLList(*List))
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
      }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Κάνει διάσχιση της συνδεδεμένης λίστας, αν δεν είναι κενή.
   Έξοδος:     Εξαρτάται από την επεξεργασία
*/
{
  ListPointer CurrPtr;

  if (!EmptyLList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d,%d,%f,%d) ",CurrPtr,Node[CurrPtr].Data.am,Node[CurrPtr].Data.grade, Node[CurrPtr].Next);
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
    printf("8. Find all max elements-add to stack\n");
    printf("9. Telos\n");
    printf("\nChoice 1-9 : ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>7);
}
float FindMax(ListPointer FreePtr,NodeType Node[],StackType *stack1)
{
    float max=-1;
int j;
int s=0;
    if (!EmptyLList(FreePtr))
    {
    for  (j=1;j<=FreePtr;j++)
    {
        if (Node[j].Data.grade==max)
        {Push(&(*stack1),Node[j].Data.am);
            s++;
            }
          if (Node[j].Data.grade>max){
                max=Node[j].Data.grade;
                CreateStack(&(*stack1));

                 Push(&(*stack1),Node[j].Data.am);}}}
    else
    {
        printf("Empty");
    }
     return (max);
}




void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=1;i<=NumberOfNodes;i++)
        printf("(%d,%d,%f,%d) ",i,Node[i].Data.am,Node[i].Data.grade, Node[i].Next);
    printf("\n");
}




















void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα.*
*/
{
    Stack -> Top = -1;

}

boolean EmptyStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται: Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος: Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:  Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=Stack.Top;i>=0;i--) {
        printf("%d, ",Stack.Element[i]);
    }
    printf("\n");
}








