import java.util.*;
import java.io.*;

public class GestioneStudioMedico {
    // predispongo le liste collegate per gli operatori ed i pazienti
    static List<Operatore> operatori = new LinkedList<Operatore>();
    static List<Paziente> pazienti = new LinkedList<Paziente>();

    // predispongo hashmap per poter ricavare il paziente dal solo codice
    // static Map<Integer, Paziente> daCodice_a_Paziente = new HashMap<Integer,
    // Paziente>();

    public static void main(String[] args) {

        // PUNTO 1: MEMORIZZAZIONE OPERATORI

        try {
            // apro il file di testo per la lettura creando il bufferedreader
            BufferedReader br = new BufferedReader(new FileReader("operatori.txt"));

            // leggo la prima linea e continuo a farlo finchè questa non è vuota
            String line = br.readLine();

            while (line != null) {
                // uso stringtokenizer perchè ci sono più elementi da memorizzare sulla stessa
                // linea
                StringTokenizer tok = new StringTokenizer(line);

                // uso Integer.parseInt per convertire la stringa tokenizzata in integer
                int codice_operatore = Integer.parseInt(tok.nextToken());

                String tipo = tok.nextToken();

                String nome_operatore = br.readLine();

                // stesso discorso del codice_operatore, uso Double.parseDouble per convertire
                // la stringa letta da br.readLine in double
                double costo_visita = Double.parseDouble(br.readLine());

                // procedo a seconda del tipo di operatore, medico o terapista
                if (tipo.equals("medico")) {
                    String specialita = br.readLine();
                    // leggo tutta linea successiva e ne divido i contenuti per memorizzarli
                    // separatamente con stringtokenizer, come fatto in precedenza
                    line = br.readLine();
                    tok = new StringTokenizer(line);
                    int n_visite_mese_precedente = Integer.parseInt(tok.nextToken());
                    String ambulatorio = tok.nextToken();

                    // creo l'oggetto "med", con classe Medico, da inserire nella lista collegata
                    // degli operatori
                    Medico med = new Medico(codice_operatore, tipo, nome_operatore, costo_visita, specialita,
                            n_visite_mese_precedente, ambulatorio);
                    operatori.add(med);

                } else {
                    // caso in cui l'operatore sia un terapista
                    String terapia = br.readLine();
                    // leggo tutta linea successiva e ne divido i contenuti per memorizzarli
                    // separatamente con stringtokenizer, come fatto in precedenza
                    line = br.readLine();
                    tok = new StringTokenizer(line);
                    String studio = tok.nextToken();
                    int n_sedute_terapia = Integer.parseInt(tok.nextToken());

                    // creo l'oggetto "ter", classe Terapista, che inserisco nella lista collegata
                    // degli operatori
                    Terapista ter = new Terapista(codice_operatore, tipo, nome_operatore, costo_visita, terapia, studio,
                            n_sedute_terapia);
                    operatori.add(ter);

                }

                // procedo con la lettura della linea successiva per memorizzare il prossimo
                // operatore
                line = br.readLine();

            }
            // chiudo la lettura del file per evitare leak
            br.close();

        } catch (IOException e) {
            System.err.println(e);
        } catch (Exception e) {
            System.err.println(e);
        }

        // PUNTO 2: MEMORIZZAZIONE PAZIENTI

        try {
            BufferedReader br = new BufferedReader(new FileReader("pazienti.txt"));
            String line = br.readLine();

            while (line != null) {
                int codice_paziente = Integer.parseInt(line);
                String nome_paziente = br.readLine();

                Paziente paz = new Paziente(codice_paziente, nome_paziente);
                pazienti.add(paz);

                // aggiungo il paziente all'hashmap con il metodo ".put"
                // daCodice_a_Paziente.put(codice_paziente, paz);

                line = br.readLine();
                StringTokenizer tok = new StringTokenizer(line);

                // finchè non sono alla fine del file pazienti.txt e tok contiene token, procedo
                // con la memorizzazione dei valori
                while (line != null && tok.hasMoreTokens()) {
                    int codice_operatore = Integer.parseInt(tok.nextToken());
                    int n_sedute = Integer.parseInt(tok.nextToken());

                    // creo l'oggetto vis, classe Visita, che aggiungo attraverso il metodo
                    // "addVisita" della classe "Paziente all'oggetto "paz" creato poco
                    // sopra
                    Visita vis = new Visita(codice_operatore, n_sedute);
                    paz.addVisita(vis);

                    // incremento il numero di visite totali del paziente attraverso il metodo
                    // creato appositamente nella classe "Paziente"
                    paz.incrementaNumeroVisiteTotali(n_sedute);
                }

                line = br.readLine();
            }

            br.close();

        } catch (IOException e) {
            System.err.println(e);
        } catch (Exception e) {
            System.err.println(e);
        }

        // PUNTO 1: STAMPA ELENCO OPERATORI
        System.out.println(
                "nome operatore, codice, costo, specialità, visite, ambulatorio, terapia, studio, sedute, tipo");

        for (Operatore op : operatori) {
            System.out.println(op);
        }

        System.out.println(); // spazio vuoto per maggiore chiarezza in stampa

        // PUNTO 2: STAMPA ELENCO PAZIENTI
        System.out.println("codice, nome, numero operatori, visite");

        for (Paziente pa : pazienti) {
            System.out.println(pa);
        }

        System.out.println(); // spazio vuoto per maggiore chiarezza in stampa

        // PUNTO 3: STAMPA NOME PAZIENTE E NUMERO TOTALE DI VISITE DA CODICE LETTO DA
        // RIGA DI COMANDO

        try {
            int codiceInserito = Integer.parseInt(args[0]);

            for (Paziente pazie : pazienti) {
                if (pazie.codice_paziente == codiceInserito) {
                    System.out.println("Numero di visite del paziente " + pazie.getNomePaziente() + ": "
                            + pazie.getNumeroVisiteTotali());
                }
            }
        } catch (Exception e) {
            System.err.println(e);
        }
    }
}
