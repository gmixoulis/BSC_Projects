
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define HMax 10
#define VMax 100
#define EndOfList -1

typedef struct {
    char name[20];
    int byte;
} ListElementType;

typedef struct {
	char RecKey[30];
	char phone[11];
	int type;
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
void PrintPinakes(HashListType HList);
void CreateHashList(HashListType *HList);
void HashKey(char Key[30],int *HValue);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,char KeyArg[30],int *Loc,int *Pred);
void SearchHashList(HashListType HList,char KeyArg[30],int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,char DelKey[30]);
void menu(int *choice);
void Search_HashList_By_Subject(HashListType HList,int code);
int findAverage(char s[30]);
void BuildHashList(HashListType *HList);
void Print_HashList(HashListType HList);
    main()
    {
        HashListType HList;
        ListElm AnItem;
        int choice,code;
        int Loc, Pred;
        char surname[20],AKey[30],ch;

         do
         {
   	        menu(&choice);
            switch(choice)
            {
      	        case 1:do
            {
   	                   BuildHashList(&HList);
   	                   printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');
   	                    break;
                case 2:

                            printf("Enter teacher's name: ");
                            scanf("%s", &AnItem.RecKey);
                            printf("Enter teacher's surname ");
                            scanf("%s", &surname);


                            strcat(AnItem.RecKey," ");
                            strcat(AnItem.RecKey,surname);
                            AddRec(&HList,AnItem);
                            printf("Enter the phone: ");
                            scanf("%d", &AnItem.phone);
                            printf("Enter teacher's code");
                            scanf("%d",AnItem.type);
                            AddRec(&HList, AnItem);
                            break;

                case 3:
                        printf("Enter teacher's name to delete: ");
                            scanf("%s", &AKey);
                            printf("Enter teacher's surname to delete: ");
                            scanf("%s", &surname);

                            strcat(AKey," ");
                            strcat(AKey,surname);
                        DeleteRec(&HList, AKey);
         			    break;
                case 4:
                        printf("Enter teacher's name for search: ");
                            scanf("%s", &AKey);
                            printf("Enter teacher's surname for search: ");
                            scanf("%s", &surname);


                            strcat(AKey," ");
                            strcat(AKey,surname);
                        SearchHashList(HList,AKey,&Loc,&Pred);
                        if ( Loc != 0)
                        {
                            printf("%s ",HList.List[Loc].RecKey);
                            printf("%s",HList.List[Loc].phone);
                            printf("%d",HList.List[Loc].type); }
                       else{
                            printf("There is no user with the code %d.\n", AKey);
                        }
         			    break;
                case 5:
                        printf("Enter code:\n ");
		                scanf("%d",&code);
                         Search_HashList_By_Subject(HList,code);
		        case 6:
                    Print_HashList(HList);
		            break;
		        case 7:
                     PrintPinakes(HList);
         			    break;
		}
   } while (choice!=8);


        system("PAUSE");
    }
void Search_HashList_By_Subject(HashListType HList,int code)
{
    int i,SubIndex;
    for(i=0;i<HMax;i++)
    {
       SubIndex = HList.HashTable[i];
              while ( SubIndex != EndOfList )
              {
                   if(code==HList.List[SubIndex].type)
                   {printf("[%s, %s,%d, %d]",HList.List[SubIndex].RecKey,HList.List[SubIndex].phone,HList.List[SubIndex].type,HList.List[SubIndex].Link);
                   printf(" -> ");
                   SubIndex = HList.List[SubIndex].Link;}
               }
    }



}
void HashKey(char Key[30],int *HValue)
{
	int value, average;

	average=findAverage(Key);
	value=average%HMax+1;
}

void CreateHashList(HashListType *HList)
/* ÀÂÈÙÔıÒ„ﬂ·: ƒÁÏÈÔıÒ„Âﬂ ÏÈ· ‰ÔÏﬁ HList.
   ≈ÈÛÙÒ›ˆÂÈ: ‘ÁÌ ‰ÔÏﬁ HList
*/
{
	int index;
    int i;
	HList->Size=0;
	HList->StackPtr=1;

    /*¡—◊… œ–œ…≈… ‘œÕ –…Õ¡ ¡ HashTable ‘«” ƒœÃ«” HList Ÿ”‘≈  ¡»≈ ”‘œ…◊≈…œ’ ‘œ’
        Õ¡ ≈◊≈… ‘« ‘…Ã« EndOfList (-1)*/
    index=1;
	while (index<=HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }


	while(index < VMax)
	{
		HList->List[index].Link=index+1;
        for(i=0;i<30;i++)
          strcpy(HList->List[index].RecKey," ");
        for(i=0;i<10;i++)
         strcat(HList->List[index].phone," ");
        HList->List[index].type=0;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;
}


boolean FullHashList(HashListType HList)
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,char KeyArg[30],int *Loc,int *Pred)
{
	int Next;
	Next=HList.SubListPtr;
	int L1, P1;
	*Loc=0;
	*Pred=0;
	while(Next!=EndOfList)
	{
		if (strcmp(HList.List[Next].RecKey,KeyArg)==0)
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
void SearchHashList(HashListType HList,char KeyArg[30],int *Loc,int *Pred)
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
void DeleteRec(HashListType *HList,char DelKey[30])
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
    printf("2. Insert new teacher\n");
    printf("3. Delete a teacher\n");
    printf("4. Search for a teacher\n");
    printf("5. Search by subject\n");
    printf("6. EMFANISH DOMHS\n");
    printf("7. EMFANISH PINAKWN\n");
    printf("8. Quit\n");
    printf("\nCHOICE: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>8);
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
	   printf("%s, %d\n",i,HList.List[i].RecKey,HList.List[i].Link);
	printf("\n");
}


void BuildHashList(HashListType *HList)
{
    ListElm AnItem;
    FILE* infile;
    char surname[20];
    CreateHashList(HList);

    printf("Anoigma tou arxeio eisodou I4F6.txt: \n");
    infile = fopen ("I4F6.txt", "w");
    if (infile == NULL)
    printf("Error");
    int  nscan;
    char termch;
    while(TRUE){
        nscan=fscanf(infile,"%9[^,], %20[^,], %10[^,], %d%c",AnItem.RecKey,surname,
                     AnItem.phone,&AnItem.type,&termch);
        if(nscan==EOF) break;
        if(nscan!=5 || termch!='\n'){
            printf("Error");
            break;
        }}
  strcat(AnItem.RecKey," ");
  strcat(AnItem.RecKey,surname);
  AddRec(HList,AnItem);



}
int findAverage(char s[30])
{
    char last,first;
    if (s[0]>='A' ||  s[0]<='Z')
        first=s[0];
    else
        first=s[0]-32;
    if(s[29]>='A' ||  s[29]<='Z')
        last=s[29];
    else
        last=s[29]-32;
    return((first-64)+(last-64))/2;

}
void Print_HashList(HashListType HList)
{
   int i, SubIndex;

     printf("HASHLIST STRUCTURE with SYNONYM CHAINING\n");
     printf("========================================\n");

          printf("PINAKAS DEIKTWN STIS YPO-LISTES SYNWNYMWN EGGRAFWN:\n");
          for (i=1; i<=HMax;i++)
              printf("%d ",HList.HashTable[i]);
          printf("\n");

          printf("OI YPO-LISTES TWN SYNWNYMWN EGGRAFWN:\n");
          for (i=1; i<=HMax;i++)
          {
              SubIndex = HList.HashTable[i];
              while ( SubIndex != EndOfList )
              {
                   printf("[%s, %s,%d, %d]",HList.List[SubIndex].RecKey,HList.List[SubIndex].phone,HList.List[SubIndex].type,HList.List[SubIndex].Link);
                   printf(" -> ");
                   SubIndex = HList.List[SubIndex].Link;
               }
              printf("TELOS % dHS YPO-LISTAS\n", i);
          }

          printf("H STOIBA TWN ELEY8ERWN 8ESEWN THS LISTAS:\n");
          SubIndex = HList.StackPtr;
          while ( SubIndex != EndOfList )
          {
                printf("%d <= ",SubIndex);
                SubIndex = HList.List[SubIndex].Link;
          }
          printf("TELOS\n");

          printf("MEGE8OS THS LISTAS = %d\n", HList.Size);
          printf("========================================\n");
}
