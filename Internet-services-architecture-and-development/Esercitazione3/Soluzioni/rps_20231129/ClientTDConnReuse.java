import java.io.*;
import java.net.*;

public class ClientTDConnReuse
{
    public static void main(String args[])
    {
        if (args.length != 2) {
            System.err.println("Errore! La sintassi corretta è: java ClientTDConnReuse hostname porta");
            System.exit(1);
        }

        try {
            var theSocket = new Socket(args[0], Integer.parseInt(args[1]));

            var userIn = new BufferedReader(new InputStreamReader(System.in));
            var networkIn = new BufferedReader(new InputStreamReader(theSocket.getInputStream(),"UTF-8"));
            var networkOut = new BufferedWriter(new OutputStreamWriter(theSocket.getOutputStream(),"UTF-8"));

            for (;;) {
                var option = userIn.readLine();

                /* Esco se l'utente digita . */
                if (option.equals(".")) {
                    break;
                }

                networkOut.write(option);
                networkOut.newLine();
                networkOut.flush();

                /* Leggo la risposta del server e la stampo a video */
                String theLine;
                for (;;) {
                    /* Leggo input da Server riga per riga */
                    theLine = networkIn.readLine();

                    /* Controllo errori */
                    if (theLine == null) {
                        System.err.println("Errore! Il Server ha chiuso la connessione!");
                        System.exit(2);
                    }

                    /* Stampo riga letta da Server */
                    System.out.println(theLine);

                    /* Passo a nuova richiesta una volta terminato input Server */
                    if (theLine.equals("--- END REQUEST ---")) {
                        break;
                    }
                }
            }

            /* Ricordarsi sempre di chiudere la socket! */
            theSocket.close();
        }
        catch (IOException e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(2);
        }
    }
}
