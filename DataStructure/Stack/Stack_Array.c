#include <stdio.h>
#include <stdlib.h>

void push(int[], const int);
void pop(int[]);
void peek(int[]);
bool isEmpty(int[]);
void display(int[]);

int top = -1;

void push(int array[], const int data) {
    top++;
    array[top] = data;
}

void pop(int array[]) {
    if(!isEmpty(array)) {
        top--;
    } else {
        printf("The stack is empty. \n");
    }
}

bool isEmpty(int array[]) {
    return (top == -1) ? true : false;
}

void peek(int array[]) {
    if(!isEmpty(array)) {
        printf("The top of stack: %d \n", array[top]);
    } else {
        printf("The stack is empty. \n");
    }
}

void display(int array[]) {
    printf("The stack: ");

    if(!isEmpty(array)) {
        for(int i = 0; i <= top; i++) {
            printf("%d ", array[i]);
        }
    } else {
        printf("The stack is empty. \n");
    }
}

int main() {
    int stack[50];

    push(stack, 9);
    push(stack, 7);
    push(stack, 5);
    push(stack, 3);
    push(stack, 1);

    printf("Is the stack empty: %d \n", isEmpty(stack));
    peek(stack);
    display(stack);
    printf("\n ===== \n");

    pop(stack);
    pop(stack);
    pop(stack);
    peek(stack);
    display(stack);
    printf("\n ===== \n");

    pop(stack);
    pop(stack);
    // pop(stack);
    printf("Is the stack empty: %d \n", isEmpty(stack));
    peek(stack);
    display(stack);
    printf("\n");

    return 0;
}