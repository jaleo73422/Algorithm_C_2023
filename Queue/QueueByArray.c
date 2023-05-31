#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue -> capacity = capacity;
    queue -> size = 0;
    queue -> front = 0;
    queue -> rear = capacity - 1;
    queue -> array = (int*) malloc(queue -> capacity * sizeof(int));
    
    return queue;
}

int isEmpty(struct Queue* queue) {
    return queue -> size == 0;
}

int isFull(struct Queue* queue) {
    return queue -> size == queue -> capacity;
}

void enqueue(struct Queue* queue, int data) {
    if(isFull(queue)) {
        int* new_array = malloc(2 * queue -> capacity * sizeof(int));
        int new_idx = 0;
        
        for(int i = queue -> front; i < queue -> front + queue -> size; i++)
            new_array[new_idx++] = queue -> array[i % queue -> capacity];
        
        int* tem_arr = queue -> array;
        
        queue -> array = new_array;
        
        queue -> capacity *= 2;
        queue -> front = 0;
        queue -> rear = queue -> size - 1;
        
        free(tem_arr);
    }

    queue -> rear = ++queue -> rear % queue -> capacity;
    queue -> array[queue -> rear] = data;
    queue -> size++;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("queue is empty \n");
        return INT_MIN;
    }
    
    int deVal = queue -> array[queue -> front];
    queue -> front = ++queue -> front % queue -> capacity;
    queue -> size = queue -> size - 1;
    
    return deVal;
}

int peekFront(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("queue is empty \n");
        return INT_MIN;
    }
    
    return queue -> array[queue -> front];
}

int peekRear(struct Queue* queue){
    if (isEmpty(queue)) {
        printf("queue is empty \n");
        return INT_MIN;
    }
    
    return queue -> array[queue -> rear];
}

void display(struct Queue* queue) {
    printf("The queue: ");
    
    if (isEmpty(queue)) {
        printf("queue is empty \n");
        return ;
    }
    
    for(int i = queue -> front; i < queue -> front + queue -> size; i++)
        printf("%d ", queue -> array[i % queue -> capacity]);
}

void main() {
    struct Queue* queue = createQueue(5);

    enqueue(queue, 1);
    enqueue(queue, 3);
    enqueue(queue, 5);
    enqueue(queue, 7);
    enqueue(queue, 9);

    printf("Is the queue empty: %d \n", isEmpty(queue));
    printf("Is the queue full: %d \n", isFull(queue));
    peekFront(queue);
    peekRear(queue);
    display(queue);
    printf("\n ===== \n");

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    display(queue);
    printf("\n ===== \n");

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printf("Is the queue empty: %d \n", isEmpty(queue));
    peekFront(queue);
    peekRear(queue);
    display(queue);
    printf("\n ===== \n");
    
    printf("%d %d \n", queue -> capacity, queue -> size);
    enqueue(queue, 1);
    enqueue(queue, 3);
    enqueue(queue, 5);
    enqueue(queue, 7);
    enqueue(queue, 9);
    enqueue(queue, 11);
    display(queue);
    printf("\n%d %d \n", peekFront(queue), peekRear(queue));
    printf("%d %d \n", queue -> capacity, queue -> size);
}
