#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** node, int data) {    
    // struct Node* new_node = NULL;
    
    if(*node == NULL) {
        *node = (struct Node*) malloc(sizeof(*node));
    } else {

        while(*node != NULL) {
            node = &((*node) -> next);
        }
        *node = (struct Node*) malloc(sizeof(*node));
    }

    (*node) -> data = data;
    (*node) -> next = NULL;
}

void push(struct Node** node, int data) {
    struct Node* new_node = NULL;

    if(*node == NULL) {
        *node = (struct Node*) malloc(sizeof(*node));
    } else{
        new_node = (struct Node*) malloc(sizeof(new_node));
        
        new_node -> data = (*node) -> data;
        new_node -> next = (*node) -> next;
    }

    (*node) -> data = data;
    (*node) -> next = new_node;
}

void insertAfter(struct Node* node, int data) {
    if(node == NULL) {
        printf("The given previous node cannot be NULL. \n");
        
        return;
	}

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = data;
    new_node -> next = node -> next;

    node -> next = new_node;
}

void deletValue(struct Node* node, int data) {
    struct Node* temp;

    if(node -> data == data) {
        temp = node;
        *node = *(node -> next);
        free(&temp);
        return ;
    }

    while(node -> next != NULL) {
        temp = node -> next;

        if(node -> next -> data == data) {
            break;
        }

        node = node -> next;
    }

    if(node -> next == NULL) {
        printf("The value doesn't exist. \n");

        return ;
    }

    node -> next = node -> next -> next;
    free(temp);
}




// deleteIndex


void printList(struct Node* node) {
    while(node != NULL) {
        printf("%d ", node -> data);

        node = node -> next;
    }
}


// driver program to test above functions
int main() {
    struct Node* head = NULL;

    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head -> next, 8);

    printf("\n Created Linked list is: ");
    printList(head);
    printf("\n");

    deletValue(head, 1);
    // deletIndex(head, 2);

    printf("\n Created Linked list is: ");
    printList(head);
    printf("\n");

    // 1 7 8 6 4
    // 1 8 6 4
    // 1 8 4

    return 0;
}