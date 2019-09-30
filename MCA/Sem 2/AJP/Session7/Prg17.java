import java.io.*;
import java.util.*;


/**
	17. File Input and Output
		Create a file containing a set of strings. Read the file, sort the strings and
			store them in another file.
*/
public class Prg17 {
	public static void main(String[] args) throws IOException {
		// Read list of strings from STDIN and write to file unsorted.txt
		System.out.println("Enter strings; Press ENTER to terminate.");		
		BufferedReader reader  = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter fwriter = new BufferedWriter(new FileWriter("unsorted.txt"));
		String line;
		while((line = reader.readLine()).length() > 0) {
			fwriter.write(line + "\n");
		}
		reader.close();
		fwriter.close();
		System.out.println("Strings are written to input file.");
		
		// Read list of strings from file: unsorted.txt
		ArrayList<String> list = new ArrayList<String>();
		BufferedReader freader = new BufferedReader(new FileReader("unsorted.txt"));
		while((line = freader.readLine()) != null)
			list.add(line);
		freader.close();
		System.out.println("Strings are read from input file.");
		
		System.out.println("Unsorted strings: " + list);
		
		// Sort the list of strings 
		System.out.println("Sorting list of strings...");
		Collections.sort(list);
		
		System.out.println("Sorted strings:   " + list);
		
		// Write back the list of strings to file: sorted.txt
		fwriter = new BufferedWriter(new FileWriter("sorted.txt"));
		for(String string : list)
			fwriter.write(string + "\n");
		fwriter.close();
		System.out.println("Strings are written to output file.");
	}
}