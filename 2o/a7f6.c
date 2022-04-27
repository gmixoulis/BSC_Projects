/* askhsh 7 fylladio 6 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define HMax 11              /*     �� ������� ��� ������ HashTable
                                ���������� ��� �� 5 */
#define VMax 100             /*�� ������� ��� ������,
                                ���������� ��� �� 30 */
#define EndOfList -1        /* ������ ��� ����������� �� ����� ��� ������
                                ��� ��� ���� ��������� ��������� */

  

typedef struct {
	int RecKey;
	int poso;
	char onoma[20];
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax+1];   // ������� ������� ���� ��� ��������� ���������
    int Size;                // ������ �������� ��� ������ List
	int SubListPtr;          // D������� �� ��� �������� ���������
    int StackPtr;           // ������� ���� ��� ����� �������� ���� ��� ������ List
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
void menuprint();
void printHashlistdata(HashListType HList,int Key);

main(){
    
    ListElm stoixio;
    HashListType hash;
    char cont[0];
    int i,key,loc,pred,keydelete,eyrw;
    
    
    do{
        menuprint();
        printf("Choose what you want:");
        i=GetInteger();
        
        
        switch(i){

            case 1:
                CreateHashList(&hash);
                break;
            case 2:
                do{ printf("Name Surname:\n");
                    gets(stoixio.onoma);
                    
                    printf("Code:\n");
                    stoixio.RecKey=GetInteger();
                    
                    printf("Debt:\n");
                    stoixio.poso=GetInteger();
                    
                    AddRec(&hash,stoixio);   
                    printf("Continue?(Yes or No):");
                    gets(cont);
                    
                }while(cont[0]=='Y' || cont[0]=='y');
                break;
            case 3:
                do{
                    printf("Give the code who want to delete:");
                    keydelete=GetInteger();
                    
                    SearchHashList(hash,keydelete,&loc,&pred);
                    
                    if(loc==0 && pred==0){
                        printf("The user doesn't exist in data base\n");
                    }
                    else{
                        if(hash.List[loc].poso>0){
                            printf("Member must arrange his/her bill first\n");
                        }
                        else{
                            
                            DeleteRec(&hash,keydelete);
                        }
                    }
                    printf("Continue?(Yes or No):");
                    gets(cont);
                    
                }while(cont[0]=='Y' || cont[0]=='y');
                
                break;
            case 4:
                do{
                    printf("Give the code who want to search:");
                    key=GetInteger();
                    
                    SearchHashList(hash,key,&loc,&pred);
                    
                    if(loc==0 && pred==0)
                        printf("There is no member with code x");
                    else{
                        printf("[code:%d,name surname:%s,debt:%d]",hash.List[loc].RecKey,
                        hash.List[loc].onoma,hash.List[loc].poso);
                    }
                    
                    printf("\nContinue?(Yes or No):");
                    gets(cont);
                    
                }while(cont[0]=='Y' || cont[0]=='y');
                break;
            case 5:
                do{
                    printf("Give the code who want to update the debt:");
                    key=GetInteger();
                    printf("Give the new debt:");
                    eyrw=GetInteger();
                    
                    SearchHashList(hash,key,&loc,&pred);
                    
                    hash.List[loc].poso=eyrw;
                    
                    
                    printf("\nContinue?(Yes or No):");
                    gets(cont);
                    
                }while(cont[0]=='Y' || cont[0]=='y');
                break;
            case 6:
                printf("Give the number and i will print the synonyms of it:");
                key=GetInteger();
                
                printHashlistdata( hash , key);
                
                
                
                break;
            case 7:
                break;


        }

    }while(i!=7);
    
 
 
 
    
    
    system("pause");
}

