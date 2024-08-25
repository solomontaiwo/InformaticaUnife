package es7;

import java.util.Random;


public class Macchina extends Thread {

    Produzione produzione = null;

    public Macchina(Produzione produzione) {
        this.produzione = produzione;
    }

    public void run() {
		
        final Random random = new Random();
        
		for(int i = 0; i < 35; i++) {
            
			// 1) Simulo produzione
            System.out.println(Thread.currentThread() + " ....begin manufacturing....");
            long sleepTime = 500 + (long)(random.nextDouble() * 100);
			try {
                Thread.sleep(sleepTime);
            } catch(InterruptedException ex) {
                ex.printStackTrace();
            }
            System.out.println(Thread.currentThread() + " ....end manufacturing....");
			
            // 2) Simulo incremento produzione
            produzione.incrementa();
        }
		
    }
    
}