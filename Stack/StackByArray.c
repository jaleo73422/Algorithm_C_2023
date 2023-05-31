#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned n) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    
    stack -> capacity = n;
    stack -> top = -1;
    
    stack -> array = (int*) malloc(n * sizeof(int));
    
    return stack;
}

bool isEmpty(struct Stack* stack) {
    return stack -> top == -1;
}

bool isFull(struct Stack* stack) {
    return stack -> top == stack -> capacity - 1;
}

void push(struct Stack* stack, const int data) {
    if(isFull(stack)) {
        stack -> array = realloc(stack -> array, 2 * stack -> capacity);
        stack -> capacity *= 2;
    }
    
    stack -> array[++stack -> top] = data;
}

int pop(struct Stack* stack) {
    if(isEmpty(stack))
        return INT_MIN;
    else
        return stack -> array[stack -> top--];
}

int peek(struct Stack* stack) {
    if(isEmpty(stack))
        return INT_MIN;
    else
        return(stack -> array[stack -> top]);
}

void display(struct Stack* stack) {
    printf("The stack: ");

    if(isEmpty(stack))
        printf("empty \n");
    else
        for(int i = 0; i <= stack -> top; i++)
            printf("%d ", stack -> array[i]);
}

void main() {
    struct Stack* stack = createStack(5);

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
    
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    
    printf("%d %d\n", stack -> capacity, stack -> top);
    
    push(stack, 6);
    
    printf("%d %d\n", stack -> capacity, stack -> top);
}
