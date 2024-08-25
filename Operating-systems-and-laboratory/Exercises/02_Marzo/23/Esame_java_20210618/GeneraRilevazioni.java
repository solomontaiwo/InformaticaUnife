import java.io.*;
import java.util.*;
import java.util.concurrent.atomic.AtomicBoolean;

public class GeneraRilevazioni extends Thread {
    private AtomicBoolean isRunning = new AtomicBoolean(false);
    private PipedOutputStream pos = null;

    public GeneraRilevazioni(PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run() {
        isRunning.set(true);

        ObjectOutputStream oos = null;

        try {
            oos = new ObjectOutputStream(pos);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }

        while (isRunning.get()) {
            Rilevazione r = new Rilevazione((int) (200 * Math.random()), System.currentTimeMillis());

            try {
                oos.writeObject(r);
                oos.flush();
            } catch (IOException e) {
                e.printStackTrace();
            }

            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        }
    }

    public void terminaRilevazioni() {
        Thread.currentThread().interrupt();
        isRunning.set(false);
    }
}