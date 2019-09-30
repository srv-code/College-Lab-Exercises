import java.net.DatagramSocket;
import java.net.DatagramPacket;
import java.net.SocketException;
import java.io.IOException;


public class UDPServer {
    public static void main(String[] args) {
        final int serverPort = 6789;
        DatagramSocket socket = null;
        try {
            socket = new DatagramSocket(serverPort);
            while(true) {
                DatagramPacket packetRcv = new DatagramPacket(new byte[1000], 1000);
                socket.receive(packetRcv);
                System.out.println("Server: Message received: " + new String(packetRcv.getData()));
                byte[] dataSnd = ">>>".concat(new String(packetRcv.getData(), 0, packetRcv.getData().length-2)).getBytes();
                // byte[] dataSnd = (":::").getBytes();
                DatagramPacket packetSnd = new DatagramPacket(dataSnd, dataSnd.length, packetRcv.getAddress(), packetRcv.getPort());
                // System.out.println("  // Server: Message to send: " + new String(dataSnd));
                socket.send(packetSnd);
            }
        } catch(SocketException e) {
            System.err.println("SocketException: " +  e.getMessage());
        } catch(IOException e) {
            System.err.println("IOException: " +  e.getMessage());
        } finally {
            if(socket != null) 
                socket.close();
        }
    }    
}