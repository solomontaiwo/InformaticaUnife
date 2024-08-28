package es5.object;

import java.io.IOException;
import java.io.PipedInputStream;
import java.io.ObjectInputStream;

public class Actuator extends Thread {

    private PipedInputStream pis;
    private float desideredTemperature;

    public Actuator(PipedInputStream pis, float temperature) {
        this.pis = pis;
        this.desideredTemperature = temperature;
    }

    public void run() {
        ObjectInputStream ois = null;
        try {
            ois = new ObjectInputStream(pis);
        } catch (IOException e) {
            System.err.println("Impossibile to create an ObjectInputStream from the given PipedInputStream!");
            e.printStackTrace();
            System.exit(-2);
        }
        try {
            while (true) {
                Message tempMessage = (Message) ois.readObject();
                if (tempMessage == null)
                    break;
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