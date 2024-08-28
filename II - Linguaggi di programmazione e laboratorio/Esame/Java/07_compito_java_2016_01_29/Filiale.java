import java.util.*;
import java.io.*;

public class Filiale {
    public static void main(String[] args) {
        List<Cliente> clienti = new LinkedList<Cliente>();
        Map<String, Integer> premi = new HashMap<String, Integer>();
        int premioMax = 0;
        String clientePremioMax = "";

        try {
            BufferedReader br = new BufferedReader(new FileReader("clienti.txt"));
            String line = br.readLine();

            while (line != null) {
                StringTokenizer tok = new StringTokenizer(line);
                String tipo = tok.nextToken();
                int codice = Integer.parseInt(tok.nextToken());
                String indirizzo = br.readLine();
                line = br.readLine();

                tok = new StringTokenizer(line);
                int giorno = Integer.parseInt(tok.nextToken());
                int mese = Integer.parseInt(tok.nextToken());
                int anno = Integer.parseInt(tok.nextToken());

                String nomeRagioneSociale = br.readLine();

                if (tipo.equals("privato")) {
                    Cliente c = new Privato(codice, indirizzo, giorno, mese, anno, nomeRagioneSociale);
                    clienti.add(c);
                } else {
                    int fatturato = Integer.parseInt(br.readLine());
                    Cliente c = new Azienda(codice, indirizzo, giorno, mese, anno, nomeRagioneSociale, fatturato);
                    clienti.add(c);
                }

                line = br.readLine();

                int premiTot = 0;

                while (line != null && !(line.isEmpty())) {
                    int premio = Integer.parseInt(line);
                    premiTot = premiTot + premio;
                    line = br.readLine();
                }

                premi.put(nomeRagioneSociale, new Integer(premiTot));

                line = br.readLine();

                if (premioMax < premiTot) {
                    premioMax = premiTot;
                    clientePremioMax = nomeRagioneSociale;
                }

            }

            br.close();

        } catch (IOException e) {
            System.err.println(e);
        }

        catch (Exception e) {
            System.err.println(e);
        }

        System.out.println("Tipo\tCodice\tNome\tRagioneSociale\tIndirizzo\tData\tFatturato");

        for (Cliente c : clienti) {
            System.out.println(c);
        }

        System.out.println("\nSomma dei premi per cliente");
        System.out.println(premi);

        System.out.println("\nCliente con massima somma dei premi");
        System.out.println(clientePremioMax);
    }
}