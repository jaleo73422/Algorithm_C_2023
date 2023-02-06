#include <stdio.h>
#include <stdlib.h>

void push(struct Node**, int);
void append(struct Node**, int);
struct Node* lastNode(struct Node*);
struct Node* secLastNode(struct Node*);
void swap(struct Node*, struct Node*);

void bubbleSort(struct Node*);
void bubbleSort_2(struct Node*);
void bubbleSort_3(struct Node*, int);

void insertionSort(struct Node*);
void insertionSort_2(struct Node**);

void selectionSort(struct Node*);

void merge(struct Node*);
void mergeSort(struct Node**);
struct Node* split(struct Node*);

struct Node* partition(struct Node*, struct Node*);
void quickSort(struct Node*, struct Node*);

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

	while (last -> next != NULL) {
        last = last -> next;
    }

	last -> next = new_node;
}

void swap(struct Node* x, struct Node* y) {
    int tem = x -> data;

    x -> data = y -> data;
    y -> data = tem;
}

void bubbleSort(struct Node* node) {
    int n = 0;
    struct Node* original = node;

    if(node == NULL) {
        printf("The list is empty, \n");
        return ;
    }

    while(node != NULL) {
        n++;
        node = node -> next;
    }

    for(int i = 0; i < n; i++) {
        node = original;

        for(int j = 0; j < n - i - 1; j++) {
            if((node -> data) > (node -> next -> data)) {
                swap(node, node -> next);
            }

            node = node -> next;
        }
    }
}

void bubbleSort_2(struct Node* node) {
    int done = 0;
    struct Node* now;
    struct Node* end = NULL;

    if(node == NULL) {
        printf("The list is empty, \n");
        return ;
    }

    while(!done) {
        done = 1;
        now = node;

        while(now -> next != end) {
            if((now -> data) > (now -> next -> data)) {
                swap(now, now -> next);
                done = 0;
            }

            now = now -> next;
        }

        end = now;
    }
}

// Recursive implementation Of bubble sort
void bubbleSort_3(struct Node* node, int n) {
    int done = 1;
    struct Node* now = node;

    if(node == NULL) {
        printf("The list is empty, \n");
        return ;
    }

    for(int i = 0; i < n - 1; i++) {
        if((now -> data) > (now -> next -> data)) {
            swap(now, now -> next);
            done = 0;
        }

        now = now -> next;
    }

    if(done) {
        return ;
    }

    bubbleSort_3(node, n - 1);
}

void insertionSort(struct Node* node) {
    int tem, pre;
    struct Node* now = node -> next;
    struct Node* start;

    if(node == NULL) {
        printf("The list is empty, \n");
        return ;
    }

    while(now != NULL) {
        start = node;

        while((start -> data) <= (now -> data)) {
            start = start -> next;

            if(start == now) {
                break;
            }
        }

        pre = start -> data;
        start -> data = now -> data;
        start = start -> next;

        while(start != now -> next) {
            tem = start -> data;
            start -> data = pre;
            pre = tem;
            start = start -> next;
        }

        now = now -> next;
    }
}

void insertionSort_2(struct Node** node) {
    struct Node* pre_now = *node;
    struct Node* now = (*node) -> next;
    struct Node* start;
    struct Node* new_head = (struct Node*) malloc(sizeof(struct Node));
    struct Node* free_node;

    if(node == NULL) {
        printf("The list is empty, \n");
        return ;
    }

    if(((*node) -> data) > (now -> data)) {
        int tem = (*node) -> data;
        (*node) -> data = now -> data;
        now -> data = tem;
        now = now -> next;
        pre_now = pre_now -> next;
    }

    while(now != NULL) {        
        start = *node;

        if((start -> data) > (now -> data)) {
            free_node = now;

            new_head -> data = now -> data;
            new_head -> next = start;
            *node = new_head;

            pre_now -> next = now -> next;
            now = pre_now -> next;
            free(free_node);

            continue;
        }

        while((start -> next -> data) <= (now -> data)) {
            start = start -> next;

            if(start -> next == now) {
                pre_now = pre_now -> next;
                now = now -> next;
                break;
            }
        }

        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

        free_node = now;

        new_node -> data = now -> data;
        new_node -> next = start -> next;
        start -> next = new_node;

        pre_now -> next = now -> next;
        now = pre_now -> next;
        free(free_node);
    }
}

void selectionSort(struct Node* node) {
    struct Node* left_node = node;
    struct Node* right_node;
    struct Node* min_node;

    if(node == NULL) {
        printf("The list is empty, \n");
        return ;
    }

    while(left_node -> next != NULL) {
        right_node = left_node -> next;
        min_node = right_node;

        while(right_node  != NULL) {
            if(right_node -> data < min_node -> data) {
                min_node  = right_node;
            }

            right_node = right_node -> next;
        }

        if(min_node -> data < left_node -> data) {
            swap(left_node, min_node);
        }

        left_node = left_node -> next;
    }
}

