#include <stdio.h>

int upper_bound(const int nums[], size_t size, int val) {
	int output = 0;

	for(int i = 0; i < size; i++) {
		if(nums[i] <= val)  output++;
        else  return output;
	}

	return output;
}

int main() {
    int nums[] = {4, 6, 6, 6, 6, 10, 12, 18, 20};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("array contains: ");

    for(int i = 0; i < n; i++)  printf("%d ", nums[i]);

    printf("\n");

    printf("upper_bound for element %d is at position %d \n", 2, upper_bound(nums, n, 2));
    printf("upper_bound for element %d is at position %d \n", 5, upper_bound(nums, n, 5));
    printf("upper_bound for element %d is at position %d \n", 6, upper_bound(nums, n, 6));
    printf("upper_bound for element %d is at position %d \n", 19, upper_bound(nums, n, 19));
    printf("upper_bound for element %d is at position %d \n", 20, upper_bound(nums, n, 20));
    printf("upper_bound for element %d is at position %d \n", 21, upper_bound(nums, n, 21));

    return 0;
}