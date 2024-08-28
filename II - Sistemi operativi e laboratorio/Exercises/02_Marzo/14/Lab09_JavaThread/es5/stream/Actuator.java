package es5.stream;

import java.io.IOException;
import java.io.PipedInputStream;
import java.nio.charset.Charset;

public class Actuator extends Thread {

    private PipedInputStream pis;
    private float desideredTemperature;

    public Actuator(PipedInputStream pis, float temperature) {
        this.pis = pis;
        this.desideredTemperature = temperature;
    }

    public void run() {
        byte buffer[] = new byte[128];
        int nread = 0;
        try {
            while ((nread = pis.read(buffer)) > 0) {
                String received = new String(buffer, Charset.forName("UTF-8"));
                float temperature = Float.parseFloat(received);
                if (temperature < desideredTemperature) {
                    System.out.println("****Accendere il riscaldamento, temperatura corrente: " + temperature + "*****");
                }
            }
        } catch (IOException e) {
            System.err.println("Actuator: error when reading from Sensor");
            e.printStackTrace();
        }
    }
}