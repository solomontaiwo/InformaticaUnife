import java.io.*;
import java.time.Year;

public class Main {
    public static void main(String args[]) {
        PipedInputStream pis = new PipedInputStream();
        PipedOutputStream pos = null;

        try {
            pos = new PipedOutputStream(pis);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }

        GeneraDati gd = new GeneraDati(pos);
        Thread tgD = new Thread(gd);
        tgD.start();

        ObjectInputStream dis = null;
        try {
            dis = new ObjectInputStream(pis);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-2);
        }

        boolean first = true;
        int umiditaPrecedente = 0;

        while (true) {
            Misure mis = null;
            try {
                mis = (Misure) dis.readObject();
            } catch (IOException | ClassNotFoundException e) {
                System.err.println(e);
            }
            int umidita = mis.getUmidita();

            if (!first) {
                float variazione = (float) Math.abs(umidita - umiditaPrecedente) / umiditaPrecedente;
                System.out.println("Umidità variazione registrata: " + variazione);
                if (variazione > 0.2) {
                    System.out.println("Variazione superiore al 20%, termino!");
                    gd.finisci();
                    break;
                } else {
                    first = true;
                }

                umiditaPrecedente = umidita;
            }
        }
    }
}