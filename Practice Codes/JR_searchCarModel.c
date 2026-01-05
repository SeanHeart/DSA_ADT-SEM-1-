#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef enum{
	ASIAN, EU_US
}makeType;


typedef enum{
	FALSE, TRUE
}Boolean;


typedef struct{
	char brand[20];
	char model[20];	
	int year;
	makeType carMake;
}CarType;


typedef struct{
	CarType cars[MAX];
	int top;
}Stack;

typedef struct{
	CarType cars[MAX];
	int front;
	int rear;
}Queue;


typedef struct{
	Stack S;
	Queue Q;
}ComboSQ;


Boolean isFullStack(Stack S){
	return S.top >= MAX-1 ? TRUE : FALSE; 
}

Boolean isEmptyStack(Stack S){
	return S.top < 0 ? TRUE : FALSE; 
}

void initStack(Stack *S){
	S->top = -1;
}

void push(CarType c, Stack *S){
	if(!isFullStack(*S)){
		S->cars[++S->top] = c;
	}
}

CarType pop(Stack *S){
	CarType temp;
	
	if(!isEmptyStack(*S)){
		temp = S->cars[S->top--];
	}
	else{
		temp.year = -1;
	}
	return temp;
}



Boolean isFullQueue(Queue Q){
	return (Q.rear + 2)%MAX == Q.front ? TRUE : FALSE; 
}

Boolean isEmptyQueue(Queue Q){
	return (Q.rear + 1)%MAX == Q.front ? TRUE : FALSE; 
}

void initQueue(Queue *Q){
	Q->front = 1;
	Q->rear = 0;
}

void enqueue(CarType c, Queue *Q){
	if(!isFullQueue(*Q)){
		Q->rear = (Q->rear+1)%MAX;
		Q->cars[Q->rear] = c;
	}
}

CarType dequeue(Queue *Q){
	CarType temp;
	if(!isEmptyQueue(*Q)){
		temp = Q->cars[Q->front];
		Q->front = (Q->front+1)%MAX;
	}
	else{
		temp.year = -1;	
	}
	return temp;
}

void displayStack(Stack S){
	CarType temp;
	
	printf("\n\nContents of the Stack.\n");
	while(!isEmptyStack(S)){
		temp = pop(&S);
		printf("[%s]", temp.model);
	}

}
void displayQueue(Queue Q){
	CarType temp;
	
	printf("\n\nContents of the Queue.\n");
	while(!isEmptyQueue(Q)){
		temp = dequeue(&Q);
		printf("[%s]", temp.model);
	}

}
void populateStack(Stack *S){
	int x, count = 7;
	CarType cars[] = {
        {"Mercedes", "E-Class", 2023, EU_US},
        {"Hyundai", "Sonata", 2021, EU_US},
        {"Audi", "A4", 2022, EU_US},
        {"Lexus", "RX", 2019, ASIAN},
        {"Volkswagen", "Golf", 2020, EU_US},
        {"Subaru", "Outback", 2021, ASIAN},
        {"Ford", "F-150", 2022, EU_US}
    };
    
    for(x = 0; x<count; x++){
    	push(cars[x], S);
	}
}

void populateQueue(Queue *Q){
	int x, count = 6;
	CarType cars[] = {
        {"Toyota", "Camry", 2020, ASIAN},
        {"Honda", "Accord", 2019, ASIAN},
        {"Ford", "Sonata", 2022, EU_US},
        {"BMW", "X5", 2021, EU_US},
        {"Nissan", "Altima", 2020, ASIAN},
        {"Chevrolet", "Camaro", 2018, EU_US}
    };
    
    for(x = 0; x<count; x++){
    	enqueue(cars[x], Q);
	}
}


Boolean searchCarModel(CarType car, ComboSQ *SQ){
	Stack tempStack;
	Queue tempQueue;
	CarType temp;
	initStack(&tempStack);
	initQueue(&tempQueue);
	Boolean retval = FALSE;
	
	
	while(!isEmptyStack(SQ->S)){
		temp = pop(&(SQ->S));
		push(temp, &tempStack);
		if(strcmp(temp.model, car.model) == 0 && temp.carMake == 0){
			retval = TRUE;
		}
	}
	
	if(retval != TRUE){
		while(!isEmptyQueue(SQ->Q)){
			temp = dequeue(&(SQ->Q));
			enqueue(temp, &tempQueue);
			if(strcmp(temp.model, car.model) == 0){
				retval = TRUE;
			}
		}
	}
	
	while(!isEmptyQueue(tempQueue)){
		temp = dequeue(&tempQueue);
		enqueue(temp, &(SQ->Q));
		}
		
	while(!isEmptyStack(tempStack)){
		temp = pop(&tempStack);
		push(temp, &(SQ->S));
	}
	
	return retval;
}

int main(){
	Boolean result;
	ComboSQ SQ;
	initStack(&SQ.S);
	initQueue(&SQ.Q);
	populateStack(&SQ.S);
	populateQueue(&SQ.Q);
	displayStack(SQ.S);
	displayQueue(SQ.Q);
	
	CarType car = {"Mercedes", "Sonata", 2023, EU_US};
	
	result = searchCarModel(car, &SQ);
	printf("\n\n\nAfter seachCarModel.\n\n");
	
	if (result == TRUE) {
        printf("Result is true\n");
    } else {
        printf("Result is false\n");
    }
    
	displayStack(SQ.S);
	displayQueue(SQ.Q);
	return 0;
}
