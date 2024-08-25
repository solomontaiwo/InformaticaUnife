import java.io.*;
import java.net.*;

public class ClientTDConnreuse {
    // java ClientTDConnreuse hostname port
    //                        args[0]  args[1]
    public static void main(String[] args) {
        // Controllo argomenti
        if (args.length != 2) {
            System.err.println("Error! Usage is\n\tjava ClientTDConnreuse hostname port");
            System.exit(1);
        }

        try {
            // Creo socket
            var s = new Socket(args[0], Integer.parseInt(args[1]));
            var netIn = new BufferedReader(new InputStreamReader(s.getInputStream(), "UTF-8"));
            var netOut = new BufferedWriter(new OutputStreamWriter(s.getOutputStream(), "UTF-8"));
            // Non devo specificare codifica UTF-8: uso codifica di default della piattaforma
            var keyboard = new BufferedReader(new InputStreamReader(System.in)); 

            for (;;) {
                System.out.println("Inserisci tipo sensore (fine per terminare):");
                var tipoSensore = keyboard.readLine();
                if (tipoSensore.equals("fine")) {
                    System.out.println("Ok, esco!");
                    break;
                }

                System.out.println("Inserisci stanza sensore (fine per terminare):");
                var stanzaSensore = keyboard.readLine();
                if (stanzaSensore.equals("fine")) {
                    System.out.println("Ok, esco!");
                    break;
                }

                System.out.println("Inserisci numero letture (fine per terminare):");
                var numeroLetture = keyboard.readLine();
                if (numeroLetture.equals("fine")) {
                    System.out.println("Ok, esco!");
                    break;
                }

                // Mando dati al Server
                netOut.write(tipoSensore); netOut.newLine();
                netOut.write(stanzaSensore); netOut.newLine();
                netOut.write(numeroLetture); netOut.newLine();
                netOut.flush();

                // Leggo risposta
                String line;
                while ((line = netIn.readLine()) != null) {
                    if (line.equals("--- END REQUEST ---"))
                        break;

                    System.out.println(line);
                }
            }

            s.close();
        }
        catch(Exception e) {
            System.err.println(e.getMessage());
            e.printStackTrace(System.err);
            System.exit(1);
        }
    }
}
