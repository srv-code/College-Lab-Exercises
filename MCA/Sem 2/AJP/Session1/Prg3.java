/**
 * Command Line Arguments (Numeric data) - 2 
 * Input a floating-point number from the command line. 
 * For this number, display the following: 
 * 		Absolute value
 * 		Square root
 * 		Cube root
 *		Square
 *		Next integer
 *		Previous integer
 *		Nearest integer
 */
 
 class Prg3 {
	 public static void main(String[] args) {
		float sample = Float.parseFloat(args[0]);
		System.out.println("Absolute value: " + Math.abs(sample));
		System.out.println("Square root value: " + Math.sqrt(sample));
		System.out.println("Cube root value: " + Math.cbrt(sample));
		System.out.println("Square value: " + Math.pow(sample, 2));
		System.out.println("Next integer value: " + (int)Math.ceil(sample));
		System.out.println("Previous integer value: " + (int)Math.floor(sample));
		System.out.println("Nearest integer value: " + (int)Math.round(sample));
	 }
 }