import java.io.*;

public class Main {
    public static void main(String[] args) {
        PipedInputStream pis = new PipedInputStream();
        PipedOutputStream pos = null;

        try {
            pos = new PipedOutputStream(pis);
        } catch (IOException e) {
            System.err.println("Main--- errore creazione pipe");
            System.exit(-1);
        }

        SimulaConsumoCarburante scc = new SimulaConsumoCarburante(pos);

        int soglia = 0;
        System.out.println("Inserisci un valore di soglia: ");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try {
            soglia = Integer.parseInt(br.readLine());
        } catch (IOException e) {
            System.err.println("Main--- errore parseInt o readLine per soglia");
            System.exit(-2);
        }

        int numeroRilevazione = 1;
        scc.start();
        ObjectInputStream ois = null;

        try {
            ois = new ObjectInputStream(pis);
        } catch (IOException e) {
            System.err.println("Main--- errore ObjectInputStream");
            System.exit(-3);
        }

        CarburanteAttuale ca = null;

        while (numeroRilevazione <= 60) {
            try {
                ca = (CarburanteAttuale) ois.readObject();
            } catch (IOException | ClassNotFoundException e) {
                System.err.println("Main--- errore readObject");
            }

            System.out.println(
                    "Attuale livello di carburante: " + ca.getCarburante() + " (" + numeroRilevazione + " s.)");
            if (ca.getCarburante() < soglia) {
                System.out.println("Warning: livello carburante inferiore a soglia indicata");
            }

            numeroRilevazione++;
        }

        scc.termina();

        try {
            scc.join();
            Thread.currentThread().interrupt();
        } catch (InterruptedException e) {
            System.err.println("Main--- errore join");
        }

        System.out.println("Programma concluso.");

    }
}