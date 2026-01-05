#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

Stack S;  

void initialize(Stack *s){
    s->top = MAX;   // empty stack (starts from end)
}


bool isFull(Stack *s){
    return s->top == 0;
}

bool isEmpty(Stack *s){
    return s->top == MAX;
}


void push(Stack *s, int value){
    if(isFull(s)){
        printf("Error: Stack overflow!\n");
        return;
    }

    s->top--;                  
    s->items[s->top] = value;
}


int pop(Stack *s){
    if(isEmpty(s)){
        printf("Error: Stack underflow!\n");
        return -1;
    }

    int value = s->items[s->top];
    s->top++;     
    return value;
}


int peek(Stack *s){
    if(isEmpty(s)){
        printf("Error: Stack is empty!\n");
        return -1;
    }

    return s->items[s->top];
}


int top(Stack *s){
    return s->top;
}


void display(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return;
    }

    printf("Stack contents:\n");
    for(int i = s->top; i < MAX; i++){
        if(i == s->top){
            printf("[%d] : %d <- top\n", i, s->items[i]);
        } else {
            printf("[%d] : %d\n", i, s->items[i]);
        }
    }
}


int main(){
    initialize(&S);

    printf("STACK INITIALIZATION\n");
    printf("Top = %d\n\n", top(&S));

    push(&S, 10);
    push(&S, 20);
    push(&S, 30);
    push(&S, 40);

    display(&S);

    printf("\nPEEK: %d\n", peek(&S));
    printf("POP: %d\n", pop(&S));

    printf("\nAfter pop:\n");
    display(&S);

    printf("\nCurrent top index: %d\n", top(&S));

    return 0;
}

//DONE7
