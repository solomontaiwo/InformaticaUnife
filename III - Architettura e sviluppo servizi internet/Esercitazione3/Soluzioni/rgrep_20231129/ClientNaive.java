import java.io.*;
import java.net.*;

public class ClientNaive
{
    public static void main(String[] argv)
    {
        if (argv.length != 2) {
            System.err.println("Uso corretto: java ClientNaive server porta");
            System.exit(1);
        }

        try {
            String theLine;
            var fromUser = new BufferedReader(new InputStreamReader(System.in));

            System.out.println("Inserisci file: ");
            var file = fromUser.readLine();
            System.out.println("Inserisci stringa: ");
            var stringa = fromUser.readLine();

            var s = new Socket(argv[0], Integer.parseInt(argv[1]));
            var fromServer = new BufferedReader(new InputStreamReader(s.getInputStream(),"UTF-8"));
            var toServer = new BufferedWriter(new OutputStreamWriter(s.getOutputStream(),"UTF-8"));

            // Invio nome file al server
            toServer.write(file);
            toServer.flush();

            // Ricevo ACK dal server
            theLine = fromServer.readLine();

            if (!theLine.equals("ack")){
                System.err.println("Errore lettura Ack dal server");
                System.exit(2);
            }

            // Invio stringa da cercare al server
            toServer.write(stringa);
            toServer.flush();

            // Leggo la risposta finale del server e la stampo a video
            while ((theLine = fromServer.readLine()) != null) {
                System.out.println(theLine);
            }

            // Ricordarsi sempre di chiudere la socket!
            s.close();
        }
        catch(IOException e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(3);
        }
    }
}
