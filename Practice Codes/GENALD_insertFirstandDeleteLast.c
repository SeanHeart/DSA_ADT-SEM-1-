#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define sentinel 999

typedef struct node{
    int data;
    struct node *link;
}*LL;

void init(LL *L){
    *L=NULL;
}

void insertfirst(LL *L, int X){
    LL temp;
    
    temp=(LL *)malloc(sizeof(struct node));
    if(temp!=NULL){
        temp->data=X;
        temp->link=*L;
        *L=temp;
    }
}

void del(LL *L){
    LL *trav, temp;
    
    for(trav=L;(*trav)->link!=NULL;trav=&(*trav)->link){
        printf("!");
    }
    temp=*trav;
    *trav=temp->link;
    free(temp);
}

int main(){
    LL *head;
    int i, arr[]={1,2,3,4,5};
    init(&head);
    
    for(i=0;i<MAX;i++){
        insertfirst(&head, arr[i]);
    }
    
    for(i=0;i<MAX;i++){
        del(&head);
    }
}
