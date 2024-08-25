import java.io.*;
import java.net.*;

public class ClientNaive {
    public static void main(String[] argv) {

        if (argv.length != 2) {
            System.err.println("Uso corretto: java ClientNaive server porta");
            System.exit(1);
        }

        try{
            BufferedReader fromUser = new BufferedReader(new InputStreamReader(System.in));

            while (true) {
                System.out.println("Inserisci il nome di un vino cui sei interessato ('fine' per uscire): ");
                String nomeVino = fromUser.readLine();

                if (nomeVino.equals("fine")){
                    System.out.println("Hai scelto di terminare il programma.");
                    break;
                }

                System.out.println("Inserisci l'annata di un vino cui sei interessato ('fine' per uscire): ");
                String annata = fromUser.readLine();

                if (annata.equals("fine")){
                    System.out.println("Hai scelto di terminare il programma.");
                    break;
                }

                Socket s = new Socket(argv[0], Integer.parseInt(argv[1]));

                BufferedReader fromServer = new BufferedReader(new InputStreamReader(s.getInputStream(),"UTF-8"));
                BufferedWriter toServer = new BufferedWriter(new OutputStreamWriter(s.getOutputStream(),"UTF-8"));

                toServer.write(nomeVino);
                toServer.flush();

                String buff = fromServer.readLine();

                if(!buff.equals("ack")){
                    System.err.println("Errore lettura Ack dal server");
                    System.exit(2);
                }

                toServer.write(annata);
                toServer.flush();

                while ((buff = fromServer.readLine()) != null) {
                    System.out.println(buff);
                }

                s.close();
            }

        }
        catch(IOException e){
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(3);
        }

    }
}
