/* askhsh 1 fylladio 3 */


#include <stdio.h>
#include <stdlib.h>

#define QueueLimit 21

typedef int QueueElementType;   /* � ����� ��������� ��� ��������� ��� �����
                                  ���������� ����� int */

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];;
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void TraverseQ(QueueType Queue);
void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
int QsizeA(QueueType *Queue);
int QsizeB(QueueType *Queue);

main(){
    
    int n1,n2,i;
    QueueType oyra;
    
    CreateQ(&oyra);
    
    for(i=0;i<20;i++)
        AddQ(&oyra,i);
   
   
   
    printf("Question a\n");
   
    printf("Full Queue\nQueue\n");
    TraverseQ( oyra);
    
    n1=QsizeA(&oyra);
    n2=QsizeB(&oyra);
    
    
    printf("<QsizeA> size of queue:%d\n",n1);
    printf("<QsizeB> size of queue:%d\n\n",n2);
    
    for(i=0;i<20;i++)
        AddQ(&oyra,i);
    
    printf("Question b\n");
    printf("Full Queue\nQueue\n");
    TraverseQ( oyra);
    
    
    for(i=0;i<10;i++)
        RemoveQ(&oyra,&n1);
  
    printf("Queue\n");
    TraverseQ( oyra);

    n1=QsizeA(&oyra);
    n2=QsizeB(&oyra);
    
    printf("<QsizeA> size of queue:%d\n",n1);
    printf("<QsizeB> size of queue:%d\n\n",n2);

    printf("Question c\n");
    
    n1=QsizeA(&oyra);
    n2=QsizeB(&oyra);

    printf("<QsizeA> size of queue:%d\n",n1);
    printf("<QsizeB> size of queue:%d\n\n",n2);
  
    
    
    system("pause");
}


void CreateQ(QueueType *Queue)
/*  ����������:  ���������� ��� ���� ����.
    ����������:  ���� ����
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ����.
   ����������: True �� � ���� ����� ����, False �����������
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ������.
   ����������: True �� � ���� ����� ������, False �����������
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* �������:    ��� ����.
   ����������: ������� �� �������� Item ��� ��� ������ ���� ��� �����
                �� � ���� ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� ����.
   ������:     ������ ����� ���� �� � ���� ����� ����
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
/* �������:    ��� ���� Queue ��� ��� �������� Item.
   ����������: ��������� �� �������� Item ���� ���� Queue
                �� � ���� ��� ����� ������.
   ����������: ��� ������������� ����.
   ������:     ������ ������� ����� �� � ���� ����� ������
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

int QsizeB(QueueType *Queue){
    
    int i=0,j;
    
    while((QueueLimit-Queue->Front+Queue->Rear)%QueueLimit){
        
        
        RemoveQ( Queue,&j);
        i++;
            
    }
    
    return i;
    
}

int QsizeA(QueueType *Queue){
    
    return(QueueLimit-Queue->Front+Queue->Rear)%QueueLimit;
 
 
    
}
