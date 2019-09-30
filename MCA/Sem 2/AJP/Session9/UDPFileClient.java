import java.net.*;


public class UDPFileClient {
	/* DEBUG */
	final static boolean DEBUG = false;
	private static void d(final String fmtStr, final Object ... args) {
		if(DEBUG)
			System.out.printf("  // " + fmtStr+ "\n", args);
	}
	/* DEBUG */

	public static void main(String[] args) {
		startClient(Integer.parseInt(args[0]), args[1], args[2]);
	}
	
	private static void startClient(final int port, final String host, final String fname) {
		DatagramSocket sock = null;
		
		try {
			sock = new DatagramSocket();
			d("creating pack...");
			InetAddress addr = InetAddress.getByName(host);
			DatagramPacket pack = new DatagramPacket(fname.getBytes(), fname.length(), addr, port);
			d("pack created, sending...");
			sock.send(pack);
			d("pack sent");
			
			final int maxLineLen = 80;			
			// byte[] line = new byte[maxLineLen];
			// pack = new DatagramPacket(new byte[maxLineLen], maxLineLen, addr, port);
			
			while(true) {
				d("receiving...");
				pack = new DatagramPacket(new byte[maxLineLen], maxLineLen, addr, port);
				sock.receive(pack);
				// line = pack.getData();
				if(pack.getData()[0] == -1) {
					d("term sig pack identified");
					break;
				}
				System.out.println(new String(pack.getData(), 0, pack.getLength()));
			}
			d("out of loop");
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