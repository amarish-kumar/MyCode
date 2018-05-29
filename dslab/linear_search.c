#include <stdio.h>

int linear_search(int arr[], int n, int item)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(arr[i] == item)
			return i;
	}
	return -1;
}

int main()
{
	int i, n, arr[100], item, index;
	printf("Enter the no. of elements: ");
	scanf("%d", &n);

	printf("Enter the elements: ");
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("Enter an item to search: ");
	scanf("%d", &item);

	index = linear_search(arr, n, item);

	if(index == -1)
		printf("Item not found!\n");
	else
		printf("Item found in index: %d\n", index);

	return 0;
}