void printHashlistdata(HashListType HList,int Key){
    
    
    int Loc,Pred,Next;
    
    HashKey(Key,&Next);
    
	Next=HList.HashTable[Next];
	Loc=0;
	Pred=0;
	while(Next!=-1)
	{
		if (HList.List[Next].RecKey==Key)
		{
			
		}
		else
		{    
            printf("[code:%d,name surname:%s,debt:%d]\n",HList.List[Next].RecKey,
                        HList.List[Next].onoma,HList.List[Next].poso);
			
            
			
		}
		Next=HList.List[Next].Link;
	}
    
    
    
}

void menuprint(){
    
    
    int i;

    printf("%25s\n","MENU");
    for(i=1; i<=50 ; i++)
       printf("=");
    printf("\n1.%10s","Create HashList");
    printf("\n2.%10s","Insert new member");
    printf("\n3.%10s","Delete a member");
    printf("\n4.%10s","Search for a number");
    printf("\n5.%10s","Update member's account");
    printf("\n6.%10s","Print list of synonyms");
    printf("\n7.%-10s\n","Quit");
    
    
}

void HashKey(int Key,int *HValue)
/* �������:    ��� ���� Key ���� ��������.
   ����������: ������� ��� ���� ��������������� HValue ��� �� ������ Key.
   ����������: ��� ���� ��������������� HValue
*/
{
	*HValue=(Key%HMax) + 1;
}

void CreateHashList(HashListType *HList)
/* ����������: ���������� ��� ���� HList.
   ����������: ��� ���� HList
*/
{
	int index;

	HList->Size=0;           //���������� ��� ���� �����
	HList->StackPtr=1;       //������� ��� ������ ��� ������� ��� ��������� ������

    /*����������� ��� ������ HashTable ��� ����� HList ���� ���� ��������� ���
        �� ���� �� ���� EndOfList (-1)*/
    index=1;
	while (index<=HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

     //���������� ��� ������� ��� ��������� ������ ��� ����� HList
    index=1;
	while(index < VMax)
	{
		HList->List[index].Link=index+1;
		HList->List[index].poso=0;
		strcpy(HList->List[index].onoma,"-");
		index=index+1;
	}
	HList->List[index].Link=EndOfList;

	//for (index=1;index<=HMax;index++)
	  // printf("%d, %d, \n",index,HList->HashTable[index]);

	//for (index=1;index<=VMax;index++)
	  // printf("%d, %d, \n",index,HList->List[index].Link);
}

boolean FullHashList(HashListType HList)
/* �������:    ��� ���� HList.
   ����������: ������� �� � ����� List ��� ����� HList ����� ������.
   ����������: TRUE �� � ����� List ����� ������, FALSE �����������.
*/
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,int KeyArg,int *Loc,int *Pred)
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ���� �������� ���������.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ��� ������������
                �������� ���� ��������
*/
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
/* �������:     ��� ���� HList ��� ��� ���� �������� KeyArg.
    ����������: ������� ��� ������� �� ������ KeyArg ��� ���� HList.
    ����������: �� ���� Loc ��� �������� ��� �� ���� Pred ���
                ������������ �������� ��� ��������� ���� ����� ������.
                �� ��� ������� ������� �� ������ KeyArg ���� Loc=Pred=0
*/
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
/* �������:    ��� ���� HList ��� ��� ������� InRec.
   ����������: ������� ��� ������� InRec ��� ����� List, �� ��� ����� ������,
                ��� ���������� �� ���� HList.
   ����������: ��� ������������� ���� HList.
   ������:     ������ ������� ������, �� � List ����� ������, �����������,
                �� ������� ��� ������� �� �� ���� ������,
                �������� ����������� ���������
*/
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
/* DEXETAI:    TH DOMH (HList) KAI To KLEIDI (DelKey) THS EGGRAFHS
               POY PROKEITAI NA DIAGRAFEI
   LEITOYRGIA: DIAGRAFEI, THN EGGRAFH ME KLEIDI (DelKey) APO TH
               LISTA (List), AN YPARXEI ENHMERWNEI THN DOMH HList
   EPISTREFEI: THN TROPOPOIHMENH DOMH (HList)
   EJODOS:     "DEN YPARXEI EGGRAFH ME KLEIDI" MHNYMA
*/
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

