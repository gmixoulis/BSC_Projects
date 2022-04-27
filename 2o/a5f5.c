//File name: a5f5.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
int BSTLevel(BinTreePointer *Root, BinTreeElementType Item, int count);

    main()
    {
        BinTreePointer ARoot, LocPtr;
        BinTreeElementType AnItem[9];
        char s[9];
        int i, level, count;
        count=0;
        
        CreateBST(&ARoot);
        s[0]='P';
        s[1]='R';
        s[2]='O';
        s[3]='C';
        s[4]='E';
        s[5]='D';
        s[6]='U';
        s[7]='R';
        s[8]='E';
        strcpy(AnItem,s);
        for (i=0;i<=8;i++)
            BSTInsert(&ARoot,AnItem[i]);
        InorderTraversal(ARoot);
        printf("\n");
        for (i=0;i<=8;i++)
        {
            level = BSTLevel(&ARoot,AnItem[i],count);
            printf("Level of %c: %d\n",AnItem[i],level);
        }
        
        system("PAUSE");
    }


void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item < LocPtr ->Data)
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
        LocPtr ->Data = Item;
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
{

   BinTreePointer
   n,                   
   Parent,              
   nNext,               
   SubTree;             
   boolean Found;       

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO %d DEN EINAI STO DDA\n", KeyValue);
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                n->Data = nNext->Data;
                n = nNext;
          } 
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root)
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%d ",Root->Data);
        InorderTraversal(Root->RChild);
    }
}

int BSTLevel(BinTreePointer *Root, BinTreeElementType Item, int count)
{
    BinTreePointer LocPtr;
    LocPtr=(*Root);
    
    while (LocPtr!=NULL)
    {
        if (Item==LocPtr->Data)
        {
            count = count + 1;
            return count;
        }
        else if (Item<LocPtr->Data)
        {
            count = count + 1;
            LocPtr = LocPtr->LChild;
        }
        else if (Item>LocPtr->Data)
        {
            count = count + 1;
            LocPtr = LocPtr->RChild;
        }
    }
    return -1;
}
