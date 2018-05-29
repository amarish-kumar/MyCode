#include <stdio.h>

void insertion_sort(int *arr, int n)
{
	int i, j, item;
	for(i = 1; i < n; i++)
	{
		item = arr[i];
		j = i-1;

		while(j > -1 && arr[j] > item)
		{
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = item;
	}
}

int main()
{
	int i, n, arr[100];
	printf("Enter the no. of elements: ");
	scanf("%d", &n);

	printf("Enter the elements: ");
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	insertion_sort(arr, n);

	printf("The sorted array is: \n");
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}