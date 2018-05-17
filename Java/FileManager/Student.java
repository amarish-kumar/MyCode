import java.util.Scanner;
import java.io.*;

public class Student implements Serializable {
	private int roll;
	private String sName;
	private String fName;
	private double marks;
	
	public void userInput() {
		Scanner mm = new Scanner(System.in);
		System.out.print("Enter roll: ");
		roll = mm.nextInt();
		System.out.print("Enter Student Name: ");
		sName = getInput();
		System.out.print("Enter Father's Name: ");
		fName = getInput();
		System.out.print("Enter marks: ");
		marks = mm.nextDouble();
	}

	private static String getInput() {
		Scanner scanner = new Scanner(System.in);
		return scanner.nextLine();
	}
};