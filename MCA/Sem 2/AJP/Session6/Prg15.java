/**
	Packages:
	Create a class that performs conversion of temperatures – from Celsius to
	Fahrenheit and vice versa. Include the following two packages:
		• CToF with a class CelsToFahr containing a method called ConvertCToF (double C)
		• FToC with a class FahrToCels containing a method called ConvertFToC (double F).
	Use a menu to select the type of conversion, input the relevant data, calculate
	and display the result.
*/

import CToF.CelsToFahr;
import FToC.FahrToCels;
import java.util.Scanner;


class Prg15 {
	public static void main(String[] args) {
		while(true) {
			System.out.println("Choose the type of temperature conversion:");
			System.out.println("  1  Celsius to Fahrenheit");
			System.out.println("  2  Fahrenheit to Celsius");
			System.out.println("  3  Exit");
			System.out.print  ("Enter choice:  ");
			Scanner sc = new Scanner(System.in);
			
			switch(sc.nextInt()) {
				case 1: // C to F
					System.out.print("Enter temperature in celsius:  ");
					System.out.printf("Temperature in fahrenheit:  %.2f \n", new CelsToFahr().ConvertCToF(sc.nextDouble()));
					break;
				
				case 2: // F to C
					System.out.print("Enter temperature in fahrenheit:  ");
					System.out.printf("Temperature in celsius:  %.2f \n", new FahrToCels().ConvertFToC(sc.nextDouble()));
					break;
					
				case 3: 
					System.exit(0);
				
				default: 
					System.err.println("Invalid choice!");
			}
			System.out.println();
		}
	}
}