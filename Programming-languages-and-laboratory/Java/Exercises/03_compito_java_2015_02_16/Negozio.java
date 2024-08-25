import java.io.*;
import java.util.*;

public class Negozio {

    public static void main(String[] args) {

        List<Prodotto> prodotti = new LinkedList<Prodotto>();
        Map<String, Integer> prodotti_autore = new HashMap<String, Integer>();

        // PUNTO 1: memorizzazione prodotti
        try {
            BufferedReader br = new BufferedReader(new FileReader("vendite.txt"));
            String line = br.readLine(); // prima riga: tipo+codice
            while (line != null) {
                // lettura di 1 prodotto
                StringTokenizer tokenizer = new StringTokenizer(line);
                String type = tokenizer.nextToken();
                int id = Integer.parseInt(tokenizer.nextToken());
                String titolo = br.readLine();
                String autori = br.readLine();
                int prezzo = Integer.parseInt(br.readLine());
                String isbn_durata = br.readLine();

                /* PUNTO 3 */
                Integer pezzi = prodotti_autore.get(autori);
                if (pezzi == null)
                    prodotti_autore.put(autori, new Integer(1));
                else
                    prodotti_autore.put(autori, new Integer(pezzi + 1));
                /* PUNTO 3 */

                line = br.readLine();
                if (line == null) { // EOF
                    if (type.equals("libro")) {
                        Prodotto p = new Libro(id, titolo, autori, prezzo, isbn_durata);
                        prodotti.add(p);
                    } else {
                        int d = Integer.parseInt(isbn_durata);
                        Prodotto p = new Cd(id, titolo, autori, prezzo, d);
                        prodotti.add(p);
                    }
                    br.close();
                } else { // line is empty
                    if (type.equals("libro")) {
                        Prodotto p = new Libro(id, titolo, autori, prezzo, isbn_durata);
                        prodotti.add(p);
                    } else {
                        int d = Integer.parseInt(isbn_durata);
                        Prodotto p = new Cd(id, titolo, autori, prezzo, d);
                        prodotti.add(p);
                    }
                    line = br.readLine();
                } // else
            } // while
            br.close();
            System.out.println("Totale prodotti letti: " + prodotti.size() + "\n"); // controllo lettura
        } catch (IOException e) {
            System.err.println(e);
        } catch (Exception e) {
            System.err.println(e);
        }
        // PUNTO 2
        System.out.println("Tipo\tCodice\tTitolo\tAutori\tPrezzo\tISBN\tDurata");
        for (Prodotto p : prodotti)
            System.out.println(p);

        // PUNTO 3
        System.out.println("\nN. prodotti per autore");
        System.out.println(prodotti_autore);

        // PUNTO 4
        float tot = 0;
        for (Prodotto p : prodotti)
            tot = tot + p.getPrezzo();
        float media = tot / prodotti.size();
        System.out.println("\nPrezzo medio = " + media);

    }// main
}// class