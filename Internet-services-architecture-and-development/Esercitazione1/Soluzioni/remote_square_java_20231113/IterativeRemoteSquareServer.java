import java.io.*;
import java.net.*;


public class IterativeRemoteSquareServer
{
    public static void main(String args[])
    {
        try {
            if (args.length != 1) {
                System.out.println("Errore! La sintassi corretta è: java IterativeRemoteSquareServer porta");
                System.exit(1);
            }

            ServerSocket ss = new ServerSocket(Integer.parseInt(args[0]));

            while(true) {
                Socket ns = ss.accept();

                BufferedReader networkIn  = new BufferedReader(
                    new InputStreamReader(ns.getInputStream(), "UTF-8"));
                BufferedWriter networkOut = new BufferedWriter(
                    new OutputStreamWriter(ns.getOutputStream(), "UTF-8"));

                String line;
                while ((line = networkIn.readLine()) != null) {
                    System.out.println("Ricevuto: " + line);
                    int N = Integer.parseInt(line);
                    // Uso Integer.toString per forzare la conversione a stringa
                    networkOut.write(Integer.toString(N * N));
                    // Una possibile soluzione alternativa sarebbe:
                    // networkOut.write(N * N + "");
                    networkOut.newLine();
                    networkOut.flush();
                }

                ns.close();
            }
        }
        catch(IOException e) {
            System.err.println(e);
            System.exit(2);
        }
    }
}
