#include <stdio.h>
#include <stdbool.h>
#define MAX 10


typedef struct{
	char name[20];
	int id;	
}Stud;


typedef struct{
	Stud data;
	int next;
}Node;


typedef struct{
	Node node[MAX];
	int avail;
}VHeap;


typedef struct{
	Node front;
	Node rear;
}Queue;



void initHeap(VHeap *h);
void initQueue(Queue *q);
int alloc(VHeap *h);
void dealloc(VHeap *h, int index);
void display(VHeap h);
void enqueue(VHeap *h, Stud student, Queue *q);
void dequeue(VHeap *h, Queue *q);


int main(){
	
	return 0;
}


void initQueue(Queue *q){
	q->front = -1;
	q->rear = -1;
}

void initHeap(VHeap *h){
	int i;
	for(i = MAX - 1; i >= 0; i--){
		h->node[i].next = i - 1;
	}
	
	h->avail = MAX - 1;
}

int alloc(VHeap *h){
	int avail = h->avail;
	h->avail = h->node[avail].next;
	
	return avail;
}

void dealloc(VHeap *h, int index){
	
	if(index >= 0 && index < MAX){
		h->node[index].next = h->avail;
		h->avail = index;
	}
}


void enqueue(VHeap *h, Stud student, Queue *q){
	int avail = alloc(h);
	
	if(avail != -1){
		h->node[avail].data = student;
		h->node[avail].next = -1;
		if(q->rear == -1){
			q->front = avail;
		}
		else{
			q->rear.next = avail;
		}
		q->rear = avail;
	}
}


void dequeue(VHeap *h, Queue *q){
	int temp = q->front;
	
	if(temp != -1){
		q->front = q->front.next;
		
		if(q->front == -1){
			q->rear = -1;
		}	
	}

	dealloc(h, temp);
}



