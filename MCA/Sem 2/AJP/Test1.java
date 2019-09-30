import java.util.*;
import java.net.*;
import java.io.*;


class CubeRootCalculator extends Thread {
	private int num;

	CubeRootCalculator(int n) {
		super("CubeRootCalculator");
		num = n;
	}

	@Override 
	public void run() {
		try  {
			for(int i=1; i<=num; i++) {
				System.out.printf("Cube root of %d is %.2f \n", i, Math.cbrt(i));
				Thread.sleep(100);
			}
		} catch(Exception e) {
			System.err.println("Err: " + e);
		}
	}
}

class SquareRootCalculator implements Runnable {
	private int num;
	Thread thread;

	SquareRootCalculator(int n) {
		num = n;
		thread = new Thread(this, "SquareRootCalculator");
	}

	@Override 
	public void run() {
		try  {
			for(int i=1; i<=num; i++) {
				System.out.printf("Square root of %d is %.2f \n", i, Math.sqrt(i));
				Thread.sleep(100);
			}
		} catch(Exception e) {
			System.err.println("Err: " + e);
		}
	}
}

public class Test1 {
	/* DEBUG */
	private static final boolean DEBUG = true;
	private static void d(final String fmtStr, final Object ... args) {
		if(DEBUG)
			System.out.printf("  // "+ fmtStr +"\n", args);
	}
	/* DEBUG */

	public static void main(String[] args) throws Exception {
		l16();
	}

	private static void l16() {
		CubeRootCalculator cbrtCalc = new CubeRootCalculator(5);
		SquareRootCalculator sqrtCalc = new SquareRootCalculator(5);

		cbrtCalc.start();
		sqrtCalc.thread.start();

		System.out.println("Main thread waiting...");
		try {
			cbrtCalc.join();
			sqrtCalc.thread.join();
		} catch(InterruptedException e) {
			System.err.println("Err: " + e);
		}
		System.out.println("Main thread exiting...");
	}

	private static void l17() throws IOException {
		File file = new File("a.txt");
		BufferedWriter writer = new BufferedWriter(new FileWriter(file));
		for(String s : new String[]{"abc", "12de", "Abc"}) {
			writer.write(s);
			writer.newLine();
		}
		writer.close();

		ArrayList<String> ls = new ArrayList<String>();
		BufferedReader reader = new BufferedReader(new FileReader(file));
		String line;
		while((line=reader.readLine()) != null)
			ls.add(line);
		reader.close();

		Collections.sort(ls);
		writer = new BufferedWriter(new FileWriter(new File("b.txt")));
		for(String s : ls) {
			writer.write(s);
			writer.newLine();
		}
		writer.close();
	}

	private static void l18(final String cmd) {
		if(cmd.equals("-s"))
			startTCPServer(5300);
		else if(cmd.equals("-c"))
			startTCPClient(5300, "localhost");
		else 
			System.err.println("Err: Invalid option! " + cmd);
	}

	private static void startTCPServer(final int port) {
		ServerSocket sock = null;
		try {
			sock = new ServerSocket(port);
			new Connection(sock.accept()).start();
		} catch(Exception e) {
			System.err.println("Err: " + e);
		} finally {
			if(sock != null) {
				try {
					sock.close();
				} catch(Exception e) {
					System.err.println("Err: cannot close socket! " + e);
				}
			}
		}
	}

	private static void startTCPClient(final int port, final String host) {
		Socket sock = null;
		try {
			sock = new Socket(host, port);
			DataOutputStream out = new DataOutputStream(sock.getOutputStream());
			DataInputStream in   = new DataInputStream(sock.getInputStream());
			final String termString = "bye";
			String line;
			Scanner sc = new Scanner(System.in);
			while(true) {
				line = in.readUTF();
				System.out.println("Server:  " + line);
				d("line='%s', len=%d", line, line.length());
				if(line.equals(termString))
					break;

				System.out.print("Client:  ");
				line = sc.nextLine();
				d("line='%s', len=%d", line, line.length());
				out.writeUTF(line);
				if(line.equals(termString))
					break;
			}
			System.out.println("--- Terminated ---");
			out.close();
			in.close();
		} catch(Exception e) {
			System.err.println("Err: " + e);
		} finally {
			if(sock != null) {
				try {
					sock.close();
				} catch(Exception e) {
					System.err.println("Err: cannot close socket! " + e);
				}
			}
		}	
	}

	private static void l19(final String cmd) {
		if(cmd.equals("-s"))
			startUDPServer(5300);
		else if(cmd.equals("-c"))
			startUDPClient("Test1.java", 5300, "localhost");
		else 
			System.err.println("Err: Invalid option! " + cmd);
	}

