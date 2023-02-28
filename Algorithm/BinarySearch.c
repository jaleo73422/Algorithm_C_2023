#include <stdio.h>

// Iterative method
int binarySearch(int* num, int n, int target) {
    int l = 0;
    int r = n - 1;
    int mid;

    while(l <= r) {
        // mid = l + (r - l) / 2;
        mid = (l + r) / 2;
        
        if (num[mid] == target)  return mid;

        if (num[mid] < target)  l = mid + 1;

        if (num[mid] > target)  r = mid - 1;
    }
    
    return -1;
}

// Recursive method
int binarySearch_2(int* num, int n, int target, int l, int r) {
    int mid;

    while(l <= r) {
        // mid = l + (r - l) / 2;
        mid = (l + r) / 2;

        if (num[mid] == target)  return mid;

        if (num[mid] < target)
            return binarySearch_2(num, n, target, mid + 1, r);

        if (num[mid] > target)
            return binarySearch_2(num, n, target, l, mid - 1);
    }
    
    return -1;
}

int main() {
    int nums[] = {2, 3, 4, 10, 40};
    int n = sizeof(nums) / sizeof(nums[0]);
    // int target = 1;
    int target = 2;
    // int target = 4;
    // int target = 12;
    // int target = 40;
    // int target = 42;

	int result = binarySearch(nums, n, target);
    int result_2 = binarySearch_2(nums, n, target, 0, n - 1);

    printf("array contains: ");

    for(int i = 0; i < n; i++)  printf("%d ", nums[i]);

    printf("\n");

	result == -1
		? printf("Element %d is not present in array. \n", target)
		: printf("Element %d is present at index %d. \n", target, result);

	result_2 == -1
		? printf("Element %d is not present in array. \n", target)
		: printf("Element %d is present at index %d. \n", target, result_2);

    return 0;
}