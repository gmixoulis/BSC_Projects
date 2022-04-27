
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
     int AM;
     char LastName[20];
     char Name[20];
     char sex[2];
     int year;
     float degrees;
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
void InsertNewStudent(BinTreeElementType AnItem[10], BinTreePointer *Root1,int i);
void SearchForAStudent(BinTreeElementType AnItem[10],BinTreePointer *Root);
void menu(int *epilogh);
void ReadData(FILE* infile, BinTreeElementType AnItem[10], int *s);
void PrintUpperThanAverage(BinTreePointer Root,int t);
    main()
    {
        FILE* infile;
        BinTreeElementType AnItem[10];
        int s,t,i;
        BinTreePointer Root1,LocPtr;
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
                        while (TRUE)
                        {
                            printf("Anoi3e to arxeio eisodou foitites.dat: \n");
                            infile = fopen ("foitites.dat", "r");
                            if (infile != NULL) break;
                            printf("Error");
                        }
                        ReadData(infile,AnItem,&s);
                        break;
                 case 2:
                        InsertNewStudent(AnItem,&Root1,i);
                        i++;
                        break;
                 case 3:
                        SearchForAStudent(AnItem,&Root1);
                        break;
                 case 4:
                        printf("Dialekse kwdiko ypaliloy: ");
                        scanf("%d",&t);
                        RecBSTInorder(Root1);
                        break;
                 case 5:
                        printf("dwse ton MO:\n ");
                        scanf("%d",t);
                        PrintUpperThanAverage(Root1,t);
                                        }
        }while (epilogh!=6);
    }

void PrintUpperThanAverage(BinTreePointer Root,int t)
{
    int i;
    for(i=0;i<t;i++)
        printf("<%d %s %s %s %d %lf>,",Root->Data.AM, Root->Data.LastName, Root->Data.Name,Root->Data.sex ,Root->Data.year, Root->Data.degrees);
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
        printf("<%d %s %s %s %d %lf>,",Root->Data.AM, Root->Data.LastName, Root->Data.Name,Root->Data.sex ,Root->Data.year, Root->Data.degrees);
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
    printf("5 Print all the degrees over the average\n");
    printf("6 Quit\n");
    printf("\n");
    do
    {
    	scanf("%d", epilogh);
    } while (*epilogh<1 && *epilogh>5);
}

void ReadData(FILE* infile, BinTreeElementType AnItem[20], int *s)
{   float degrees1;
    int nscan, date, i=0,arithmos_mitroou;
    char termch, LastName1[20], name1[20],sex1[2];
    while (TRUE)
    {
        nscan = fscanf(infile,"%d %20s %20s %2s %d %f%c", &arithmos_mitroou,LastName1, name1,sex1, &date,degrees1, &termch);
            if (nscan == EOF) break;
            if (nscan != 7 || termch != '\n')
                printf("Error\n");
            else
            {
                AnItem[i].AM=arithmos_mitroou;
                strcpy(AnItem[i].LastName, LastName1);
                strcpy(AnItem[i].Name, name1);

               strcpy(AnItem[i].sex,sex1);
                AnItem[i].year=date;
                AnItem[i].degrees = degrees1;
                i++;
            }
    }
    *s = i;
}

void InsertNewStudent(BinTreeElementType AnItem[20], BinTreePointer *Root1, int i)
{
          BSTInsert(Root1,AnItem[i]);
}

void SearchForAStudent(BinTreeElementType AnItem[10],BinTreePointer *Root)
{    BinTreePointer LocPtr;
    BinTreeElementType Itemm;
    int codex;
    boolean Found;


    printf("Dwse Arithmo Mhtrwou: ");
    scanf("%d",&Itemm.AM);
    BSTSearch(*Root,Itemm,&Found,&LocPtr);
    if (Found==TRUE)
     printf("%d %s %s %s %d %f\n",LocPtr->Data.AM,LocPtr->Data.LastName, LocPtr->Data.Name,LocPtr->Data.sex,LocPtr->Data.year,LocPtr->Data.degrees );    else
        printf("Can not Found\n");

}


void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (KeyValue.AM < (*LocPtr)->Data.AM)
            (*LocPtr) = (*LocPtr)->LChild;
       else
            if (KeyValue.AM > (*LocPtr)->Data.AM)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;

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
