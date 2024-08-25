import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.PipedInputStream;
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
        }

        while (isRunning.get()) {
            try {
                Messaggio mess = (Messaggio) ois.readObject();
                float fIndicator = mess.getFindicator();

                if (fIndicator > 0) {
                    System.out.println("OK");
                } else {
                    System.out.println("Errore-- pezzo numero: " + mess.getPezziProdotti());
                }
            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    public void terminaQuality() {
        isRunning.set(false);
    }
}