package es8.object;

import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Esercizio8Object {

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

        MacchinaA mA = new MacchinaA(pos);
        Thread tmA = new Thread(mA);
        tmA.start();

        MacchinaB mB = new MacchinaB(pis);
        Thread tmB = new Thread(mB);
        tmB.start();

        // sleep di un minuto e poi interrompo la produzione
        try {
            Thread.sleep( 10 * 1000);
            mA.stop();
            mB.stop();
        } catch(InterruptedException e) {
            e.printStackTrace();
        }

        // join thread
        try {
            tmA.join();
            tmB.join();
        } catch(InterruptedException e) {
            System.err.println("InterruptedException when joining threads");
            e.printStackTrace();
        }

    }
    
}