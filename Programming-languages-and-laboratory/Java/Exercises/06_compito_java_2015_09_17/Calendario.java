import java.util.*;
import java.io.*;

public class Calendario {
    public static void main(String[] args) {
        List<Partita> partite = new LinkedList<Partita>();
        Map<String, Integer> p_vinte = new HashMap<String, Integer>();
        int casa = 0, fuoricasa = 0;
        int vinte_casa = 0, vinte_fuoricasa = 0;
        int trovato = 0;

        // punto 1, memorizzazione delle partite
        try {
            BufferedReader br = new BufferedReader(new FileReader("partite.txt"));
            String line = br.readLine();

            while (line != null) {
                StringTokenizer tok = new StringTokenizer(line);
                String tipo = tok.nextToken();
                String palazzetto_citta = tok.nextToken();
                String data = tok.nextToken();
                String ora = tok.nextToken();
                String risultato = tok.nextToken();
                int vinta = Integer.parseInt(tok.nextToken());

                if (tipo.equals("c")) {
                    Partita p = new InCasa(data, ora, risultato, vinta, palazzetto_citta);
                    partite.add(p);
                    casa++;
                } else {
                    Partita p = new FuoriCasa(data, ora, risultato, vinta, palazzetto_citta);
                    partite.add(p);
                    fuoricasa++;
                }
                line = br.readLine();
            }
            br.close();

        } catch (IOException e) {
            System.err.println(e);

        } catch (Exception e) {
            System.err.println(e);
        }

        // punto 2, stampa elenco partite
        System.out.println("Palazzetto\tCitta\tData\tOra\tRisultato");
        for (Partita p : partite) {
            System.out.println(p);
        }

        // punto 3, stampa numero totale partite giocate in case e fuori casa e numero
        // partite vinte per ciascuno

        for (Partita p : partite) {
            if (p instanceof InCasa) {
                int vinta = p.getVinta();
                if (vinta == 1) {
                    Integer n = p_vinte.get(casa + " partite in casa");
                    if (n == null)
                        p_vinte.put(casa + " partite in casa", 1);
                    else
                        p_vinte.put(casa + " partite vinte in casa", n + 1);
                }
            } else {
                int vinta = p.getVinta();
                if (vinta == 1) {
                    Integer n = p_vinte.get(fuoricasa + " partite fuori casa");
                    if (n == null)
                        p_vinte.put(fuoricasa + " partite fuori casa", 1);
                    else
                        p_vinte.put(fuoricasa + " partite fuori casa", n + 1);
                }
            }
        }
        System.out.println(p_vinte);

        for (Partita p : partite) {
            if (p instanceof FuoriCasa) {
                String citta = ((FuoriCasa) p).getCitta();
                if (citta.equals(args[0])) {
                    System.out.println(p);
                    trovato = 1;
                }
            }
        }
        if (trovato == 0)
            System.out.println("\n Partita a " + args[0] + " non ancora giocata");
    }
}