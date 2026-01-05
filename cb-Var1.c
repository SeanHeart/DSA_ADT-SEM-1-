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
    return ret;
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

void insertPos(int* L, VHeap* V, int elem);)

// void insertSorted(int* L, VHeap* V, int elem){

// }

void delete(int* L, VHeap* V, int elem){
    int *trav, temp;
    trav = L;
    while(*trav != -1 && V->H[*trav].elem != elem){
        trav = &V->H[*trav].next;
    }
    if(*trav != -1){
        temp = *trav;
        *trav = V->H[*trav].next;
        deallocSpace(V, temp);
    }
}

// void deleteAllOccurrence(int* L, VHeap* V, int elem)

void display(int L, VHeap V){
    for(; L != -1; L = V.H[L].next){
        printf("%d ", V.H[L].elem);
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
    printf("List elements: \t");
    display(L, VH);

    //deleted
    printf("\nDeleted elements: ");
    delete(&L, &VH, 30);
    display(L, VH);

    

    printf("\n");

    return 0;
}

//Status: Lacking insertSorted() and deleteAllOccurrence() ahhh