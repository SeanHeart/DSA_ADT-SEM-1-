#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct{
    Node *head;
    int count;
}List;

List* initialize(){
    List* newNode = (List*)malloc(sizeof(List));
    if(newNode == NULL){
        // printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->head = NULL;
    newNode->count = 0;

    return newNode;
}

void empty(List *list){
    Node *current = list->head;
    Node *temp;

    while(current != NULL){
        temp = current;
        current = current->next;
        free(temp);
    }

    //reset the list
    list->head = NULL;
    list->count = 0;
}

void insertFirst(List *list, int data){
    //allocate memory
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }

    //set the data
    newNode->data = data;
    newNode->next = list->head;     //set the pointer of newNode to current head of list
    list->head = newNode;           //update the list's head pointer to point to the newNode
    list->count++;
}

void insertLast(List *list, int data){
    //allocate memory for a newNode
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }

    //set the data
    newNode->data = data;
    newNode->next = NULL;

    if(list->head == NULL){
        printf("list is empty");
        list->head = newNode;
    }else{
        Node *current = list->head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
    list->count++;

    //traverse the list until current->next is NULL
    
}

void display(List *list){
    Node *current;

    current = list->head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
    printf("count: %d", list->count);

}

int main(){
    
    List *L;

    L = initialize();

    printf("INSERT FIRST:\n");
    printf("Before:");
    insertFirst(L, 5);
    insertFirst(L, 6);
    insertFirst(L, 2);
    display(L);

    insertFirst(L, 7);

    printf("\nAfter:");
    display(L);

    printf("\n");

    printf("\nEMPTY THE LIST:\n");
    printf("After:");
    empty(L);
    display(L);

    printf("\n");
    printf("\nINSERT LAST:\n");
    printf("Before: ");
    insertFirst(L, 5);
    insertFirst(L, 6);
    insertFirst(L, 2);
    display(L);

    insertLast(L, 7);

    printf("\nAfter: ");
    display(L);


    return 0;
}
