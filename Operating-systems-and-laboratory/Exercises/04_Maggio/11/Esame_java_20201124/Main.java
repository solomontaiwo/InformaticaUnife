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
            System.exit(-1);
        }

        // Creo i due thread
        Machine machine = new Machine(pos);
        Quality quality = new Quality(pis);

        // mando in esecuzione i thread
        machine.start();
        quality.start();

        try {
            Thread.currentThread().sleep(15000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        machine.termina();
        quality.termina();

        try {
            machine.join();
            quality.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}