import java.io.*;
import java.net.*;

public class Client {
    public static void main(String args[]) {
        if (args.length != 2) {
            System.err.println("Errore argomenti! Uso: java client hostname porta");
            System.exit(1);
        }

        try {
            Socket theSocket = new Socket(args[0], Integer.parseInt(args[1]));
            BufferedReader userIn = new BufferedReader(new InputStreamReader(System.in));
            BufferedReader netIn = new BufferedReader(new InputStreamReader(theSocket.getInputStream(), "UTF-8"));
            BufferedWriter netOut = new BufferedWriter(new OutputStreamWriter(theSocket.getOutputStream(), "UTF-8"));

            while (true) {
                System.out.println("Username: ");
                String username = userIn.readLine();

                if (username.equals("fine")) {
                    break;
                }

                System.out.println("Password: ");
                String password = userIn.readLine();

                if (password.equals("fine")) {
                    break;
                }

                System.out.println("Tipologia: ");
                String tipologia = userIn.readLine();

                if (tipologia.equals("fine")) {
                    break;
                }

                netOut.write(username);
                netOut.newLine();
                netOut.write(password);
                netOut.newLine();
                netOut.write(tipologia);
                netOut.newLine();
                netOut.flush();

                String line;

                while (true) {
                    line = netIn.readLine();

                    if (line == null) {
                        System.err.println("Il server ha chiuso la connessione");
                        System.exit(2);
                    }

                    if (line.equals("--- END REQUEST ---")) {
                        break;
                    }
                }
            }

            theSocket.close();

        } catch (IOException e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(100);
        }
    }
}