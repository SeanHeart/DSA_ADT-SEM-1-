#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct node{
    int num;
    int *next;
}*LL;

void push(LL *T, int num){
    LL temp=(LL*)malloc(sizeof(struct node));
    temp->num=num;
    temp->next=*T;
    *T=temp;
}

void pop(LL *T){
    LL trav=(*T)->next;
    
    free(*T);
    *T=trav;
}

int top(LL T){
    return (T!=NULL)?T->num:0;
}

int main(){
    LL *Top=NULL;
    int skibidi;
    
    push(&Top, 1);
    push(&Top, 12);
    
    pop(&Top);
    
    skibidi=top(Top);
    
    printf("%d", skibidi);
}
