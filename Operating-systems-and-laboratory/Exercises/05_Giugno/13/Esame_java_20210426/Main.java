import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    public static void main(String[] args) {
        PipedInputStream pis = new PipedInputStream();
        PipedOutputStream pos = null;

        try {
            pos = new PipedOutputStream(pis);
        } catch (IOException e) {
            System.err.println("Errore PipedOutputStream Main");
            System.exit(-1);
        }

        BufferedReader br = new BufferedReader(new InputStreamReader(pis));
        RilevatoreAria ra = new RilevatoreAria(pos);

        ra.start();

        long oldTime = 0;

        for (int i = 0; i < 8; i++) {
            int val = 0;
            long newTime = 0L;
            try {
                val = Integer.parseInt(br.readLine());
                newTime = Long.parseLong(br.readLine());
            } catch (IOException e) {
                System.err.println("Errore parse Main");
            }

            if (val < 20)
                System.out.println("Basso (" + val + ")");
            else if (val < 75)
                System.out.println("Medio (" + val + ")");
            else
                System.out.println("Alto (" + val + ")");

            long elapsedTime = newTime - oldTime;
            if (elapsedTime > 15 && oldTime != 0)
                System.out.println("Attenzione (" + elapsedTime + ")");
            oldTime = newTime;
        }

        ra.fermaRilevatoreAria();

        try {
            ra.join();
            System.out.println("Il thread RilevatoreAria è terminato dopo aver prodotto 8 rilevazioni");
        } catch (InterruptedException e) {
            System.err.println("Errore join Main");
        }
    }
}