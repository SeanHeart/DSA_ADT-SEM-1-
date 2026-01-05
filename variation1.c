#include <stdio.h>

#define MAX 10

typedef struct
{
    int elem[MAX];
    int count;
}List;


List initialize(List L){
    L.count = 0;

    return L;
}

List insertPos(List L, int data, int position){
    if (position < 0 || position > L.count){
        printf("Error: Invalid position!\n");
    }

    //shift elements to the right
    for(int i=L.count; i>=position; i--){
        L.elem[i] = L.elem[i-1];
    }

    //insert new element
    L.elem[position] = data;
    L.count++;

    return L;
}

List deletePos(List L, int position){
    for(int i = position; i<=L.count-1; i++){
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
    }

    int position = 0;
    
    //find the position as to where the data should go
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

    int position, data;


    L = initialize(L);
//    printf("count is %d", L.count);

    printf("\nBefore: \n");
    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 2, 2);
    display(L);

    printf("\n");

    printf("After: \n");
    L = insertPos(L, 100, 0);
    L = insertPos(L, 670, 2);
    display(L);

    printf("\n");

    printf("Deleted\n");
    L = deletePos(L, 0);
    display(L);

    printf("\n");

    printf("Locate\n");
    printf("Search for the postion of 670\n");
    printf("%d\n", locate(L, 670));

    printf("\n");

    printf("Insert Sorted\n");
    printf("Before:\n");
    display(L);
    
    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 5, 2);
    L = insertPos(L, 10, 3);

    L = insertSorted(L, 8);

    printf("After:\n");
    display(L);
    
    
 

    return 0;
}

//DONE