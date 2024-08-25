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
        Random random = new Random();
        ObjectOutputStream oos = null;

        try {
            oos = new ObjectOutputStream(pos);
        } catch (IOException e) {
            System.err.println("Errore ObjectOutputstream GeneraRilevazioni");
            e.printStackTrace();
        }

        while (isRunning.get()) {
            int valore = random.nextInt(200);
            long timestamp = System.currentTimeMillis();
            Rilevazione r = new Rilevazione(valore, timestamp);

            try {
                oos.writeObject(r);
                oos.flush();
            } catch (IOException e) {
                System.err.println("Errore writeObject GeneraRilevazioni");
                e.printStackTrace();
            }

            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                System.err.println("Errore sleep GeneraRilevazioni");
                e.printStackTrace();
            }
        }
    }

    public void terminaRilevazioni() {
        isRunning.set(false);
        Thread.currentThread().interrupt();
    }
}