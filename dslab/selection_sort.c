#include <stdio.h>

void selection_sort(int *arr, int n)
{
	int i, j, item, min;
	for(i = 0; i < n-1; i++)
	{
		item = arr[i];
		min = i+1;
		for(j = i+1; j < n; j++)
		{
			if(arr[j] < arr[min])
				min = j;
		}
		if(item > arr[min])
		{
			arr[i] = arr[min];
			arr[min] = item;
		}
	}
}

int main()
{
	int arr[100], n, i;
	printf("Enter number of elements: ");
	scanf("%d", &n);

	printf("Enter the elements: \n");
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	selection_sort(arr, n);

	printf("Sorted elements are: \n");
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}