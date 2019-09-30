/**
 * Command Line Arguments (Numeric data) - 1 
 * Input an integer from the command line. 
 * Check whether it is odd or even. 
 * Find and display the sum of its digits. 
*/

class Prg2 {
	public static void main(String[] args) {
		int sample = Integer.parseInt(args[0]);
		System.out.println("Nature: " + (sample%2==0?"Even":"Odd") );
		
		sample = sample < 0 ? -sample : sample;
		
		int sum=0;
		while(sample>0) {
			sum += sample%10;
			sample = sample/10;
		}
		
		System.out.println("Summation of its digits: " + sum);
	}
}