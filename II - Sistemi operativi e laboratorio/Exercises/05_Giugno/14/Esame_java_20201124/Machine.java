import java.io.IOException;
import java.io.ObjectOutput;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;
import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;

public class Machine extends Thread {
    private AtomicBoolean isRunning = new AtomicBoolean(false);
    private PipedOutputStream pos = null;
    private int prodotti_creati = 0;

    public Machine(PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run() {
        isRunning.set(true);
        Random random = new Random();
        ObjectOutputStream oos = null;

        try {
            oos = new ObjectOutputStream(pos);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }

        while (isRunning.get()) {
            // genero un valore tra - 1000 + 1000
            float num = -1000 + random.nextFloat() * 2000;

            // incremento il numero di prodotti creati
            prodotti_creati++;

            // creo un messaggio contenente i dati richiesti
            Messaggio m = new Messaggio(prodotti_creati, num);

            // inviare il numero al Thread Quality
            try {
                oos.writeObject(m);
            } catch (IOException e) {
                e.printStackTrace();
            }

            try {
                // produco un pezzo ogni 750 ms
                Thread.currentThread().sleep(750);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }

    public void termina() {
        isRunning.set(false);
    }
}
