import java.lang.Thread;

public class MultiThreadDemo extends Thread {
	public MultiThreadDemo(String tname) {
		super(tname);
		System.out.println("MultiThreadDemo Constructor invoked");
		}
		public void run() {
			System.out.println(Thread.currentThread() + " in run!");
		}

	public static void main(String[] args) {
		MultiThreadDemo t1 = new MultiThreadDemo("Griffindor");
		t1.start();
		MultiThreadDemo t2 = new MultiThreadDemo("Ravenclaw");
		t2.start();
		MultiThreadDemo t3 = new MultiThreadDemo("Huffulpuff");
		t3.start();
		MultiThreadDemo t4 = new MultiThreadDemo("Slytherin");
		t4.start();
	}
};