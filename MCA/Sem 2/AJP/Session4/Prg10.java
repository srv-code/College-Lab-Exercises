/** 
	String manipulation – 2
	Input a string. Rearrange the characters in it in alphabetic order (E.g.,
	COMPUTER should be written in the form of CEMOPRTU).
	Rearranging should be done for the two cases:
		• Considering the upper/lower case of alphabets
		• Without considering the upper/lower case of alphabets
	Note: Write separate functions for the two cases
*/

import java.util.Scanner;


public class Prg10 {
	public static void main(String[] args) {		
		Scanner sc = new Scanner(System.in);
		System.out.print("Input string:  ");
		String str = sc.next();
		System.out.println("Rearrangement considering case: " + rearrangeCaseSensitively(str));
		System.out.println("Rearrangement without considering case: " + rearrangeCaseInsensitively(str));
	}
	
	private static String rearrangeCaseSensitively(String str) {
		/*
		char[] chars = str.toCharArray();		
		char key;
		for(int i=1, j; i<chars.length; i++) {
			key = chars[i];
			for(j=i-1; j>=0; j--) {
				if(key < chars[j])
					chars[j+1]=chars[j];
				else
					break;
			}
			chars[j+1]=key;
		}
		return new String(chars);
		*/
		
		StringBuffer sb = new StringBuffer(str);
		char key;
		for(int i=1, j; i<sb.length(); i++) {
			key = sb.charAt(i);
			for(j=i-1; j>=0; j--) {
				if(key < sb.charAt(j))
					sb.setCharAt(j+1, sb.charAt(j));
				else
					break;
			}
			sb.setCharAt(j+1, key);
		}
		return sb.toString();
	}
	
	private static String rearrangeCaseInsensitively(String str) {
		/*
		char[] chars = str.toCharArray();		
		char key;
		for(int i=1, j; i<chars.length; i++) {
			key = chars[i];
			for(j=i-1; j>=0; j--) {
				if(Character.toUpperCase(key) < Character.toUpperCase(chars[j]))
					chars[j+1]=chars[j];
				else
					break;
			}
			chars[j+1]=key;
		}
		return new String(chars);
		*/
		
		StringBuffer sb = new StringBuffer(str);
		char key;
		for(int i=1, j; i<sb.length(); i++) {
			key = sb.charAt(i);
			for(j=i-1; j>=0; j--) {
				if(Character.toLowerCase(key) < Character.toLowerCase(sb.charAt(j)))
					sb.setCharAt(j+1, sb.charAt(j));
				else
					break;
			}
			sb.setCharAt(j+1, key);
		}
		return sb.toString();
	}
}