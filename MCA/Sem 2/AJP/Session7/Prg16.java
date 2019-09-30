import java.util.Scanner;


/** 
	16. Multithreading
		Input an integer n. Calculate and display the squares and cubes of all integers
			from 1 to n using two different threads.
*/
public class Prg16 {
	public static void main(String[] args) throws InterruptedException {
		Scanner sc = new Scanner(System.in);
		System.out.print("Input integer n:  ");
		int n = sc.nextInt();
		
		SquareCalculator sqrCalc = new SquareCalculator(n);
		CubeCalculator cubeCalc = new CubeCalculator(n);
		
		sqrCalc.thread.join();
		cubeCalc.join();
	}
}

class SquareCalculator
	implements Runnable 
{
	Thread thread;
	int num;
	
	SquareCalculator(int n) {
		thread = new Thread(this);
		num = n;
		thread.start();
	}
	
	public void run() {
		for(int i=1; i<=num; i++)
			System.out.println("Square of " + i + " = " + (i*i));
	}	
}

class CubeCalculator 
	extends Thread 
{
	int num;
	
	CubeCalculator(int n) {
		num = n;
		start();
	}
	
	public void run() {
		for(int i=1; i<=num; i++)
			System.out.println("Cube of " + i + " = " + (i*i*i));
	}
}