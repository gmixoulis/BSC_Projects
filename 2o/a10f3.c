#define QueueLimit 20
#include <stdio.h>
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


 main()
 {
QueueType q,w,e,p;
CreateQ(&p); CreateQ(&w);CreateQ(&q);CreateQ(&e);


int item,g;
int t=0,f=0;



QueueElementType l;


for (g=0;g<20;g++)
{
    item= rand() % QueueLimit ;

    if (item % 2 ==0) {
        AddQ(&q,item);
    t++;
                       }
    else {
        AddQ(&w,item);
        f++;
          }

 }


printf("Size OddQueue: %d\n",f);
TraverseQ(w);
printf("\n");
printf("Size EvenQueue: %d\n",t);
TraverseQ(q);


item=rand() %t;
for (g=0;g<item;g++)
{
    RemoveQ(&q,&l);
    AddQ(&e,l);
}

for (g=0;g<item;g++)
{
     RemoveQ(&e,&l);
    AddQ(&q,l);
}


printf("random numbers =%d\n",item);
printf("Size EvenQueue: %d\n",t);
TraverseQ(q);

for (g=0;g<item;g++)
{
     RemoveQ(&p,&l);
    AddQ(&w,l);
}

item= rand() % f;
for (g=0;g<item;g++)
{
    RemoveQ(&w,&l);
    AddQ(&p,l);
}




printf("random num item =%d\n",item);
printf("Size OddQueue: %d\n",f);
TraverseQ(w);

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


