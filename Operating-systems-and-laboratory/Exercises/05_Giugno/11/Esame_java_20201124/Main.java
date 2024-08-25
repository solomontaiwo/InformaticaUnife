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
        }

        Machine mac = new Machine(pos);
        Quality qua = new Quality(pis);

        mac.start();
        qua.start();

        try {
            Thread.sleep(15 * 1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        mac.termina();
        qua.termina();

        try {
            mac.join();
            qua.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Terminazione main...");
    }
}