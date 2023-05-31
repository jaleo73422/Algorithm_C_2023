#include <stdio.h>

void swap(int* x, int* y) {
    int tem = *x;
    *x = *y;
    *y = tem;
}

void insertionSort(int* arr, int n) {
    for(int i = 1; i < n; i++) {
        for(int j = i; j > 0; j--) {
            if(arr[j] < arr[j - 1]) {
                swap(&arr[j], &arr[j - 1]);
            } else  break;
        }
    }
}

void insertionSort_2(int nums[], int n) {
    if(n == 1)  return;
    
    insertionSort(nums, n - 1);

    for(int j = n - 1; j > 0; j--) {
        if(nums[j] < nums[j - 1])
            swap(&nums[j], &nums[j - 1]);
        else  break;
    }
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

    printf("\n == Insertion sort == \n");

    insertionSort(arr, n);
    printArray(arr, n);
    insertionSort_2(arr2, n);
    printArray(arr2, n);
}