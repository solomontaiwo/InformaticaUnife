import java.util.*;
import java.io.*;

public class Magazzini {
    public static void main(String[] args) {
        List<Prodotto> prodotti = new LinkedList<Prodotto>();
        Map<String, Integer> tot_pezzi = new HashMap<String, Integer>();
        Map<String, Float> avPezzi = new HashMap<String, Float>();

        try {
            BufferedReader br = new BufferedReader(new FileReader("inventario.txt"));
            String line = br.readLine(); // legge la prima riga, tipo + codice

            while (line != null) {
                StringTokenizer tok = new StringTokenizer(line);
                String tipo = tok.nextToken();
                int codice = Integer.parseInt(tok.nextToken());
                String modello = br.readLine();
                String produttore = br.readLine();
                line = br.readLine();
                tok = new StringTokenizer(line);
                int giorno = Integer.parseInt(tok.nextToken());
                int mese = Integer.parseInt(tok.nextToken());
                int anno = Integer.parseInt(tok.nextToken());
                int prezzo = Integer.parseInt(br.readLine());

                if (tipo.equals("toner")) {
                    String modelloStampante = br.readLine();
                    Prodotto a = new Toner(codice, modello, produttore, giorno, mese, anno, prezzo, modelloStampante);
                    prodotti.add(a);
                } else {
                    int peso = Integer.parseInt(br.readLine());
                    Prodotto a = new Stampante(codice, modello, produttore, giorno, mese, anno, prezzo, peso);
                    prodotti.add(a);
                }
                line = br.readLine();

                int i = 0, pezziTot = 0;
                while (line != null && !line.isEmpty()) {
                    int pezzi = Integer.parseInt(line);
                    i = i + 1;
                    pezziTot = pezziTot + pezzi;
                    line = br.readLine();
                }

                // PUNTO 3
                tot_pezzi.put(modello, new Integer(pezziTot));

                // PUNTO 4
                avPezzi.put(modello, new Float(((float) pezziTot) / i));
                line = br.readLine();
            }
            br.close();
        } catch (IOException e) {
            System.err.println(e);
        } catch (Exception e) {
            System.err.println(e);
        }

        // PUNTO 2 - stampa elenco prodotti
        System.out.println("Tipo\tCodice\tModello\tProduttore\tData\tPrezzo\tModelloStampante\tPeso");
        for (Prodotto a : prodotti)
            System.out.println(a);

        // PUNTO 3 - stampa numero totale di pezzi
        System.out.println("\nN. totale pezzi di ciascun modello: " + tot_pezzi);

        // PUNTO 4 - stampa numero medio pezzi per magazzino
        System.out.println("\nN. medio pezzi per magazzino di ciascun modello: " + avPezzi);
    }
}