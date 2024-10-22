package es9;

import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;
import java.nio.charset.Charset;

public class Esercizio9 {

    public static void main(String args[]) {

        // creo il canale di comunicazione tra MacchinaB e main
        PipedInputStream pis = new PipedInputStream();
        PipedOutputStream pos = null;
        try {
            pos = new PipedOutputStream(pis);
        } catch(IOException ioe) {
            System.err.println("Impossible to create a PipedOutputStream");
            System.exit(-3);
        }

        ControlloProduzione controlloProduzione = new ControlloProduzione();
        
        // creo due macchine di tipo A
        MacchinaA maA1 = new MacchinaA(controlloProduzione);
        Thread tmA1 = new Thread(maA1);
        MacchinaA maA2 = new MacchinaA(controlloProduzione);
        Thread tmA2 = new Thread(maA2);
        tmA1.start();
        tmA2.start();

        // creo una macchina di tipo B
        MacchinaB mB = new MacchinaB(controlloProduzione, pos);
        Thread tmB = new Thread(mB);
        tmB.start();

		// ricevo 15 prodotti finiti
        for (int i = 0; i < 15; i++) {
            byte[] buffer = new byte[128];
            try {
                int nread = pis.read(buffer);
                String msg = new String(buffer, 0, nread, Charset.forName("UTF-8"));
                System.out.println("Main - arrivato prodotto finito");
            } catch(IOException e) {
                e.printStackTrace();
            }
        }
		
        // interrompo la produzione dopo 15 prodotti
        maA1.stopMacchinaA()
        maA2.stopMacchinaA();
        mB.stopMacchinaB();

        // join thread
        try {
            tmA1.join();
        } catch(InterruptedException e) {
            System.err.println("InterruptedException when joining threads");
            e.printStackTrace();
        }
		try {
            tmA2.join();
        } catch(InterruptedException e) {
            System.err.println("InterruptedException when joining threads");
            e.printStackTrace();
        }
		try {
			tmB.join();
        } catch(InterruptedException e) {
            System.err.println("InterruptedException when joining threads");
            e.printStackTrace();
        }

        System.out.println("Semilavorati: " + controlloProduzione.getSemilavorati() + " Finiti: " + controlloProduzione.getFiniti());
    }
    
}