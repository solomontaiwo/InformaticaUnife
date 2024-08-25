import java.util.concurrent.atomic.AtomicBoolean;
import java.io.*;

public class SimulaConsumi implements Runnable {
    private Consumi consumi = null;
    private AtomicBoolean isRunning = new AtomicBoolean(false);

    public SimulaConsumi(Consumi consumi) {
        this.consumi = consumi;
    }

    public void run() {
        isRunning.set(true);

        while (isRunning.get()) {
            consumi.setConsumi((float) (Math.random() * 30));

            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void terminaSimulazioneConsumi() {
        isRunning.set(false);
    }
}