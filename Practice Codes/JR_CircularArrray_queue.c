#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10


typedef struct{
	int data[MAX];
	int front;
	int rear;
}Queue;



void initialize(Queue *q){
	q->front = 0;
	q->rear = MAX - 1;
}

bool isFull(Queue q){
	return (q.rear + 2)%MAX == q.front;
}

bool isEmpty(Queue q){
	return (q.rear + 1)%MAX == q.front;
}

int front(Queue q){
	return q.data[q.front];
}

void enQueue(Queue *q, int elem){
	
	if(!isFull(*q)){
		q->rear = (q->rear + 1) % MAX;
		q->data[q->rear] = elem;
	}
}


void deQueue(Queue *q){
	
	if(!isEmpty(*q)){
		q->front = (q->front + 1) % MAX;
	}
}


void display(Queue q){
	
	while(!isEmpty(q)){
		printf("%d, ", q.data[q.front]);
		q.front = (q.front + 1) % MAX;
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
