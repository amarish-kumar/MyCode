import java.util.Scanner;

public class Test2 extends InsertionSort
{
	
	public static void main(String[] args) {

		Scanner mm = new Scanner(System.in);
		int i, n;

		System.out.print("Enter the number of elements of the array: ");
		n = mm.nextInt();
		int[] arr = new int[n+1];
		System.out.println("Enter the elements of the array: ");
		
		for(i = 1; i < n+1; i++)
		{
			arr[i] = mm.nextInt();
		}

		arr[0] = 0;

		insertionSort(arr, n);
	
		System.out.println("The array after sorting is: ");
		for(i = 1; i < n+1; i++)
		{
			System.out.println(arr[i]);
		}

	}
};
			