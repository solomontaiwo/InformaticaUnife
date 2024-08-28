package es9;

import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaA implements Runnable {
	
    private ControlloProduzione controlloProduzione = null;
    public MacchinaA(ControlloProduzione controlloProduzione) {
        this.controlloProduzione = controlloProduzione;
    }

    final AtomicBoolean isRunning = new AtomicBoolean(false);

    public void stop() {
        isRunning.set(false);
        //Thread.currentThread().interrupt();
    }
    
    public void run() {
        isRunning.set(true);

        while (isRunning.get()) {
            System.out.println("Inizio lavorazione semilavorato");
            try {
                int sleepTime = (int)(400 + Math.random() * 100);
                Thread.sleep(sleepTime);
            } 
			catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Fine lavorazione semilavorato");

            // incremento semilavorato
            controlloProduzione.increaseSemilavorati();
        }
    }

}