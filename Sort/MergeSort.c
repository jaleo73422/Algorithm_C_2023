#include <stdio.h>

void swap(int* x, int* y) {
    int tem = *x;
    *x = *y;
    *y = tem;
}

void merge(int* nums, int l, int m, int r) {
    int tems[r - l + 1];
    int idx = l, tem_l = l, tem_m = m + 1;

    while(tem_l != m + 1 || tem_m != r + 1) {
        if(tem_l == m + 1) {
            tems[idx - l] = nums[tem_m];
            idx++;
            tem_m++;
            continue;
        } else if(tem_m == r + 1) {
            tems[idx - l] = nums[tem_l];
            idx++;
            tem_l++;
            continue;
        }

        if(nums[tem_l] > nums[tem_m]) {
            tems[idx - l] = nums[tem_m];
            idx++;
            tem_m++;
        } else {
            tems[idx - l] = nums[tem_l];
            idx++;
            tem_l++;
        }
    }

    for(int i = 0, j = l; i < r - l + 1; i++, j++)
        nums[j] = tems[i];
}

void mergeSort(int* nums, int l, int r) {
    int m = (l + r) / 2;

    if(l == r)  return ;

    mergeSort(nums, l, m);
    mergeSort(nums, m + 1, r);
    merge(nums, l, m, r);
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

    printf("\n == merge sort == \n");

    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
}