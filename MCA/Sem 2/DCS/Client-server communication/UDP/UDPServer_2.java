import java.net.DatagramSocket;
import java.net.DatagramPacket;


public class UDPServer {
	
	/**
		Server module: Sends length of message buffer
		@param args[0] server port
	*/
	public static void main(String[] args) {
		DatagramSocket socket = null;
		try {
			socket = new DatagramSocket(Integer.parseInt(args[0]));
			System.out.println("[Server started]");
			while(true) {
				DatagramPacket rcvPack = new DatagramPacket(new byte[1024], 1024);
				socket.receive(rcvPack);
				DatagramPacket sndPack = new DatagramPacket(	new byte[] { (byte)rcvPack.getLength() }, 
																1, 
																rcvPack.getAddress(), 
																rcvPack.getPort());
				socket.send(sndPack);
			}
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