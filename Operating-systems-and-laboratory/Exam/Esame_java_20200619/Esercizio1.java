package esame.es1;

import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Esercizio1 {
    
    public static void main(String args[]) {
		// creo il canale di comunicazione tra MacchinaA e MacchinaB
		PipedInputStream pis = new PipedInputStream();

		PipedOutputStream pos = null;
		try {
			pos = new PipedOutputStream(pis);
		} catch(IOException ioe) {
			System.err.println("Impossible to create a PipedOutputStream");
			System.exit(-3);
		}

		InputUtente iU = new InputUtente(pos);
		Thread tiU = new Thread(iU);
		tiU.start();

		ScansionaInput sI = new ScansionaInput(pis);
		Thread tsI = new Thread(sI);
		tsI.start();

		// sleep di 30 secondi e poi interrompo i due thread
		try {
			Thread.currentThread().sleep( 30 * 1000);
			System.out.println("Il programma sta per terminare...");
			iU.stop();
			sI.stop();
		} catch(InterruptedException e) {
			e.printStackTrace();
		}

		// join threads before terminating
		try {
			tiU.join();
			tsI.join();
		} catch(InterruptedException e) {
			System.err.println("InterruptedException when joining threads");
			e.printStackTrace();
		}
    }
}