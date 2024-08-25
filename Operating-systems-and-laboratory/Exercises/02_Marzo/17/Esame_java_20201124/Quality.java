import java.util.*;
import java.io.*;
import java.util.concurrent.atomic.AtomicBoolean;

public class Quality extends Thread {
    private PipedInputStream pis = null;
    private AtomicBoolean isRunning = new AtomicBoolean(false);

    public Quality(PipedInputStream pis) {
        this.pis = pis;
    }

    public void run() {
        isRunning.set(true);

        ObjectInputStream ois = null;

        try {
            ois = new ObjectInputStream(pis);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }

        while (isRunning.get()) {
            try {
                Message m = (Message) ois.readObject();

                float findicator = m.getFIndicator();

                if (findicator > 0) {
                    System.out.println("OK");
                } else {
                    System.out.println("Errore per pezzo numero " + m.getPezziProdotti());
                }
            } catch (IOException e) {
                e.printStackTrace();
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            }
        }

    }

    public void termina() {
        isRunning.set(false);
    }
}