void merge(struct Node** front, struct Node* back) {
    struct Node* tem = (struct Node*) malloc(sizeof(struct Node));
    struct Node* frist;

    tem = NULL;
    append(&tem, 0);
    frist = tem;

    while(*front != NULL || back != NULL) {
        if(*front == NULL) {
            while(back != NULL) {
                tem -> data = back -> data;
                append(&tem, 0);
                tem = tem -> next;
                back = back -> next;
            }

            break;
        }

        if(back == NULL) {
            while((*front) != NULL) {
                tem -> data = (*front) -> data;
                append(&tem, 0);
                tem = tem -> next;
                (*front) = (*front) -> next;
            }

            break;
        }

        if(((*front) -> data) > (back -> data)) {
            tem -> data = back -> data;
            append(&tem, 0);
            tem = tem -> next;

            back = back -> next;
        } else {
            tem -> data = (*front) -> data;
            append(&tem, 0);
            tem = tem -> next;

            *front = (*front) -> next;
        }
    }

    struct Node* tem_2 = secLastNode(frist);

    tem_2 -> next = NULL;
    *front = frist;
}

void mergeSort(struct Node** node) {
    struct Node* tem;

    if(*node == NULL || (*node) -> next == NULL) {
        return ;
    } else {
        tem = split(*node);
    }

    mergeSort(&tem);
    mergeSort(node);
    merge(node, tem);
}

// split a linked list to front list and back list
// return frist node of back list
// if the length is odd, the extra node should go in the front list
struct Node* split(struct Node* node) {
    struct Node* slow = node;
    struct Node* fast = node;
    struct Node* tem;
    
    while((fast -> next) != NULL && (fast -> next -> next) != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    tem = slow -> next;
    slow -> next = NULL;

    return tem;
}

struct Node* lastNode(struct Node* node) {
    while(node -> next != NULL) {
        node = node -> next;
    }

    return node;
}

struct Node* secLastNode(struct Node* node) {
    while(node -> next -> next != NULL) {
        node = node -> next;
    }

    return node;
}

struct Node* partition(struct Node* frist, struct Node* last) {
    struct Node* front_pivot = frist;
    struct Node* replace_node = frist;
    struct Node* slide_node = frist;

    while(slide_node != last) {
        if((slide_node -> data) < (last -> data)) {
            swap(slide_node, replace_node);

            if(replace_node != frist) {
                front_pivot = front_pivot -> next;
            }

            replace_node = replace_node -> next;
        }

        slide_node = slide_node -> next;
    }

    swap(replace_node, last);

    return front_pivot;
}

void quickSort(struct Node* frist, struct Node* last) {
    if(frist == last) {
        return ;
    }

    struct Node* mid_node = partition(frist, last);

    quickSort(frist, mid_node);
    quickSort(mid_node -> next, last);
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
    int arr[] = {12, 56, 2, 11, 1, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < n; i++) {
        push(&head, arr[i]);
    }

    printf("\n Created linked list is: ");
    printList(head);

    printf("\n Bubble sort: ");
    bubbleSort(head);
    printList(head);

    head = NULL;

    for(int i = 0; i < n; i++) {
        push(&head, arr[i]);
    }

    printf("\n Created linked list is: ");
    printList(head);

    printf("\n Bubble sort: ");
    bubbleSort_2(head);
    printList(head);

    head = NULL;

    for(int i = 0; i < n; i++) {
        push(&head, arr[i]);
    }

    printf("\n Created linked list is: ");
    printList(head);

    printf("\n Bubble sort: ");
    bubbleSort_3(head, n);
    printList(head);

    head = NULL;

    for(int i = 0; i < n; i++) {
        push(&head, arr[i]);
    }

    printf("\n Created linked list is: ");
    printList(head);    

    printf("\n Insertion sort: ");
    insertionSort(head);
    printList(head);

    head = NULL;

    for(int i = 0; i < n; i++) {
        push(&head, arr[i]);
    }

    printf("\n Created linked list is: ");
    printList(head);    

    printf("\n Insertion sort: ");
    insertionSort_2(&head);
    printList(head);

    head = NULL;

    for(int i = 0; i < n; i++) {
        push(&head, arr[i]);
    }

    printf("\n Created linked list is: ");
    printList(head);

    printf("\n Selection sort: ");
    selectionSort(head);
    printList(head);

    head = NULL;

    for(int i = 0; i < n; i++) {
        push(&head, arr[i]);
    }

    printf("\n Created linked list is: ");
    printList(head);

    printf("\n Merge sort: ");
    mergeSort(&head);
    printList(head);

    head = NULL;

    for(int i = 0; i < n; i++) {
        push(&head, arr[i]);
    }

    printf("\n Created linked list is: ");
    printList(head);

    printf("\n Quick sort: ");
    quickSort(head, lastNode(head));
    printList(head);

    return 0;
}
