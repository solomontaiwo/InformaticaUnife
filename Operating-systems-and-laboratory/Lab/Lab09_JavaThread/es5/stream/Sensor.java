package es5.stream;

import java.io.IOException;
import java.io.PipedOutputStream;
import java.util.Random;

public class Sensor extends Thread {

    private PipedOutputStream pos;

    public Sensor(PipedOutputStream pos) {
        this.pos = pos;
    }
	
    public void run() {
        final Random random = new Random();

        while (true) {
            try {
                float temperature = 18 + random.nextFloat() * (21 - 18);
                // System.out.println("Current temperature is: " + temperature);
                // converto temperatura in Stringa, per scrivere tale valore
                // su PipedOutputStream. altre soluzioni sono possibili
                String strTemp = temperature + "";
                byte message[] = strTemp.getBytes();
                try {
                    pos.write(message);
                    pos.flush();
                } catch(IOException e) {}

                Thread.sleep(300);
            } catch(final InterruptedException e) {}
        }
    }
	
}