	private static void startUDPServer(final int port) {
		DatagramSocket sock = null;
		try {
			sock = new DatagramSocket(port);
			DatagramPacket pack = new DatagramPacket(new byte[200], 200);
			sock.receive(pack);
			File file = new File(new String(pack.getData(), 0, pack.getLength()));
			String line;
			if(!file.exists()) {
				line = "File "+ file +" not found!";
				sock.send(new DatagramPacket(line.getBytes(), line.length(), pack.getAddress(), pack.getPort()));
				d("data=%s, len=%d", new String(line.getBytes(), 0, line.length()), line.length());
			} else {
				BufferedReader reader = new BufferedReader(new FileReader(file));
				while((line=reader.readLine()) != null) {
					sock.send(new DatagramPacket(line.getBytes(), line.length(), pack.getAddress(), pack.getPort()));
				}
				reader.close();
			}
			sock.send(new DatagramPacket(new byte[]{-1}, 1, pack.getAddress(), pack.getPort()));
		} catch(Exception e) {
			System.err.println("Err: " + e);
		} finally {
			if(sock != null) {
				try {
					sock.close();
				} catch(Exception e) {
					System.err.println("Err: cannot close socket! " + e);
				}
			}
		}
	}

	private static void startUDPClient(final String fname, final int port, final String host) {
		DatagramSocket sock = null;
		try {
			sock = new DatagramSocket();
			InetAddress srvaddr = InetAddress.getByName(host);
			DatagramPacket pack = new DatagramPacket(fname.getBytes(), fname.length(), srvaddr, port);
			sock.send(pack);

			while(true) {
				sock.receive(pack = new DatagramPacket(new byte[200], 200, srvaddr, port));
				if(pack.getData()[0] == -1)
					break;
				System.out.println(new String(pack.getData(), 0, pack.getLength()));
				d("data=%s, len=%d", new String(pack.getData(), 0, pack.getLength()), pack.getLength());
			}			
		} catch(Exception e) {
			System.err.println("Err: " + e);
		} finally {
			if(sock != null) {
				try {
					sock.close();
				} catch(Exception e) {
					System.err.println("Err: cannot close socket! " + e);
				}
			}
		}
	}

	private static void l20() {
		Vector<Integer> vec = new Vector<Integer>();
		vec.add(1);
		vec.add(3);
		vec.add(5);
		vec.add(7);
		vec.add(9);
		System.out.println("init: vec=" + vec);

		vec.add(2, Integer.valueOf(8));
		System.out.println("After insert: vec=" + vec);

		vec.add(11);
		System.out.println("After append: vec=" + vec);

		System.out.println("removal successful: " + vec.remove(Integer.valueOf(11)));
		System.out.println("After removal: vec=" + vec);
		System.out.println("Displaying: ");
		for(int i=0; i<vec.size(); i++)
			System.out.print("  " + vec.elementAt(i));
	}

	private static void l21() {
		ArrayList<String> ls = new ArrayList<String>();
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter 5 strings: ");
		for(int i=0; i<5; i++) {
			System.out.printf("String %d:  ", i+1);
			ls.add(sc.next());
		}

		// System.out.println("ls=" + ls);
		for(int i=0; i<ls.size(); i++) {
			System.out.print("  " + ls.get(i));
		}
		System.out.println();


		Collections.sort(ls, Comparator.reverseOrder());

		Iterator<String> itr = ls.iterator();
		System.out.println("Showing using iterator:");
		while(itr.hasNext()) {
			System.out.print("  " + itr.next());
		}
		
		ListIterator<String> lsitr = ls.listIterator();
		System.out.println("\nShowing in fwd using list iterator:");		
		while(lsitr.hasNext()) {
			System.out.print("  " + lsitr.next());
		}

		System.out.println("\nShowing in backward using list iterator:");
		while(lsitr.hasPrevious()) {
			System.out.print("  " + lsitr.previous());
		}
	}

	static class Connection extends Thread {
		private DataOutputStream out;
		private DataInputStream  in;
		private Socket sock;
		private final String termString = "bye";

		Connection(Socket s) throws IOException {
			sock = s;
			out = new DataOutputStream(s.getOutputStream());
			in  = new DataInputStream(s.getInputStream());
		}

		@Override 
		public void run() {
			try {
				String line;
				Scanner sc = new Scanner(System.in);
				while(true) {
					System.out.print("Server:  ");
					line = sc.nextLine();
					out.writeUTF(line);
					d("line='%s', len=%d", line, line.length());
					if(line.equals(termString))
						break;

					line = in.readUTF();
					System.out.println("Client:  " + line);
					d("line='%s', len=%d", line, line.length());
					if(line.equals(termString))
						break;
				}
				System.out.println("--- Terminated ---");
				out.close();
				in.close();
			} catch(Exception e) {
				System.err.println("Err: " + e);
			} finally {
				try {
					sock.close();
				} catch(Exception e) {
					System.err.println("Err: Cannot close client socket! " + e);
				}
			}
		}
	}
}

