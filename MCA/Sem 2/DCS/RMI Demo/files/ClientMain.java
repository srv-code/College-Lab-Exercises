import java.rmi.Naming;


public class ClientMain {
	public static void main(final String[] args) throws Exception {
		startClient(args[0], args[1], Integer.parseInt(args[2]), Integer.parseInt(args[3]));
	}

	private static void startClient(	final String serverAddr,
										final String serverName,
										final int operand1,
										final int operand2) throws Exception {
		final String rmiURL = "rmi://" + serverAddr + "/" + serverName;
		System.out.printf("[Connecting to server (URL=%s) ...] \n", rmiURL);
		AddServer server = (AddServer) Naming.lookup(rmiURL);
		System.out.println("[Connection with server established successfully]");

		System.out.printf("Result: %d + %d = %d \n", 
							operand1, 
							operand2, 
							server.add(operand1, operand2));
	}
}
