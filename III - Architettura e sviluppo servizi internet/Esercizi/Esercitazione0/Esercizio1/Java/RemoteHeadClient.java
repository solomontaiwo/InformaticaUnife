package Esercitazione_0.Esercizio_1.Java;
// java RemoteHeadClient hostname   porta   nomefile
//                       args[0]    args[1] args[2]
import java.io.*;
import java.net.*;

class RemoteHeadClient {
    public static void main(String args[]) {
        if (args.length != 3) {
            System.err.println("Usage: java RemoteHeadClient hostname porta nomefile");
            System.exit(1);
        }

        try {
            Socket s = new Socket(args[0], Integer.parseInt(args[1]));

            BufferedReader netIn = new BufferedReader(new InputStreamReader(s.getInputStream(), "UTF-8"));
            BufferedWriter netOut = new BufferedWriter(new OutputStreamWriter(s.getOutputStream(), "UTF-8"));

            // mando nomefile
            netOut.write(args[2]);
            netOut.newLine();
            netOut.flush();

            // leggo dati dal server...
            String line;
            int line_number = 1;
            while ((line = netIn.readLine()) != null && line_number <= 5) {
                // ... e li mando a video
                System.out.println(line);
                line_number += 1;
            }

            s.close();
        } catch (IOException e) {
            System.err.println(e.getMessage());
            System.exit(2);
        }
    }
}