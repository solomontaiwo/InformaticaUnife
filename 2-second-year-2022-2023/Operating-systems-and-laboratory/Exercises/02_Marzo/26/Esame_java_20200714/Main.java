import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String args[]) {
        DatiAzionari datoAzionario = new DatiAzionari();

        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Inserire il nome dell'indice: ");
        String indice = null;

        try {
            indice = stdin.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }

        datoAzionario.setIndice(indice);
        RecuperaDati rd = new RecuperaDati(datoAzionario);
        rd.start();

        int valorePrecedente = 0;
        boolean first = true;

        while (true) {
            try {
                Thread.sleep(7000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            int valore = datoAzionario.getValore();
            System.out.println("Main--- indice: " + datoAzionario.getIndice() + "  valore: " + valore);
            if (valore > 70 || valore < 30) {
                System.out.println("Main--- riscontrato valore eccessivo termino");
                rd.terminaThread();
                break;
            }
        }

        try {
            rd.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Main--- termino");
    }
}