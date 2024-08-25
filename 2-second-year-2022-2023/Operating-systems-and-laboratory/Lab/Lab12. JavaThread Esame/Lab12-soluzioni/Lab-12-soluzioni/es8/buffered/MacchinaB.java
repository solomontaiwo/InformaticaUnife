package es8.buffered;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedInputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaB implements Runnable {

    final private AtomicBoolean isRunning = new AtomicBoolean(false);
    private PipedInputStream pis = null;
    private int lavoratiFiniti = 0;

    public MacchinaB(PipedInputStream pis) {
        this.pis = pis;
    }
	
    public void stop() {
        isRunning.set(false);
		// Thread.currentThread().interrupt();
    }
    
    public void run() {
        isRunning.set(true);
        BufferedReader br = new BufferedReader(new InputStreamReader(pis));

        while (isRunning.get()) {

            String msg = null;
            try {
                msg = br.readLine();
            } catch (IOException e1) {
                System.err.println("Error in reading from BufferedReader");
                e1.printStackTrace();
            }
            System.out.println("Arrivato prodotto grezzo: " + msg);
            
            try {
                Thread.sleep(200);
            } catch(InterruptedException e) {
                e.printStackTrace();
            }
            lavoratiFiniti++;
            System.out.println("Fine lavorazione prodotto finale, lavorati finiti: " + lavoratiFiniti);
        }

    }

}
