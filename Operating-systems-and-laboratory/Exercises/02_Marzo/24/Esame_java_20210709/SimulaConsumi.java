import java.util.concurrent.atomic.AtomicBoolean;

public class SimulaConsumi implements Runnable {
    private AtomicBoolean isRunning = new AtomicBoolean(false);
    private Consumi consumi = null;

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