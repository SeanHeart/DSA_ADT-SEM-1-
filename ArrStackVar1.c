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

// int pop(Stack* s){
//     //check if stack is empty
//     if(isEmpty(s)){
//         printf("Stack is empty!");
//     }else{
//         printf("Stack has elements.\n");
//     }

//     //get the value at the current top of the stack
//     // for(int i=MAX)
// }


void display(Stack* s){
    if(isEmpty(s)){
        printf("is empty");
    }

    for(int i=s->top; i>=0; i--){
        if(i == s->top){
            printf("[%d] :%d <- top\n", i, s->items[i]);
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

    // //check if full
    // if(isFull(S)){
    //     printf("Stack is full!\n");
    // }else{
    //     printf("Stack is not full.\n");
    // }

    // //check if empty
    // if(isEmpty(S)){
    //     printf("Stack is empty!\n");
    // }else{
    //     printf("Stack has elements.\n");
    // }

    //PUSH
    push(S, 10);
    push(S, 20);
    push(S, 30);

    display(S);

    free(S);    //clean up memory

    return 0;
}
//Humm