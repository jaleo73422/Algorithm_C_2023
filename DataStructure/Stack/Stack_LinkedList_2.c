#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node**, const int);
void pop(struct Node**);
void peek(struct Node*);
bool isEmpty(struct Node*);
void display(struct Node*);

void push(struct Node** head, int val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node -> data = val;
    new_node -> next = NULL;


    if(!isEmpty(*head)) {
        struct Node* last_node = *head;

        while(last_node -> next != NULL)
            last_node = last_node -> next;

        last_node -> next = new_node;
    } else  *head = new_node;
}

void pop(struct Node** head) {
    if(!isEmpty(*head)) {
        if((*head) -> next == NULL) {
            *head = NULL;
            return ;
        }

        struct Node* last_node = *head;

        while(last_node -> next -> next != NULL)
            last_node = last_node -> next;

        free(last_node -> next);
        last_node -> next = NULL;
    } else printf("stack is empty");
}

void peek(struct Node* head) {
    if(!isEmpty(head)) {
        while(head -> next != NULL) {
            head = head -> next;
        }

        printf("%d \n", head -> data);
    } else printf("stack is empty");
}

bool isEmpty(struct Node* head) {
    return head == NULL;
}

void display(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head -> data);
        head = head -> next;
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
    printf("Is the stack empty: %d \n", isEmpty(top));
    peek(top);
    display(top);
    printf("\n");

    return 0;
}