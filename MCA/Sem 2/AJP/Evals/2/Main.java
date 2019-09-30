/**	Input an integer 'n' from the user and input n strings in 
	a string array 'strArr'. Input two more strings from the user S1 and S2. 
	Show the strings from the array which start with S1 and not end with S2.
	Write separate methods to input the array called 'getArray()' 
		and to inspect the string called 'stringCheck()'. These 
		methods should not be static and should be in a different class.
*/


import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Input an integer n:  ");
		int n = sc.nextInt();
		String[] strArr = new String[n];
		StringChecker schk = new StringChecker();
		schk.getArray(strArr);
		System.out.print("Input two strings S1 and S2:  ");
		String S1 = sc.next(), S2 = sc.next();
		System.out.println("Strings starting with S1 and not ending with S2:");
		for(String s : strArr) {
			if(schk.stringCheck(s, S1, S2))
				System.out.println(s);
		}
	}
}

class StringChecker {
	public void getArray(String[] strArr) {
		Scanner sc = new Scanner(System.in);
		int len = strArr.length;
		System.out.println("Input " + len + " strings in strArr:");
		for(int i=0; i<len; i++) {
			System.out.print("  Enter string " + (i+1) + ": ");
			strArr[i] = sc.next();
		}
	}

	public boolean stringCheck(String tgt, String s1, String s2) {
		return tgt.startsWith(s1) && !tgt.endsWith(s2);
	}
}