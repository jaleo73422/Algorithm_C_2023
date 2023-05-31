#include <stdio.h>

void swap(int* x, int* y) {
    int tem = *x;
    *x = *y;
    *y = tem;
}

int partition(int* nums, int l, int r) {
    int pivot = r;
    int lptr = l, replace = l;

    while(lptr != r) {
        if(nums[lptr] < nums[pivot]) {
            swap(&nums[lptr], &nums[replace]);
            replace++;
        }

        lptr++;
    }

    swap(&nums[replace], &nums[pivot]);

    return replace;
}

void quickSort(int* nums, int l, int r) {
    if(l < r) {
        int pivot = partition(nums, l, r);
        
        quickSort(nums, l, pivot - 1);
        quickSort(nums, pivot + 1, r);
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
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);

    printf("\n == Quick sort == \n");

    quickSort(arr, 0, n - 1);
    printArray(arr, n);
}