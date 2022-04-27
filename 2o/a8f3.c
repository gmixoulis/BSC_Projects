/* askhsh 8 fylladio 3 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "QueueADT.h"

 


void TraverseQ(QueueType Queue);
boolean SearchQ(QueueType *Queue, QueueElementType item);



main(){
     int i;
    QueueElementType item;
    QueueType Queue;
    CreateQ( &Queue);
    
    for( i=3; i<=100; i=i+3){
        AddQ( &Queue , i);
    }
    
    TraverseQ( Queue);
    
    printf("Give the search value:");
    scanf( "%d", &item);
    
    if( SearchQ(&Queue, item)){
       printf("FOUND");
       TraverseQ( Queue);
    }
    else 
       printf("NOT FOUND THE ITEM\n");
    
system("pause");
    
}

void TraverseQ(QueueType Queue) {
	int current;
	current = Queue.Front;
	while (current != Queue.Rear) {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}

boolean SearchQ(QueueType *Queue, QueueElementType item){
    
    int i;
    QueueElementType itembox;
    for(i=0;i<=100;i++){
    
       RemoveQ( &Queue , &itembox);
       if( itembox == item)
            return itembox == item;
    }
}
         
