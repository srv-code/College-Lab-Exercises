import java.io.IOException;
import java.net.DatagramSocket;
import java.net.DatagramPacket;
import java.net.SocketException;
import java.net.InetAddress;


public class UDPClient {

    /**
     * @param args [0]=hostname, [1]=message
    */
    public static void main(String[] args) {
        final int serverPort = 6789;
        final String hostName = args[0];
        final String message = args[1];

        DatagramSocket socket = null;
        try {
            socket = new DatagramSocket();
            InetAddress hostAddr = InetAddress.getByName(hostName);
            DatagramPacket packetSnd = new DatagramPacket(message.getBytes(), message.length(), hostAddr, serverPort);
            socket.send(packetSnd);
            DatagramPacket packetRcv = new DatagramPacket(new byte[1000], 1000);
            socket.receive(packetRcv);
            System.out.println("Client: Message received: " + new String(packetRcv.getData()));
        } catch(SocketException e) {
            System.err.println("SocketException: " + e.getMessage());
            System.exit(1);
        } catch(IOException e) {
            System.err.println("IOException: " + e.getMessage());
            System.exit(1);
        } finally {
            if(socket != null) {
                socket.close();
            }
        }
    }
}