/** 
 * User inputs (Numeric data) 
 * Input two integers, n and r.
 * 		Evaluate nCr = n! / (r! * (n-r)!).
 * 		Find the GCD and LCM of these two integers.
 * Note: Write separate functions for calculating factorial and GCD.
 */
 
 import java.util.Scanner;
 
 class Prg4 {
	 public static void main(String[] args) {
		 Scanner sc = new Scanner(System.in);
		 System.out.print("Input n:  ");
		 int n = sc.nextInt();
		 System.out.print("Input r:  ");
		 int r = sc.nextInt();
		 System.out.println(n+"C"+r+": "+ nCr(n,r));
		 int gcd = getGcd(n,r);		 
		 System.out.println("GCD of " + n + " and " + r + ": " + gcd);
		 int lcm = (n*r)/gcd;
		 System.out.println("LCM of " + n + " and " + r + ": " + lcm);
	 }
	 
	 private static int getGcd(int a, int b) {
		 int rem;
		 while(b>0) {
			 rem=a%b;
			 a=b;
			 b=rem;
		 }
		 return a;
	 }
	 
	 private static int nCr(int n, int r) {
		 return fact(n) / (fact(r) * fact(n-r));
	 }
	 
	 private static int fact(int n) {
		 int fact=n;
		 while(n > 1)
			 fact *= --n;
		 return fact;
	 }
 }