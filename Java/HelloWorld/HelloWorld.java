import java.util.Scanner;

public class HelloWorld{

	public static void main(String[] args){

		String pass = "helloworld";
		String word;
		System.out.println("Hello, World!");
		System.out.print("What is your name: ");
		Scanner mm = new Scanner(System.in);
		String name = mm.next();
		System.out.println("\nWelcome, " + name);
		do{
			System.out.print("\nEnter your password: ");
			word = mm.next();
			if(!pass.equals(word)){
				System.out.println("Access Denied!");
			}
		}while(!pass.equals(word));
		System.out.println("Access Granted.");
			
	}
};