package es8.stream;

import java.io.IOException;
import java.io.PipedOutputStream;
import java.io.UnsupportedEncodingException;
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

        while(isRunning.get()) {
            
			System.out.println("Inizio lavorazione prodotto");
            try {
                Thread.sleep(200);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Fine lavorazione prodotto");
            // la comunicazione avviene direttamente con stream byte
            String pg = "prodotto-grezzo";

            byte[] message = null;
            try {
                message = pg.getBytes("UTF-8");
            } catch (UnsupportedEncodingException e1) {
                e1.printStackTrace();
            }

            try {
                pos.write(message);
                pos.flush();
            } catch (IOException e) {
                e.printStackTrace();
            }
			
        }
		
    }

}