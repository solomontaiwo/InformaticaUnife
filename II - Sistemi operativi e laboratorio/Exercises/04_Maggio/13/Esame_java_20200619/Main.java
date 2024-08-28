import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    public static void main(String[] args) {
        PipedInputStream pis = new PipedInputStream();
        PipedOutputStream pos = null;

        try {
            pos = new PipedOutputStream(pis);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }

        InputUtente iu = new InputUtente(pos);
        Thread tiu = new Thread(iu);
        tiu.start();

        ScansionaInput si = new ScansionaInput(pis);
        Thread tsi = new Thread(si);
        tsi.start();

        try {
            Thread.currentThread().sleep(30 * 1000);
            System.out.println("Il programma sta per terminare...");
            iu.stop();
            si.stop();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        try {
            tiu.join();
            tsi.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}