/* askhsh 7 fylladio 5 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char BinTreeElementType;       

typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType Item, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);
BinTreeElementType MaxBSTValue(BinTreePointer Root);
BinTreeElementType MinBSTValue(BinTreePointer Root);

main(){
 
 
    BinTreePointer Dentro;
   
    
    CreateBST(& Dentro);
    
    BinTreeElementType min,max;
    
    BSTInsert(&Dentro,'P');  
    BSTInsert(&Dentro,'R');
    BSTInsert(&Dentro,'O');
    BSTInsert(&Dentro,'C');
    BSTInsert(&Dentro,'E');
    BSTInsert(&Dentro,'D');
    BSTInsert(&Dentro,'U');
    BSTInsert(&Dentro,'R');
    BSTInsert(&Dentro,'E');
    
    
    min=MinBSTValue(Dentro);
    max=MaxBSTValue(Dentro);
    
    printf("\n");
    
    printf("H mikroteri timi toy DDA einai to gramma: %c \n",min);
    printf("H megalyteri timi toy DDA einai to gramma: %c \n",max);
    
    system("pause");
}


BinTreeElementType MaxBSTValue(BinTreePointer Root){

    BinTreePointer LocPtr;

    LocPtr=Root;

    while(LocPtr!=NULL){
        if(LocPtr->RChild==NULL)
            return LocPtr->Data;
        else
            LocPtr=LocPtr->RChild;
    }

}



BinTreeElementType MinBSTValue(BinTreePointer Root){

    BinTreePointer LocPtr;

    LocPtr=Root;

    while(LocPtr!=NULL){
        if(LocPtr->LChild==NULL)
            return LocPtr->Data;
        else
            LocPtr=LocPtr->LChild;
    }

}
    

void CreateBST(BinTreePointer *Root)
/* ����������: ���������� ��� ���� ���.
   ����������:  ��� �������� ������(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* �������:   ��� ��� �� �� Root �� ������� ��� ���� ���.
  ����������: ������� �� �� ��� ����� ����.
  ����������: TRUE �� �� ��� ����� ���� ��� FALSE �����������
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* �������:     ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� �������� Item.
   ����������:  ������� �� �������� Item ��� ���.
   ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���
*/
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item < LocPtr->Data)
            LocPtr = LocPtr ->LChild;
        else if (Item > LocPtr ->Data)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }

    if (Found)
        printf("To %c EINAI HDH STO DDA\n", Item);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        strcpy(&LocPtr ->Data , &Item);
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item < Parent ->Data)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���.
   ����������: � Found ���� ���� TRUE ��� � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE
*/
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (KeyValue < (*LocPtr)->Data)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (KeyValue > (*LocPtr)->Data)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent)
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���
                ��� ��� ������ ��� ������ �����.
   ����������: � Found ���� ���� TRUE, � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue ��� � Parent ������� ���� ������
                ����� ��� ������, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE.
*/
{
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
        if (KeyValue < (*LocPtr)->Data) {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (KeyValue > (*LocPtr)->Data) {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }

}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* �������:  ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
  ����������: ��������� �� ���� ���� ����� ��� ��� ��� �� �������� ��� ����
                KeyValue ��� ����� ������ ��� �������� ��������� ��� ���,
                �� ��� ����, ��� ��������� ��� �� ���.
  ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���.
*/
{

   BinTreePointer
   n,                   //������� ���� ����� ��� �������� ��� ���� KeyValue *)
   Parent,              // ������� ��� n � ��� nNext
   nNext,               // ����������������� �������� ��� n
   SubTree;             // ������� ���� ��������� ��� n
   boolean Found;       // TRUE AN TO �������� KeyValue EINAI ������� ��� ��� *)

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO %d DEN EINAI STO DDA\n", KeyValue);
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // ������ ���� �������� �� ��� ������
                 //���� ��� ���������������� ������� ��� ��� ������ ���
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* ��������� ��� ������������ ��� nNext ���� n ���
                ������ ��� n ���� �� ������� ���� ������� */
                strcpy( &n->Data, &nNext->Data);
                n = nNext;
          } //����������� �� ��� ��������� ��� � ������ ���� �� ���� 1 �����
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 //* 8A DIAGRAFEI H RIZA *)
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s ",Root->Data);
        InorderTraversal(Root->RChild);
    }
}



