package esame.es1;

import java.io.*;
import java.time.Year;

public class Esercizio1 {

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
        Thread tgD = new Thread(gd);
        tgD.start();

        ObjectInputStream dis = null;
        try {
            dis = new ObjectInputStream(pis);
        } catch(IOException e) {
            e.printStackTrace();
            System.exit(-2);
        }

        // per gestire la prima iterazione del ciclo
        // controllo umidita'
        boolean first = true;
        int umiditaPrecedente = 0;

        while(true) {
            Misure mis = null;
            try {
                mis = (Misure)dis.readObject();
            } catch(IOException | ClassNotFoundException e) {
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