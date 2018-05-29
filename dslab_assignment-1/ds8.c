#include <stdio.h>
#include <stdlib.h>

int* intersection(int* a, int* b, int n1, int n2, int &n)
{
	int i, j, k = 0;
	int *common = (int*) malloc((n1+n2)*sizeof(int));
	for(i = 0; i < n1; i++)
	{
		if(i != 0 && a[i] == a[i-1])
			continue;

		for(j = 0; b[j] <= a[i]; j++)
			if(a[i] == b[j])
			{
				common[k++] = a[i];
				break;
			}
	}
	n = k;
	return common;
}

int main()
{
	int n1, n2, n3, i;
	printf("Enter no. of elements in array 1, 2 and 3: ");
	scanf("%d %d %d", &n1, &n2, &n3);

	int arr1[n1], arr2[n2], arr3[n3];

	printf("Enter the elements in array-1 in sorted order: \n");
	for(i = 0; i < n1; i++)
		scanf("%d", &arr1[i]);

	printf("Enter the elements in array-2 in sorted order: \n");
	for(i = 0; i < n2; i++)
		scanf("%d", &arr2[i]);

	printf("Enter the elements in array-3 in sorted order: \n");
	for(i = 0; i < n3; i++)
		scanf("%d", &arr3[i]);

	int n;
	int *arr = intersection(arr1, arr2, n1, n2, n);
	arr = intersection(arr, arr3, n, n3, n);

	printf("\nCommon elements in all 3 arrays are: \n");
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);

	free(arr);
	return 0;
}