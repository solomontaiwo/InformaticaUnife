import java.io.*;
import java.net.*;

public class client {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Errore argomenti! Uso: java client hostname porta");
            System.exit(1);
        }

        try {
            Socket s = new Socket(args[0], Integer.parseInt(args[1]));
            BufferedReader netIn = new BufferedReader(new InputStreamReader(s.getInputStream(), "UTF-8"));
            BufferedWriter netOut = new BufferedWriter(new OutputStreamWriter(s.getOutputStream(), "UTF-8"));
            BufferedReader userIn = new BufferedReader(new InputStreamReader(System.in));

            while (true) {
                System.out.println("Username ('fine' per uscire): ");
                String username = userIn.readLine();

                if (username.equals("fine")) {
                    break;
                }

                System.out.println("Password ('fine' per uscire): ");
                String password = userIn.readLine();

                if (password.equals("fine")) {
                    break;
                }

                System.out.println("Tipologia giocattolo ('fine' per uscire): ");
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
                        System.err.println("Errore! Il server ha chiuso la connessione");
                        System.exit(2);
                    }

                    System.out.println(line);

                    if (line.equals("--- END REQUEST ---")) {
                        break;
                    }
                }
            }
            s.close();
        } catch (IOException e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(100);
        }
    }
}
