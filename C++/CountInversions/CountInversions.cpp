#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

const int SIZE = 100000;

long long int merge(int *arr, int left, int mid, int right)
{
	long long int inv_count = 0;
	int i, j, k;
	i = left;
	j = mid+1;
	k = 0;

	int temp[right-left+1];

	while(i <= mid && j <= right)
	{
		if(arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
			inv_count += (mid - i + 1);
		}
	}

	while(i <= mid)
		temp[k++] = arr[i++];
	while(j <= right)
		temp[k++] = arr[j++];

	k = 0;

	for(i = left; i <= right; i++)
		arr[i] = temp[k++];

	return inv_count;
}

long long int merge_count(int *arr, int left, int right)
{
	int mid; 
	long long int inv_count = 0;
	if(left < right)
	{
		mid = (left + right)/2;

		inv_count = merge_count(arr, left, mid);
		inv_count += merge_count(arr, mid+1, right);

		inv_count += merge(arr, left, mid, right);
	}
	return inv_count;
}

int main() 
{
	int i = 0;
	int arr[SIZE];
	fstream ptr;
	ptr.open("IntegerArray.txt");
	while(!ptr.eof())
	{
		ptr >> arr[i++];
	}
	cout << "No. of inversions: " << merge_count(arr, 0, SIZE - 1);
	getch();
	return 0;
}