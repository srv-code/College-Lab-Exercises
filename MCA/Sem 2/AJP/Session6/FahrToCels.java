/**
	Packages:
	Create a class that performs conversion of temperatures – from Celsius to
	Fahrenheit and vice versa. Include the following two packages:
		• CToF with a class CelsToFahr containing a method called ConvertCToF (double C)
		• FToC with a class FahrToCels containing a method called ConvertFToC (double F).
	Use a menu to select the type of conversion, input the relevant data, calculate
	and display the result.
*/

package FToC;


public class FahrToCels {
	public double ConvertFToC(double fahrenheitValue) {
		return (fahrenheitValue-32) * (5.0/9.0);
	}
}
