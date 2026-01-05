#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10
typedef struct {
    int *elemPtr;
    int count;
    int max;
}List;

List initialize(List L){
    L.elemPtr = (int*)malloc(LENGTH * sizeof(int));
    L.max = LENGTH;
    L.count = 0;
    return L;
}

List resize(List L){
    L.max = L.max * 2;
    L.elemPtr = (int*)realloc(L.elemPtr, L.max * sizeof(int));
    return L;
}

List insertPos(List L, int data, int position){
    if (position < 0 || position > L.count){
        printf("Invalid position!\n");
        return L;
    }
    if (L.count == L.max){
        L = resize(L);
    }
    for (int i = L.count; i > position; i--){
        L.elemPtr[i] = L.elemPtr[i-1];
    }
    L.elemPtr[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position){
    if (position < 0 || position >= L.count){
        printf("Invalid position!\n");
        return L;
    }
    for (int i = position; i < L.count - 1; i++){
        L.elemPtr[i] = L.elemPtr[i+1];
    }
    L.count--;
    return L;
}

int locate(List L, int data){
    for (int i = 0; i < L.count; i++){
        if (L.elemPtr[i] == data){
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data){
    if (L.count == L.max){
        L = resize(L);
    }

    int pos = 0;
    while (pos < L.count && L.elemPtr[pos] < data){
        pos++;
    }

    for(int i = L.count; i > pos; i--){
        L.elemPtr[i] = L.elemPtr[i-1];
    }

    L.elemPtr[pos] = data;
    L.count++;
    return L;
}

void display(List L){
    printf("elem: [");
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elemPtr[i]);
    }
    printf("]\n");
    printf("count: %d\n", L.count);
    printf("max: %d\n\n", L.max);
}





int main()
{
    List L;
    L = initialize(L);

    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 2, 2);
    L = insertPos(L, 5, 3);
    printf("Before: \n");
    display(L);

    L = insertPos(L, 4, 2);

    printf("After insertPos(L, 4, 2): \n");
    display(L);

    L = deletePos(L, 1);

    printf("After deletePos(L, 1): \n");
    display(L);

    printf("Locate 5: %d\n\n", locate(L, 5));

    List S;
    S = initialize(S);
    S = insertPos(S, 1, 0);
    S = insertPos(S, 3, 1);
    S = insertPos(S, 5, 2);
    S = insertPos(S, 10, 3);

    printf("Sorted Before:\n");
    display(S);

    S = insertSorted(S, 8);

    printf("Sorted After insertSorted(S, 8):\n");
    display(S);


    return 0;
}

//DONE3