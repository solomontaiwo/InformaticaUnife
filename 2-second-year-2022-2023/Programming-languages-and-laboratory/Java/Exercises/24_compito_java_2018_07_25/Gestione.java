import java.util.*;
import java.io.*;

public class Gestione {
    static List<Progetto> progetti = new LinkedList<Progetto>();
    static List<Ricercatore> ricercatori = new LinkedList<Ricercatore>();
    static Map<Integer, Progetto> codProg = new HashMap<Integer, Progetto>();

    public static void main(String[] args) {

        // PUNTO 1: memorizzazione progetti
        try {
            BufferedReader br = new BufferedReader(new FileReader("progetti.txt"));
            String line = br.readLine();
            while (line != null) {
                StringTokenizer tok = new StringTokenizer(line);
                int cod = Integer.parseInt(tok.nextToken());
                String tipo = tok.nextToken();
                line = br.readLine();
                String titolo = line;
                line = br.readLine();
                String coord = line;
                line = br.readLine();
                String org = line;
                line = br.readLine();

                if (tipo.equals("ricerca")) {
                    tok = new StringTokenizer(line);
                    String arg = tok.nextToken();
                    int partner = Integer.parseInt(tok.nextToken());
                    line = br.readLine();
                    double tot = Double.parseDouble(line);
                    Ricerca t = new Ricerca(cod, titolo, coord, org, arg, partner, tot);
                    progetti.add(t);
                    codProg.put(cod, t);
                } else {
                    tok = new StringTokenizer(line);
                    int aziende = Integer.parseInt(tok.nextToken());
                    double tot = Double.parseDouble(tok.nextToken());
                    Innovazione i = new Innovazione(cod, titolo, coord, org, aziende, tot);
                    progetti.add(i);
                    codProg.put(cod, i);
                }
                line = br.readLine();
            }
            br.close();
        } catch (IOException e) {
            System.err.println(e);

        } catch (Exception e) {
            System.err.println(e);
        }

        // PUNTO 2: lettura di tutti i ricercatori

        try {
            BufferedReader br = new BufferedReader(new FileReader("ricercatori.txt"));
            String line = br.readLine();
            while (line != null) {
                String nome = line;
                line = br.readLine();
                String cognome = line;
                Ricercatore r = new Ricercatore(nome, cognome);
                ricercatori.add(r);
                line = br.readLine();
                while (line != null && !line.equals("")) {
                    StringTokenizer tok = new StringTokenizer(line);
                    int cod = Integer.parseInt(tok.nextToken());
                    double imp = Double.parseDouble(tok.nextToken());
                    r.addProg(codProg.get(cod), imp);
                    line = br.readLine();
                }
                line = br.readLine();
            }
            br.close();
        } catch (IOException e) {
            System.err.println(e);
        }

        // PUNTO 3: stampa di tutti i progetti
        System.out.println(
                "tipo, titolo, codice, coordinatore, organizzazione, argomento, partner, aziende, importo totale in migliaia di euro");
        for (Progetto p : progetti) {
            System.out.println(p);
            System.out.println();

            // PUNTO 4: stampa ricercatori
            for (Ricercatore r : ricercatori)
                System.out.println(r);

            // PUNTO 5: stampe dell'esame con voto piu' alto
            System.out.println();
            String cog = args[0];
            for (Ricercatore r : ricercatori) {
                if (r.getCognome().equals(cog)) {
                    Impegno i = r.getMax();
                    System.out.println(
                            r.getNome() + " " + r.getCognome() + " " + i.getOre() + " " + i.getProg().getTitolo());
                }
            }
        }
    }
}