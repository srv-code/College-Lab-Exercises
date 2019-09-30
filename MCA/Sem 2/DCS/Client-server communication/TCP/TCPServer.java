import java.net.Socket;
import java.net.ServerSocket;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;


public class TCPServer {
	
	/**
		@param args[0] Server port
	*/
	public static void main(String[] args) {
		ServerSocket srvSocket = null;
		try {
			srvSocket = new ServerSocket(Integer.parseInt(args[0]));
			System.out.println("[Server started]");
			
			while(true) {
				new Connection(srvSocket.accept()).start();
			}
		} catch(Exception e) {
			System.err.println("Err while read/write: " + e);
		} finally {
			try {
				if(srvSocket != null) {
					srvSocket.close();
				}
			} catch(Exception e) {
				System.err.println("Err while closing server socket: " + e);
			}
		}
	}
}

class Connection extends Thread {
	private Socket cliSocket;
	private DataInputStream in;
	private DataOutputStream out;		
	
	Connection(final Socket socket) throws IOException {
		cliSocket = socket;
		in = new DataInputStream(socket.getInputStream());
		out = new DataOutputStream(socket.getOutputStream());
	}
	
	@Override 
	public void run() {
		try {
			out.writeUTF("<<" + in.readUTF() + ">>");
		} catch(IOException e) {
			System.err.println("[I/O Err: "+ e +"]");
		} finally {
			try {
				if(cliSocket != null) {
					cliSocket.close();
				}
			} catch(IOException e) {
				System.err.println("Err while closing client socket: " + e);
			}
		}
	}
}