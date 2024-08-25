import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    public static void main(String args[]) {
        PipedOutputStream pos = new PipedOutputStream();
        PipedInputStream pis = null;

        try {
            pis = new PipedInputStream(pos);
            BufferedReader br = new BufferedReader(new InputStreamReader(pis));

            RilevatoreAria ra = new RilevatoreAria(pos);
            ra.start();

            long oldTime = 0;

            for (int i = 0; i < 8; i++) {
                int val = Integer.parseInt(br.readLine());
                long newTime = Long.parseLong(br.readLine());

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
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            br.close();
            System.out.println("Il thread main ha completato la sua esecuzione");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}