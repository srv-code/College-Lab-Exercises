import java.net.*;
import java.io.*;


public class UDPFileServer {
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
		DatagramSocket sock = null;
		
		try {
			sock = new DatagramSocket(port);
			d("socket bound to port %d", port);
			final int maxLineLen = 80;			
			byte[] line = new byte[maxLineLen];
			DatagramPacket pack = new DatagramPacket(line, maxLineLen);
			d("will call receive() now...");
			sock.receive(pack);
			d("received pack from cli: data=%s", new String(pack.getData()));

			/*
			String fname = new String(pack.getData());
			int len = fname.length();
			System.out.printf("chars (size=%d): ", pack.getLength());
			for(int i=0; i<len; i++) {
				System.out.printf("%d:%c/%d; ", i, (char)fname.charAt(i), (int)fname.charAt(i));
			}
			System.out.println();
			*/

			final InetAddress cliAddr = pack.getAddress();
			final int cliPort = pack.getPort();

			/*
			File f = new File("Test1.java");
			System.out.println("f=" + f + ", exists=" + f.exists());
			*/
			
			File file = new File(new String(pack.getData(), 0, pack.getLength()));
			d("line=%s, file=%s, file.exists()=%b", new String(line), file, file.exists());
			if(!file.exists()) {
				line = "Err: File not found!".getBytes();
				d("data to be sent: line=%s, line.length=%d", new String(line), line.length);
				sock.send(new DatagramPacket(line, line.length, cliAddr, cliPort));
				d("err pack sent");
			} else {
				BufferedReader rdr = new BufferedReader(new FileReader(file));
				String fLine;
				while((fLine=rdr.readLine()) != null) {
					d("sending file line to client (addr=%s, port=%d)...", cliAddr, cliPort);
					sock.send(new DatagramPacket(fLine.getBytes(), fLine.length(), cliAddr, cliPort));
				}
				rdr.close();
			}
			sock.send(new DatagramPacket(new byte[] {-1}, 1, cliAddr, cliPort)); // EOF signal
			d("term sig pack sent");
		} catch(Exception e) {
			System.err.println("Err: " + e);
			e.printStackTrace(System.err);
		} finally {
			if(sock != null) {
				try {
					sock.close();
				} catch(Exception e) {
					System.err.println("Err: Unable to close socket: " + e);
					e.printStackTrace(System.err);
				}
			}
		}
	}
}