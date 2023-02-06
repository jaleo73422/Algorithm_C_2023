#include <stdio.h>
#include <stdlib.h>

void enqueue(int[], int);
void dequeue(int[]);
void peekFront(int[]);
void peekRear(int[]);
bool isEmpty(int[]);
void display(int[]);

int front = -1, rear = -1;

void enqueue(int array[], int data) {
    if(isEmpty(array)){
        front++;
    }

    rear++;
    array[rear] = data;
}

void dequeue(int array[]) {
    if(!isEmpty(array)) {
        if(front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    } else {
        printf("The queue is empty. \n");
        return ;
    }
}

bool isEmpty(int array[]) {
    return (front == -1) ? true : false;
}

void peekFront(int array[]) {
    if(!isEmpty(array)) {
        printf("The front of the queue: %d \n", array[front]);
    } else {
        printf("The queue is empty. \n");
    }
}

void peekRear(int array[]){
    if(!isEmpty(array)) {
        printf("The rear of the queue: %d \n", array[rear]);
    } else {
        printf("The queue is empty. \n");
    }
}

void display(int array[]) {
    printf("The queue: ");
    
    if(!isEmpty(array)) {
        for(int i = front; i <= rear; i++) {
            printf("%d ", array[i]);
        }
    } else {
        printf("The queue is empty. \n");
    }
}

int main() {
    int queue[50];

    enqueue(queue, 1);
    enqueue(queue, 3);
    enqueue(queue, 5);
    enqueue(queue, 7);
    enqueue(queue, 9);

    printf("Is the queue empty: %d \n", isEmpty(queue));
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

    return 0;
}