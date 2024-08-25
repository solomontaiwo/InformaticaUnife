import java.io.*;
import java.net.*;

public class ClientNaive {
    public static void main(String[] argv) {

        if (argv.length != 2) {
            System.err.println("Uso corretto: java ClientNaive server porta");
            System.exit(1);
        }

        try{
            BufferedReader fromUser = new BufferedReader(new InputStreamReader(System.in));

            while (true) {
                System.out.println("Inserisci la categoria di spese cui sei interessato ('fine' per uscire):");
                String categoria = fromUser.readLine();
                String buff;

                if (categoria.equals("fine")){
                    System.out.println("Hai scelto di terminare il programma.");
                    break;
                }

                Socket s = new Socket(argv[0], Integer.parseInt(argv[1]));

                BufferedReader fromServer = new BufferedReader(new InputStreamReader(s.getInputStream(),"UTF-8"));
                BufferedWriter toServer = new BufferedWriter(new OutputStreamWriter(s.getOutputStream(),"UTF-8"));

                // Invio il nome della categoria al server, terminatore gestito server-side.
                toServer.write(categoria);
                toServer.flush();

                // Leggo la risposta finale del server e la stampo a video
                while ((buff = fromServer.readLine()) != null) {
                    System.out.println(buff);
                }

                s.close();
            }

        }
        catch(IOException e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(2);
        }
    }
}
