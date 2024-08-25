import java.util.*;
import java.io.*;

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

        int soglia = 0;

        while (true) {
            System.out.println("Inserire il valore di soglia: ");
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            try {
                soglia = Integer.parseInt(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            } catch (NumberFormatException e) {
                System.out.println("La soglia deve essere un intero");
                continue;
            }

            if (soglia >= 100 && soglia <= 200)
                break;
            else
                System.out.println("La soglia deve essere un intero tra 100 e 200");
        }

        GeneraRilevazioni gr = new GeneraRilevazioni(pos);
        gr.start();

        ObjectInputStream ois = null;
        try {
            ois = new ObjectInputStream(pis);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }

        int count = 0;
        int countCons = 0;
        Rilevazione r = null;

        while (count < 10) {
            try {
                r = (Rilevazione) ois.readObject();
            } catch (IOException e) {
                e.printStackTrace();
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            }

            if (r.getValore() <= 50) {
                System.out.println("Basso - " + r.getValore());
            } else if (r.getValore() <= 100)
                System.out.println("Moderato - " + r.getValore());
            else
                System.out.println("Alto - " + r.getValore());

            if (r.getValore() > soglia)
                countCons++;
            else
                countCons = 0;

            if (countCons >= 3)
                System.out.println("Attenzione");

            count++;
        }

        gr.terminaRilevazioni();
        try {
            gr.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Il thread GeneraRilevazioni è terminato");
    }
}