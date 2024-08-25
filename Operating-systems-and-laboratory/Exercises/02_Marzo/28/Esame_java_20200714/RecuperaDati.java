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
            String aIndice = datoAzionario.getIndice();
            if (!indice.equals(aIndice)) {
                System.out.println("Warning-- cambiato indice da monitorare in " + aIndice);
                indice = aIndice;
            }
            int valore = 20 + random.nextInt(60);
            datoAzionario.setValore(valore);

            System.out.println("RecuperaDati-- " + indice + ": " + valore);

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
