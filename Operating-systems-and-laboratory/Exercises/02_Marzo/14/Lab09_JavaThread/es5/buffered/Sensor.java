package es5.buffered;

import java.io.IOException;
import java.io.PipedOutputStream;
import java.io.DataOutputStream;
import java.util.Random;

public class Sensor extends Thread {
    private PipedOutputStream pos;

    public Sensor(PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run() {
        final Random random = new Random();

        DataOutputStream dos = new DataOutputStream(pos);
        while (true) {
            try {
                float temperature = 18 + random.nextFloat() * (21 - 18);
                try {
                    dos.writeFloat(temperature);
                    dos.flush();
                } catch (IOException e) {
                }

                Thread.sleep(300);
            } catch (final InterruptedException e) {
            }
        }
    }

}
