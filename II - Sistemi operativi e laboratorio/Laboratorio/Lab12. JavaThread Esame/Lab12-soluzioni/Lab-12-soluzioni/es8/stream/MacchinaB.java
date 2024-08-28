package es8.stream;

import java.io.IOException;
import java.io.PipedInputStream;
import java.nio.charset.Charset;
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

        while (isRunning.get()) {

            byte[] buffer = new byte[128];
            try {
                pis.read(buffer);
            } catch (IOException e1) {
                e1.printStackTrace();
            }

            String received = new String(buffer, Charset.forName("UTF-8"));
            System.out.println("Arrivato prodotto grezzo: " + received);
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