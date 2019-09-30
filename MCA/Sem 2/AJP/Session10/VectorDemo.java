import java.util.Vector;
import java.util.Scanner;


/**
	Collections – 1
		Create and initialize a vector with first five odd integers. Using a menu,
		perform the following operations on this vector:
			• Insert an element at a specified position
			• Insert an element at the end
			• Delete an element
			• Display the contents
*/
public class VectorDemo {
	public static void main(String[] args) {
		Vector<Integer> vec = new Vector<Integer>();
		vec.add(1);
		vec.add(3);
		vec.add(5);
		vec.add(7);
		vec.add(9);

		Scanner sc = new Scanner(System.in);
		int choice=-1;

		while(choice != 5) {
			System.out.println("\n\nChoose an operation:");
			System.out.println("  1  Insert an element at a specified position");
			System.out.println("  2  Insert an element at the end");
			System.out.println("  3  Delete an element");
			System.out.println("  4  Display the contents");
			System.out.println("  5  Exit");
			System.out.print  ("Choice:  ");
			choice = sc.nextInt();

			switch(choice) {
				case 1: // insert using index					
					System.out.print("Enter index:  ");
					int idx = sc.nextInt();
					System.out.print("Enter int element:  ");
					int e = sc.nextInt();
					
					vec.add(idx, e);
					System.out.println("Element inserted");
					break;

				case 2: // insert at end
					System.out.print("Enter int element:  ");
					vec.add(sc.nextInt());
					System.out.println("Element inserted");
					break;

				case 3: // delete an element
					System.out.print("Enter int element:  ");
					System.out.printf("Element deletion was " + (vec.remove(Integer.valueOf(sc.nextInt())) ? "successful": "unsuccessful"));
					break;

				case 4: // display elements
					System.out.println("Vector: " + vec);

					/*
					// 2nd method
					System.out.println("Vector elements: ");
					for(int i=0; i<vec.size(); i++) {
						System.out.println("  " + vec.get(i));
					}
					*/
					break;

				case 5: // exit 
					break;

				default: 
					System.err.println("Invalid choice!");
			}
		}

		sc.close();
	}
}