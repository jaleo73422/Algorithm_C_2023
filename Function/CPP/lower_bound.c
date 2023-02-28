#include <stdio.h>

int lower_bound(const int nums[], size_t size, int val) {
	int output = 0;

	for(int i = 0; i < size; i++) {
		if(nums[i] < val)  output++;
		else  return output;
	}

	return output;
}

int main() {
    int nums[] = {4, 6, 6, 6, 6, 10, 12, 18, 20};
	int nums_2[] = {1, 2, 3, 6, 6, 6, 7};
    int n = sizeof(nums) / sizeof(nums[0]);
	int n_2 = sizeof(nums_2) / sizeof(nums_2[0]);

	printf("array contains: ");

    for(int i = 0; i < n; i++)  printf("%d ", nums[i]);

	printf("\n");

    printf("lower_bound for element %d is at position %d \n", 2, lower_bound(nums, n, 2));
    printf("lower_bound for element %d is at position %d \n", 5, lower_bound(nums, n, 5));
	printf("lower_bound for element %d is at position %d \n", 6, lower_bound(nums, n, 6));
    printf("lower_bound for element %d is at position %d \n", 19, lower_bound(nums, n, 19));
    printf("lower_bound for element %d is at position %d \n", 20, lower_bound(nums, n, 20));
	printf("lower_bound for element %d is at position %d \n", 21, lower_bound(nums, n, 21));

	printf("\n");
	printf("array contains: ");

    for(int i = 0; i < n_2; i++)  printf("%d ", nums_2[i]);

	printf("\n");

    printf("lower_bound for element %d is at position %d \n", 5, lower_bound(nums_2, n_2, 5));

    return 0;
}