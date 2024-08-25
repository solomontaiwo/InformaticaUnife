import java.io.*;
import java.net.*;


public class RemoteSquareClient
{
    static boolean isNumber(String num)
    {
        try{
            Integer.parseInt(num);
        } catch(NumberFormatException ne) {
            return false;
        }
        return true;
    }

    public static void main(String args[])
    {
        try {
            if (args.length != 2) {
                System.out.println("Errore! La sintassi corretta è: java RemoteSquareClient hostname porta");
                System.exit(1);
            }

            Socket theSocket = new Socket(args[0], Integer.parseInt(args[1]));

            BufferedReader userIn = new BufferedReader(new InputStreamReader(System.in));
            BufferedReader networkIn = new BufferedReader(
                new InputStreamReader(theSocket.getInputStream(), "UTF-8"));
            BufferedWriter networkOut = new BufferedWriter(
                new OutputStreamWriter(theSocket.getOutputStream(), "UTF-8"));

            System.out.println("Connesso al server RemoteSquare");

            while (true) {
                System.out.println("Inserisci un numero di cui vuoi ottenere il quadrato: ");
                String theLine = userIn.readLine();

                if (theLine.equals("fine")) break;

                if (!isNumber(theLine))
                    System.out.println("Devi inserire un numero intero!");
                else{
                    networkOut.write(theLine);
                    networkOut.newLine();
                    networkOut.flush();
                    System.out.println("Quadrato: " + networkIn.readLine());
                }
            }

            // ricordarsi sempre di chiudere la socket
            theSocket.close();
        }
        catch (IOException e) {
            System.err.println("Errore: " + e);
            System.exit(2);
        }
    }
}
