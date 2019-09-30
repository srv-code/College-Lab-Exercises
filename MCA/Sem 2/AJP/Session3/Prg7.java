/**
	Method overloading – 1 
	Input the coordinates (integer values) of three points P1, P2 and P3 in a plane.
		• Calculate and the distance between P1 and P2 (by passing the coordinates of one point as arguments).
		• Calculate and the distance between P1 and P3 (by passing one point itself as argument).
*/

import java.util.Scanner;


public class Prg7 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter x and y for point P1:  ");
		Point p1 = new Point(sc.nextInt(), sc.nextInt());
		
		System.out.print("Enter x and y for point P2:  ");
		Point p2 = new Point(sc.nextInt(), sc.nextInt());
		
		System.out.print("Enter x and y for point P3:  ");
		Point p3 = new Point(sc.nextInt(), sc.nextInt());
		
		System.out.println("Distance between points P1 & P2:  " + p1.calcDist(p2.x, p2.y));
		System.out.println("Distance between points P1 & P3:  " + p1.calcDist(p3));
	}
}

class Point {
	int x, y;
	
	Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	double calcDist(int x, int y) {
		return Math.sqrt( Math.pow(x-this.x, 2) + Math.pow(y-this.y, 2) );
	}
	
	double calcDist(Point p) {
		return Math.sqrt( Math.pow(p.x-this.x, 2) + Math.pow(p.y-this.y, 2) );
	}
}