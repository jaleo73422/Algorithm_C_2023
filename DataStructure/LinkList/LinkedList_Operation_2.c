#include <stdio.h>
#include <stdlib.h>

void push(struct Node**, int);
void append(struct Node**, int);
void insertAfter(struct Node*, int);
void deleteBeginning(struct Node**); 
void deleteEnd(struct Node**);
void deleteValue(struct Node**, int);
void deleteIndex(struct Node**, int);
void printList(struct Node*);

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** node, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node -> data = data;
    new_node -> next = *node;

    *node = new_node;
}

void append(struct Node** node, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *node;

    new_node -> data = data;
	new_node -> next = NULL;

    if(*node == NULL) {
        *node = new_node;
        return;
	}

    while (last -> next != NULL)
        last = last -> next;

	last -> next = new_node;
}

void insertAfter(struct Node* node, int data) {
    if(node == NULL) {
        printf("The given previous node cannot be NULL. \n");
        return ;
	}

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node -> data = data;
    new_node -> next = node -> next;

    node -> next = new_node;
}

void deleteBeginning(struct Node** node) {
    if(*node == NULL) {
        printf("list is empty \n");
        return ;
    }

    if((*node) -> next == NULL) {
        *node = (*node) -> next;
        return ;
    }

    struct Node* tem = (*node) -> next;

    (*node) -> data = (*node) -> next -> data;
    (*node) -> next = (*node) -> next -> next;
}

void deleteEnd(struct Node** node) {
    if(*node == NULL) {
        printf("list is empty \n");
        return ;
    }

    if((*node) -> next == NULL) {
        *node = (*node) -> next;
        return ;
    }

    struct Node* last = *node;
    struct Node* tem;

    while(last -> next -> next != NULL) {
        last = last -> next;
        tem = last -> next;
    }

    last -> next = NULL;
}

void deleteValue(struct Node** node, int value) {
    if(*node == NULL) {
        printf("list is empty \n");
        return ;
    }

    struct Node* last_node = *node;
    struct Node* target_node = NULL;

    if(last_node -> data == value) {
        target_node = last_node;
    }
    
    while(last_node -> next != NULL) {
        if(last_node -> next -> data == value) {
            target_node = last_node -> next;
            break;
        }
        
        last_node = last_node -> next;
    }

    if(target_node == NULL) {
        printf("the value doesn't exist \n");
        return ;
    }
    
    if(target_node == *node) {
        *node = (*node) -> next;
        return ;
    }

    last_node -> next = target_node -> next;
}

void deleteIndex(struct Node** node, int index) {
    if(*node == NULL) {
        printf("list is empty \n");
        return ;
    }

    struct Node* last_node = *node;
    struct Node* target_node = NULL;
    int count = 0;

    if(index == 0) {
        target_node = last_node;
    }

    while(last_node -> next != NULL) {
        if(count + 1 == index) {
            target_node = last_node -> next;
            break;
        }

        count++;
        last_node = last_node -> next;
    }

    if(target_node == NULL) {
        printf("the value doesn't exist \n");
        return ;
    }
    
    if(target_node == *node) {
        *node = (*node) -> next;
        return ;
    }

    last_node -> next = target_node -> next;
}

void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head -> data);
        head = head -> next;
    }

    printf("\n");
}

// driver program to test above functions
int main() {
    struct Node* head = NULL;

    deleteBeginning(&head);
    insertAfter(head, 19);
    append(&head, 17);
    deleteBeginning(&head);
    append(&head, 15);
    deleteBeginning(&head);
    insertAfter(head, 11);
    push(&head, 7);
    append(&head, 6);
    deleteBeginning(&head);
    deleteEnd(&head);
    push(&head, 16);
    append(&head, 0);
    deleteEnd(&head);
    push(&head, 21);
    append(&head, 13);
    push(&head, 1);
    deleteEnd(&head);
    deleteValue(&head, 50);
    deleteValue(&head, 1);
    deleteValue(&head, 16);
    deleteValue(&head, 21);
    append(&head, 31);
    push(&head, 8);
    append(&head, 22);
    push(&head, 19);
    deleteValue(&head, 19);
    append(&head, 14);
    push(&head, 6);
    deleteValue(&head, 31);
    deleteIndex(&head, 0);
    deleteIndex(&head, 2);
    deleteIndex(&head, 1);
    deleteIndex(&head, 0);
    append(&head, 14);
    push(&head, 6);    

    printList(head);

    return 0;
}
