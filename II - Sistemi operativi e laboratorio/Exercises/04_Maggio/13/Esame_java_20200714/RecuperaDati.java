import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;

public class RecuperaDati extends Thread {
    private DatiAzionari datiAzionari = null;
    private AtomicBoolean isRunning = new AtomicBoolean(false);

    public RecuperaDati(DatiAzionari datiAzionari) {
        this.datiAzionari = datiAzionari;
    }

    public void run() {
        isRunning.set(true);
        Random random = new Random();

        String indice = datiAzionari.getIndice();

        while (isRunning.get()) {
            String vIndice = datiAzionari.getIndice();
            if (!indice.equals(vIndice)) {
                System.out.println("Warning-- cambiato indice da monitorare in " + vIndice);
                indice = vIndice;
            }

            int valore = 20 + random.nextInt(60);
            datiAzionari.setValore(valore);

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