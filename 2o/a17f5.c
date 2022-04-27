/* askhsh 17 fylladio 5 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef char BinTreeElementType[10];        /*ΤΥΠΟΣ ΔΕΔΟΜΕΝΩΝ ΠΟΥ ΑΠΟΘΗΚΕΥΟΝΤΑΙ ΣΤΟΥς
                                            ΚΟΜΒΟΥΣ ΤΟΥ ΔΕΝΔΡΟΥ Huffman */
typedef struct BinTreeNode *BinTreePointer;
struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;


void AddToTree(char ch[], char code[], int codelen, BinTreePointer *Root);
void BuildDecodingTree(BinTreePointer *Root,   FILE  *CodeFile);
void Decode(BinTreePointer Root, FILE* MessageFile);
void PrintTree(FILE *t, BinTreePointer Root, int indent);

main()
{   
    FILE *x1;
    FILE *x2;
    BinTreePointer dentro;
    
    x1=fopen("codesRW.TXT","r");
    x2=fopen("program.TXT","r");
    
    if(x1 == NULL)
        printf("Can't open CODES.TXT\n");
    else
    {   
        BuildDecodingTree(&dentro,x1);
        if(x2 == NULL)
            printf("Can't open MESSAGES.TXT\n");
       else
          Decode(dentro, x2);
    }
    
    
    

    system("PAUSE");
}

void AddToTree(char ch[], char code[], int codelen, BinTreePointer *Root)
/* ΔΕΧΕΤΑΙ: ΕΝΑ ΧΑΡΑΚΤΗΡΑ ch, ΕΝΑ string code, ΕΝΑ ΑΚΕΡΑΙΟ codelen (ΜΗΚΟΣ ΤΟΥ
            string code) ΚΑΙ ΤΟ ΔΕΙΚΤΗ Root ΠΟΥ ΔΕΙΧΝΕΙ ΤΗ ΡΙΖΑ ΤΟΥ ΔΕΝΔΡΟΥ Huffman
  ΛΕΙΤΟΥΡΓΙΑ: ΔΗΜΙΟΥΡΓΕΙ ΕΝΑΝ ΚΟΜΒΟ ΜΕ ΠΕΡΙΕΧΟΜΕΝΟ ΤΟ ΧΑΡΑΚΤΗΡΑ ch
                ΤΟΥ ΟΠΟΙΟΥ Ο ΚΩΔΙΚΟΣ ΕΙΝΑΙ code ΜΗΚΟΥΣ codelen ΚΑΙ ΤΟΝ
                ΠΡΟΣΘΕΤΕΙ ΣΤΟ ΔΕΝΔΡΟ Huffman
  ΕΠΙΣΤΡΕΦΕΙ: ΤΟ ΤΡΟΠΟΠΟΙΗΜΕΝΟ ΔΕΝΔΡΟ Huffman, ΠΟΥ ΔΕΙΚΤΟΔΟΤΕΙΤΑΙ ΑΠΟ ΤΟ ΔΕΙΚΤΗ Root
*/
{
  int i;
  BinTreePointer TempPtr,p;
  i =0;
  p =*Root;
  while (i<codelen)

    if (code[i]=='0')
    {
        if (p->LChild==NULL)
        {
            TempPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
            strcpy(TempPtr->Data,"*");
            TempPtr->LChild=NULL;
            TempPtr->RChild=NULL;
            p->LChild=TempPtr;
        }
        i=i+1;
        p=p->LChild;
    }
    else
      if (code[i]=='1')
      {
          if (p->RChild==NULL)
          {
              TempPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
              strcpy(TempPtr->Data,"*");
              TempPtr->LChild=NULL;
              TempPtr->RChild=NULL;
              p->RChild=TempPtr;
          }
          i=i+1;
          p=p->RChild;
      }
      strcpy(p->Data,ch);
     
}


void BuildDecodingTree(BinTreePointer *Root, FILE  *CodeFile)
/* ΔΕΧΕΤΑΙ:    ΤΟ ΑΡΧΕΙΟ CodeFile
   ΛΕΙΤΟΥΡΓΘΑ: ΔΙΑΒΑΖΕΙ ΤΟΥΣ ΧΑΡΑΚΤΗΡΕΣ ΚΑΙ ΤΟΥΣ ΚΩΔΙΚΟΥΣ ΤΟΥΣ ΑΠΟ ΤΟ ΑΡΧΕΙΟ
                CodeFile ΚΑΙ ΚΑΤΑΣΚΕΥΑΖΕΙ ΤΟ ΔΕΝΔΡΟ Huffman.
   ΕΠΙΣΤΡΕΦΕΙ: ΤΟ ΔΕΙΚΤΗ Root ΠΟΥ ΔΕΙΧΝΕΙ ΣΤΗ ΡΙΖΑ ΤΟΥ ΔΕΝΔΡΟΥ Huffman.
*/
{
  char  ch[10],termch;
  char code[3];
    int nscan;


    (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
    strcpy((*Root)->Data,"*");
    //(*Root)->Data='*';
    (*Root)->LChild=NULL;
    (*Root)->RChild=NULL;
            while (TRUE)
            {
                nscan = fscanf(CodeFile, "%s[^\n]%c",&ch ,&termch);
    
                
                nscan = fscanf(CodeFile, "%4s[^\n]%c",&code ,&termch);
                if (nscan == EOF) break;
                if (nscan != 1 )
                {
                    printf("Improper file format\n");
                    break;
                }
                else
                    AddToTree(ch, code, strlen(code), &(*Root));
            }
            
            
}

void Decode(BinTreePointer Root, FILE* MessageFile)
/* Δέχεται: Ένα δέντρο Huffman και μια ακολουθία από bits που αναπαριστά ένα μήνυμα,
            το οποίο έχει κωδικοποηθεί με χρήση του δέντρου Huffman.
  Λειτουργία:  Αποκωδικοποιεί το μήνυμα.
  Επιστρέφει: Το αποκωδικοποιημένο μήνυμα.*)
*/
{
  char bit;
  BinTreePointer p;


        while (TRUE)
        {
            p=Root;
            while (p->LChild!=NULL || p->RChild!=NULL)
            {
                bit=fgetc(MessageFile);
                if (bit != EOF)
                {
                    printf("%c",bit);
                    if (bit=='0')
                        p=p->LChild;
                    else
                        if (bit=='1')
                            p=p->RChild;
                        else
                            if (bit!='\n')
                                printf("MH APODEKTO bit: \n", bit);
                }
                else break;
            }
             if (bit != EOF) printf("---%s\n",p->Data);
             else break;
        }
}

void PrintTree(FILE *t, BinTreePointer Root, int indent)
/* ΣΧΕΔΙΑΖΕΙ ΣΤΟ ΑΡΧΕΙΟ HUFF.TXT ΤΟ ΔΕΝΔΡΟ Huffman
*/
{
  int i;
  if (Root!=NULL)
  {
      PrintTree(t, Root->RChild, indent+8);
      for (i=1;i<=indent;i++) fprintf(t," ");
      fprintf(t,"%c\n", Root->Data);
      PrintTree(t, Root->LChild, indent+8);
  }
}

