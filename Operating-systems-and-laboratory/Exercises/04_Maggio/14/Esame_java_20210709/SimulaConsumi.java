import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;

public class SimulaConsumi implements Runnable {
    private AtomicBoolean isRunning = new AtomicBoolean(false);
    private Consumi consumi;

    public SimulaConsumi(Consumi consumi) {
        this.consumi = consumi;
    }

    public void run() {
        isRunning.set(true);
        Random random = new Random();

        while (isRunning.get()) {
            consumi.setConsumi((float) random.nextFloat(30));

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
