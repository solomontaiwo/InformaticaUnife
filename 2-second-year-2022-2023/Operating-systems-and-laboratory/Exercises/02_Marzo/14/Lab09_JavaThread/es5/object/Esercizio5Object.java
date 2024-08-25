package es5.buffered;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Esercizio5Stream {
    public static void main(String args[]) {
        float temperature = 0;

        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader stdin = new BufferedReader(isr);

        System.out.println("Inserisci il valore di temperatura desiderato: ");
        String strTemperature = "";

        try {
            strTemperature = stdin.readLine();
        } catch (IOException e) {
            System.err.println("Exception when reading from stdin");
            System.exit(-1);
        }

        try {
            temperature = Float.parseFloat(strTemperature);
        } catch (NumberFormatException e) {
            System.err.println("Il valore di temperatura inserito non è un numero valido");
            System.exit(-1);
        }

        PipedInputStream pis = new PipedInputStream();

        PipedOutputStream pos = null;

        try {
            pos = new PipedOutputStream(pis);
        } catch (IOException ioe) {
            System.err.println("Impossibile to create a PipedOutputStream");
            System.exit(-3);
        }

        Sensor sensor = new sensor(pos);
        sensor.start();

        Actuator actuator = new Actuator(pis, temperature);
        actuator.start();
    }
}