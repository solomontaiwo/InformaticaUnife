package es5.buffered;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.PipedInputStream;

public class Actuator extends Thread {

    private PipedInputStream pis;
    private float desideredTemperature;

    public Actuator(PipedInputStream pis, float temperature) {
        this.pis = pis;
        this.desideredTemperature = temperature;
    }

    public void run() {
        try {
            DataInputStream dis = new DataInputStream(pis);
            while(true) {

                float temperature = dis.readFloat();
                if (temperature < desideredTemperature) {
                    System.out.println("****Accendere il riscaldamento, temperatura corrente: " + 
                    temperature + "*****");
                }
            }
        } catch(IOException e) {
            System.err.println("Actuator: error when reading from Sensor");
            e.printStackTrace();
        }
    }
	
}