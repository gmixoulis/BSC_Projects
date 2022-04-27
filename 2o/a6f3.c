/* askhsh 6 fylladio 3 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define QueueLimit 10

typedef int QueueElementType;

typedef struct{
    int Front,Rear,Count;
    QueueElementType Element[QueueLimit];
}QueueType;

typedef enum{FALSE, TRUE}boolean;

void CreateQ(QueueType *Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

main(){
      
      int i;
      QueueElementType prwtos;
     
      QueueType Queue;
      
      CreateQ( &Queue);
   
      for(i=0; i<=9; i++){
         
          AddQ( &Queue, i);
      
      }
      
      printf("--a--\nQueue:");
      
      TraverseQ( Queue) ;
      
      printf("Front=%d Rear=%d Count=%d\n", Queue.Front , Queue.Rear, Queue.Count);
      
      
      printf("--b--\n");
      AddQ( &Queue, 40);
      printf("\nQueue:");
      TraverseQ( Queue) ;
      
      printf("Front=%d Rear=%d Count=%d", Queue.Front , Queue.Rear, Queue.Count);
      
      printf("\n--c--");
      
      RemoveQ( &Queue, &prwtos);
      
      printf("\nQueue:");
      TraverseQ( Queue) ;
      
      printf("Removed Item=%d Front=%d Rear=%d Count=%d", prwtos ,Queue.Front , Queue.Rear, Queue.Count);
      
      printf("\n--d--");
      AddQ( &Queue , 25);
      printf("\nQueue:");
      TraverseQ( Queue) ;
      printf("Front=%d Rear=%d Count=%d", Queue.Front , Queue.Rear, Queue.Count);
    
      printf("\n--e--\n");
      AddQ( &Queue, 43);
      printf("\nQueue:");
      TraverseQ( Queue) ;
      printf("Front=%d Rear=%d Count=%d\n", Queue.Front , Queue.Rear, Queue.Count);
    
    
    
 
  system("pause");
}

void CreateQ(QueueType *Queue)
{
	Queue->Front = 0;
	Queue->Rear = 0;
    Queue->Count = 0;
}

void AddQ(QueueType *Queue, QueueElementType Item)
{

	if(Queue ->Count!=10)
	{
		
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
		Queue ->Count++;
	}
	else
		printf("Full Queue");
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
	if(Queue ->Count!=0)
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
		Queue ->Count --;
		
	}
	else
		printf("Empty Queue");
}

void TraverseQ(QueueType Queue) {
	int i;
	for(i=0; i<=Queue.Count;i++) {
        printf("%d ", Queue.Element[Queue.Front]);
		Queue.Front = (Queue.Front + 1) % QueueLimit;
	}
	printf("\n");
}

















