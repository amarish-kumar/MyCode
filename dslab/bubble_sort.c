#include <stdio.h>

void bubble_sort(int *arr, int n)
{
	int i, j, temp;
	for(i = 0; i < n-1; i++)
	{
		for(j = 0; j < n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
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

	bubble_sort(arr, n);

	printf("The sorted array is: \n");
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}