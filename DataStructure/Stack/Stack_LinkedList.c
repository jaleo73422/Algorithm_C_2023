#include <stdio.h>
#include <stdlib.h>

void push(struct Node**, const int);
void pop(struct Node**);
void peek(struct Node*);
bool isEmpty(struct Node*);
void display(struct Node*);

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** node, const int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node -> data = data;
    new_node -> next = *node;

    *node = new_node;
}

void pop(struct Node** node) {
    if(isEmpty(*node)) {
        printf("The stack is empty. \n");
        return ;
    }

    struct Node* tem = (*node) -> next;

    if(isEmpty((*node) -> next)) {
        *node = NULL;
    } else {
        **node = *tem;
    }

    free(tem);
}

bool isEmpty(struct Node* node) {
    return (node == NULL) ? true : false;
}

void peek(struct Node* node) {
    if(isEmpty(node)) {
        printf("The stack is empty. \n");
    } else {
        printf("The top of stack: %d \n", node -> data);
    }
}

void display(struct Node* node) {
    printf("The stack: ");

    if(!isEmpty(node)) {
        while(node != NULL) {
            printf("%d ", node -> data);
            node = node -> next;
        }
    } else {
        printf("The stack is empty. \n");
    }
}

int main() {
    struct Node* top = NULL;

    push(&top, 9);
    push(&top, 7);
    push(&top, 5);
    push(&top, 3);
    push(&top, 1);

    printf("Is the stack empty: %d \n", isEmpty(top));
    peek(top);
    display(top);
    printf("\n ===== \n");

    pop(&top);
    pop(&top);
    pop(&top);
    peek(top);
    display(top);
    printf("\n ===== \n");

    pop(&top);
    pop(&top);
    // pop(&top);
    printf("Is the stack empty: %d \n", isEmpty(top));
    peek(top);
    display(top);
    printf("\n");

    return 0;
}