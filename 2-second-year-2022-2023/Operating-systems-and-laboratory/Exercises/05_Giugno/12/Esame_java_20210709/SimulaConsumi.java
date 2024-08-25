import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;

public class SimulaConsumi implements Runnable {
    private AtomicBoolean isRunning = new AtomicBoolean(false);
    private Consumi consumo = null;

    public SimulaConsumi(Consumi consumi) {
        this.consumo = consumi;
    }

    public void run() {
        isRunning.set(true);
        Random random = new Random();

        while (isRunning.get()) {
            float cons = random.nextFloat(30);
            consumo.setConsumi(cons);

            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
                System.err.println("Errore sleep SimulaConsumi");
            }
        }
    }

    public void terminaSimulazioneConsumi() {
        isRunning.set(false);
    }
}