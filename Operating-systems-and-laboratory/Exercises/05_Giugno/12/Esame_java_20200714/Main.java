import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        DatiAzionari datoAzionario = new DatiAzionari();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Inserire il nome dell'indice: ");
        String indice = null;

        try {
            indice = br.readLine();
        } catch (IOException e) {
            System.err.println("Impossibile leggere da tastiera");
            System.exit(-1);
        }

        datoAzionario.setIndice(indice);
        RecuperaDati rd = new RecuperaDati(datoAzionario);
        rd.start();

        int valorePrecedente = 0;
        boolean first = true;

        while (true) {
            try {
                Thread.currentThread().sleep(7000);
            } catch (InterruptedException e) {
                System.err.println("Errore sleep in main");
            }

            int valore = datoAzionario.getValore();
            if (valore > 70 || valore < 30) {
                System.out.println("Main--- riscontrato valore eccessivo (" + valore + ")");
                rd.terminaThread();
                break;
            }
        }

        try {
            rd.join();
        } catch (InterruptedException e) {
            System.err.println("Errore join in main");
            e.printStackTrace();
        }

        System.out.println("Main--- terminazione");
    }
}