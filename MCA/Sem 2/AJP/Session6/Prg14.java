/**
	Exception handling:
	Create a try block that is likely to generate Number Format and Arithmetic
	exceptions and incorporate necessary catch blocks to catch and handle them
	appropriately. Use these exceptions to count the number of strings and
	integers entered through the command line. Also, use an exception to
	demonstrate user-defined exception (entered number is negative).
*/

public class Prg14 {
	public static void main(String[] args) {
		int intCount=0, stringCount=0, totalCount=0;
		for(int i=0; i<args.length; i++) {
			try {
				int num = Integer.parseInt(args[i]);
				System.out.println("Argument " + (i+1) + " is an integer: " + num);
				intCount++;
				
				if(num < 0)
					throw new NegativeNumberException(num);
				double q = 5/num;
			} catch(NumberFormatException e) {
				System.out.println("Argument " + (i+1) + " is a string: " + args[i]);
				System.out.println(e);
				stringCount++;
			} catch(ArithmeticException e) {
				System.out.println("Arithmetic error: Division by zero");
				System.out.println(e);
			} catch(NegativeNumberException e) {
				System.out.println("Negative input number: " + args[i]);
				System.out.println(e);
			} finally {
				totalCount++;
				System.out.println();
			}
		}
		
		System.out.println("Total integer arguments: " + intCount);
		System.out.println("Total string arguments:  " + stringCount);
		System.out.println("Total arguments:         " + totalCount);		
	}
}

class NegativeNumberException extends Exception {
	NegativeNumberException(int n) {
		super("Negative number: " + n);
	}
}