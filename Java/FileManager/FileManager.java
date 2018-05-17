import java.util.Scanner;
import java.io.*;

public class FileManager extends Student {

	public FileManager() {
		try {
			String ch = "y";
			File outFile = new File("Database.ser");
			FileOutputStream fo = new FileOutputStream(outFile);
			ObjectOutputStream s = new ObjectOutputStream(fo);
			Student obj = new Student();

			while(ch.equals("y")) {
				Scanner mm = new Scanner(System.in);
				obj.userInput();
				s.writeObject(obj);
				s.flush();
				System.out.print("Add more data?(y/n): ");
				ch = mm.next();
			}
		}
		catch(IOException io) {
			System.out.println("IOException, io= " + io);
		}
	}

	public static void main(String[] args) { 
		FileManager f = new FileManager();
	}
};
		