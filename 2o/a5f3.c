/* askhsh 5 fylladio 3 */


#include <stdio.h>
#include <stdlib.h>

#define  QueueLimit 16 
#define  StackLimit 16 



typedef struct {
	int Front, Rear;
	int Element[QueueLimit];;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

typedef struct  {
    int Top;
    int Element[StackLimit];
} StackType;



void TraverseQ(QueueType Queue);
void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, int *Item);
void AddQ(QueueType *Queue, int Item);
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, int Item);
void Pop(StackType *Stack, int *Item);
void ReverseQ(QueueType *Queue);

main(){
    
    QueueType oyra;
    int i;
    CreateQ( &oyra);

    for(i=2 ; i<32;i=i+2){
        AddQ( &oyra, i);
    }
    
    
    
    ReverseQ( &oyra);





      system("pause");
}    


void CreateQ(QueueType *Queue)
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, int *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, int Item)
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
*/
{
    int NewRear;

	if(!FullQ(*Queue))
	{
		NewRear = (Queue ->Rear + 1) % QueueLimit;
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = NewRear;
	}
	else
		printf("Full Queue");
}




void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
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

void Push(StackType *Stack, int Item)
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

void Pop(StackType *Stack, int *Item)
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


void TraverseQ(QueueType Queue) {
	int current;
	current = Queue.Front;
	while (current != Queue.Rear) {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}


void ReverseQ(QueueType *Queue){
    
    StackType stoiva;   
    
    int stoixeio;
    
    CreateStack( &stoiva);
    
    //TraverseQ( Queue) ; 
    
    while( !EmptyQ( *Queue)){
      
        
        RemoveQ( Queue, &stoixeio);
        printf("%d ",stoixeio);
        Push( &stoiva, stoixeio);
    
    }
    
    
    
    printf("\n");
    
    while( !EmptyStack( stoiva)){
        
        Pop( &stoiva, &stoixeio);
        printf("%d ",stoixeio);
        AddQ( Queue, stoixeio);
    }
   
    //TraverseQ( Queue);
    
    printf("\n");
}


