public class InsertionSort
{
	public static void insertionSort(int[] arr, int n) {

		int item, ptr;

		for(int i = 2; i < n+1; i++)
		{
			item = arr[i];
			ptr = i - 1;

			while(item < arr[ptr])
			{
				arr[ptr+1] = arr[ptr];
				ptr--;
			}
			
			arr[ptr+1] = item;
		}
	}
};