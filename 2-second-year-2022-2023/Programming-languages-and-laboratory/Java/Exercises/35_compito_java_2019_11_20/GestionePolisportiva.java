
import java.util.*;
import java.io.*;

public class GestionePolisportiva {

    static List<Squadra> squadre = new LinkedList<Squadra>();
    static List<Giocatore> giocatori = new LinkedList<Giocatore>();
    static List<Squadra> pallamano = new LinkedList<Squadra>();
    static List<Squadra> hockey = new LinkedList<Squadra>();

    public static void main(String[] args) {

        // Svolgimento punto 1: vengono memorizzate le squadre all'interno del file squadre.txt
        try {
            BufferedReader br = new BufferedReader(new FileReader("squadre.txt"));
            String line = br.readLine();

            while (line != null) {
                StringTokenizer tok = new StringTokenizer(line);
                int codice = Integer.parseInt(tok.nextToken());
                String sport = tok.nextToken();
                line = br.readLine();
                tok = new StringTokenizer(line);
                String nomeSquadra = line;
                line = br.readLine();
                tok = new StringTokenizer(line);
                int vinte = Integer.parseInt(tok.nextToken());
                int perse = Integer.parseInt(tok.nextToken());

                if (sport.equals("hockey")) {
                    double gol = Double.parseDouble(tok.nextToken());
                    double falli = Double.parseDouble(tok.nextToken());
                    line = br.readLine();
                    Squadra s = new Hockey(codice, sport, nomeSquadra, vinte, perse, gol, falli);
                    squadre.add(s);
                    hockey.add(s);
                } else {
                    double reti = Double.parseDouble(tok.nextToken());
                    line = br.readLine();
                    Squadra s = new Pallamano(codice, sport, nomeSquadra, vinte, perse, reti);
                    squadre.add(s);
                    pallamano.add(s);
                }

                line = br.readLine();

            }

            br.close();

        } catch (IOException e) {
            System.err.println(e);
        } catch (Exception e) {
            System.err.println(e);
        }

        // Svolgimento punto 2: memorizzazione giocatori all'intern del file giocatori.txt
        try {
            BufferedReader br = new BufferedReader(new FileReader("giocatori.txt"));
            String line = br.readLine();

            while (line != null) {
                int codiceSquadra = Integer.parseInt(line);
                String cognome = br.readLine();
                String nome = br.readLine();
                line = br.readLine();
                StringTokenizer tok = new StringTokenizer(line);
                int eta = Integer.parseInt(tok.nextToken());
                int numeroMaglia = Integer.parseInt(tok.nextToken());
                String ruolo = tok.nextToken();
                boolean titolare = Boolean.parseBoolean(tok.nextToken());
                line = br.readLine();
                Giocatore g = new Giocatore(codiceSquadra, cognome, nome, eta, numeroMaglia, ruolo, titolare);
                giocatori.add(g);
            }

            br.close();

        } catch (IOException e) {
            System.err.println(e);
        } catch (Exception e) {
            System.err.println(e);
        }

        // Svolgimento punto 3: stampa di tutte le squadre della polisportiva
        System.out.println("nome della squadra\tcodice\tn. partite vinte\tn. partite perse\tn. medio di gol\tn.medio di falli\tn.medio di reti\tsport");

        for (Squadra s : squadre) {
            System.out.println(s);
        }

        // Svolgimento punto 4: stampa elenco giocatori
        System.out.println("nome\tcognome\tnumero di maglia\truolo\ttitolare\tnome squadra");

        for (Giocatore g : giocatori) {
            System.out.print(g);
            for (Squadra s : squadre) {
                if (g.codiceSquadra == s.codice) {
                    System.out.println(s.nome);
                }
            }
        }

        // Svolgimento punto 5: stampa media partite vinte
        System.out.println("media partite vinte delle squadre di hockey: " + media(hockey));
        System.out.println("media partite vinte delle squadre di hockey: " + media(pallamano));

    }

    private static double media(List<Squadra> squadre) {
        double somma = 0.0;
        for (Squadra s : squadre) {
            somma = somma + s.getVinte();
        }
        return somma / squadre.size();
    }
}
