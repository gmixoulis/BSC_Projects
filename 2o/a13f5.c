
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char Name[20];
    char LastName[20];
    int arithmos;
}BinTreeElementType;


typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;
typedef enum {
    FALSE, TRUE
} boolean;
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,BinTreePointer *LocPtr);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void RecBSTInorder(BinTreePointer Root);
void InsertNewEmployee(BinTreeElementType AnItem[10], BinTreePointer *Root1, BinTreePointer *Root2, BinTreePointer *Root3, int i);
void SearchForAnEmployee(BinTreeElementType AnItem[10],BinTreePointer *Root1, BinTreePointer *Root2, BinTreePointer *Root3);
void menu(int *epilogh);
void ReadData(FILE* infile, BinTreeElementType AnItem[10], int *s);

    main()
    {
        FILE* infile;
        BinTreeElementType AnItem[10];
        int s,t,i;
        BinTreePointer Root1,Root2,Root3,LocPtr;
        boolean Found;
        int epilogh;
        s=i=0;
        do
        {
            menu(&epilogh);
            switch(epilogh)
            {
      	         case 1:
                        CreateBST(&Root1);
                        CreateBST(&Root2);
                        CreateBST(&Root3);
                        while (TRUE)
                        {
                            printf("Anoi3e to arxeio eisodou I13F5.txt: \n");
                            infile = fopen ("I13F5.txt", "r");
                            if (infile != NULL) break;
                            printf("Error");
                        }
                        ReadData(infile,AnItem,&s);
                        break;
                 case 2:
                        InsertNewEmployee(AnItem,&Root1,&Root2,&Root3,i);
                        i++;
                        break;
                 case 3:
                        SearchForAnEmployee(AnItem,&Root1,&Root2,&Root3);
                        break;
                 case 4:
                        printf("Dialekse kwdiko ypaliloy: ");
                        scanf("%d",&t);
                        if (t==1)
                            RecBSTInorder(Root1);
                        else if (t==2)
                            RecBSTInorder(Root2);
                        else if (t==3)
                            RecBSTInorder(Root3);
                        break;
            }
        }while (epilogh!=5);
    }


void CreateBST(BinTreePointer *Root)
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
{
    return (Root==NULL);
}

void RecBSTInorder(BinTreePointer Root)
{
    if (Root!=NULL) {
        RecBSTInorder(Root->LChild);
        printf("<%s %s %d>,",Root->Data.LastName, Root->Data.Name, Root->Data.arithmos);
        RecBSTInorder(Root->RChild);
    }
}

void menu(int *epilogh)
{
    printf("\n");
    printf("                  MENOY                  \n");
    printf("1 Create BSTs from file\n");
    printf("2 Insert new employee\n");
    printf("3 Search for an employee\n");
    printf("4 Print employees\n");
    printf("5 Quit\n");
    printf("\n");
    do
    {
    	scanf("%d", epilogh);
    } while (*epilogh<1 && *epilogh>4);
}

void ReadData(FILE* infile, BinTreeElementType AnItem[20], int *s)
{
    int nscan, code1, i=0;
    char termch, LastName1[20], name1[20];
    while (TRUE)
    {
        nscan = fscanf(infile,"%20s %20s %d%c", LastName1, name1, &code1, &termch);
            if (nscan == EOF) break;
            if (nscan != 4 || termch != '\n')
                printf("Error\n");
            else
            {
                strcpy(AnItem[i].LastName, LastName1);
                strcpy(AnItem[i].Name, name1);
                AnItem[i].arithmos = code1;
                i++;
            }
    }
    *s = i;
}

void InsertNewEmployee(BinTreeElementType AnItem[20], BinTreePointer *Root1, BinTreePointer *Root2, BinTreePointer *Root3, int i)
{
    if (AnItem[i].arithmos == 1)
        BSTInsert(Root1,AnItem[i]);
    else if (AnItem[i].arithmos == 2)
        BSTInsert(Root2,AnItem[i]);
    else if (AnItem[i].arithmos == 3)
        BSTInsert(Root3,AnItem[i]);
}

void SearchForAnEmployee(BinTreeElementType AnItem[10],BinTreePointer *Root1, BinTreePointer *Root2, BinTreePointer *Root3)
{    BinTreePointer LocPtr;
    BinTreeElementType Itemm;
    int codex;
    boolean Found;

    printf("lastname: ");
    scanf("%s",&Itemm.LastName);
    printf("arithmos: ");
    scanf("%d",&Itemm.arithmos);
    if (Itemm.arithmos == 1)
    {
        BSTSearch(*Root1,Itemm,&Found,&LocPtr);
    }
    else if (Itemm.arithmos== 2)
    {
        BSTSearch(*Root2,Itemm,&Found,&LocPtr);
    }
    else if (Itemm.arithmos == 3)
    {
        BSTSearch(*Root3,Itemm,&Found,&LocPtr);
    }
    if (Found==TRUE)
    {
        printf("%s %s %d\n",LocPtr->Data.LastName, LocPtr->Data.Name, LocPtr->Data.arithmos);
    }
    else
        printf("Can not Found\n");

}


void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
{
    int i=0;
    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (KeyValue.LastName[i] < (*LocPtr)->Data.LastName[i])
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (KeyValue.LastName[i] > (*LocPtr)->Data.LastName[i])
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
        i++;
    }
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
{
    BinTreePointer LocPtr, Parent;
    boolean Found;
    int i=0;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item.LastName[i] < LocPtr ->Data.LastName[i])
            LocPtr = LocPtr ->LChild;
        else if (Item.LastName[i] > LocPtr ->Data.LastName[i])
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
        i++;
    }
    if (Found)
        printf("yparxei hdh ");
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data = Item;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item.LastName[0] < Parent ->Data.LastName[0])
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}
