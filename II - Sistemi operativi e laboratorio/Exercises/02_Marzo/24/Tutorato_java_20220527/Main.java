import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    public static void main(String args[]) {
        PipedInputStream pis = new PipedInputStream();
        PipedOutputStream pos = null;

        try {
            pos = new PipedOutputStream(pis);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }

        Overall overall = new Overall();

        Machine machine = new Machine(pos);
        Quality quality = new Quality(pis, overall);

        machine.start();
        quality.start();

        boolean keepGoing = true;

        while (keepGoing) {
            try {
                Thread.sleep(1000);
                if (overall.getDifettosi() > overall.getCorretti()) {
                    System.out.println("Difettosi (" + overall.getDifettosi() + ") sono più che i corretti ("
                            + overall.getCorretti() + ")");
                    machine.termina();
                    quality.termina();

                    keepGoing = false;
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        try {
            machine.join();
            quality.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}