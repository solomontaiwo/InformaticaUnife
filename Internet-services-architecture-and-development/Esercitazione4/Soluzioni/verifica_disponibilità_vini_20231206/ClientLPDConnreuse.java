import java.io.*;
import java.net.*;


public class ClientLPDConnreuse {
    public static void main(String[] argv) {

        if (argv.length != 2) {
            System.err.println("Uso corretto: java ClientLPDConnreuse server porta\n");
            System.exit(1);
        }

        try{
            BufferedReader fromUser = new BufferedReader(new InputStreamReader(System.in));

            Socket s = new Socket(argv[0], Integer.parseInt(argv[1]));
            InputStream fromServer = s.getInputStream();
            OutputStream toServer  = s.getOutputStream();
            byte[] len = new byte[2];

            do {
                System.out.println("Inserisci nome: ");
                String nome = fromUser.readLine();

                if (nome.equals("fine")) {
                    break;
                }

                System.out.println("Inserisci annata: ");
                String annata = fromUser.readLine();

                // effettuo encoding di nome in UTF-8 e calcolo la
                // dimensione in byte del buffer risultante
                byte[] nome_utf8 = nome.getBytes("UTF-8");
                int nome_len = nome_utf8.length;

                // effettuo encoding della dimensione del buffer nome_utf8
                // in un unsigned a 16 bit con ordine big endian
                len[0] = (byte)((nome_len & 0xFF00) >> 8);
                len[1] = (byte)(nome_len & 0xFF);

                // trasmetto nome
                toServer.write(len);
                toServer.write(nome_utf8);

                // effettuo encoding di stringa in UTF-8 e calcolo la
                // dimensione in byte del buffer risultante
                byte annata_utf8[] = annata.getBytes("UTF-8");
                int annata_len = annata_utf8.length;
                
                // effettuo encoding della dimensione del buffer annata_utf8
                // in un unsigned a 16 bit con ordine big endian
                len[0] = (byte)((annata_len & 0xFF00) >> 8);
                len[1] = (byte)(annata_len & 0xFF);

                // trasmetto annata
                toServer.write(len);
                toServer.write(annata_utf8);

                /* Leggo dimensione messaggio di risposta */
                fromServer.read(len);
                int to_read = ((int)(len[0] & 0xFF) << 8) | (int)(len[1] & 0xFF);

                /* Stampo contenuto risposta a video */
                while (to_read > 0) {
                    byte[] buffer = new byte[4096];

                    int bufsize = buffer.length;
                    int sz = (to_read < bufsize) ? to_read : bufsize;

                    int nread = fromServer.read(buffer, 0, sz);
                    System.out.write(buffer, 0, nread);

                    to_read -= nread;
                }

            } while(true);

            s.close();
        }
        catch(IOException e){
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(100);
        }
    }
}

