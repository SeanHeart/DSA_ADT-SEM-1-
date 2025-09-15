#include <stdio.h>
#include <stdlib.h>

#define MAX 4

typedef struct{
    int elem;
    int next;
}Cell, HeapSpace[MAX];

typedef struct{
    HeapSpace H;
    int avail;
}VHeap;

typedef int List;


void initialize(VHeap *V){
    for(int i=0; i<MAX-1; i++){
        V->H[i].next = i+1;
    }
    V->H[MAX-1].next = -1;
    V->avail = 0;
}

int allocSpace(VHeap* V){
    int ret = V->avail;
    if(ret != -1){
        V->avail = V->H[ret].next;
    }
    return 0;
}

void deallocSpace(VHeap* V, int index){
    V->H[index].next = V->avail;
    V->avail = index;
}

void insertFirst(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    if(newCell != -1){
        V->H[newCell].elem = elem;
        V->H[newCell].next = *L;
        *L = newCell;
    }
}

void insertLast(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    if(newCell != -1){
        V->H[newCell].elem = elem;
        V->H[newCell].next = -1;

        //traverse
        int *trav = L;
        while(*trav != -1){
            trav = &V->H[*trav].next;
        }
        *trav = newCell;
    }
}

int main()
{
    VHeap VH;
    List L = -1;

    initialize(&VH);

    //insert some elements
    insertFirst(&L, &VH, 10);
    insertFirst(&L, &VH, 20);
    insertFirst(&L, &VH, 30);
    insertFirst(&L, &VH, 40);

    //print the list
    printf("List elements: ");
    for(int trav = L; trav!= -1; trav = VH.H[trav].next){
        printf("%d ", VH[trav].elem);
    }

    printf("\n");

    return 0;
}