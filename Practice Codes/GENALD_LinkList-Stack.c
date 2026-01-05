#include <stdio.h>

#define MAX 5

typedef struct node{
	int elem[MAX];
	struct node *link;
}*Stack;

void stackInit(Stack *S);
void stackPush(Stack *S, int data);
void stackPop(Stack *S);

int main(){
	Stack S;
	
	stackInit(&S);
	stackPush(&S, 1);
	stackPop(&S);
}

void stackInit(Stack *S){
	S=NULL;
}
void stackPush(Stack *S, int data){
	Stack temp;
	temp=(Stack)malloc(sizeof(struct node));
	if(temp!=NULL){
		temp->elem=data;
		temp->link=*S;
		*S=temp;
	}
}
void stackPop(Stack *S){
	Stack temp;
	if(*S != NULL){
		temp=*S;
		*S=temp->link;#include <stdio.h>

#define MAX 5

typedef struct node{
    int elem;
    struct node *link;
}*Stack;

void stackInit(Stack *S);
void stackPush(Stack *S, int data);
void stackPop(Stack *S);

int main(){
    Stack S;
    
    stackInit(&S);
    stackPush(&S, 1);
    stackPop(&S);
}

void stackInit(Stack *S){
    *S=NULL;
}
void stackPush(Stack *S, int data){
    Stack temp;
    temp=(Stack)malloc(sizeof(struct node));
    if(temp!=NULL){
        temp->elem=data;
        temp->link=*S;
        *S=temp;
    }
}
void stackPop(Stack *S){
    Stack temp;
    if(*S != NULL){
        temp=*S;
        *S=temp->link;
        free(temp);
    }
}
		free(temp);
	}
}
