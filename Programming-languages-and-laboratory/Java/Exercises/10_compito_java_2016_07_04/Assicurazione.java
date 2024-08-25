import java.io.*;
import java.util.*;

public class Assicurazione {

    static List<Filiale> filiali = new LinkedList<Filiale>();
    static List<Cliente> clienti = new LinkedList<Cliente>();

    public static void main(String[] args) {

        // PUNTO 1: memorizzazione filiali
        try {
            BufferedReader br = new BufferedReader(new FileReader("filiali.txt"));
            String line = br.readLine();
            while (line != null) {
                String nomeFil = line;
                int cod = Integer.parseInt(br.readLine());
                String indirizzo = br.readLine();
                Filiale f = new Filiale(cod, nomeFil, indirizzo);
                filiali.add(f);
                line = br.readLine();
                line = br.readLine();
            }
            br.close();
        } catch (IOException e) {
            System.err.println(e);
        } catch (Exception e) {
            System.err.println(e);
        }

        // PUNTO 2: lettura di tutti i clienti

        try {
            BufferedReader br = new BufferedReader(new FileReader("clienti.txt"));
            String line = br.readLine();
            while (line != null) {
                StringTokenizer tok = new StringTokenizer(line);
                // statistiche
                String tipo = tok.nextToken();
                int cod = Integer.parseInt(tok.nextToken());
                String nome = br.readLine();
                int filAtt = Integer.parseInt(br.readLine());
                Filiale fa = trovaFiliale(filAtt);
                line = br.readLine();
                tok = new StringTokenizer(line);
                List<Filiale> filpass = new LinkedList<Filiale>();
                while (tok.hasMoreTokens()) {
                    int fcod = Integer.parseInt(tok.nextToken());
                    filpass.add(trovaFiliale(fcod));
                }
                float p = Float.parseFloat(br.readLine());
                if (tipo.equals("azienda")) {
                    float pt = Float.parseFloat(br.readLine());
                    Azienda a = new Azienda(cod, nome, p, fa, filpass, pt);
                    clienti.add(a);
                } else {
                    Privato pr = new Privato(cod, nome, p, fa, filpass);
                    clienti.add(pr);
                }
                line = br.readLine();
                line = br.readLine();
            }
            br.close();
        } catch (IOException e) {
            System.err.println(e);
        } catch (Exception e) {
            System.err.println(e);
        }

        // PUNTO 3: stampa di tutti i clienti
        System.out.println(
                "tipo, nome e cognome o ragione sociale, codice, nome filiale attuale, premio corrente, premio corrente più tasse");
        for (Cliente c : clienti)
            System.out.println(c);

        System.out.println();
        // PUNTO 4: conteggio clienti per filiale
        for (Filiale f : filiali)
            System.out.println(f);

    }// main

    private static Filiale trovaFiliale(int codice) {
        Filiale fi = null;
        for (Filiale f : filiali)
            if (f.getCodice() == codice)
                fi = f;
        return fi;
    }
}
