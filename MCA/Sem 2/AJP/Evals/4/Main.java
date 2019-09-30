import java.io.*;
import java.net.*;


/**
	Write the UDP server-side program to receive a string from client, 
		then convert it to its uppercase and reverse it and finally 
		send it back to the client. Do all the house-keeping operations also.
*/
public class Main {
	public static void main(String[] args) {
		if(args[0].equals("-s")) 
			startUDPServer(Integer.parseInt(args[1]));
		else if(args[0].equals("-c")) 
			startUDPClient(args[1], Integer.parseInt(args[2]), args[3]);
		else 
			System.err.println("Invalid option!");
	}

	private static void startUDPServer(final int port) {
		DatagramSocket sock = null;
		try {
			sock = new DatagramSocket(port);			
			byte[] msg = new byte[1000];
			DatagramPacket pack = new DatagramPacket(msg, msg.length);
			sock.receive(pack);

			/*
			String newMsg = new String(msg, 0, pack.getLength()).toUpperCase();			
			newMsg = new StringBuffer(newMsg).reverse().toString();
			*/

			String newMsg = new StringBuffer(new String(msg, 0, pack.getLength()).toUpperCase()).reverse().toString();

			sock.send(new DatagramPacket(newMsg.getBytes(), newMsg.length(), pack.getAddress(), pack.getPort()));
		} catch(Exception e) {
			System.err.println("Server side error: " + e);
		} finally {
			if(sock != null) {
				try {
					sock.close();
				} catch(Exception e) {
					System.err.println("Err: Unable to close server socket: " + e);
				} 
			}
		}
	}

	private static void startUDPClient(final String host, final int port, final String string) {
		DatagramSocket sock = null;
		try {
			sock = new DatagramSocket();
			DatagramPacket pack = new DatagramPacket(string.getBytes(), string.length(), InetAddress.getByName(host), port);
			sock.send(pack);

			pack = new DatagramPacket(new byte[string.length()], string.length());
			sock.receive(pack);

			System.out.println("Result: " + new String(pack.getData()));
		} catch(Exception e) {
			System.err.println("Client side error: " + e);
		} finally {
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