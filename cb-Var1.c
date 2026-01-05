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

void insertPos(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    if(newCell == -1){
        printf("Heap is full!\n");
        return;
    }

    V->H[newCell].elem = elem;

    //if list is empty or only has one element, insert at beginning
    if(*L == -1 || V->H[*L].next == -1){
        V->H[newCell].next = *L;
        *L = newCell;
        return;
    }

    //insert after first element
    int *trav = &V->H[*L].next;
    V->H[newCell].next = *trav;;
    *trav = newCell;

}

void insertSorted(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    if(newCell == -1){
        printf("Heap is full!\n");
        return;
    }

    V->H[newCell].elem = elem;

    int *trav = L;
    while(*trav != -1 && V->H[*trav].elem < elem){
        trav = &V->H[*trav].next;
    }

    V->H[newCell].next = *trav;
    *trav = newCell;
}

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

void deleteAllOccurrence(int* L, VHeap* V, int elem){
    int *trav, temp;
    trav = L;
    while(*trav != -1){
        if(V->H[*trav].elem == elem){
            temp = *trav;
            *trav = V->H[*trav].next;
            deallocSpace(V, temp);
        }else{
            trav = &V->H[*trav].next;
        }
    }
}

void display(int L, VHeap V){
    for(; L != -1; L = V.H[L].next){
        printf("%d ", V.H[L].elem);
    }

    printf("\n");

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

    printf("Initial List: \n");
    display(L, VH);

    printf("\nAfter Delete 20: \n");
    delete(&L, &VH, 20);
    display(L, VH);

    printf("\nAfter insertSorted 25: \n");
    insertSorted(&L, &VH, 25);
    display(L, VH);

    printf("\nAfter deleteAllOccurrence 30: \n");
    deleteAllOccurrence(&L, &VH, 30);
    display(L, VH);

    printf("\nAfter insertPos:\n");
    insertPos(&L, &VH, 97);
    display(L, VH);

    return 0;
}

//DONE8