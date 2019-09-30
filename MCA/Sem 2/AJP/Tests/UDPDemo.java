import java.net.*;
import java.io.*;


/**
	Simple UDP client/server to send message  and receive
	messages to and from the server.
*/
public class UDPDemo {	
	/** Starts the server. */
	private void startServer(	final String hostName,
								final int port,
								final int msgLength)
		throws IOException 
	{
		DatagramSocket socket = new DatagramSocket(port, InetAddress.getByName(hostName));
		DatagramPacket packet = new DatagramPacket(new byte[msgLength], msgLength);
		showPacket(packet, "Server: Packet received");
		socket.receive(packet);
		
		byte[] data = packet.getData();
		for(int i=0; i<3 && i<data.length; i++) // modifying packet data for fisrt 3 chars
			data[i]=(byte)'X';
		packet.setData(data);
		
		showPacket(packet, "Server: Sending packet");
		socket.send(packet);
		socket.close();
	}
	
	/** Starts the client. */
	private void startClient(	final String hostName,
								final int port,
								final String msg)
		throws IOException
	{
		DatagramSocket socket = new DatagramSocket(port, InetAddress.getByName(hostName));
		DatagramPacket packet = new DatagramPacket(msg.getBytes(), msg.length(), InetAddress.getByName(hostName), port);
		showPacket(packet, "Client: Sending packet");
		socket.send(packet);
		packet = new DatagramPacket(new byte[msg.length()], msg.length()); // reset packet contents
		socket.receive(packet);
		showPacket(packet, "Client: Packet received");
		socket.close();
	}
	
	private void showPacket(final DatagramPacket packet, final String msg) {
		System.out.println(msg + ": ");
		System.out.println("  Address: " + packet.getAddress());
		System.out.println("  Port: " + packet.getPort());
		System.out.println("  Data: " + new String(packet.getData()));
		System.out.println("  Socket address: " + packet.getSocketAddress());
	}
	
	public static void main(String[] args) {
		boolean isServer = false;
		String msg = null;
		int port = -1;
		String hostName = null;
		
		try {
			switch(args[0]) {
				case "-s": 
					isServer = true;
					break;
				case "-c": 
					isServer = false;
					msg = args[3];
					break;
				default: throw new IllegalArgumentException(args[0]);
			}
			port = Integer.parseInt(args[1]);
			hostName = args[2];
		} catch(Exception e) {
			System.err.println("Usage: UDPDemo -s|-c <portNumber> <hostName> [<msg>]");
			System.exit(1);
		}
		
		try {
			System.out.printf("[Starting %s...] \n", isServer ? "server" : "client");
			if(isServer) {
				new UDPDemo().startServer(hostName, port, 1000);
			} else {
				new UDPDemo().startClient(hostName, port, msg);
			}
			System.out.printf("[%s closed] \n", isServer ? "server" : "client");
		} catch(Exception e) {
			e.printStackTrace(System.err);
			System.exit(1);
		}
	}
}