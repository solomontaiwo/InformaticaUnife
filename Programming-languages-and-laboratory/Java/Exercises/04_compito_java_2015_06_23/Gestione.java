import java.util.*;
import java.io.*;

public class Gestione {
    public static void main(String[] args) {
        List<Appello> appelli = new LinkedList<Appello>();
        Map<String, Integer> appelli_docente = new HashMap<String, Integer>();

        // PUNTO 1: memorizzazione appelli

        try {
            BufferedReader br = new BufferedReader(new FileReader("appelli.txt"));
            String line = br.readLine();

            while (line != null) {
                StringTokenizer tok = new StringTokenizer(line);
                String type = tok.nextToken();
                int codice = Integer.parseInt(tok.nextToken());
                String docente = br.readLine();
                String corso = br.readLine();
                line = br.readLine();
                tok = new StringTokenizer(line);
                int giorno = Integer.parseInt(tok.nextToken());
                int mese = Integer.parseInt(tok.nextToken());
                int anno = Integer.parseInt(tok.nextToken());
                int ora = Integer.parseInt(br.readLine());

                // PUNTO 3 - NUMERO TOTALE DI APPELLI PER CIASCUN DOCENTE
                Integer app = appelli_docente.get(docente);
                if (app == null)
                    appelli_docente.put(docente, new Integer(1));
                else
                    appelli_docente.put(docente, new Integer(app + 1));
                // FINE PUNTO 3

                if (type.equals("scritto")) {
                    String aula = br.readLine();
                    int durata = Integer.parseInt(br.readLine());
                    Appello a = new Scritto(codice, docente, corso, giorno, mese, anno, ora, aula, durata);
                    appelli.add(a);
                } else {
                    int studenti = Integer.parseInt(br.readLine());
                    Appello a = new Orale(codice, docente, corso, giorno, mese, anno, ora, studenti);
                    appelli.add(a);
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

        // PUNTO 2
        System.out.println("Tipo\tCodice\tProfessore\tCorso\tData\tOra\tAula\tDurata\tStudentimax");
        for (Appello a : appelli)
            System.out.println(a);

        // PUNTO 3
        System.out.println("\nN. appelli per docente");
        System.out.println(appelli_docente);

        // PUNTO 4
        int ora_max = 0;
        for (Appello a : appelli) {
            if (a.getOra() > ora_max)
                ora_max = a.getOra();
        }
        System.out.println("\nOra max = " + ora_max);
    }
}