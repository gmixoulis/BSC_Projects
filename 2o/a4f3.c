/* askhsh 4 fylladio 3 */

#include <stdio.h>
#include <stdlib.h>

#define  QueueLimit 21

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
void GetNthElementA(QueueType *Queue, int n);
void GetNthElementB(QueueType *Queue, int n);


main(){
    
    int n,i;
    
    QueueType oyra;
    
    
    CreateQ( &oyra);
    
    for(i=5; i<101; i=i+5){
       AddQ( &oyra, i);
    }    
    
    
    do{
        printf("Dwse n:");
       
        n=GetInteger();

        
    
    }while( n > ( QueueLimit - oyra.Front + oyra.Rear)%QueueLimit );
    
     
    GetNthElementB( &oyra, n);
    
    GetNthElementA( &oyra, n);
    
    
    
    
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

void GetNthElementA(QueueType *Queue, int n)
{
    QueueElementType stoixeio;
    int i;    
       
    for(i=0;i<n;i++){
        RemoveQ( Queue, &stoixeio);
    }
    
    printf("%d\n",stoixeio);

}

void GetNthElementB(QueueType *Queue, int n)
{   
    
    int i=0,p;
    QueueElementType stoixeio;
    
    p = Queue->Front-1;   
    
    while( i<n) {
               
         p ++;
         
        
         i++;  
    }
        
    if( 0<i)            
      printf("%d\n",Queue->Element[p]);
    else
      printf("0\n");
}   
