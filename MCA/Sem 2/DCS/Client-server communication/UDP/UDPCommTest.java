/**
	Sessional 1, question number: 9 (3 marks)
		UDP based client-server java program to send 
			an integer from client and the server has to 
			check the received integer is a part of 
			Fibbinoacci series or not, and send the 
			message back to the client.
*/

import java.net.*;
import java.io.IOException;


public class UDPCommTest { 
	public static void main(String[] args) throws Exception {
		int port;
		switch(args[0]) {
			case "-s": // call server
				port = Integer.parseInt(args[1]);
				startUDPServer(port);
				break;
				
			case "-c": // call client
				port = Integer.parseInt(args[1]);
				byte num = Byte.parseByte(args[3]);
				String hostName = args[2];
				startUDPClient(port, hostName, num);
				break;

			default: 
				throw new IllegalArgumentException("Invalid option: " + args[0]);
		}
	}
	
	private static void startUDPClient(final int port, final String hostName, final byte num) throws IOException {
		DatagramSocket socket = new DatagramSocket();
		socket.send(new DatagramPacket(new byte[] { num }, 1, InetAddress.getByName(hostName), port));
		// System.out.println("  // Client: packet sent, waiting for server response...");
		
		DatagramPacket packetReceived = new DatagramPacket(new byte[1], 1);
		socket.receive(packetReceived);
		
		if(packetReceived.getData()[0] == 1)
			System.out.println(num + " is a member of fibonacci series");
		else
			System.out.println(num + " is not a member of fibonacci series");
	}
	
	private static void startUDPServer(final int port) throws IOException {
		DatagramSocket socket = new DatagramSocket(port);
		DatagramPacket packetReceived = new DatagramPacket(new byte[1], 1);
		// System.out.println("[Server started, listening to port " + port + "]");
		
		while(true) {
			socket.receive(packetReceived);
			// System.out.println("  // Server: packet received, num=" + packetReceived.getData()[0]);
			socket.send(
				new DatagramPacket(
					new byte[] { (byte)(isMemberOfFibonacciSeries((int)packetReceived.getData()[0]) ? 1 : 0) }, 
					1, 
					packetReceived.getAddress(), 
					packetReceived.getPort()));
		}
	}
	
	private static boolean isMemberOfFibonacciSeries(final int num) {
		int prev=0, curr=1, tmp;
		
		if(num==prev || num==curr) 
			return true;
		
		while(curr < 128 && curr < num) {
			tmp = curr;
			curr += prev;
			prev = tmp;
			
			// System.out.printf("  // Server: curr=%d, prev=%d, num=%d \n", curr, prev, num);
			
			if(num == curr) 
				return true;
		}
		
		return false;
	}
}