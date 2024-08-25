import java.util.*;
import java.io.*;

public class GestioneAbbigliamento {
    static List<Articolo> articoli = new LinkedList<Articolo>();
    static List<Negozio> negozi = new LinkedList<Negozio>();

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader("articoli.txt"));
            String line = br.readLine();

            while (line != null) {
                StringTokenizer tok = new StringTokenizer(line);
                int codice = Integer.parseInt(tok.nextToken());
                String tipo = tok.nextToken();
                String marca = br.readLine();
                line = br.readLine();

                if (tipo.equals("giacca-a-vento")) {
                    String taglia = line;
                    String modello = br.readLine();
                    line = br.readLine();
                    tok = new StringTokenizer(line);
                    float costo = Float.parseFloat(tok.nextToken());
                    int tasche = Integer.parseInt(tok.nextToken());
                    int sconto = Integer.parseInt(tok.nextToken());
                    GiaccaAVento gav = new GiaccaAVento(codice, tipo, marca, taglia, modello, costo, tasche, sconto);
                    articoli.add(gav);
                } else {
                    tok = new StringTokenizer(line);
                    String taglia = tok.nextToken();
                    int peso = Integer.parseInt(tok.nextToken());
                    String modello = br.readLine();
                    line = br.readLine();
                    tok = new StringTokenizer(line);
                    float costo = Float.parseFloat(tok.nextToken());
                    int sconto = Integer.parseInt(tok.nextToken());
                    Piumino piu = new Piumino(codice, tipo, marca, taglia, peso, modello, costo, sconto);
                    articoli.add(piu);
                }

                line = br.readLine();
            }

        } catch (IOException e) {
            System.err.println(e);
        } catch (Exception e) {
            System.err.println(e);
        }
        /*
         * /
         * try {
         * BufferedReader br = new BufferedReader(new FileReader("negozi.txt"));
         * String line = br.readLine();
         * 
         * int codice = Integer.parseInt(line);
         * String nome = br.readLine();
         * String indirizzo = br.readLine();
         * 
         * } catch (IOException e) {
         * System.err.println(e);
         * } catch (Exception e) {
         * System.err.println(e);
         * }
         */

        System.out.println("tipo, codice, marca, modello, taglia, tasche, peso, costo, sconto");

        for (Articolo d : articoli)
            System.out.println(d);
    }
}