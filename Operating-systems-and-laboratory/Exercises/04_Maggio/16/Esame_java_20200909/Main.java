import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    public static void main(String args[]) {
        PipedInputStream pis = new PipedInputStream();
        PipedOutputStream pos = null;

        try {
            pos = new PipedOutputStream(pis);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-2);
        }

        GeneraDati gd = new GeneraDati(pos);
        Thread tdg = new Thread(gd);
        tdg.start();

        boolean first = true;
        int precedente = 0;

        ObjectInputStream ois = null;

        try {
            ois = new ObjectInputStream(pis);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-3);
        }

        while (true) {
            Misure mis = null;
            try {
                mis = (Misure) ois.readObject();
            } catch (IOException | ClassNotFoundException e) {
                System.err.println(e);
            }

            int umidita = mis.getUmidita();

            if (!first) {
                float variazione = (float) Math.abs(umidita - precedente) / precedente;
                System.out.println("Umidita' variazione registrata: " + variazione);
                if (variazione > 0.2) {
                    System.out.println("Variazione superiore al 20%, termino...");
                    gd.finisci();
                    break;
                }
            } else {
                first = false;
            }

            precedente = umidita;
        }
    }
}