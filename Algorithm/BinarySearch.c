#include <stdio.h>

// Iterative method
int binarySearch(int* num, int n, int target) {
    int l = 0;
    int r = n - 1;
    int mid;

    while(l <= r) {
        // mid = l + (r - l) / 2;
        mid = (l + r) / 2;
        
        if (num[mid] == target) {
            return mid;
        }

        if (num[mid] < target) {
            l = mid + 1;
        }

        if (num[mid] > target) {
            r = mid - 1;
        }
    }
    
    return -1;
}

// Recursive method
int binarySearch_2(int* num, int n, int target, int l, int r) {
    int mid;

    while(l <= r) {
        // mid = l + (r - l) / 2;
        mid = (l + r) / 2;

        if (num[mid] == target) {
            return mid;
        }

        if (num[mid] < target) {
            return binarySearch_2(num, n, target, mid + 1, r);
        }

        if (num[mid] > target) {
            return binarySearch_2(num, n, target, l, mid - 1);
        }
    }
    
    return -1;
}

int main() {
    int nums[] = {2, 3, 4, 10, 40};
    int n = sizeof(nums) / sizeof(nums[0]);
    // int target = 2;
    // int target = 4;
    int target = 40;

	int result = binarySearch(nums, n, target);

	result == -1
		? printf("Element is not present in array. \n")
		: printf("Element is present at index %d. \n", result);

    int result_2 = binarySearch_2(nums, n, target, 0, n - 1);

	result_2 == -1
		? printf("Element is not present in array \n")
		: printf("Element is present at index %d \n", result_2);
    
    // int result_3 = binarySearch(nums, n, target);

	// result_3 == -1
	// 	? printf("Element is not present in array")
	// 	: printf("Element is present at index %d", result_3);

    return 0;
}