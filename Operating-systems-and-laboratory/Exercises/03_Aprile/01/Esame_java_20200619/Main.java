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
            e.printStackTrace();
        }

        InputUtente iu = new InputUtente(pos);
        ScansionaInput si = new ScansionaInput(pis);
        Thread tiu = new Thread(iu);
        Thread tsi = new Thread(si);
        tiu.start();
        tsi.start();

        try {
            Thread.sleep(30 * 1000);
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