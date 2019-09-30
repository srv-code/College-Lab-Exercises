import java.rmi.Remote;
import java.rmi.RemoteException;


public interface AddServer extends Remote {
	int add(final int a, final int b) throws RemoteException;
}