package es5.stream;

import java.io.IOException;
import java.io.PipedOutputStream;
import java.io.ObjectOutputStream;
import java.util.Random;

public class Sensor extends Thread {
    private PipedOutputStream pos;

    public Sensor(PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run() {
        final Random random = new Random();
        ObjectOutputStream oos = null;

        try {
            oos = new ObjectOutputStream(oos);
        } catch (IOException e) {
            System.err.println("Impossible to init ObjectOutputStream using the given PipedOutputStream");
            e.printStackTrace();
            System.exit(-2);
        }

        while (true) {
            try {
                float temperature = 18 + random.nextFloat() * (21 - 18);
                Message tempMessage = new Message(temperature);
                try {
                    oos.writeObject(tempMessage);
                    oos.flush();
                } catch (IOException e) {
                }

                Thread.sleep(300);
            } catch (final InterruptedException e) {
            }
        }
    }

}