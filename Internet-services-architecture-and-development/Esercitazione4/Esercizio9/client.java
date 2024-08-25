import java.net.*;
import java.io.*;

public class client {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.err.println("Errore argomenti! Uso: java client server porta");
            System.exit(1);
        }

        try {
            Socket theSocket = new Socket(args[0], Integer.parseInt(args[1]));
            BufferedReader userIn = new BufferedReader(new InputStreamReader(System.in));
            BufferedReader networkIn = new BufferedReader(new InputStreamReader(theSocket.getInputStream(), "UTF-8"));
            BufferedWriter networkOut = new BufferedWriter(
                    new OutputStreamWriter(theSocket.getOutputStream(), "UTF-8"));

            while (true) {
                System.out.println("Inserisci la categoria di spese a cui sei interessato ('fine' per uscire): ");
                String categoria = userIn.readLine();

                if (categoria.equals("fine")) {
                    System.out.println("Hai scelto di terminare il programma!");
                    break;
                }

                networkOut.write(categoria);
                networkOut.flush();

                String line;

                while ((line = networkIn.readLine()) != null) {
                    System.out.println(line);
                }

                theSocket.close();

            }

        } catch (IOException e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(100);
        }
    }
}
