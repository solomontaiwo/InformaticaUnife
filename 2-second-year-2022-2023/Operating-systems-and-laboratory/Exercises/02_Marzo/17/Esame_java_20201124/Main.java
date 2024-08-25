import java.io.*;
import java.util.*;

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

        Machine machine = new Machine(pos);
        Quality quality = new Quality(pis);

        machine.start();
        quality.start();

        try {
            Thread.currentThread().sleep(15000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        machine.termina();
        quality.termina();

        try {
            machine.join();
            quality.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}