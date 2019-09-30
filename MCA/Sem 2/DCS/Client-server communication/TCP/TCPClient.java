import java.net.Socket;
import java.io.DataInputStream;
import java.io.DataOutputStream;


public class TCPClient {
	
	/**
		@param args[0] Server machine name/IP
		@param args[1] Server port number
		@param args[2] Message to server
	*/
	public static void main(String[] args) {
		Socket socket = null;
		try {
			socket = new Socket(args[0], Integer.parseInt(args[1]));
			DataOutputStream out = new DataOutputStream(socket.getOutputStream());
			out.writeUTF(args[2]);
			System.out.println("Written to server, waiting for response...");
			
			DataInputStream in = new DataInputStream(socket.getInputStream());
			System.out.println("Server response: " + in.readUTF());
		} catch(Exception e) {
			System.err.println("Err while read/write: " + e);
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