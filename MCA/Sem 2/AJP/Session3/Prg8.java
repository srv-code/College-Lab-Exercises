/**
	Method overloading – 2
	Input an array of n1 integers and n2 strings.
	Sort each of the arrays using bubble sort method. 
*/

import java.util.Scanner;

public class Prg8 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter size of integer array: ");
		int n1 = sc.nextInt();
		int[] intArr = new int[n1];
		for(int i=0; i<n1; i++) {
			System.out.print("  Enter element " + (i+1) + ": ");
			intArr[i] = sc.nextInt();
		}
		
		System.out.print("\nEnter size of string array: ");
		int n2 = sc.nextInt();
		String[] strArr = new String[n2];
		for(int i=0; i<n2; i++) {
			System.out.print("  Enter element " + (i+1) + ": ");
			strArr[i] = sc.next();
		}
		
		System.out.println("\n\nInteger array before sorting:");
		for(int e : intArr)
			System.out.print(e + "  ");
		
		System.out.println("\n\nString array before sorting:");
		for(String e : strArr)
			System.out.print(e + "  ");
		
		
		System.out.println("\n\nSorting...");
		
		bubbleSort(intArr);
		bubbleSort(strArr);
		
		System.out.println("\n\nInteger array after sorting:");
		for(int e : intArr)
			System.out.print(e + "  ");
		
		System.out.println("\n\nString array after sorting:");
		for(String e : strArr)
			System.out.print(e + "  ");
	}
	
	private static void bubbleSort(int[] arr) {
		for(int i=0, n=arr.length; i<n-1; i++) {
			for(int j=0, temp; j<n-i-1; j++) {
				if(arr[j] > arr[j+1]) {
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
	}
	
	private static void bubbleSort(String[] arr) {
		String temp;
		for(int i=0, n=arr.length; i<n-1; i++) {
			for(int j=0; j<n-i-1; j++) {
				if(arr[j].compareTo(arr[j+1]) > 0) {
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
	}
}