/** 
	String manipulation – 1
	Input a string. Reverse it. Check whether it is a palindrome or not.
	Note: Write a separate function for reversing the string
*/

import java.util.Scanner;


public class Prg9 {
	public static void main(String[] args) {		
		Scanner sc = new Scanner(System.in);
		System.out.print("Input string:  ");
		String orgStr = sc.next();
		String revStr = reverse(orgStr);
		
		System.out.print("String '" + orgStr + "' is ");
		if(!orgStr.equals(revStr)) 
			System.out.print("not ");
		System.out.println("palindrome.");
	}
	
	private static String reverse(String str) {
		return new StringBuffer(str).reverse().toString();
	}
}