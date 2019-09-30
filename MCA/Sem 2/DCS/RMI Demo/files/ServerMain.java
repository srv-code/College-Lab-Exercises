import java.rmi.Naming;


public class ServerMain {
	public static void main(final String[] args) throws Exception {
		System.out.println("[Staring server...]");
		startServer();
	}

	private static void startServer() throws Exception {
		AddServerImpl server = new AddServerImpl();
		Naming.rebind("AddServer", server);
		System.out.println("[Listening to any client connection...]");
	}
}
