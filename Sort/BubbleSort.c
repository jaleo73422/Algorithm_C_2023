#include <stdio.h>

void swap(int* x, int* y) {
    int tem = *x;
    *x = *y;
    *y = tem;
}

void bubbleSort(int* arr, int n) {
    int done = 1;

    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);

            done = 0;
        }

        if(done)  break;
    }
}

// Recursive implementation Of bubble sort
void bubbleSort_2(int* arr, int n) {
    int done = 1;

    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            swap(&arr[i], &arr[i + 1]);
            done = 0;
        }
    }

    if(done)  return ;

    bubbleSort_2(arr, n - 1);
}

void printArray(int* arr, int size) {
    printf("The array: ");

    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

void main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);

    printf("== Bubble sort == \n");

    bubbleSort(arr, n);
    printArray(arr, n);

    printf("\n == Recursive implementation Of bubble sort == \n");

    bubbleSort_2(arr2, n);
    printArray(arr2, n);
}