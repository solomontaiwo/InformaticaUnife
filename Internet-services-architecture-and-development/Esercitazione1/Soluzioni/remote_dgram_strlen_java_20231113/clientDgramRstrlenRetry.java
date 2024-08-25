import java.io.*;
import java.net.*;

public class clientDgramRstrlenRetry {

	private static final int TIMEOUT = 5000; //in milliseconds
	private static final int MAX_TRIES = 5;    
	
    public static void main(String args[]){
        try{
            
            BufferedReader userIn = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("\nInserire stringa : ");
            String fromUser = userIn.readLine();

            InetAddress serverAddr = InetAddress.getByName(args[0]);
            int porta = Integer.parseInt(args[1]);

            DatagramSocket cs = new DatagramSocket();
            cs.setSoTimeout(TIMEOUT);

            //preparo l'invio 
            byte[] request = fromUser.getBytes("UTF-8");
            DatagramPacket pktOut = new DatagramPacket(request, request.length, serverAddr, porta);
            // inizializzo pacchetto di ricezione
            DatagramPacket response; /*fuori dal loop perchè lo scope della variabile non si limita al loop */
            
            Boolean msgReceived = false;
            int numTries = 0;
            
            do {
                System.out.println("\n Invio a server : " + fromUser);
                cs.send(pktOut);

                //preparo la ricezione
                byte[] buf = new byte[2048];
                response = new DatagramPacket(buf, buf.length);
                
                try {
                    cs.receive(response);
                    msgReceived = true;
                }
                catch(SocketTimeoutException e){
                    numTries++;
                }
            }
            while( (numTries < MAX_TRIES) && !msgReceived);

            if(msgReceived){
                String risposta = new String(response.getData(), "UTF-8");
                risposta = risposta.trim();
                System.out.println("Server ha risposto : " + risposta);
            }
            else{
                System.out.println("Nessuna risposta dopo " + MAX_TRIES + " tentativi. Esco.");
            }
            cs.close();

        }
        catch(IOException e){/*TODO*/}

    }



}
