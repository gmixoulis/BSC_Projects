/* askhsh 11 fylladio 2 */

#include <stdio.h>
#include <stdlib.h>

#define  StackLimit 16 


typedef int StackElementType;   // � ����� ��� ���������  ��� �������
                                //���������� ����� int
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;


void FilterStack(StackType stoiva , StackElementType n);
void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);





main(){
    StackElementType n=5;
    StackType stoiva;
    
    CreateStack(&stoiva);
    
    Push( &stoiva, 1);
    Push( &stoiva, 7);
    Push( &stoiva, 5);
    Push( &stoiva, 10);
    Push( &stoiva, 13);
    Push( &stoiva, 2);
    
    TraverseStack( stoiva);
    printf("\nStoixeio poy tha diagrafei:%d\n",n);

    FilterStack( stoiva, n);
    
    TraverseStack( stoiva);
    
    
    system("pause");
}



void CreateStack(StackType *Stack)
/* ����������: ���������� ��� ���� ������.
   ����������: ���� ������.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ����.
   ����������: True �� � Stack ����� ����, False �����������
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ������.
   ����������: True �� � Stack ����� ������, False �����������
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* �������: ��� ������ Stack ��� ��� �������� Item.
   ����������: ������� �� �������� Item ���� ������ Stack �� � Stack ��� ����� ������.
   ����������: ��� ������������� Stack.
   ������: ������ ������� �������, �� � ������ Stack ����� ������
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* �������: ��� ������ Stack.
   ����������: ��������� �� �������� Item ��� ��� ������ ��� ������� �� � ������ ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� Stack.
   ������:  ������ ����� ������� �� � Stack ����� ����
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}



void FilterStack(StackType stoiva, StackElementType n)
{   
    StackType Stack2;
    
    StackElementType item;
    
    CreateStack(&Stack2);
    
    Pop(&stoiva,&item);
    if( item != n)
        Push(&Stack2,item);
    
    while(item != n && !EmptyStack(stoiva) ){
        
        Pop(&stoiva,&item);
        Push(&Stack2, item);
        
    }
    
    if(item == n){
      Pop(&Stack2,&item);
    }
   
    while( !EmptyStack( Stack2)){
        
        Pop(&Stack2,&item);
        Push(&stoiva, item);
       
    }
    
    TraverseStack( stoiva);
    
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
