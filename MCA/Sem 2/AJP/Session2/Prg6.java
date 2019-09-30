/**
	Array manipulation – 2
	Input an array of n integers.
	Reverse all elements of the array and store them in another array.
	Display the original and reversed integers in two columns.
	Note: Write separate functions for reversing an integer. 
*/

import java.util.Scanner;

public class Prg6 {
	private static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {	
		System.out.print("Enter size of array: ");
		int n = sc.nextInt();
		int[] orgArr = new int[n];
		int[] revArr = new int[n];
		getArray(orgArr);
		
		for(int i=0; i<n; i++)
			revArr[i]=reverse(orgArr[i]);
		
		System.out.println("\nOriginal \t Reversed");
		for(int i=0; i<n; i++)
			System.out.printf("%8d \t %8d \n", orgArr[i], revArr[i]);
	}
	
	private static int reverse(int n) {
		int rev=0;
		boolean wasNeg = false;
		if(n < 0) {
			wasNeg = true;
			n = -n;
		}
		
		while(n > 0) {
			rev = rev*10 + n%10;
			n /= 10;
		}
		
		return wasNeg ? -rev : rev;
	}
	
	private static void getArray(int[] arr) {
		for(int i=0; i<arr.length; i++) {
			System.out.print("  Enter element " + (i+1) + ": ");
			arr[i] = sc.nextInt();
		}
	}
}