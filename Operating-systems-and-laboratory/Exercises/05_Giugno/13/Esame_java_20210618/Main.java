import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    public static void main(String[] args) {
        PipedInputStream pis = new PipedInputStream();
        PipedOutputStream pos = null;

        try {
            pos = new PipedOutputStream(pis);
        } catch (IOException e) {
            System.err.println("Errore pipe Main");
            System.exit(-1);
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Inserisci il valore di soglia critica tra 100 e 200");

        int soglia = 0;

        try {
            soglia = Integer.parseInt(br.readLine());
        } catch (IOException e) {
            System.err.println("Errore parseInt - readLine Main");
        }

        if (soglia < 100 || soglia > 200) {
            System.out.println("Errore: il valore non è compreso tra 100 e 200 (" + soglia + ")");
            System.exit(-2);
        }

        GeneraRilevazioni gr = new GeneraRilevazioni(pos);
        gr.start();

        ObjectInputStream ois = null;
        try {
            ois = new ObjectInputStream(pis);
        } catch (IOException e) {
            System.err.println("Errore ObjectInputStream Main");
            System.exit(-3);
        }

        int count = 0;
        int countCons = 0;
        Rilevazione r = null;

        while (count < 10) {
            try {
                r = (Rilevazione) ois.readObject();
            } catch (IOException | ClassNotFoundException e) {
                System.err.println("Errore readObject Main");
            }

            if (r.getValore() <= 50) {
                System.out.println("Basso - " + r.getValore());
            } else if (r.getValore() <= 100) {
                System.out.println("Moderato - " + r.getValore());
            } else {
                System.out.println("Alto - " + r.getValore());
            }

            if (r.getValore() > soglia) {
                countCons++;
            } else {
                countCons = 0;
            }

            if (countCons >= 3) {
                System.out.println("Attenzione");
            }

            count++;
        }

        gr.terminaRilevazioni();

        try {
            gr.join();
        } catch (InterruptedException e) {
            System.err.println("Errore join Main");
        }

        System.out.println("Il thread GeneraRilevazione è terminato!");
    }
}