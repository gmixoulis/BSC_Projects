#include <stdio.h>
#include <stdlib.h> //den einai aparaititi..
#define StackLimit 100   // �� ���� �������� ��� �������, ���������� ��� �� 50


typedef int StackElementType;   // � ����� ��� ���������  ��� �������
                                //���������� ����� int
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

void GetTopElementA(StackType *Stack, StackElementType *topElement);
void GetTopElementB(StackType Stack, StackElementType *topElement);



main()
{
    int i;
    StackType Stack;
    StackElementType AItem, BItem;
    
    i=1;
    
    CreateStack(&Stack);
    
    while(i>0 && i<100){
        Push(&Stack, i);
        i+=2;
    }
    
    GetTopElementA(&Stack,&AItem);
    GetTopElementB(Stack,&BItem);
    
    printf("GetTopElementA = %d\n",AItem);
    printf("GetTopElementB = %d\n",BItem);
    
    system("pause");
    
}


void GetTopElementA(StackType *Stack, StackElementType *topElement)
{
    Pop(Stack,topElement);
    Push(Stack,*topElement);
}

void GetTopElementB(StackType Stack, StackElementType *topElement)
{
    *topElement=Stack.Element[Stack.Top];
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


boolean FullStack(StackType Stack)
/* �������: ��� ������ Stack.
   ����������: ������� �� � ������ Stack ����� ������.
   ����������: True �� � Stack ����� ������, False �����������
*/
{
    return (Stack.Top == (StackLimit - 1));
}
