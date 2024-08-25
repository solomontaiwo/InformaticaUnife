// TAIWO SOLOMON OLAMIDE - MATRICOLA 181050
import java.io.*;
import java.net.*;

public class client {
    public static void main(String args[]) {
        if (args.length != 2) {
            System.err.println("Errore argomenti! Uso: java client <server> <porta>");
            System.exit(1);
        }

        try {
            var theSocket = new Socket(args[0], Integer.parseInt(args[1]));
            var userInput = new BufferedReader(new InputStreamReader(System.in));
            var networkIn = new BufferedReader(new InputStreamReader(theSocket.getInputStream(), "UTF-8"));
            var networkOut = new BufferedWriter(new OutputStreamWriter(theSocket.getOutputStream(), "UTF-8"));

            for (;;) {
                System.out.println("Inserisci il mese ('fine' per terminare): ");
                var mese = userInput.readLine();

                if (mese.equals("fine")) {
                    System.out.println("Ok, esco!");
                    break;
                }

                System.out.println("Inserisci la tipologia ('fine' per terminare): ");
                var tipologia = userInput.readLine();

                if (tipologia.equals("fine")) {
                    System.out.println("Ok, esco!");
                    break;
                }

                System.out.println("Inserisci la località ('fine' per terminare): ");
                var localita = userInput.readLine();

                if (localita.equals("fine")) {
                    System.out.println("Ok, esco!");
                    break;
                }

                networkOut.write(mese);
                networkOut.write(tipologia);
                networkOut.write(localita);
                networkOut.flush();

                String risposta;

                while ((risposta = networkIn.readLine()) != null) {
                    if (risposta.equals("--- END REQUEST ---")) {
                        break;
                    }

                    System.out.println(risposta);
                }
            }

            theSocket.close();

        } catch (Exception e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(1);
        }
    }
}
