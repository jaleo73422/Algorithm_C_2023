#include <stdio.h>
#include <stdlib.h>

void enqueue(struct Node**, int);
void dequeue(struct Node**);
void peekFront(struct Node*);
void peekRear(struct Node*);
bool isEmpty(struct Node*);
void display(struct Node*);

struct Node {
    int data;
    struct Node* next;
};

struct Node* rear = NULL;

void enqueue(struct Node** node, const int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    if(isEmpty(*node)) {
        new_node -> data = data;
        new_node -> next = *node;

        *node = new_node;
        rear = new_node;
    } else {
        new_node -> data = data;
        new_node -> next = rear -> next;
        rear -> next = new_node;

        rear = new_node;
    }
}

void dequeue(struct Node** node) {
    if(isEmpty(*node)) {
        printf("The queue is empty. \n");
        return ;
    }

    if(isEmpty((*node) -> next)) {
        rear = rear -> next;
        *node = (*node) -> next;

        return ;
    }

    struct Node* tem = (*node) -> next;

    **node = *((*node) -> next);
    free(tem);
}

bool isEmpty(struct Node* node) {
    return (node == NULL) ? true : false;
}

void peekFront(struct Node* node) {
    if(isEmpty(node)) {
        printf("The queue is empty. \n");
    } else {
        printf("The front of the queue: %d \n", node -> data);
    }
}

void peekRear(struct Node* node){
    if(isEmpty(node)) {
        printf("The queue is empty. \n");
    } else {
        printf("The rear of the queue: %d \n", rear -> data);
    }
}

void display(struct Node* node) {
    printf("The queue: ");

    if(!isEmpty(node)) {
        while(node != NULL) {
            printf("%d ", node -> data);
            node = node -> next;
        }
    } else {
        printf("The queue is empty. \n");
    }
}

int main() {
    struct Node* front = NULL;

    enqueue(&front, 1);
    enqueue(&front, 3);
    enqueue(&front, 5);
    enqueue(&front, 7);
    enqueue(&front, 9);

    printf("Is the queue empty: %d \n", isEmpty(front));
    peekFront(front);
    peekRear(front);
    display(front);
    printf("\n ===== \n");

    dequeue(&front);
    dequeue(&front);
    dequeue(&front);
    display(front);
    printf("\n ===== \n");

    dequeue(&front);
    dequeue(&front);
    dequeue(&front);
    printf("Is the queue empty: %d \n", isEmpty(front));
    peekFront(front);
    peekRear(front);
    display(front);
    printf("\n ===== \n");

    return 0;
}