import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class GeneraRilevazione extends Thread {
    private PipedOutputStream pos = new PipedOutputStream();
    private AtomicBoolean isRunning = new AtomicBoolean(false);

    public GeneraRilevazione(PipedOutputStream pos) {
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
            Rilevazione r = new Rilevazione((int) (Math.random() * 200), System.currentTimeMillis());

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

    public void terminaRilevazione() {
        isRunning.set(false);
        Thread.currentThread().interrupt();
    }
}