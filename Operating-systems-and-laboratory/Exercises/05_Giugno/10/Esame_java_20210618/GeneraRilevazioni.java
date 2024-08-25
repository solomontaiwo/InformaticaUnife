import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;
import java.util.Random;
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
        Random random = new Random();

        try {
            oos = new ObjectOutputStream(pos);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }

        while (isRunning.get()) {
            int valore = random.nextInt(200);
            long timestamp = System.currentTimeMillis();

            Rilevazione r = new Rilevazione(valore, timestamp);

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
        isRunning.set(false);
        Thread.currentThread().interrupt();
    }
}