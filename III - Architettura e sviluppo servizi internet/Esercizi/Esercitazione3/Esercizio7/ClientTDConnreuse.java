package Esercitazione3.Esercizio7;

import java.io.*;
import java.net.*;

public class ClientTDConnreuse {
    public static void main(String args[]) {
        if (args.length != 2) {
            System.err.println("Errore. La sintassi corretta è: java ClientTDConnreuse hostname porta");
            System.exit(1);
        }

        try {
            var theSocket = new Socket(args[0], Integer.parseInt(args[1]));

            var userIn = new BufferedReader(new InputStreamReader(System.in));
            var networkIn = new BufferedReader(new InputStreamReader(theSocket.getInputStream(), "UTF-8"));
            var networkOut = new BufferedWriter(new BufferedWriter(theSocket.getOutputStream(), "UTF-8"));

            for (;;) {
                var option = userIn.readLine();

                if (option.equals(".")) {
                    break;
                }

                networkOut.write(option);
                networkOut.newLine();
                networkOut.flush();

                String theLine;
                for (;;) {
                    theLine = networkIn.readLine();

                    if (theLine == null) {
                        System.err.println("Errore. Il server ha chiuso la connessione");
                        System.exit(2);
                    }

                    System.out.println(theLine);

                    if (theLine.equals("--- END REQUEST ---")) {
                        break;
                    }
                }
            }

            theSocket.close();
        } catch (IOException e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(2);
        }
    }
}
