#include <stdio.h>

void swap(int*, int*);
void bubbleSort(int[], int);
void bubbleSort_2(int[], int);
void insertionSort(int[], int);
void selectionSort(int[], int);
void merge(int[], int, int, int);
void mergeSort(int[], int, int);
int partition(int[], int, int);
void quickSort(int[], int, int);
void printArray(int[], int);

void swap(int* x, int* y) {
    int tem = *x;
    *x = *y;
    *y = tem;
}

void bubbleSort(int arr[], int n) {
    bool done = true;

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }

            done = false;
        }

        if(done) {
            break;
        }
    }
}

// Recursive implementation Of bubble sort
void bubbleSort_2(int arr[], int n) {
    bool done = true;

    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            swap(&arr[i], &arr[i + 1]);
            done = false;
        }
    }

    if(done) {
        return ;
    }

    bubbleSort_2(arr, n - 1);
}

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        for(int j = i; j > 0; j--) {
            if(arr[j] < arr[j - 1]) {
                swap(&arr[j], &arr[j - 1]);
            } else {
                break;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min_position = i;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min_position]) {
                min_position = j;
            }
        }

        if(min_position != i) {
            swap(&arr[i], &arr[min_position]);
        }
    }
}

void merge(int arr[], int l, int m, int r) {
    int tem[r + 1], tem_index = l;
    int l_ptr = l, r_ptr = m + 1;

    for(int i = 0; i <= r; i++) {
        tem[i] = arr[i];
    }

    /*
    arr = [X     X X X X X X X X]
           ^           ^ ^     ^
           l           m ^     r
           ^             ^
           l_ptr         r_ptr
    */

    while(l_ptr != m + 1 || r_ptr != r + 1) {
        if(l_ptr == m + 1) {
            tem[tem_index] = arr[r_ptr];
            r_ptr++;
            tem_index++;
        } else if (r_ptr == r + 1) {
            tem[tem_index] = arr[l_ptr];
            l_ptr++;
            tem_index++;
        } else {
            if(arr[l_ptr] < arr[r_ptr]) {
                tem[tem_index] = arr[l_ptr];
                l_ptr++;
            } else{
                tem[tem_index] = arr[r_ptr];
                r_ptr++;
            }
            tem_index++;
        }
    }

    for(int i = l; i < r + 1; i++) {
        arr[i] = tem[i];
    }
}

void mergeSort(int arr[], int l, int r) {
    int m = (l + r) / 2;

    // stop when l = r
    if(l < r) {
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int l, int r) {
    int replace = l;

    // r is pivot position
    for(int move = l; move < r; move++) {
        if(arr[move] < arr[r]) {
            swap(&arr[replace], &arr[move]);
            replace++;
        }
    }

    swap(&arr[replace], &arr[r]);

    return replace;
}

void quickSort(int arr[], int l, int r) {
    // stop when l = r
    if(l < r) {
        int m = partition(arr, l, r);
    
        quickSort(arr, l, m - 1);
        quickSort(arr, m + 1, r);
    }
}

void printArray(int arr[], int size) {
    printf("The array: ");

    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n \n");
}

int main() {
    int arr_1[] = {64, 34, 25, 12, 22, 11, 90};
    int n_1 = sizeof(arr_1) / sizeof(arr_1[0]);
    printArray(arr_1, n_1);

    printf("== Bubble sort == \n");

    bubbleSort(arr_1, n_1);
    printArray(arr_1, n_1);

    int arr_2[] = {64, 34, 25, 12, 22, 11, 90};
    int n_2 = sizeof(arr_2) / sizeof(arr_2[0]);

    printf("\n == Recursive implementation Of bubble sort == \n");

    bubbleSort_2(arr_2, n_2);
    printArray(arr_2, n_2);

    int arr_3[] = {64, 34, 25, 12, 22, 11, 90};
    int n_3 = sizeof(arr_3) / sizeof(arr_3[0]);

    printf("\n == Insertion sort == \n");

    insertionSort(arr_3, n_3);
    printArray(arr_3, n_3);

    int arr_4[] = {64, 34, 25, 12, 22, 11, 90};
    int n_4 = sizeof(arr_4) / sizeof(arr_4[0]);

    printf("\n == Selection sort == \n");

    selectionSort(arr_4, n_4);
    printArray(arr_4, n_4);

    int arr_5[] = {64, 34, 25, 12, 22, 11, 90};
    int n_5 = sizeof(arr_5) / sizeof(arr_5[0]);

    printf("\n == merge sort == \n");

    mergeSort(arr_5, 0, n_5 - 1);
    printArray(arr_5, n_5);

    int arr_6[] = {64, 34, 25, 12, 22, 11, 90};
    int n_6 = sizeof(arr_6) / sizeof(arr_6[0]);

    printf("\n == quick sort == \n");

    quickSort(arr_6, 0, n_6 - 1);
    printArray(arr_6, n_6);
    
    return 0;
}