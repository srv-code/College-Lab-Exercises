/**	Input a string 's' from user and an array of double type from the 
		command line.
	Show the count of special characters in the string.
	Show the minimum and maximum elements in the double array.
	Use methods for counting the special characters in string 
		and getting the maximum and minimum values in the array.
*/

import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Input a string:  ");
		String s = sc.next();

		System.out.println("Count of special characters:  " + countSpecialChars(s));

		double[] arr = new double[args.length];

		for(int i=0; i<args.length; i++) {
			arr[i] = Double.parseDouble(args[i]);
		}

		System.out.println("Min element in double array: " + getMin(arr));
		System.out.println("Max element in double array: " + getMax(arr));
	}

	private static double getMin(double[] arr) {
		double min = arr[0];
		for(double d : arr) 
			min = Math.min(d, min);
		return min;
	}

	private static double getMax(double[] arr) {
		double max = arr[0];
		for(double d : arr) 
			max = Math.max(d, max);
		return max;
	}

	private static int countSpecialChars(String s) {
		int count = 0;
		for(int i=0; i<s.length(); i++) {
			if(!Character.isLetter(s.charAt(i)) && !Character.isDigit(s.charAt(i))) 
				count++;
		}
		return count;
	}
}