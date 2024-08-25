import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;
import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;

public class Machine extends Thread {
    private PipedOutputStream pos = null;
    private AtomicBoolean isRunning = new AtomicBoolean(false);
    private int prodotti_creati = 0;

    public Machine(PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run() {
        isRunning.set(true);

        ObjectOutputStream oos = null;

        try {
            oos = new ObjectOutputStream(pos);
        } catch (IOException e) {
            e.printStackTrace();
        }

        Random random = new Random();

        while (isRunning.get()) {
            float num = -1000 + random.nextFloat() * 2000;
            prodotti_creati++;
            Messaggio mess = new Messaggio(prodotti_creati, num);

            try {
                oos.writeObject(mess);
            } catch (IOException e) {
                e.printStackTrace();
            }

            try {
                Thread.sleep(750);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void terminaMachine() {
        isRunning.set(false);
    }
}