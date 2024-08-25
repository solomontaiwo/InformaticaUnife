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

            System.out.println("Inserisci username: ");
            String username = fromUser.readLine();

            do {
                System.out.println("Inserisci password: ");
                String password = fromUser.readLine();

                System.out.println("Inserisci categoria macchine: ");
                String categoria_macchine = fromUser.readLine();

                Socket s = new Socket(argv[0], Integer.parseInt(argv[1]));
                BufferedReader fromServer = new BufferedReader(new InputStreamReader(s.getInputStream(),"UTF-8"));
                BufferedWriter toServer = new BufferedWriter(new OutputStreamWriter(s.getOutputStream(),"UTF-8"));

                toServer.write(username);
                toServer.flush();

                String buff = fromServer.readLine();
                if (!buff.equals("ack")) {
                    System.err.println("Errore lettura Ack dal server");
                    System.exit(2);
                }

                toServer.write(password);
                toServer.flush();

                buff = fromServer.readLine();
                if (!buff.equals("ack")) {
                    System.err.println("Errore lettura Ack dal server");
                    System.exit(2);
                }

                toServer.write(categoria_macchine);
                toServer.flush();

                while ((buff = fromServer.readLine()) != null) {
                    System.out.println(buff);
                }

                s.close();

                System.out.println("Inserisci username: ('fine' per terminare)");
                username = fromUser.readLine();
            } while(!username.equals("fine"));
        }
        catch(IOException e){
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(100);
        }
    }
}
