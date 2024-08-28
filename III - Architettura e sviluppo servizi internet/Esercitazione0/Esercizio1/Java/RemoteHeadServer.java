package Esercitazione_0.Esercizio_1.Java;
import java.io.*;
import java.net.*;

// java RemoteHeadServer porta
//                       args[0]

class RemoteHeadServer {
    public static void main(String args[]) {
        if (args.length != 1) {
            System.err.println("Usage: java RemoteHeadServer porta");
            System.exit(1);
        }

        try {
            ServerSocket ss = new ServerSocket(Integer.parseInt(args[0]));

            for (;;) {
                Socket s = ss.accept();

                BufferedReader netIn = new BufferedReader(new InputStreamReader(s.getInputStream(), "UTF-8"));
                BufferedWriter netOut = new BufferedWriter(new OutputStreamWriter(s.getOutputStream(), "UTF-8"));

                // leggo filename dalla socket
                String filename = netIn.readLine();

                // controllo esistenza file
                File f = new File(filename);
                if (f.exists()) {
                    BufferedReader bfr = new BufferedReader(new FileReader(f));
                    String line;
                    while ((line = bfr.readLine()) != null) {
                        int line_number = 1;
                        while ((line = bfr.readLine()) != null && line_number <= 5) {
                            netOut.write(line);
                            netOut.newLine();
                            netOut.flush();
                            line_number += 1;
                        }
                    }
                }
                s.close();
            }
        } catch (IOException e) {
            System.err.println(e.getMessage());
            System.exit(2);
        }
    }
}