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

void insertPos(List *list, int data, int index){
    if(index < 0 || index > list->count){
        printf("Invalid index!\n");
        return;
    }
    if(index == 0){
        insertFirst(list, data);
        return;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;

    Node *current = list->head;
    for(int i = 0; i < index - 1; i++){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    list->count++;
}

void deleteStart(List *list){
    if(list->head == NULL){
        printf("List is empty!\n");
        return;
    }

    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->count--;
}

void deleteLast(List *list){
    if(list->head == NULL){
        printf("List is empty!\n");
        return;
    }

    if(list->head->next == NULL){
        free(list->head);
        list->head = NULL;
    }else{
        Node *current = list->head;
        while(current->next->next != NULL){
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    list->count--;
}

void deletePos(List *list, int index){
    if(index < 0 || index >= list->count){
        printf("Invalid index!\n");
        return;
    }
    if(index == 0){
        deleteStart(list);
        return;
    }

    Node *current = list->head;
    for(int i = 0; i < index - 1; i++){
        current = current->next;
    }
    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    list->count--;
}

int retrieve(List *list, int index){
    if(index < 0 || index >= list->count){
        printf("Invalid index!\n");
        return -1;
    }

    Node *current = list->head;
    for(int i = 0; i < index; i++){
        current = current->next;
    }
    return current->data;
}

int locate(List *list, int data){
    Node *current = list->head;
    int index = 0;

    while(current != NULL){
        if(current->data == data){
            return index;
        }
        current = current->next;
        index++;
    }

    return -1; 
}

void display(List *list){
    Node *current;

    current = list->head;
    printf("\nhead: ");
    while(current != NULL){
        printf("%d ", current->data);
        if(current->next != NULL){
            printf("-> ");
        }
        current = current->next;
    }

    printf("-> NULL\n");
    printf("count: %d\n\n", list->count);

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

    printf("\n");
    printf("\nINSERT POS:\n");
    empty(L);
    insertLast(L, 2);
    insertLast(L, 6);
    insertLast(L, 5);

    printf("\nBefore:");
    display(L);
    insertPos(L, 7, 2);

    printf("\nAfter: ");
    display(L);

    
    printf("\n");
    printf("\nDELETE START:\n");
    empty(L);
    insertLast(L, 2);
    insertLast(L, 6);
    insertLast(L, 5);
    printf("\nBefore: ");
    display(L);

    deleteStart(L);

    printf("\nAfter: ");
    display(L);



    printf("\n");
    printf("\nDELETE LAST:\n");
    empty(L);
    insertLast(L, 2);
    insertLast(L, 6);
    insertLast(L, 5);
    printf("\nBefore: ");
    display(L);

    deleteLast(L);

    printf("\nAfter: ");
    display(L);


    printf("\n");
    printf("\nDELETE POS:\n");
    empty(L);
    insertLast(L, 2);
    insertLast(L, 6);
    insertLast(L, 5);
    printf("\nBefore: ");
    display(L);

    deletePos(L, 1);

    printf("\nAfter: ");
    display(L);

    printf("Retrieve index 1: %d\n", retrieve(L, 1));
    printf("Locate data 5: %d\n", locate(L, 5));

    empty(L);
    free(L);

    return 0;
}


//DONE5