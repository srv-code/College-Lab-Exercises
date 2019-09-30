/**
	Inheritance - 1
	Create a class called Box having length, width, and height as attributes. Use a
	method along with all possible constructors to calculate volume. Create a
	derived class with additional data members namely weight and color. Include
	a method to display the volume and all the data members used in both the
	classes.
*/

import java.util.Scanner;

class Box {
	int length, width, height;
	
	Box(int l, int w, int h) {
		length=l;
		width=w;
		height=h;
	}
	
	void showDetails() {
		System.out.println("Length: " + length + " units");
		System.out.println("Width: " + width + " units");
		System.out.println("Height: " + height + " units");
		System.out.println("Volume: " + getVolume() + " cubic units");
	}
	
	int getVolume() {
		return length*width*height;
	}
}

class Box2 extends Box {
	int weight;
	String color;
	
	Box2(int l, int width, int h, int weight, String c) {
		super(l, width, h);
		this.weight=weight;
		color=c;
	}
	
	void showDetails() {
		super.showDetails();		
		System.out.println("Weight: " + weight + " units");
		System.out.println("Color:  " + color);
	}
}

public class Prg12 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Input length:  ");	int length = sc.nextInt();
		System.out.print("Input width:   "); 	int width = sc.nextInt();
		System.out.print("Input height:  "); 	int height = sc.nextInt();
		System.out.print("Input weight:  "); 	int weight = sc.nextInt();
		System.out.print("Input color:   "); 	String color = sc.next();
		
		Box2 box2 = new Box2(length, width, height, weight, color);
		box2.showDetails();
	}
}