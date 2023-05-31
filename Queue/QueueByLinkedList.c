#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Node* newNode(int val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node -> data = val;
    new_node -> next = NULL;
    
    return new_node;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));

    queue -> front = NULL;
    queue -> rear = NULL;
    
    return queue;
};

void enqueue(struct Queue* queue, int val) {
    struct Node* new_node = newNode(val);

    if(queue -> rear == NULL) {
        queue -> front = new_node;
        queue -> rear = new_node;
        
        return ;
    }

    queue -> rear -> next = new_node;
    queue -> rear = new_node;
}

void dequeue(struct Queue* queue) {
    if(queue -> front == NULL) {
        printf("queue is empty \n");
        return ;
    }
    
    struct Node* tem_node = queue -> front;
    queue -> front = queue -> front -> next;
    
    if(queue -> front == NULL);
        queue -> rear = NULL;
    
    free(tem_node);
}

void peekFront(struct Queue* queue) {
    if(queue -> front == NULL)  printf("queue is empty \n");
    else  printf("%d \n", queue -> front -> data);
}

void peekRear(struct Queue* queue) {
    if(queue -> rear == NULL)  printf("queue is empty \n");
    else  printf("%d \n", queue -> rear -> data);
}

void display(struct Queue* queue) {
    if(queue -> front == NULL) {
        printf("queue is empty \n");
    }
    
    struct Node* tem_node = queue -> front;
    
    while(tem_node != NULL) {
        printf("%d ", tem_node -> data);
        tem_node = tem_node -> next;
    }
}

void main() {
    struct Queue* front = createQueue();

    enqueue(front, 1);
    enqueue(front, 3);
    enqueue(front, 5);
    enqueue(front, 7);
    enqueue(front, 9);

    peekFront(front);
    peekRear(front);
    display(front);
    printf("\n ===== \n");

    dequeue(front);
    dequeue(front);
    dequeue(front);
    display(front);
    printf("\n ===== \n");

    dequeue(front);
    dequeue(front);
    dequeue(front);
    peekFront(front);
    peekRear(front);
    display(front);
    printf("\n ===== \n");
}
