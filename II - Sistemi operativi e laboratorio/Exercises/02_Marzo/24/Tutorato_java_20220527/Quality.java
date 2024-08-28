import java.util.concurrent.atomic.AtomicBoolean;
import java.io.*;

public class Quality extends Thread {
    private PipedInputStream pis = null;
    private Overall overall = null;
    private AtomicBoolean isRunning = new AtomicBoolean(false);

    public Quality(PipedInputStream pis, Overall overall) {
        this.pis = pis;
        this.overall = overall;
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
                float fIndicator = m.getfIndicator();

                if (fIndicator > 0) {
                    System.out.println("OK");
                    overall.incrementaCorretti();
                } else {
                    System.out.println("Errore pezzo numero " + m.getPezziProdotti());
                    overall.incrementaDifettosi();
                }
            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

    public void termina() {
        isRunning.set(false);
    }
}