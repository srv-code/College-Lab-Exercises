import java.io.*;
import java.net.Socket;
import java.util.Scanner;


public class TCPChatClient {
	/* DEBUG */
	final static boolean DEBUG = false;
	private static void d(final String fmtStr, final Object ... args) {
		if(DEBUG)
			System.out.printf("  // " + fmtStr + "\n", args);
	}
	/* DEBUG */
	
	public static void main(String[] args) {
		startClient(Integer.parseInt(args[0]), args[1]);
	}
	
	private static void startClient(final int port, final String host) {
		Socket sock = null;
		try {
			System.out.println("[Attempting to connect to server...]");
			sock = new Socket(host, port);
			System.out.println("[Connected to server]");
			
			/*
			BufferedInputStream in   = new BufferedInputStream(new InputStreamReader(sock.getInputStream()));
			BufferedOutputStream out = new BufferedOutputStream(new OutputStreamReader(sock.getOutputStream()));
			*/
			/*
			InputStream in = sock.getInputStream();
			OutputStream out = sock.getOutputStream();
			*/
			DataInputStream in   = new DataInputStream(sock.getInputStream());
			DataOutputStream out = new DataOutputStream(sock.getOutputStream());
			Scanner sc = new Scanner(System.in);

			final String termStr = "bye"; 
			System.out.println("[Press enter to send, '"+ termStr +"' to terminate]\n");
			String myLine, hisLine, termBy;
			while(true) {
				hisLine = in.readUTF();
				System.out.println("Server:  " + hisLine);
				d("hisLine='%s', term?=%b", hisLine, hisLine.equals(termStr));
				if(hisLine.equals(termStr)) {
					termBy = "server";
					break;
				}				
				
				System.out.print  ("Client:  ");
				myLine = sc.nextLine();
				out.writeUTF(myLine);				
				d("myLine='%s', term?=%b", myLine, myLine.equals(termStr));
				if(myLine.equals(termStr)) {
					termBy = "client";
					break;
				}
			}
			sc.close();
		
			
			/*
			// while((line=in.readLine()) != null && line != null) {
			while((hisLine=in.read()) != null && myLine != null) { // server's msg should be read first
				System.out.println("Server:  " + hisLine);
				System.out.print  ("Client:  ");
				myLine = sc.nextLine();
				out.writeUTF(myLine);
			}
			*/
			
			System.out.println("\n[Chat terminated by " + termBy + "]");
		} catch(Exception e) {
			System.err.println("Err: " + e);
		} finally {
			if(sock != null) {
				try {
					sock.close();
				} catch(Exception e) {
					System.err.println("Err: Unable to close socket: " + e);
				}
			}
		}
	}
}