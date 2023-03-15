#include <stdio.h>
#include <stdlib.h>

void enqueue(struct Node**, int);
void dequeue(struct Node**);
void peekFront(struct Node*);
void peekRear(struct Node*);
void display(struct Node*);

struct Node {
    int data;
    struct Node* next;
};

struct Node* rear = NULL;

void enqueue(struct Node** node, int val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node -> data = val;
    new_node -> next = NULL;

    if(*node == NULL)
        *node = new_node;
    else {
        struct Node* last_node = *node;

        while(last_node -> next != NULL)
            last_node = last_node -> next;

        last_node -> next = new_node;
    }
}

void dequeue(struct Node** node) {
    if(*node == NULL)
        printf("queue is empty \n");
    else if((*node) -> next == NULL)
        *node = NULL;
    else {
        struct Node* tem = *node;

        *node = (*node) -> next;
        
        free(tem);
    }
}

void peekFront(struct Node* node) {
    if(node == NULL)  printf("queue is empty \n");
    else  printf("%d \n", node -> data);
}

void peekRear(struct Node* node) {
    if(node == NULL)  printf("queue is empty \n");
    else {
        while(node -> next != NULL)
            node = node -> next;
        
        printf("%d \n", node -> data);
    }
}

void display(struct Node* node) {
    if(node == NULL)  printf("queue is empty \n");
    else {
        while(node != NULL) {
        printf("%d ", node -> data);
        node = node -> next;
        }
    }
}

int main() {
    struct Node* front = NULL;

    enqueue(&front, 1);
    enqueue(&front, 3);
    enqueue(&front, 5);
    enqueue(&front, 7);
    enqueue(&front, 9);

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
    peekFront(front);
    peekRear(front);
    display(front);
    printf("\n ===== \n");

    return 0;
}