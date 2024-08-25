import java.io.*;
import java.net.*;

public class ClientNaive
{
    public static void main(String args[])
    {
        if (args.length < 1 || args.length > 2) {
            System.err.println("Errore! La sintassi corretta è: java Client hostname <opt>");
            System.exit(1);
        }

        try {
            String theLine;
            var theSocket = new Socket(args[0], 50000);

            var userIn = new BufferedReader(new InputStreamReader(System.in));
            var networkIn = new BufferedReader(new InputStreamReader(theSocket.getInputStream(),"UTF-8"));
            var networkOut = new BufferedWriter(new OutputStreamWriter(theSocket.getOutputStream(),"UTF-8"));

            if (args.length == 2) {
                networkOut.write(args[1]);
                networkOut.flush();
            }

            theSocket.shutdownOutput();

            // Leggo la risposta finale del server e la stampo a video
            while ((theLine = networkIn.readLine()) != null) {
                System.out.println(theLine);
            }

            // Ricordarsi sempre di chiudere la socket!
            theSocket.close();
        }
        catch (IOException e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(2);
        }
    }
}
