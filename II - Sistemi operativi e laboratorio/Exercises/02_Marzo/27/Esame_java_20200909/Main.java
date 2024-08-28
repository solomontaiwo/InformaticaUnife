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
        } catch (IOException e1) {
            e1.printStackTrace();
            System.exit(-2);
        }

        GeneraDati gd = new GeneraDati(pos);
        Thread tgd = new Thread(gd);
        tgd.start();

        ObjectInputStream ois = null;

        try {
            ois = new ObjectInputStream(pis);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-2);
        }

        boolean first = true;
        int umiditaPrecedente = 0;

        while (true) {
            Misure mis = null;
            try {
                mis = (Misure) ois.readObject();
            } catch (IOException | ClassNotFoundException e) {
                System.err.println(e);
            }
            int umidita = mis.getUmidita();

            if (!first) {
                float variazione = (float) Math.abs(umidita - umiditaPrecedente) / umiditaPrecedente;
                System.out.println("Umidita' variazione registrata: " + variazione);
                if (variazione > 0.2) {
                    System.out.println("Variazione superiore al 20%, termino!");
                    gd.finisci();
                    break;
                }
            } else {
                first = false;
            }

            umiditaPrecedente = umidita;
        }
    }
}