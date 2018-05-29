#include <stdio.h>
#include <stdlib.h>

int* init_array(int n)
{
	int i;
	int *arr = (int*) malloc(n*sizeof(int)); 
	printf("Enter the elements: \n");
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	return arr;
}

void show(int *arr, int n)
{
	if(n == 0)
	{
		printf("\nThe array is empty.");
		return;
	}
	printf("\nElements in the array are: \n");
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

void insert(int *arr, int &n, int pos, int data)
{
	int i;
	arr = (int*) realloc(arr, (n+1)*sizeof(int));
	for(i = n-1; i >= pos; i--)
		arr[i+1] = arr[i];
	arr[pos] = data;
	n++;
}

void del(int *arr, int &n, int pos)
{
	int i;
	if(n == 0)
	{
		printf("\nNo elements to delete.");
		return;
	}
	for(i = pos; i < n-1; i++)
		arr[i] = arr[i+1];

	arr = (int*) realloc(arr, (n-1)*sizeof(int));
	n--;
}

int main()
{
	int n, *arr;
	int data, pos;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	arr = init_array(n);
	int ch = 0;
	while(ch != 4)
	{
		printf("\n\n\n1. Insert an element.");
		printf("\n2. Delete an element.");
		printf("\n3. Show elements.");
		printf("\n4. Exit.");
		printf("\n\nEnter your choice (1-4): ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: printf("Enter a value and its position: ");
					scanf("%d %d", &data, &pos);
					insert(arr, n, pos, data);
					show(arr, n);
					break;

			case 2: printf("Enter position of the item to delete: ");
					scanf("%d", &pos);
					del(arr, n, pos);
					show(arr, n);
					break;

			case 3: show(arr, n);
					break;

			case 4: break;

			default: printf("Invalid Choice!");
		}
	}
	free(arr);
	return 0;
}