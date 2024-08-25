import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.PipedInputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class Quality extends Thread {
    private AtomicBoolean isRunning = new AtomicBoolean(false);
    private PipedInputStream pis = null;

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
            System.exit(-2);
        }

        while (isRunning.get()) {
            try {
                Messaggio mess = (Messaggio) ois.readObject();
                if (mess.getFIndicator() < 0) {
                    System.out.println("Errore - " + mess.getFIndicator());
                } else
                    System.out.println("OK");
            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    public void termina() {
        isRunning.set(false);
    }
}