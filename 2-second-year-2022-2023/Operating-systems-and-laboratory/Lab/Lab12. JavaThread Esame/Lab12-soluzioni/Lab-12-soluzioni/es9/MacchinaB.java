package es9;

import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;
import java.io.UnsupportedEncodingException;
import java.nio.charset.Charset;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaB implements Runnable {

    final private AtomicBoolean isRunning = new AtomicBoolean(false);
    private PipedOutputStream pos = null;
    private ControlloProduzione cp = null;
    // contatore interno per prodotti finiti
    private int lavoratiFiniti = 0;

    public MacchinaB(ControlloProduzione cp, PipedOutputStream pos) {
        this.cp = cp;
        this.pos = pos;
    }
	
    public void stop() {
        isRunning.set(false);
        //Thread.currentThread().interrupt();
    }
    
    public void run() {
        isRunning.set(true);

        while (isRunning.get()) {

            int semilavoratiDis = cp.getSemilavorati();
            if (semilavoratiDis > 0) {
                // decremento numero di semilavorati disponibili
                cp.decreaseSemilavorati();
            } 
			else {
                System.out.println("MacchinaB semilavorati non sufficienti per avviare la produzione");
                try {
                    Thread.sleep(2000);
                } catch(InterruptedException e) {
                    e.printStackTrace();
                }
                continue;
            }

            try {
                int sleepTime = (int)(100 + Math.random() * 50);
                Thread.sleep(sleepTime);
            } 
			catch(InterruptedException e) {
                e.printStackTrace();
            }

            lavoratiFiniti++;
            cp.increaseFiniti();

            System.out.println("Fine lavorazione prodotto finale, lavorati finiti: " + lavoratiFiniti);

            String msg = "prodottoFinito";
            try {
                pos.write(msg.getBytes("UTF-8"));
                pos.flush();
            } 
			catch (IOException e) {
                e.printStackTrace();
            }

        }

    }

}