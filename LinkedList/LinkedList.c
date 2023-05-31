#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head, int val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = val;
    new_node -> next = *head;
    *head = new_node;
}

void append(struct Node** head, int val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));    
    new_node -> data = val;
    new_node -> next = NULL;
    
    if(*head == NULL) {
        *head = new_node;
        return ;
    }
    
    struct Node* last_node = *head;

    while(last_node -> next != NULL)
        last_node = last_node -> next;

    last_node -> next = new_node;
}

void insertAfterVal(struct Node* head, int dest, int val) {
    if(head == NULL) {
        printf("linked list is empty \n");
        return ;
    }

    struct Node* last_node = head;

    while(last_node -> data != dest && last_node != NULL)
        last_node = last_node -> next;
    
    if(last_node != NULL) {
        printf("node doesn't exist \n");
        return ;
    }

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = val;
    new_node -> next = last_node -> next;
    last_node -> next = new_node;
}

void deleteValue(struct Node** head, int val) {
    if(*head == NULL) {
        printf("linked list is empty \n");
        return ;
    }
    
    struct Node* current_node = *head;
    
    if(current_node -> data == val) {
        *head = current_node -> next;
        free(current_node);
        return;
    }
    
    struct Node* pre_node = current_node;
    
    while(current_node != NULL && current_node -> data != val) {
        pre_node = current_node;
        current_node = current_node -> next;
    }
    
    if(current_node == NULL) {
        printf("linked list is empty \n");
        return ;
    }

    pre_node -> next = current_node -> next;
    free(current_node);
}

void deleteHead(struct Node** head) {
    if(*head == NULL) {
        printf("linked list is empty \n");
        return ;
    }

    struct Node* free_node = *head;
    *head = (*head) -> next;
    free(free_node);
}

void deleteTail(struct Node** head) {
    if(*head == NULL) {
        printf("linked list is empty \n");
        return ;
    }

    if((*head) -> next == NULL) {
        *head = NULL;
        return ;
    }

    struct Node* last_node = *head;
    while(last_node -> next -> next != NULL)
        last_node = last_node -> next;

    struct Node* free_node = last_node -> next;
    last_node -> next = NULL;
    free(free_node);
}

void printLL(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
}

void main() {
    struct Node* head = NULL;
    
    // push(&head, 6);
    push(&head, 9);
    // append(&head, 5);
    // insertAfterVal(head, 5, 3);
    // append(&head, 19);
    printLL(head);
    
    deleteValue(&head, 9);
    printLL(head);
    
    append(&head, 19);
    append(&head, 11);
    deleteValue(&head, 19);
    deleteValue(&head, 11);
    printLL(head);
    
    append(&head, 7);
    append(&head, 8);
    // append(&head, 11);
    // append(&head, 19);
    printLL(head);
    printf("--- \n");
    
    // deleteHead(&head);
    deleteTail(&head);
    printLL(head);
}
