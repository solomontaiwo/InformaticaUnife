import java.io.*;
import java.net.*;

class QuoteServer {
    static final String[] quotations = { 
      "Adoro i piani ben riusciti",
      "Quel tappeto dava veramente un tono all'ambiente",
      "Se ci riprovi ti stacco un braccio",
      "Questo è un colpo di genio, Leonard",
      "I fagioli comunque erano uno schifo"
    };

    public static void main(String args[]) {
        if (args.length != 1) {
            System.err.println("Usage: java QuoteServer porta");
            System.exit(1);
        }

        // indice quote corrente
        int index = 0;

        try {
            // creo socket
            DatagramSocket ds = new DatagramSocket(Integer.parseInt(args[0]));

            while (true) {
                // creo buffer e datagram packet
                byte[] reqBuf = new byte[2048];
                DatagramPacket reqPacket = new DatagramPacket(reqBuf, reqBuf.length);

                // leggo il messaggio di richesta
                ds.receive(reqPacket);

                // estraggo la stringa dal messaggio
                String request = new String(reqPacket.getData(), 0, 
                                            reqPacket.getLength(), "UTF-8");

                // verifico che richiesta sia valida
                if (request.equals("QUOTE")) {
                    // ottengo prossima quote
                    String quote = quotations[ index % quotations.length ];

                    // converto la quote da stinga a sequenza di byte
                    byte[] respBuf = quote.getBytes("UTF-8");
                     
                    // preparo il datagram packet di risposta
                    DatagramPacket respPacket = 
                        new DatagramPacket(respBuf, respBuf.length,
                                           reqPacket.getAddress(), 
                                           reqPacket.getPort());

                    // e lo trasmetto al client
                    ds.send(respPacket);
                }

                // aggiorno contatore
                index += 1;
            }
        }
        catch (IOException e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(1);
        }
    }
}
