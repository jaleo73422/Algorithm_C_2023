#include <stdio.h>

void swap(int* x, int* y) {
    int tem = *x;
    *x = *y;
    *y = tem;
}

void selectionSort(int* arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        int min_position = i;

        for(int j = i + 1; j < n; j++)
            if(arr[j] < arr[min_position])
                min_position = j;

        if(min_position != i)
            swap(&arr[i], &arr[min_position]);
    }
}

void selectionSort_2(int* nums, int nSizes, int idx) {
    if(idx == nSizes - 1)  return ;

    for(int i = idx + 1; i < nSizes; i++) {
        int change = idx;
        if(nums[i] < nums[change])
            change = i;
        
        int tem = nums[change];
        nums[change] = nums[idx];
        nums[idx] = tem;
    }

    selectionSort_2(nums, nSizes, idx + 1);
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

    printf("\n == Selection sort == \n");

    selectionSort(arr, n);
    printArray(arr, n);

    selectionSort_2(arr2, n, 0);
    printArray(arr2, n);
}