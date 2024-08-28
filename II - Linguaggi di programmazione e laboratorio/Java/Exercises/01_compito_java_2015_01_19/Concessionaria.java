import java.util.*;
import java.io.*;

public class Concessionaria {
    public static void main(String[] args) {
        List<Auto> automobili = new LinkedList<Auto>();
        Map<String, Integer> auto_pesi = new HashMap<String, Integer>();

        try {
            FileReader f = new FileReader("ordini.txt");
            BufferedReader bf = new BufferedReader(f);
            String line = bf.readLine();

            while (line != null) {
                StringTokenizer tok = new StringTokenizer(line);
                String tipo = tok.nextToken();
                String modello = tok.nextToken();
                String produttore = tok.nextToken();
                String bag_marce = tok.nextToken();
                int peso = Integer.parseInt(tok.nextToken());
                int codice = Integer.parseInt(tok.nextToken());

                if (tipo.equals("b")) {
                    double bagagliaio = Double.parseDouble(bag_marce);
                    Auto a = new Berlina(modello, produttore, bagagliaio, peso, codice);
                    automobili.add(a);
                } else {
                    int marce = Integer.parseInt(bag_marce);
                    Auto a = new Fuoristrada(modello, produttore, marce, peso, codice);
                    automobili.add(a);
                }
                line = bf.readLine();
            }
        } catch (IOException ex) {
            System.out.println(ex);
        }

        // punto 2
        System.out.println("Codice\tMarca\tModello\tBagagliaio\tMarce");
        for (Auto a : automobili) {
            System.out.println(a);
        }

        // punto 3
        System.out.println("\nN. AUTO PER RANGE DI PESO");
        for (Auto a : automobili) {
            int peso = a.getPeso();
            if (800 <= peso && peso <= 1000) {
                Integer n = auto_pesi.get("800-1000");
                if (n == null)
                    auto_pesi.put("800-1000", 1);
                else
                    auto_pesi.put("800-1000", n + 1);
            }
            if (1000 < peso && peso <= 1500) {
                Integer n = auto_pesi.get("1000-1500");
                if (n == null)
                    auto_pesi.put("1000-1500", 1);
                else
                    auto_pesi.put("1000-1500", n + 1);
            }
            if (1500 < peso && peso <= 2000) {
                Integer n = auto_pesi.get("1500-2000");
                if (n == null)
                    auto_pesi.put("1500-2000", 1);
                else
                    auto_pesi.put("1500-2000", n + 1);
            }
        }
        System.out.println(auto_pesi);

        // punto 4
        System.out.println("\nMODELLI PRESENTI PER LA MARCA " + args[0]);
        for (Auto a : automobili) {
            String prod = a.getProduttore();
            if (prod.equals(args[0]))
                System.out.println(a.getModello());
        }
    }
}