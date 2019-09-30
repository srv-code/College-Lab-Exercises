import java.net.*;
import java.io.*;
import java.util.Scanner;


public class TCPChatServer {
	/* DEBUG */
	final static boolean DEBUG = false;
	private static void d(final String fmtStr, final Object ... args) {
		if(DEBUG)
			System.out.printf("  // " + fmtStr+ "\n", args);
	}
	/* DEBUG */
	
	public static void main(String[] args) {
		startServer(Integer.parseInt(args[0]));
	}
	
	private static void startServer(final int port) {
		ServerSocket srvSock = null;
		Socket sock = null;
		try {
			srvSock = new ServerSocket(port);
			System.out.println("[Waiting for a connection from client...]");
			sock = srvSock.accept();
			System.out.println("[Connected to client]");
			
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
				System.out.print  ("Server:  ");
				myLine = sc.nextLine();				
				out.writeUTF(myLine);
				d("myLine='%s', term?=%b", myLine, myLine.equals(termStr));
				if(myLine.equals(termStr)) {
					termBy = "server";
					break;
				}
				
				hisLine = in.readUTF();
				System.out.println("Client:  " + hisLine);				
				d("hisLine='%s', term?=%b", hisLine, hisLine.equals(termStr));
				if(hisLine.equals(termStr)) {
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
			if(srvSock != null) {
				try {
					srvSock.close();
				} catch(Exception e) {
					System.err.println("Err: Unable to close server socket: " + e);
				}
			}

			if(sock != null) {
				try {
					sock.close();
				} catch(Exception e) {
					System.err.println("Err: Unable to close client socket: " + e);
				}
			}
		}
	}
}