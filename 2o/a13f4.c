//File name: a13f4.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nameof[8];
    char job[12];
    }QueueElementType;
typedef struct QueueNode *QueuePointer;

struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} ;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;

boolean QueueError;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void readInput(FILE* infile, QueueType *AQueue, QueueType *BQueue, int *count);

    main()
    {
        QueueType AQueue,BQueue;
        QueueElementType Q;
        FILE* infile;
        char inputfilename[30];
        int count=0;
        
        CreateQ(&AQueue);
        CreateQ(&BQueue);
        
        while (TRUE)
        {
            printf("Anoi3e to arxeio eisodou I13F4.dat: \n");
            infile = fopen ("I13F4.dat", "r");
            if (infile != NULL) break;
            printf("Cannot open input file %s. Try again.\n", inputfilename);
        }
        
        readInput(infile,&AQueue,&BQueue,&count);
        while (count>=0)
        {
            if (EmptyQ(BQueue)==FALSE)
            {
                printf("Printing the job of %s %s\n",BQueue.Front->Data.nameof,BQueue.Front->Data.job);
                printf("Press any key to continue\n");
                RemoveQ(&BQueue,&Q);
            }
            else if (EmptyQ(AQueue)==FALSE)
            {
                printf("Printing the job of %s %s\n",AQueue.Front->Data.nameof,AQueue.Front->Data.job);
                printf("Press any key to continue\n");
                RemoveQ(&AQueue,&Q);
            }
            else
                printf("There are no jobs in the printing queue.\n");
            count--;
        }
        system("PAUSE");
    }



void CreateQ(QueueType *Queue)
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
	QueueError=FALSE;
}

boolean EmptyQ(QueueType Queue)
{
	return (Queue.Front==NULL);
	QueueError=FALSE;
}

void AddQ(QueueType *Queue, QueueElementType Item)
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
   	    QueueError=TRUE;
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
        QueueError=FALSE;
    }
}

void readInput(FILE* infile, QueueType *AQueue, QueueType *BQueue, int *count)
{
    char nscan[30], name[8];
    QueueElementType Q;
    int k=0;

    
    if ((infile = fopen ("I13F4.dat", "r"))==NULL)
    {
        printf("PROVLIMA STO ANOIGMA TOU ARXEIOY");
    }
    else
    {
        while (!feof(infile) )
        {
            fscanf(infile,"%s",Q.nameof);
            fscanf(infile,"%s",Q.job);
            if ((Q.nameof[0]=='U' && Q.nameof[1]=='S' && Q.nameof[2]=='E' && Q.nameof[3]=='R') || (Q.nameof[0]=='F' && Q.nameof[1]=='O' && Q.nameof[2]=='R' && Q.nameof[3]=='T'))
            {
                AddQ(AQueue,Q);
            }
            else
            {
                AddQ(BQueue,Q);
            }
            k++;
        }
    }
    *count=k;
    
}
