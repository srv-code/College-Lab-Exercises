import java.util.Scanner;

/**
 * Create a class called Employee and include data members as empCode 
 * 		(private int), empType (String), empSal (float). Write a method 
 *		called calTax() to calculate the tax paid by the employees: 30% 
 *		for regular employees and 12% for casual employees. In the main 
 *		method create two instances of employees (for each type) and display 
 *		their salary paid in thebelow format:
 *		 	Emp Code		Tax Paid
 *			101				12345.67
 *			102				89123.45
 *			Total Tax Pad:	101469.12
 */ 
 public class Main {
	 public static void main(String[] args) {
		 Scanner sc = new Scanner(System.in);
		 
		 System.out.println("Input regular employee details:");
		 System.out.print  ("  Input emp code:  "); int code = sc.nextInt();
		 System.out.print  ("  Input emp salary:  "); float sal = sc.nextFloat();		 
		 Employee regularEmp = new Employee(code, "Regular", sal);
		 
		 System.out.println("Input casual employee details:");
		 System.out.print  ("  Input emp code:  "); code = sc.nextInt();
		 System.out.print  ("  Input emp salary:  "); sal = sc.nextFloat();		 
		 Employee casualEmp = new Employee(code, "Casual", sal);
		 
		 float totalTax;
		 System.out.println("\nEmp Code \t\t Tax Paid");
		 totalTax = regularEmp.calTax();
		 System.out.printf ("%d \t\t\t %.2f \n", regularEmp.getEmpCode(), totalTax);
		 totalTax += casualEmp.calTax();
		 System.out.printf ("%d \t\t\t %.2f \n", casualEmp.getEmpCode(), casualEmp.calTax());
		 System.out.printf ("Total Tax Paid: \t %.2f \n", totalTax);
	 }
 }
 
 class Employee {
	private int empCode;
	String empType;
	float empSal;
	
	Employee(int code, String type, float sal) {
		empCode = code;
		empType = type;
		empSal = sal;
	}
	
	int getEmpCode() {
		return empCode;
	}
	
	float calTax() {
		if(empType.equals("Regular"))		return empSal*0.3f;
		else if(empType.equals("Casual"))	return empSal*0.12f;
		return 0.0f;
	}
 }