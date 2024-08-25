import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    public static void main(String args[]) {
        PipedInputStream pis = new PipedInputStream();
        PipedOutputStream pos = null;

        try {
            pos = new PipedOutputStream(pis);

            RilevatoreAria ra = new RilevatoreAria(pos);
            ra.start();
            BufferedReader br = new BufferedReader(new InputStreamReader(pis));

            long oldtime = 0;
            for (int i = 0; i < 8; i++) {
                int val = Integer.parseInt(br.readLine());
                long newtime = Long.parseLong(br.readLine());

                if (val < 20)
                    System.out.println("Basso (" + val + ")");
                else if (val < 75)
                    System.out.println("Medio (" + val + ")");
                else
                    System.out.println("Alto (" + val + ")");

                long elapsedTime = newtime - oldtime;
                if (elapsedTime > 15 && oldtime != 0)
                    System.out.println("Attenzione (" + elapsedTime + ")");
                oldtime = newtime;
            }

            ra.fermaRilevatoreAria();

            try {
                ra.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}