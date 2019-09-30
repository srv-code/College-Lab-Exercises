/**
	String manipulation – 3
	Input two strings (S1 and S2) and two integers (N1 and N2). Perform the
	following string operations.
		• Display the upper-case equivalent of S1.
		• Display the lower-case equivalent of S2.
		• Extract a substring of length N2 from S1 starting at position N1.
		• Insert S2 into S1 at position N1.
		• Append S2 to S1.
	Note: Write separate functions for the last two cases.
*/

import java.util.Scanner;


public class Prg11 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Input two strings S1 & S2:  ");
		String S1 = sc.next(), S2 = sc.next();		
		System.out.print("Input two integers N1 & N2:  ");
		int N1 = sc.nextInt(), N2 = sc.nextInt();
		
		System.out.println("Upper-case equivalent:  " + S1.toUpperCase());
		System.out.println("Lower-case equivalent:  " + S2.toLowerCase());
		System.out.println("Substring:  " + S1.substring(N1, N1+N2));
		System.out.println("Inserted S2 into S1 at position N1:  " + insert(S2, S1, N1));
		System.out.println("Appended S2 to S1:  " + append(S2, S1));
	}
	
	/** Insert S2 into S1 at position N1. */
	private static String insert(String S2, String S1, int N1) {
		StringBuffer sb = new StringBuffer(S1);
		sb.insert(N1, S2);
		return sb.toString();
	}
	
	/** Append S2 to S1. */
	private static String append(String S2, String S1) {
		StringBuffer sb = new StringBuffer(S1);
		sb.append(S2);
		return sb.toString();
	}
}