import java.io.*;
import java.net.*;


class QuoteClient {
    public static void main(String args[]) {
        if (args.length != 2) {
            System.err.println("Usage: java QuoteClient hostname porta");
            System.exit(1);
        }

        try {
            // creo socket
            DatagramSocket ds = new DatagramSocket();

            // preparo richiesta
            byte[] reqBuf = new String("QUOTE").getBytes("UTF-8");
            DatagramPacket reqPacket = new DatagramPacket(reqBuf, reqBuf.length,
                    InetAddress.getByName(args[0]), Integer.parseInt(args[1]));

            // invio richiesta
            ds.send(reqPacket);

            // preparo a ricevere risposta
            byte[] respBuf = new byte[2048];
            DatagramPacket respPacket = new DatagramPacket(respBuf, respBuf.length);

            // ricevo risposta
            ds.receive(respPacket);

            // la converto in stringa di testo
            String quote = new String(respPacket.getData(), 0,
                    respPacket.getLength(), "UTF-8");

            // e infine la stampo a video
            System.out.println(quote);

            // chiudo la socket
            ds.close();
        }
        catch (IOException e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(1);
        }
    }
}

