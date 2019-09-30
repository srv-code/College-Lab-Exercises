import java.net.DatagramSocket;
import java.net.DatagramPacket;
import java.net.InetAddress;


public class UDPClient {
	
	/**
		@param args[0] String message
		@param args[1] Server Machine name/IP
		@param args[2] Server port number
	*/
	public static void main(String[] args) {
		DatagramSocket socket = null;
		try {
			socket = new DatagramSocket();
			DatagramPacket pack = new DatagramPacket(	args[0].getBytes(), 
														args[0].length(), 
														InetAddress.getByName(args[1]), 
														Integer.parseInt(args[2]));
			socket.send(pack);
			System.out.println("Datagram sent to server, waiting for response...");
			pack = new DatagramPacket(new byte[1], 1);
			socket.receive(pack);
			System.out.println("Server response: " + pack.getData()[0]);
		} catch(Exception e) {
			System.err.println("Err while sending/receiving:  " + e);
		} finally {
			try {
				if(socket != null) {
					socket.close();
				}
			} catch(Exception e) {
				System.err.println("Err while closing socket: " + e);
			}
		}
	}
}