import java.io.*;
import java.net.*;


public class ClientLPDConnreuse {
    public static void main(String[] argv) {

        if (argv.length != 2) {
            System.err.println("Uso corretto: java ClientLPDConnreuse server porta\n");
            System.exit(1);
        }

        try{
            var fromUser = new BufferedReader(new InputStreamReader(System.in));

            var s = new Socket(argv[0], Integer.parseInt(argv[1]));
            var fromServer = s.getInputStream();
            var toServer  = s.getOutputStream();
            var len = new byte[2];

            do {
                System.out.println("Inserisci nomefile: ");
                var nomefile = fromUser.readLine();

                if (nomefile.equals("fine")) {
                    break;
                }

                System.out.println("Inserisci stringa: ");
                var stringa = fromUser.readLine();

                // effettuo encoding di nomefile in UTF-8 e calcolo la
                // dimensione in byte del buffer risultante
                var nomefile_utf8 = nomefile.getBytes("UTF-8");
                var nomefile_len = nomefile_utf8.length;

                // effettuo encoding della dimensione del buffer nomefile_utf8
                // in un unsigned a 16 bit con ordine big endian
                len[0] = (byte)((nomefile_len & 0xFF00) >> 8);
                len[1] = (byte)(nomefile_len & 0xFF);

                // trasmetto nomefile
                toServer.write(len);
                toServer.write(nomefile_utf8);

                // effettuo encoding di stringa in UTF-8 e calcolo la
                // dimensione in byte del buffer risultante
                var stringa_utf8 = stringa.getBytes("UTF-8");
                var stringa_len = stringa_utf8.length;
                
                // effettuo encoding della dimensione del buffer stringa_utf8
                // in un unsigned a 16 bit con ordine big endian
                len[0] = (byte)((stringa_len & 0xFF00) >> 8);
                len[1] = (byte)(stringa_len & 0xFF);

                // trasmetto stringa
                toServer.write(len);
                toServer.write(stringa_utf8);

                /* Leggo dimensione messaggio di risposta */
                fromServer.read(len);
                var to_read = ((int)(len[0] & 0xFF) << 8) | (int)(len[1] & 0xFF);

                /* Stampo contenuto risposta a video */
                while (to_read > 0) {
                    var buffer = new byte[4096];

                    var bufsize = buffer.length;
                    var sz = (to_read < bufsize) ? to_read : bufsize;

                    var nread = fromServer.read(buffer, 0, sz);
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

