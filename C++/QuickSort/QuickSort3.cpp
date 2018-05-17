#include <iostream>
#include <fstream>

using namespace std;

int comp = 0;
int arr[10001];

int median_pivot(int l, int r)
{
	int center, temp;
	int len = r-l+1;
	if(len == 2) return arr[l];

	if(len%2 == 0)
		center = l+len/2-1;
	else
		center = l+len/2;

	if(arr[l] > arr[center] && arr[r] < arr[center] || arr[l] < arr[center] && arr[r] > arr[center])
	{
		temp = arr[center];
		arr[center] = arr[l];
		arr[l] = temp;
	}
	else if(arr[center] > arr[l] && arr[r] < arr[l] || arr[center] < arr[l] && arr[r] > arr[l])
	{
		//Do nothing if arr[l] is the pivot
	}
	else
	{
		temp = arr[r];
		arr[r] = arr[l];
		arr[l] = temp;
	}

	return arr[l];
}

void qsort(int arr[], int l, int r)
{
	if(l >= r) return;
	comp += (r-l);
	int temp;	
	int p = median_pivot(l,r);
	int i = l+1;
	int j = l+1;
	
	while(j <= r)
	{
		if(arr[j] < p)
		{
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			i++;
		}
		j++;
	}
	temp = arr[i-1];
	arr[i-1] = arr[l];
	arr[l] = temp;
    
    qsort(arr, l, i-2);
    qsort(arr, i, r);
}

int main()
{
	int i = 0;
	fstream ptr;
	ptr.open("QuickSort.txt");

	while(!ptr.eof())
		ptr >> arr[i++];

	qsort(arr, 0, 9999);

	cout << "No. of comparisions: " << comp;

	//for(int j = 0; j < i-1; j++)
	//	cout << arr[j] << endl;
	return 0;
}