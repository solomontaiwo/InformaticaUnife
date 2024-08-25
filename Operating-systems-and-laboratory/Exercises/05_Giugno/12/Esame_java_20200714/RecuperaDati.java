import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;

public class RecuperaDati extends Thread {
    private AtomicBoolean isRunning = new AtomicBoolean(false);
    private DatiAzionari datoAzionario = null;

    public RecuperaDati(DatiAzionari datoAzionario) {
        this.datoAzionario = datoAzionario;
    }

    public void run() {
        isRunning.set(true);
        Random random = new Random();
        String indice = datoAzionario.getIndice();

        while (isRunning.get()) {
            String indiceCorrente = datoAzionario.getIndice();
            if (!indice.equals(indiceCorrente)) {
                System.out.println("Warning -- indice da monitorare cambiato");
                indice = indiceCorrente;
            }

            int valoreCorrente = random.nextInt(60) + 20;
            datoAzionario.setValore(valoreCorrente);

            System.out.println("RecuperoDati -- " + indice + ": " + valoreCorrente);

            try {
                Thread.sleep(5000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void terminaThread() {
        isRunning.set(false);
        Thread.currentThread().interrupt();
    }
}