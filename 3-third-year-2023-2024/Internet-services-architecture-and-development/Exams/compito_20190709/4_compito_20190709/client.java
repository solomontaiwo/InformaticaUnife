import java.io.*;
import java.net.*;

public class client {
    public static void main(String[] args) {
        if (args.length != 2) {
            System.err.println("Errore argomenti. Uso: java client server porta");
            System.exit(1);
        }

        try {

            Socket s = new Socket(args[0], Integer.parseInt(args[1]));
            BufferedReader netIn = new BufferedReader(new InputStreamReader(s.getInputStream(), "UTF-8"));
            BufferedWriter netOut = new BufferedWriter(new OutputStreamWriter(s.getOutputStream(), "UTF-8"));
            BufferedReader userIn = new BufferedReader(new InputStreamReader(System.in));

            while (true) {
                System.out.println("Inserisci username: ");
                String username = userIn.readLine();

                System.out.println("Inserisci password: ");
                String password = userIn.readLine();

                System.out.println("Inserisci categoria: ");
                String categoria = userIn.readLine();

                netOut.write(username);
                netOut.newLine();
                netOut.write(password);
                netOut.newLine();
                netOut.write(categoria);
                netOut.newLine();
                netOut.flush();

                String line;

                while (true) {
                    line = netIn.readLine();

                    if (line == null) {
                        s.close();
                        System.exit(0);
                    }

                    if (line.equals("--- END REQUEST ---")) {
                        break;
                    }

                    System.out.println(line);
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