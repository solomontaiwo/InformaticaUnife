import java.io.*;
import java.net.*;
import java.util.Vector;

public class ClientSimpleCSExp {
    public static void main(String[] argv) {

        if (argv.length != 2) {
            System.err.println("Uso corretto: java ClientSimpleCSExp server porta");
            System.exit(1);
        }

        try{
            BufferedReader fromUser = new BufferedReader(new InputStreamReader(System.in));

            Socket s = new Socket(argv[0], Integer.parseInt(argv[1]));

            BufferedReader fromServer = new BufferedReader(new InputStreamReader(s.getInputStream(),"UTF-8"));
            BufferedWriter toServer = new BufferedWriter(new OutputStreamWriter(s.getOutputStream(),"UTF-8"));

            while (true) {
                System.out.println("Inserisci la categoria di spese cui sei interessato ('fine' per uscire):");
                String categoria = fromUser.readLine();

                if (categoria.equals("fine")){
                    System.out.println("Hai scelto di terminare il programma.");
                    break;
                }

                // Invio il nome della categoria al server
                toServer.write("("+ categoria.length() + ":" + categoria + ")");
                toServer.flush();

                // Leggo la risposta finale del server e la stampo a video
                String respMesg;
                while ((respMesg = readMessage(fromServer)) != null) {
                    Vector<String> resp = parseCSExp(respMesg);
                    for (var m: resp) {
                        System.out.println(m);
                    }
                }
            }

            s.close();

        }
        catch(Exception e) {
            System.err.println(e.getMessage());
            e.printStackTrace();
            System.exit(2);
        }
    }

    static String readMessage(BufferedReader br) throws IOException
    {
        StringBuffer sb = new StringBuffer();
        char[] buf = new char[4096];

        int charsRead = br.read(buf, 0, buf.length);
        if (charsRead == -1) { // connection closed
            return null;
        }
        sb.append(buf, 0, charsRead);

        while (buf[charsRead-1] != ')') {
            charsRead = br.read(buf, 0, buf.length);
            if (charsRead == -1) { // connection closed
                break;
            }
            sb.append(buf, 0, charsRead);
        } 

        return sb.toString();
    }

    static Vector<String> parseCSExp(String s) throws Exception
    {
        int len = s.length();
        Vector<String> res = new Vector<String>();

        if (s.charAt(0) != '(' || s.charAt(len-1) != ')') {
            throw new Exception("Wrong message format!");
        }

        int index = 1;

        while (index < len-1) {
            int nextColonIndex = s.indexOf(':', index);
            int size = Integer.parseInt(s.substring(index, nextColonIndex));
            res.addElement(s.substring(nextColonIndex + 1, nextColonIndex + 1 + size));
            index = nextColonIndex + 1 + size;
        }

        return res;
    }
}
