#include <stdio.h>
#include <stdlib.h>


#define StackLimit 20

typedef int StackElementType;

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
void TraverseStack(StackType Stack);
main()
{
    int n,j;
    StackType Stack1, Stack2, Stack3;
    StackElementType i,Item,a,b,c,d,e,g,f,temp;
    j=0;
    CreateStack(&Stack1);
    for(i=0;i<StackLimit;i++)
    {
        Push(&Stack1,i);
    }
    TraverseStack(Stack1);
    printf("Give n <n<=19>\n ");
    scanf("%d",&n);
    Pop(&Stack1,&Item);
    a=Stack1.Top;
    Pop(&Stack1,&Item);
    printf("a->%d\n",a);
    Pop(&Stack1,&Item);
    temp=Item;
    Pop(&Stack1,&Item);
    b=Item;
    Push(&Stack1,b);
    Push(&Stack1,temp);
    printf("b->%d\n",b);
    for(i=0;i<n;i++)
        Pop(&Stack1,&Item);
    c=Item;
    printf("c->%d\n",c);
    CreateStack(&Stack2);
    for(i=0;i<n;i++)
        {Pop(&Stack1,&Item);
        Push(&Stack2,Item);}
    d=Item;
    printf("d->%d\n",d);
    for(i=0;i<n;i++)
        {Pop(&Stack2,&Item);
        Push(&Stack1,Item);}
    while(!EmptyStack(Stack1))
    {
        Pop(&Stack1,&Item);
        Push(&Stack2,Item);
        j++;
    }
    e=Item;
   printf("e->%d\n",e);
   for(i=0;i<j;i++)
    {Pop(&Stack2,&Item);
        Push(&Stack1,Item);}
    j=0;
   for(i=Stack1.Top;i>=Stack1.Element[2];i--)
      {Pop(&Stack1,&Item);
        Push(&Stack2,Item);
        j++;}
   f=Item;
   printf("f->%d\n",f);
   for(i=0;i<Stack2.Top+j;i++)
    {Pop(&Stack2,&Item);
        Push(&Stack1,Item);}
  while(!EmptyStack(Stack1))
  {
      Pop(&Stack1,&Item);
        Push(&Stack2,Item);
  }
  g=Item;
  printf("c->%d\n",g);
}


void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα.*
*/
{
    Stack -> Top = -1;

}

boolean EmptyStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται: Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος: Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:  Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d, ",Stack.Element[i]);
    }
    printf("\n");
}
