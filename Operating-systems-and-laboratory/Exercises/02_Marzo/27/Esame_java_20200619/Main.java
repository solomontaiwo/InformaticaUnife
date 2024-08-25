import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    public static void main(String args[]) {
        PipedInputStream pis = new PipedInputStream();
        PipedOutputStream pos = null;

        try {
            pos = new PipedOutputStream(pis);
        } catch (IOException e) {
            System.err.println("Impossibile creare PipedOutputStream");
            System.exit(-1);
        }

        InputUtente iu = new InputUtente(pos);
        ScansionaInput si = new ScansionaInput(pis);

        Thread tiu = new Thread(iu);
        Thread tsi = new Thread(si);

        tiu.start();
        tsi.start();

        try {
            Thread.sleep(30000);
            System.out.println("Il programma sta per terminare...");
            iu.stop();
            si.stop();
            tiu.join();
            tsi.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}