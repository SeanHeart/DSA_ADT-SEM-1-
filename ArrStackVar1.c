#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int top;
}Stack; 

Stack S;

Stack* initialize(){
    //allocate memory for one Stack struct
    Stack* s = (Stack*)malloc(sizeof(Stack));

    if(s == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }

    s->top = -1;    //empty stack
    return s;       //return pointer to the newly created stack

}

bool isFull(Stack* s){
    return s->top == MAX-1;
}

bool isEmpty(Stack* s){
    return s->top == -1;
}

void push(Stack* s, int value){
    if(isFull(s)){
        printf("Error: Stack overflow!\n");
        return; //do nothing if full
    }

    //push condition
    s->top++;                   //move top up
    s->items[s->top] = value;   //store value at new top
}


int pop(Stack* s){
    if(isEmpty(s)){
        printf("Error: Stack underflow!\n");
        return -1; //return -1 if empty
    }

    int value = s->items[s->top]; //get the top value
    s->top--;                     //move top down
    return value;                 //return the popped value
}

int peek(Stack* s){
    if(isEmpty(s)){
        printf("Error: Stack is empty!\n");
        return -1; //return -1 if empty
    }

    return s->items[s->top]; //return the top value without removing it
}

int top(Stack* s){
    return s->top;
}


void display(Stack* s){
    if(isEmpty(s)){
        printf("is empty");
    }

    for(int i=s->top; i>=0; i--){
        if(i == s->top){
            printf("[%d] : %d <- top\n", i, s->items[i]);
        }else{
            printf("[%d] : %d\n", i, s->items[i]);
        }
    }
}




int main()
{
    Stack* S = initialize();

    //initialize()
    printf("STACK INITALIZATION\nTop = %d\n", S->top);

    //PUSH
    push(S, 1);
    push(S, 3);
    push(S, 2);
    push(S, 5);

    display(S);

    printf("\nPEEK: %d\n", peek(S));
    printf("POP: %d\n", pop(S));

    printf("\nAfter POP:\n");
    display(S);

    printf("\nCurrent top index: %d\n", top(S));

    free(S);    //clean up memory

    return 0;
}
//DONE6