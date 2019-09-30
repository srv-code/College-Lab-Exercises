/**
	Array manipulation – 1
	Input an array of n integers.
	Calculate and display the following:  
		• Minimum and maximum elements in it. 
		• Sum of its elements (use enhanced-for loop). 
	Note: Write separate function for inputting the elements of the array.
*/

import java.util.Scanner;

public class Prg5 {
	private static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
		System.out.print("Enter size of array: ");
		int size = sc.nextInt();
		int[] arr = new int[size];
		getArray(arr);
		
		int min=arr[0], max=arr[0], sum=0;
		
		for(int i=0; i<size; i++) {
			min = Math.min(min, arr[i]);
			max = Math.max(max, arr[i]);
			sum += arr[i];
		}
		
		System.out.println();
		System.out.println("Minimum element: " + min);
		System.out.println("Maximum element: " + max);
		System.out.println("Summation of elements: " + sum);
	}
	
	private static void getArray(int[] arr) {
		for(int i=0; i<arr.length; i++) {
			System.out.print("  Enter element " + (i+1) + ": ");
			arr[i] = sc.nextInt();
		}
	}
}