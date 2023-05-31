#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node -> data = val;
    new_node -> next = NULL;
    
    return new_node;
}

bool isEmpty(struct Node* head) {
    return head == NULL;
}

void push(struct Node** head, int val) {
    struct Node* new_node = newNode(val);

    new_node -> next = *head;
    *head = new_node;
}

int pop(struct Node** head) {
    if(isEmpty(*head)) {
        printf("stack is empty \n");
        return INT_MIN;
    }
    
    struct Node* tem_node = *head;
    *head = (*head) -> next;
    
    int popVal = tem_node -> data;
    free(tem_node);
    
    return popVal;
}

int peek(struct Node* head) {
    if(isEmpty(head)) {
        printf("stack is empty");
        return INT_MIN;
    }
    
    return head -> data;
}

void display(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head -> data);
        head = head -> next;
    }
}

void main() {
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
}
