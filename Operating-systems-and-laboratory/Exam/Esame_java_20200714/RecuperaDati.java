package esame.es1;

import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;

public class RecuperaDati extends Thread {

    private DatiAzionari datiAzionari = null;
    private AtomicBoolean isRunning = new AtomicBoolean(false);

    public RecuperaDati(DatiAzionari datiAzionari) {
        this.datiAzionari = datiAzionari;
    }

    public void run() {
        Random random = new Random();
        isRunning.set(true);

        String indice = datiAzionari.getIndice();

        while (isRunning.get()) {

            // prima di generare un valore verifico se l'indice è diverso dal precedente
            String vIndice = datiAzionari.getIndice();
            if (!indice.equals(vIndice)) {
                System.out.println("warning-- cambiato indice da monitorare in " + vIndice);
                indice = vIndice;
            }
            // genera un valore lowerbound + random(upper - lower)
            int valore = 20 + random.nextInt(60);
            datiAzionari.setValore(valore);

            System.out.println("RecuperaDati--- " + indice + ": " + valore);
    
            try {
                Thread.sleep(5000);
            } catch (InterruptedException ex) {}
        }
    }

    public void terminaThread() {
            isRunning.set(false);
            Thread.currentThread().interrupt();
    }

}