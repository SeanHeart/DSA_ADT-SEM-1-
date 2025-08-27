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

    printf("Before: \n");
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
 

    return 0;
}