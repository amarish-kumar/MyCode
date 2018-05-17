package SwingTest2;

import javax.swing.JOptionPane;

public class SwingTest2 {
	public static void main(String[] args) {
		String firstNum, secondNum;
		int num1, num2, sum;

		firstNum = JOptionPane.showInputDialog("Enter First Number:");
		secondNum = JOptionPane.showInputDialog("Enter Second Number:");

		num1 = Integer.parseInt(firstNum);
		num2 = Integer.parseInt(secondNum);

		sum = num1 + num2;

		JOptionPane.showMessageDialog(null, "The sum is: " + sum, "Results", JOptionPane.PLAIN_MESSAGE);
		System.exit(0);
	}
};