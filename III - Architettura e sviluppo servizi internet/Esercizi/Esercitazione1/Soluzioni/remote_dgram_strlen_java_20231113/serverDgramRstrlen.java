import java.io.*;
import java.net.*;

public class serverDgramRstrlen {
    public static void main(String args[]) {
        try{
            DatagramSocket ss = new DatagramSocket(Integer.parseInt(args[0]));

            while(true) {
                //receiveing
                byte[] recvBuff = new byte[2048];
                DatagramPacket recvPkt = new DatagramPacket(recvBuff, recvBuff.length);

                ss.receive(recvPkt);

                String request = new String( recvPkt.getData(), "UTF-8" );
                request = request.trim();
                System.out.println("\nServer ha letto : " + request + " di lunghezza : " + request.length());

                InetAddress clientAddr = recvPkt.getAddress();
                int clientPort = recvPkt.getPort(); 
                System.out.println("Client "+clientAddr.toString()+" sulla porta "+clientPort);

                //sending
                byte[] sendBuff = (Integer.toString(request.length())).getBytes("UTF-8"); 
                DatagramPacket sendPkt = new DatagramPacket(sendBuff, sendBuff.length, clientAddr, clientPort);
                
                ss.send(sendPkt);
                System.out.println("Server ha inviato : " + request.length());

            }
        }
        catch(IOException e){/*TODO*/}
    }
}
