#include <stdio.h>
#include <stdlib.h>

void push(struct Node*, int);
void append(struct Node*, int);
void insertAfter(struct Node*, int);
void deleteBeginning(struct Node*); 
void deleteEnd(struct Node*);
void deleteValue(struct Node*, int);
void deleteIndex(struct Node*, int);
void printList(struct Node*);

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node* node, int data) {
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    if(node == NULL) {
        node -> data = data;
        node -> next = NULL;

        // printf("\n ---Created linked list is: ");
        // printList(node);

        return;
	}

	new_node -> data = node -> data;
	new_node -> next = node -> next;

    node -> data = data;
	node -> next = new_node;
}

void append(struct Node* node, int data) {
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	struct Node* last = node;

	if(node == NULL) {
        node = (struct Node*) malloc(sizeof(struct Node));

        node -> data = data;
        node -> next = NULL;

        printf("\n ---Created linked list is: ");
        printList(node);

        return;
	}

    new_node -> data = data;
	new_node -> next = NULL;

	while (last -> next != NULL) {
        last = last -> next;
    }

	last -> next = new_node;
}

void insertAfter(struct Node* node, int data) {
	if(node == NULL) {
        printf("The given previous node cannot be NULL. \n");
        
        return;
	}

	struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));

	new_node -> data = data;
	new_node -> next = node -> next;

	node -> next = new_node;
}

void deleteBeginning(struct Node* node) {
    struct Node* tem = node -> next;

    *node = *(node -> next);

    free(tem);
}

void deleteEnd(struct Node* node) {
    struct Node* tem;
    struct Node* last;

    while(node -> next != NULL) {
        last = node;
        tem = node -> next;
        node = node -> next;
    }


    last -> next = node -> next;

    free(tem);
}

void deleteValue(struct Node* node, int data) {
    struct Node* temp;

    if(node -> data == data) {
        temp = node -> next;
        *node = *(node -> next);
        free(temp);

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

void deleteIndex(struct Node* node, int index) {
    struct Node* tem;

    if(index == 0) {
        tem = node -> next;

        *node = *(node -> next);

        free(tem);
        return ;
    }

    for(int i = 0; i < index - 1; i++) {
        node = node -> next;

        if(node == NULL) {
            printf("\n The index doesn't exist. \n");

            return ;
        }

        tem = node -> next;
    }

    node -> next = node -> next -> next;
    free(tem);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node -> data);

        node = node -> next;
    }
}

// driver program to test above functions
int main() {
    struct Node* head = NULL;
    head = (struct Node*) malloc(sizeof(struct Node));

    head -> data = 1;
    head -> next = NULL;

    // append(head, 6);
    // push(head, 7);
    // push(head, 1);
    // append(head, 4);
    // append(head, 4);
    // append(head, 4);
    // insertAfter(head -> next, 8);
    // push(head, 1);
    // // push(&head, 1);

    // printf("\n Created linked list is: ");
    // printList(head);

    // deleteValue(head, 4);
    // deleteValue(head, 1);
    // deleteIndex(head, 3);
    // deleteIndex(head, 0);
    // deleteIndex(head, 8);

    // printf("\n Created linked list is: ");
    // printList(head);

    // deleteBeginning(head);
    // deleteEnd(head);
    printf("\n Created linked list is: ");
    printList(head);

    return 0;
}
