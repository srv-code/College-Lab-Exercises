import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.ListIterator;


/**
	Collections – 2
		Input five strings and store them in an ArrayList. Sort it in alphabetic order.
		Display the list in the forward direction (using an iterator) and in both
		directions (using a listIterator).
*/

public class IteratorDemo {
	public static void main(String[] args) {
		ArrayList<String> ls = new ArrayList<String>(5);
		Scanner sc = new Scanner(System.in);

		for(int i=0; i<5; i++) {
			System.out.printf("Enter string %d:  ", i+1);
			ls.add(sc.next());
		}

		System.out.println("Sorting...");
		Collections.sort(ls);

		Iterator<String> itr = ls.iterator();
		System.out.print("List in forward direction using iterator:  ");
		while(itr.hasNext())
			System.out.print("  " + itr.next());
		System.out.println();

		ListIterator<String> lsItr = ls.listIterator();
		System.out.print("List in forward direction using list iterator:  ");
		while(lsItr.hasNext())
			System.out.print("  " + lsItr.next());
		System.out.println();

		System.out.print("List in reverse direction using list iterator:  ");
		while(lsItr.hasPrevious())
			System.out.print("  " + lsItr.previous());
		System.out.println();
	}
}