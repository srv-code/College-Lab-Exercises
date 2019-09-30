/**
 * Command Line Arguments (String data)
 * Input a string from the command line.
 * Find its length. Count the number of alphabets, digits and other characters in it.
*/

public class Prg1 {
	public static void main(String[] args) {
		String sample = args[0];
		int len = sample.length();
		System.out.println("Length=" + len);
		int alphaCount=0, digitCount=0, otherCount=0;
		char c;
		for(int i=0; i<len; i++) {
			c = sample.charAt(i);
			if(Character.isLetter(c)) alphaCount++;
			else if(Character.isDigit(c)) digitCount++;
			else otherCount++;
		}
		
		System.out.println("Alphabets=" + alphaCount);
		System.out.println("Digits=" + digitCount);
		System.out.println("Others=" + otherCount);
	}
}