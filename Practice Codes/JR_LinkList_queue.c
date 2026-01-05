#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node{
	int data;
	struct node *next;
}*List;

typedef struct{
	List Front;
	List Rear;
}Queue;


void initialize(Queue *q){
	q->Front = NULL;
	q->Rear = NULL;
}


bool isEmpty(Queue q){
	return q.Front == NULL;
}


void enQueue(Queue *q, int elem){
	List newNode = (List)malloc(sizeof(struct node));
	if(newNode != NULL){
		newNode->data = elem;
		newNode->next = NULL;
		
		if(isEmpty(*q)){
			q->Front = newNode;
		}
		else{
			q->Rear->next = newNode;
		}
		q->Rear = newNode;
	}
}


void deQueue(Queue *q){
	if(!isEmpty(*q)){
		List temp = q->Front;
		
		q->Front = q->Front->next;
		free(temp);
	}
	else{
		q->Rear = NULL;
	}
}

void display(Queue q){
	List trav = q.Front;
	
	while(trav != NULL){
		printf("%d", trav->data);
		if(trav->next != NULL){
			printf("->");
		}
		trav = trav->next;
	}
	printf("\n\n");
}


int main(){
	
	Queue q;
	initialize(&q);
	enQueue(&q, 1);
	enQueue(&q, 2);
	enQueue(&q, 3);
	display(q);
	deQueue(&q);
	display(q);
return 0;
}
