#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10
typedef struct {
    int *elemPtr;
    int count;
    int max;
}List;

void initialize(List *L){
    L->elemPtr = (int*)malloc(LENGTH * sizeof(int));
    L->max = LENGTH;
    L->count = 0;
}

void resize(List *L){
    L->max = L->max * 2;
    L->elemPtr = (int*)realloc(L->elemPtr, L->max * sizeof(int));
}

void insertPos(List *L, int data, int position){
    if (position < 0 || position > L->count){
        printf("Invalid position!\n");
        return;
    }
    if (L->count == L->max){
        resize(L);
    }

    for (int i = L->count; i > position; i--){
        L->elemPtr[i] = L->elemPtr[i-1];
    }

    L->elemPtr[position] = data;
    L->count++;
}

void deletePos(List *L, int position){
    if (position < 0 || position >= L->count){
        printf("Invalid position!\n");
        return;
    }

    for (int i = position; i < L->count - 1; i++){
        L->elemPtr[i] = L->elemPtr[i+1];
    }

    L->count--;
}

int locate(List *L, int data){
    for (int i = 0; i < L->count; i++){
        if (L->elemPtr[i] == data){
            return i;
        }
    }
    return -1;
}

int retrieve(List *L, int position){
    if (position < 0 || position >= L->count){
        printf("Invalid position!\n");
        return -1;
    }
    return L->elemPtr[position];
}

void insertSorted(List *L, int data){
    if (L->count == L->max){
        resize(L);
    }

    int pos = 0;
    while (pos < L->count && L->elemPtr[pos] < data){
        pos++;
    }

    for (int i = L->count; i > pos; i--){
        L->elemPtr[i] = L->elemPtr[i-1];
    }

    L->elemPtr[pos] = data;
    L->count++;
}

void display(List *L){
    printf("elem: [");
    for (int i = 0; i < L->count; i++){
        printf("%d ", L->elemPtr[i]);
    }
    printf("]\n");
    printf("count: %d\n", L->count);
    printf("max: %d\n", L->max);
}

void makeNULL(List *L){
    free(L->elemPtr);
    L->elemPtr = NULL;
    L->count = 0;
    L->max = 0;
}



int main()
{
     List L;

    initialize(&L);

    insertPos(&L, 1, 0);
    insertPos(&L, 3, 1);
    insertPos(&L, 2, 2);
    insertPos(&L, 5, 3);
    printf("Before insertPos:\n");
    display(&L);

    insertPos(&L, 4, 2);
    printf("After insertPos(&L, 4, 2):\n");
    display(&L);

    deletePos(&L, 1);
    printf("After deletePos(&L, 1):\n");
    display(&L);

    printf("Locate 5: %d\n\n", locate(&L, 5));

    printf("Retrieve position 2: %d\n\n", retrieve(&L, 2));

    List S;
    initialize(&S);
    insertPos(&S, 1, 0);
    insertPos(&S, 3, 1);
    insertPos(&S, 5, 2);
    insertPos(&S, 10, 3);
    printf("Sorted before:\n");
    display(&S);

    insertSorted(&S, 8);
    printf("Sorted after insertSorted(&S, 8):\n");
    display(&S);

    makeNULL(&L);
    makeNULL(&S);

    return 0;
}

//DONE4