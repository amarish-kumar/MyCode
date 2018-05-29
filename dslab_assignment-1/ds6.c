#include <stdio.h>

int main()
{
	int n, k;
	printf("Enter the no. of elements (n): ");
	scanf("%d", &n);
	printf("Enter max appearing number k (<= n): ");
	scanf("%d", &k);

	int arr[n], i;
	int cnt[k] = {0};

	printf("Enter elements of the array: ");
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for(i = 0; i < n; i++)
		cnt[arr[i]]++;

	int max_cnt = cnt[0];
	int max_index = 0;
	for(i = 1; i < n; i++)
		if(max_cnt < cnt[i])
		{
			max_cnt = cnt[i];
			max_index = i;
		}

	printf("The no. with maximum frequency is: %d", max_index);
	return 0;
}