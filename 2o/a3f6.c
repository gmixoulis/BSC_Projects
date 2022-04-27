//File name: a3f6.c

#include <stdio.h>

#define HMax 5
#define VMax 30
#define EndOfList -1

typedef struct {
    char name[20];
    int byte;
} ListElementType;

typedef struct {
	int RecKey;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax+1];
    int Size;
	int SubListPtr;
    int StackPtr;
	ListElm List[VMax+1];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateHashList(HashListType *HList);
void HashKey(int Key,int *HValue);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,int KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,int KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,int DelKey);
void menu(int *choice);
void PrintPinakes(HashListType HList);

    main()
    {
        HashListType HList;
        ListElm AnItem;
        int choice, AKey;
        int Loc, Pred;
        char ch;

         do
         {
   	        menu(&choice);
            switch(choice)
            {
      	        case 1:
   	                    CreateHashList(&HList);
                        break;
                case 2:
                        do
                        {
                            printf("Enter the key of the user: ");
                            scanf("%d", &AnItem.RecKey);
                            printf("Enter the name of the user: ");
                            scanf("%s", &AnItem.Data.name);
                            printf("Enter the byte of the user: ");
                            scanf("%d", &AnItem.Data.byte);
                            AddRec(&HList, AnItem);
                            printf("\nContinue Y/N: ");
                            do
                            {
      	                         scanf("%c", &ch);
                            } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
                        } while (toupper(ch)!='N');
         		        break;
                case 3:
                        printf("Enter a number for deleting in the Hash: ");
                        scanf("%d", &AKey);
                        DeleteRec(&HList, AKey);
         			    break;
                case 4:
                        printf("Enter a number for searching in the Hash: ");
                        scanf("%d", &AKey);
                        SearchHashList(HList,AKey,&Loc,&Pred);
                        if ( Loc != 0)
                        {
                            printf("%s ",HList.List[Loc].Data.name);
                            if (HList.List[Loc].Data.byte==1)
                                printf("Postgraduate Student");
                            if (HList.List[Loc].Data.byte==2)
                                printf("PhD Student");
                            if (HList.List[Loc].Data.byte==3)
                                printf("Professor");
                            if (HList.List[Loc].Data.byte==4)
                                printf("External user");
                        }
                        else{
                            printf("There is no user with the code %d.\n", AKey);
                        }
         			    break;
                case 5:
                        PrintPinakes(HList);
         			    break;
		}
   } while (choice!=6);


        system("PAUSE");
    }

void HashKey(int Key,int *HValue)
{
	*HValue=Key%HMax + 1;
}

void CreateHashList(HashListType *HList)
{
	int index,i;

	HList->Size=0;
	HList->StackPtr=1;


    index=1;
	while (index<=HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }


    index=1;
	while(index < VMax)
	{
		HList->List[index].Link=index+1;
		HList->List[index].Data.byte=0;
		for(i=0;i<=20;i++)
		  HList->List[index].Data.name[i]=' ';
		index=index+1;
	}
	HList->List[index].Link=EndOfList;

	for (index=1;index<=HMax;index++)
	   printf("%d, %d, \n",index,HList->HashTable[index]);

	for (index=1;index<=VMax;index++)
	   printf("%d, %d, \n",index,HList->List[index].Link);
}

boolean FullHashList(HashListType HList)
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,int KeyArg,int *Loc,int *Pred)
{
	int Next;
	Next=HList.SubListPtr;
	int L1, P1;
	*Loc=0;
	*Pred=0;
	while(Next!=EndOfList)
	{
		if (HList.List[Next].RecKey==KeyArg)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}
void SearchHashList(HashListType HList,int KeyArg,int *Loc,int *Pred)
{
	int HVal;
	HashKey(KeyArg,&HVal);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=0;
		*Loc=0;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
{
	int Loc, Pred, New, HVal;

    New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=0;
		Pred=0;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==0)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==0)
			{
			    HashKey(InRec.RecKey,&HVal);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,int DelKey)
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=0)
	{
		if(Pred!=0)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HashKey(DelKey,&HVal);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %d \n",DelKey);
	}
}

void menu(int *choice)
{
    printf("\n");
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Create HashList\n");
    printf("2. Insert new user\n");
    printf("3. Delete a user\n");
    printf("4. Search for a user\n");
    printf("5. Print list of all users\n");
    printf("6. Quit\n");
    printf("\nCHOICE: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>6);
}

void PrintPinakes(HashListType HList)
{
    int i;
	printf("Hash table\n");
    for (i=1;i<=HMax;i++)
	   printf("%d, ",HList.HashTable[i]);
	printf("\n");


	printf("Hash List\n");
    for (i=1;i<=HList.Size;i++)
	   printf("%d) %d, %d\n",i,HList.List[i].RecKey,HList.List[i].Link);
	printf("\n");

	printf("LIBRARY USERS\n");
	for(i=1;i<=HMax;i++)
    {
        if (HList.HashTable[i]!= -1)
        {
	       printf("Synonyms, collision at position: %d\n",i);
	            if (HList.List[HList.HashTable[i]].Data.byte==1)
                    printf("%d: [%d, %s, Postgraduate Student]\n",HList.HashTable[i],HList.List[HList.HashTable[i]].RecKey,HList.List[HList.HashTable[i]].Data.name);
                if (HList.List[HList.HashTable[i]].Data.byte==2)
                    printf("%d: [%d, %s, PhD Student]\n",HList.HashTable[i],HList.List[HList.HashTable[i]].RecKey,HList.List[HList.HashTable[i]].Data.name);
                if (HList.List[HList.HashTable[i]].Data.byte==3)
                    printf("%d: [%d, %s, Professor]\n",HList.HashTable[i],HList.List[HList.HashTable[i]].RecKey,HList.List[HList.HashTable[i]].Data.name);
                if (HList.List[HList.HashTable[i]].Data.byte==4)
                    printf("%d: [%d, %s, External user]\n",HList.HashTable[i],HList.List[HList.HashTable[i]].RecKey,HList.List[HList.HashTable[i]].Data.name);
            while (HList.List[HList.HashTable[i]].Link != -1)
            {
                HList.HashTable[i]=HList.List[HList.HashTable[i]].Link;
                if (HList.List[HList.HashTable[i]].Data.byte==1)
                    printf("%d: [%d, %s, Postgraduate Student]\n",HList.HashTable[i],HList.List[HList.HashTable[i]].RecKey,HList.List[HList.HashTable[i]].Data.name);
                if (HList.List[HList.HashTable[i]].Data.byte==2)
                    printf("%d: [%d, %s, PhD Student]\n",HList.HashTable[i],HList.List[HList.HashTable[i]].RecKey,HList.List[HList.HashTable[i]].Data.name);
                if (HList.List[HList.HashTable[i]].Data.byte==3)
                    printf("%d: [%d, %s, Professor]\n",HList.HashTable[i],HList.List[HList.HashTable[i]].RecKey,HList.List[HList.HashTable[i]].Data.name);
                if (HList.List[HList.HashTable[i]].Data.byte==4)
                    printf("%d: [%d, %s, External user]\n",HList.HashTable[i],HList.List[HList.HashTable[i]].RecKey,HList.List[HList.HashTable[i]].Data.name);
            }
        }
    }
}

