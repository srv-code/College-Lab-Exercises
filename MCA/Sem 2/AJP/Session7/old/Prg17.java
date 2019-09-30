/**
	17. File Input and Output
		Create a file containing a set of strings. Read the file, sort the strings and
			store them in another file.
*/


import java.io.*;
import java.util.Scanner;


class Prg17 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter input file name:   "); String inputFilename = sc.next();
		System.out.print("Enter output file name:  "); String outputFilename = sc.next();
		
		try {
			String[] strings = new String[100];
			int stringsLen;
			BufferedReader reader
					= new BufferedReader( 
						new InputStreamReader( 
							new FileInputStream(inputFilename) ) );
			
			System.out.println("Reading from input file...");
			stringsLen = 0;
			for(String line; (line = reader.readLine()) != null; stringsLen++)
				strings[stringsLen] = line;

			reader.close();
			
			System.out.println("Sorting input string array...");
			sort(strings, stringsLen);
			
			BufferedWriter writer
					= new BufferedWriter(
						new OutputStreamWriter(
							new FileOutputStream(outputFilename)));
			
			System.out.println("Writing to output file...");
			for(int i=0; i<stringsLen; i++) {
				writer.append(strings[i]);
				writer.newLine();
			}
		
			writer.close();
		} catch(IOException e) {
			System.out.println("IO Error: " + e.getMessage());
		}
	}
	
	static void sort(String[] arr, int n) {		
		for(int i=1, j; i<n; i++) {
			String key = arr[i];
			for(j=i-1; j>=0; j--) {
				if(key.compareTo(arr[j]) < 0)
					arr[j+1] = arr[j];
				else 
					break;
			}
			arr[j+1] = key;
		}
	}
}