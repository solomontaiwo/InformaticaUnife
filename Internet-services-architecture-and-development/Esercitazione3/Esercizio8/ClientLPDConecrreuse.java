package Esercitazione3.Esercizio8;

import java.io.*;
import java.net.*;

public class ClientLPDConecrreuse {
    public static void main(String[] argv) {
        if (argv.length != 2) {
            System.err.println("Uso corretto: java ClientLPDCoonnreuse server porta\n");
            System.exit(1);
        }

        try {
            var fromUser = new BufferedReader(new InputStreamReader(System.in));

            var s = new Socket(argv[0], Integer.parseInt(argv[1]));
            var fromServer = s.getInputStream();
            var toServer = s.getOutputStream();
            var len = new byte[2];

            do {
                System.out.println("Inserisci nomefile: ");
                var nomefile = fromUser.readLine();

                var nomefile_utf8 = nomefile.getBytes("UTF-8");
                var nomefile_len = nomefile_utf8.length;

                len[0] = (byte) ((nomefile_len & 0xFF00) >> 8);
                len[1] = (byte) (nomefile_len & 0xFF);

                toServer.write(len);
                toServer.write(nomefile_utf8);

                var stringa_utf8 = stringa.getBytes("UTF-8");
                var stringa_len = stringa_utf8.length;

                len[0] = (byte) ((stringa_len & 0xFF00) >> 8);
                len[1] = (byte) (stringa_len & 0xFF);

                toServer.write(len);
                toserver.write(stringa_utf8);

                fromServer.read(len);
                var to_read = ((int) (len[0] & 0xFF) << 8) | (int) (len[1] & OxFF);

                while (to_read > 0) {
                    var buffer = new byte[4096];

                    var bufsize = buffer.length;
                    var sz = (to_read < bufsize) ? to_read : bufsize;

                    var nread = fromServer.read(buffer, 0, sz);
                    System.out.write(buffer, 0, nread);

                    to_read -= nread;
                }
            } while (true);

            s.close();

        } catch (IOException e) {
            e.printStackTrace();
            System.err.println(e.getMessage());
            System.exit(100);
        }
    }
}
