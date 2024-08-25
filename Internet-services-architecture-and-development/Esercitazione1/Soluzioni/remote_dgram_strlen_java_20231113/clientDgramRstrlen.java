import java.io.*;
import java.net.*;

public class clientDgramRstrlen {
    
    public static void main(String args[]){
        try{
            
            BufferedReader userIn = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("\nInserire stringa : ");
            String stringa = userIn.readLine();

            InetAddress serverAddr = InetAddress.getByName(args[0]);
            int porta = Integer.parseInt(args[1]);

            DatagramSocket cs = new DatagramSocket();

            //invio 
            byte[] request = stringa.getBytes("UTF-8");
            DatagramPacket pktOut = new DatagramPacket(request, request.length, serverAddr, porta);

            System.out.println("\n Invio a server : " + stringa);
            cs.send(pktOut);

            //ricezione
            byte[] buf = new byte[2048];
            DatagramPacket response = new DatagramPacket(buf, buf.length);

            cs.receive(response);

            String risposta = new String(response.getData(), "UTF-8");
            risposta = risposta.trim();
            System.out.println("Server ha risposto : " + risposta);

            cs.close();

        }
        catch(IOException e){/*TODO*/}
    }
}
