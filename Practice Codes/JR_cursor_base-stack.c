#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    char city[20];
    char name[20];
    char sex;
} person;

typedef struct {
    person elem;
    int next;
} NodeType;

typedef struct {
    NodeType data[MAX];
    int avail;
} VSpace;

void initSpace(VSpace *vs) {
    int i;
    for (i = MAX - 1; i >= 0; i--) {
        vs->data[i].next = i - 1;
    }
    vs->avail = MAX - 1;
}

int allocSpace(VSpace *vs) {
    int avail = vs->avail;

    if (avail != -1) {
        vs->avail = vs->data[avail].next;
    }
    return avail;
}

void freeSpace(VSpace *vs, int index) {
    if (index != -1 && index >= 0 && index < MAX) {
        vs->data[index].next = vs->avail;
        vs->avail = index;
    }
}

void push(VSpace *vs, int *stack, person p) {
    int temp = allocSpace(vs);

    if (temp != -1) {
        vs->data[temp].elem = p;
        vs->data[temp].next =   stack;
        *stack = temp;
    }
}

void pop(VSpace *vs, int *stack) {
    int temp;

    if (*stack != -1) {
        temp = *stack;
        *stack = vs->data[temp].next;
        freeSpace(vs, temp);
    }
}

person peek(VSpace vs, int stack) {
    return vs.data[stack].elem;
}

void insertPersonByCity(VSpace *vs, int *stack, person p) {
    int temp = allocSpace(vs);
    int tempStack = -1;
    person currentPerson;

    if(temp != -1) {
        while(*stack != -1) {
            currentPerson = peek(*vs, *stack);
            if(strcmp(currentPerson.city, p.city) < 0) {
                push(vs, &tempStack, currentPerson);
                pop(vs, stack);
            } 
			else{
                break;
            }
        }
        push(vs, stack, p);
        while (tempStack != -1) {
            push(vs, stack, peek(*vs, tempStack));
            pop(vs, &tempStack);
        }
    }
}


int extractPersonByCity(VSpace *vs, int *stack, char city[]){
	
	person currentPerson;
	int tempStack = -1;
	int extractedStack = -1;
	int temp;
	
	while(*stack != -1){
		currentPerson = vs->data[*stack].elem;
		
		if(strcmp(currentPerson.city, city) == 0){
			temp = vs->data[*stack].next;
			vs->data[*stack].next = extractedStack;
			extractedStack = *stack;
			*stack = temp;
		}
		else{
			temp = vs->data[*stack].next;
			vs->data[*stack].next = tempStack;
			tempStack = *stack;
			*stack = temp;
		}
	}
	
	while(tempStack != -1){
		temp = vs->data[tempStack].next;
		vs->data[tempStack].next = *stack;
		*stack = tempStack;
		tempStack = temp;
	}
	
	return extractedStack;
}


void displayList(VSpace vs, int list){
	int i;
	printf("{");
	for(i = list; i != -1; i = vs.data[i].next){
		printf("Name: %s, City: %s, Sex: %c\n", vs.data[i].elem.name, vs.data[i].elem.city, vs.data[i].elem.sex);
	}
	printf("}\n");
}


int main() {
    VSpace vs;
    initSpace(&vs);
    int stackList = -1;
    
    
	person p1 = {"cebu", "jaden", 'F'};
    person p2 = {"cebu", "james", 'M'};
    person p3 = {"manila", "job", 'M'};
	
	push(&vs, &stack, p2);
	push(&vs, &stack, p1);
	push(&vs, &stackList, p3);
	
	printf("Persons:\n");
	displayList(vs, stackList);
    
    int stackInCebu = extractPersonByCity(&vs, &stackList, "cebu");

    
    printf("\nPersons in cebu:\n");
    displayList(vs, stackInCebu);
    
    printf("Persons:\n");
    displayList(vs, stackList);
	
	
	
    return 0;
}

