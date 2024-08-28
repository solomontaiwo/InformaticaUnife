import java.io.*;

public class Main {
    public static void main(String args[]) {
        PipedInputStream pis = new PipedInputStream();

        PipedOutputStream pos = null;

        try {
            pos = new PipedOutputStream(pis);
        } catch (IOException e) {
            System.err.println("Impossibile creare PipedOutputStream");
            System.exit(-1);
        }

        InputUtente iU = new InputUtente(pos);
        Thread tiU = new Thread(iU);
        tiU.start();

        ScansionaInput sI = new ScansionaInput(pis);
        Thread tsI = new Thread(sI);
        tsI.start();

        try {
            Thread.currentThread().sleep(30 * 1000);
            System.out.println("Il programma sta per terminare...");
            iU.stop();
            sI.stop();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        try {
            tiU.join();
            tsI.join();
        } catch (InterruptedException e) {
            System.err.println("InterruptedException in join thread");
            e.printStackTrace();
        }
    }
}