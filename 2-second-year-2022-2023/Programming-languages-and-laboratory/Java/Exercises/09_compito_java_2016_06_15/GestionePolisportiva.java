import java.util.*;
import java.io.*;

public class GestionePolisportiva {
    static List<Squadra> squadre = new LinkedList<Squadra>();

    public static void main(String[] args) {

        // PUNTO 1: lettura e memorizzazione dati file squadre.txt
        try {
            BufferedReader br = new BufferedReader(new FileReader("squadre.txt"));
            String line = br.readLine();

            while (line != null) {
                String nome = line;
                line = br.readLine();
                StringTokenizer tok = new StringTokenizer(line);
                int codice = Integer.parseInt(tok.nextToken());
                String sport = tok.nextToken();
                line = br.readLine();
                tok = new StringTokenizer(line);
                int vinte = Integer.parseInt(tok.nextToken());
                int perse = Integer.parseInt(tok.nextToken());

                if (sport.equals("pallavolo")) {
                    float setVintiMedia = Float.parseFloat(tok.nextToken());
                    Squadra s = new Pallavolo(nome, codice, sport, vinte, perse, setVintiMedia);
                    squadre.add(s);
                } else {
                    float punteggioMedio = Float.parseFloat(tok.nextToken());
                    Squadra s = new Basket(nome, codice, sport, vinte, perse, punteggioMedio);
                    squadre.add(s);
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

        // PUNTO 2: lettura e memorizzazione dati file giocatori.txt

        try {
            BufferedReader br = new BufferedReader(new FileReader("giocatori.txt"));
            String line = br.readLine();

            while (line != null) {
                StringTokenizer tok = new StringTokenizer(line);
                int codiceSquadra = Integer.parseInt(tok.nextToken());
                String cognome = tok.nextToken();
                int eta = Integer.parseInt(tok.nextToken());
                int numeroMaglia = Integer.parseInt(tok.nextToken());
                String ruolo = tok.nextToken();
                Boolean titolare = Boolean.parseBoolean(tok.nextToken());
                Giocatore g = new Giocatore(codiceSquadra, cognome, eta, numeroMaglia, ruolo, titolare);
                trovaSquadra(codiceSquadra).addGiocatore(g);
                line = br.readLine();
            }

            br.close();

        } catch (IOException e) {
            System.err.println(e);
        } catch (Exception e) {
            System.err.println(e);
        }

        // PUNTO 3: stampa elenco di tutte le squadre della polisportiva
        for (Squadra s : squadre)
            System.out.println(s);

        // PUNTO 4: conteggio giocatori per squadra
        System.out.println("N. giocatori per squadra\n");
        for (Squadra s : squadre)
            System.out.println(s.getNome() + "\t" + s.nGiocatori());

        // PUNTO 5: stampe dei giocatori per squadra
        System.out.println("Giocatori della squadra " + args[0]);
        for (Giocatore g : trovaSquadra(args[0]).getGiocatori())
            System.out.println(g);
    }

    private static Squadra trovaSquadra(int codice) {
        Squadra sq = null;
        for (Squadra s : squadre)
            if (s.getCodice() == codice) sq = s;
        return sq;
    }

    private static Squadra trovaSquadra(String nome) {
        Squadra sq = null;
        for (Squadra s : squadre)
            if (s.getNome().equals(nome)) sq = s;
        return sq;
    }

}