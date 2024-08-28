package es8.buffered;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PipedOutputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaA implements Runnable {
    private PipedOutputStream pos = null;

    public MacchinaA(PipedOutputStream pos) {
        this.pos = pos;
    }

    final AtomicBoolean isRunning = new AtomicBoolean(false);
	
    public void stop() {
        isRunning.set(false);
		// Thread.currentThread().interrupt();
    }
    
    public void run() {
        isRunning.set(true);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pos));

        while (isRunning.get()) {
            System.out.println("Inizio lavorazione prodotto");
            try {
                Thread.sleep(200);
            } catch(InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Fine lavorazione prodotto");
            
            // la comunicazione avviene direttamente con stream byte
            String pg = "prodotto-grezzo";
            try {
                bw.write(pg);
                bw.newLine();
                bw.flush();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

}