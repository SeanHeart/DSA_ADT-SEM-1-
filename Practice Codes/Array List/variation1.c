//ARRAY LIST- V1

#include <stdio.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}List;

List initialize(List L){
    L.count = 0;
    return L;
}
List insertPos(List L, int data, int position){
    //Check if position is valid
    if(position < 0 || position > L.count){
        printf("Error: Invalid position!\n");
        return L;
    }

    if(L.count == MAX){
        printf("Error: List is full!\n");
        return L;
    }

    //shift elements to the right
    for(int i = L.count; i >= position; i--){
        L.elem[i] = L.elem[i-1];
    }

    //insert new element
    L.elem[position] = data;
    L.count++;

    return L;
}

List deletePos(List L, int position){
    //Check if position is valid
    if(position < 0 || position >= L.count){
        printf("Error: Invalid position!\n");
        return L;
    }

    //shift elements to the left (i think)
    for(int i = position; i < L.count-1; i++){
        L.elem[i] = L.elem[i+1];
    }

    L.count--;
    return L;
}

int locate(List L, int data){
    for(int i=0; i<L.count; i++){
        if(L.elem[i] == data){
            return i;
        }
    }

    return -1;
}

List insertSorted(List L, int data){
    //count should not be equal to length
    if(L.count == MAX){
        printf("Array is full!\n");
        return L;
    }

    int position = 0;

    //find the pos as to where the data should go
    while(position < L.count && L.elem[position] < data){
        position++;
    }

    //shift elements to the right
    for(int i=L.count; i>position; i--){
        L.elem[i] = L.elem[i-1];
    }

    //insert new element
    L.elem[position] = data;
    L.count++;
    
    return L;
}


void display(List L){
    printf("elem: ");
    for(int i=0; i<L.count; i++){
        printf("%d ", L.elem[i]);
    }
    printf("\ncount: %d\n", L.count);
}

int main(){
    List L;
    int i;

    L = initialize(L);

    //original
    printf("\nORIGINAL\n");
    L = insertPos(L, 1, 0);
    L = insertPos(L, 4, 1);
    L = insertPos(L, 5, 2);
    display(L);

    //insertPos
    printf("\nINSERT POSITION\n");
    L = insertPos(L, 45, 1);
    display(L);

    //deletePos
    printf("\ndeleted\n");
    L = deletePos(L, 3);    //5 gets deleted
    display(L);

    //locate
    printf("\nSearch for elem 4: %d\n", locate(L, 4));

    //insertSorted
    printf("\nINSERT SORTED\n");
    L = insertSorted(L, 9);
    display(L);
    

    return 0;
}

//This is better.