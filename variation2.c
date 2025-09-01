#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}Etype, *EPtr;

void initialize(EPtr L){
    L->count = 0;
}

void insertPos(EPtr L, int data, int position){
    if(position<0 || position>L->count){
        printf("Error: Invalid position!");
    }

    //shift elements to the right
    for(int i=L->count; i>=position; i--){
        L->elem[i] = L->elem[i-1];
    }

    //insert new element
    L->elem[position] = data;
    L->count++;
}

void deletePos(EPtr L, int position){
    for(int i = position; i<=L->count-1; i++){
        L->elem[i] = L->elem[i+1];
    }

    L->count--;
}

int locate(EPtr L, int data){
    for(int i=0; i<L->count; i++){
        if(L->elem[i] == data){
            return i;
        }
    }

    return -1;
}


void display(EPtr L){
    printf("elem: ");
    for(int i=0; i<L->count; i++){
        printf("%d ", L->elem[i]);
    }
    printf("\ncount: %d\n", L->count);
}

int main()
{
    Etype myList;
    EPtr L = &myList;

    initialize(L);
    printf("count is %d", L->count);

    printf("\nBefore: \n");
    insertPos(L, 1, 0);
    insertPos(L, 3, 1);
    insertPos(L, 2, 2);
    insertPos(L, 5, 3);
    display(L);

    printf("\n");

    printf("After: \n");
    insertPos(L, 4, 2);
    display(L);

    printf("\n");

    printf("Deleted\n");
    deletePos(L, 1);
    display(L);

    printf("\n");

    printf("Locate\n");
    printf("Search for the position of 5\n");
    printf("%d\n", locate(L, 5));


    return 0;
}