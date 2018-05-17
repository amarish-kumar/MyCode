#include <iostream>
#include <fstream>

using namespace std;

int comp = 0;
int arr[10001];

void qsort(int arr[], int l, int r)
{
	if(l >= r) return;
	comp += (r-l);
	int p = arr[l];
	int i = l+1;
	int j = l+1;
	int temp;	
	
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