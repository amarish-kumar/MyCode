#include <stdio.h>

int binary_search(int arr[], int n, int item)
{
	int low, high, mid;
	low = 0;
	high = n-1;

	while(low <= high)
	{
		mid = (low + high)/2;

		if(arr[mid] == item)
			return mid;
		else if(arr[mid] > item)
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}

int main()
{
	int i, n, arr[100], item, index;
	printf("Enter the no. of elements: ");
	scanf("%d", &n);

	printf("Enter the elements in sorted order: ");
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("Enter an item to search: ");
	scanf("%d", &item);

	index = binary_search(arr, n, item);

	if(index == -1)
		printf("Item not found!\n");
	else
		printf("Item found in index: %d\n", index);

	return 0;
}