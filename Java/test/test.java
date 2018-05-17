import java.util.Scanner;

class Test
{
	public static void main(String[] args) {

		Scanner mm = new Scanner(System.in);
		int sum = 0;
		int digit;

		System.out.println("This program adds digits of a number.");
		System.out.print("\nEnter a number: ");
		int val = mm.nextInt();
		
		while(val != 0)
		{
			digit = val % 10;
			sum = sum + digit;
			val = val / 10;
		}
		
		System.out.println("The sum of the digits is: " + sum);
	}
};
		