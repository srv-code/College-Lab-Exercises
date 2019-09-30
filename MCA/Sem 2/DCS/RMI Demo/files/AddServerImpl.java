import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;


public class AddServerImpl extends UnicastRemoteObject implements AddServer {
	public AddServerImpl() throws RemoteException {
	}

	@Override
	public int add(final int a, final int b) throws RemoteException {
		System.out.printf("[Remote server object method invoked: add(%d, %d)] \n", a, b); // DEBUG
		
		return a+b;
	}
}
