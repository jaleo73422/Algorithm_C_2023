#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void print_ll(struct Node* node) {
    while(node != NULL) {
        // printf("%d ", *node);
        printf("%d ", node -> data);
        node = node -> next;
    }
}

int main() {
    struct Node* node_1 = NULL;
    struct Node* node_2 = NULL;
    struct Node* node_3 = NULL;
    struct Node* node_4 = NULL;

    node_1 = (struct Node*) malloc(sizeof(struct Node));
    node_2 = (struct Node*) malloc(sizeof(struct Node));
    node_3 = (struct Node*) malloc(sizeof(struct Node));

    node_1 -> data = 1;
    node_1 -> next = node_2;

    node_2 -> data = 2;
    node_2 -> next = node_3;

    node_3 -> data = 3;
    node_3 -> next = NULL;

    print_ll(node_1);

    free(node_1);
    free(node_2);
    free(node_3);

    return 0;
}