#include <stdio.h>
#include <stdlib.h>

typedef struct  node{
    struct node *prev;
    char elem;
    struct node *next;
}*Queue;

void initQueue(Queue *Q){
    *Q=NULL;
}

int isEmpty(Queue *Q){
    return (*Q==NULL) ? 1 : 0;
}

void enQueue(Queue *Q, char X){
    Queue temp;
    
    temp=(Queue)malloc(sizeof(struct node));
    if(temp!=NULL){
        if(*Q==NULL){
            temp->elem=X;
            temp->next=temp;
            temp->prev=temp;
            *Q=temp;
            return;
        } 
        temp->elem=X;
        temp->prev=(*Q)->prev;
        (*Q)->prev->next=temp;
        temp->next=*Q;
        (*Q)->prev=temp;
        *Q=temp;
    }
    
    return;
}

void deQueue(Queue *Q){
    Queue temp;
    
    if(Q!=NULL){
        temp=(*Q)->prev;
        (*Q)->prev->prev->next=*Q;
        (*Q)->prev=(*Q)->prev->prev;
        free(temp);
    }
}

void display(Queue *Q){
    Queue tempQ=NULL, temp;
    
    while(*Q!=tempQ){
        printf("\n%c",(*Q)->prev->elem);
        
        temp=(*Q)->prev;
        (*Q)->prev->prev->next=*Q;
        (*Q)->prev=(*Q)->prev->prev;
        
        if(tempQ==NULL){
            temp->next=temp;
            temp->prev=temp;
            tempQ=temp;
        }else{
            temp->prev=tempQ->prev;
            tempQ->prev->next=temp;
            temp->next=tempQ;
            tempQ->prev=temp;
            tempQ=temp;
        }
    }
    *Q=NULL;
    while(*Q!=tempQ){
        temp=tempQ->prev;
        tempQ->prev->prev->next=tempQ;
        tempQ->prev=tempQ->prev->prev;
        
        if(*Q==NULL){
            temp->next=temp;
            temp->prev=temp;
            *Q=temp;
        }else{
            temp->prev=(*Q)->prev;
            (*Q)->prev->next=temp;
            temp->next=*Q;
            (*Q)->prev=temp;
            *Q=temp;
        }
    }
    
}

int main(){
    Queue Q;
    
    initQueue(&Q);
    enQueue(&Q, 'A');
    enQueue(&Q, 'B');
    enQueue(&Q, 'C');
    enQueue(&Q, 'D');
    enQueue(&Q, 'E');
    deQueue(&Q);
    display(&Q);
    
    return 0;
}
