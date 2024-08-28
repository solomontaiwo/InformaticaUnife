//165338 MATTEO RANGONI
import java.io.*;
import java.net.*;

public class Client
{
    public static void main(String args[])
    {
        if(args.length != 2)
        {
            System.err.println("Errore! Uso: java Client hostname porta");
            System.exit(1);
        }

        try
        {
            Socket theSocket = new Socket(args[0], Integer.parseInt(args[1]));

            BufferedReader userIn = new BufferedReader(new InputStreamReader(System.in));
            BufferedReader networkIn = new BufferedReader(new InputStreamReader(theSocket.getInputStream(), "UTF-8"));
            BufferedWriter networkOut = new BufferedWriter(new OutputStreamWriter(theSocket.getOutputStream(), "UTF-8"));

            for(;;)
            {
                System.out.println("username (fine per uscire):");
                String username = userIn.readLine();

                if(username.equals("fine")) {
                    break;
                }

                System.out.println("password (fine per uscire):");
                String password = userIn.readLine();

                if(password.equals("fine")) {
                    break;
                }

                System.out.println("Inserire tipologia di giocattolo (fine per uscire):");
                String tipologia = userIn.readLine();

                if(tipologia.equals("fine")) {
                    break;
                }

                networkOut.write(username);
                networkOut.newLine();
                networkOut.write(password);
                networkOut.newLine();
                networkOut.write(tipologia);
                networkOut.newLine();

                networkOut.flush();

                String theLine;
                for(;;)
                {
                    theLine = networkIn.readLine();

                    if(theLine == null)
                    {
                        System.err.println("Errore! Il server ha chiuso la connessione");
                        System.exit(2);
                    }

                    System.out.println(theLine);

                    if(theLine.equals("--- END REQUEST ---"))
                    {
                        break;
                    }
                }

            }
            theSocket.close();
        }
        catch(IOException e)
        {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(3);;
        }
    }
}
