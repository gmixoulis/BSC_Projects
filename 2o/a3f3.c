#include <stdio.h>

#define QueueLimit 17

typedef int QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);
void GetFrontElementA(QueueType *Queue,QueueElementType *j);
void GetFrontElementB(QueueType Queue,QueueElementType *j);
void GetRearElementA(QueueType Queue,QueueElementType *j);
void GetRearElementb(QueueType *Queue,QueueElementType *j);


main()
{
int i;
QueueElementType j;
QueueType x;

CreateQ(&x);


for (i=3;i<50;i=i+3)
{
 AddQ(&x,i);
}
if (EmptyQ(x))
{

}
else{
printf("after AddQ: ");

TraverseQ(x);


}

GetFrontElementA(&x,&j);
if (j!=-1){
printf("x) -> %d\n",j);
printf("after GetFrontElementA: ");
TraverseQ(x);
}

GetFrontElementB(x,&j);
if (j!=-1){

printf("b) -> %d\n",j);
printf("after GetFrontElementB: ");
TraverseQ(x);
}

GetRearElementA(x,&j);
if (j!=-1){
 printf("c) -> %d\n",j);
printf("after GetFrontElementB: ");
TraverseQ(x);
}

GetRearElementb(&x,&j);
if (j!=-1){
 printf("d) -> %d\n",j);
printf("after GetFrontElementA: ");
TraverseQ(x);
}
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

void RemoveQ(QueueType *Queue, QueueElementType *Item)
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

void AddQ(QueueType *Queue, QueueElementType Item)
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


void TraverseQ(QueueType Queue) {
	int current;
	current = Queue.Front;
	while (current != Queue.Rear) {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}




void GetFrontElementB(QueueType Queue,QueueElementType *j)
{
    if (!EmptyQ(Queue))
    *j=Queue.Element[1];
    else
        *j=-1;

}
void GetRearElementb(QueueType *Queue,QueueElementType *j)
{
    int i;

if (!EmptyQ(*Queue)){
    for (i=0;i<15;i++)
    {
        RemoveQ(&(*Queue),&(*j));
    }
    }
    else
        *j=-1;

}


void GetRearElementA(QueueType Queue,QueueElementType *j)
{
    if (!EmptyQ(Queue))
   *j=Queue.Element[15];
   else
        *j=-1;

}
void GetFrontElementA(QueueType *Queue,QueueElementType *j)
{
    if (!EmptyQ(*Queue))
    {
     RemoveQ(&(*Queue),&(*j));
    }
    else
        *j=-1;

}


