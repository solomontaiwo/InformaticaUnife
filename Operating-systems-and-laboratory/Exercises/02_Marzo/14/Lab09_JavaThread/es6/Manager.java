package es6;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedInputStream;

public class Manager extends Thread {

    private Monitor monitor = null;
    private Sorter sorter = null;
    private PipedInputStream pip = null;

    public Manager(Monitor monitor, Sorter sortter, PipedInputStream pip) {
        this.monitor = monitor;
        this.sorter = sorter;
        this.pip = pip;
    }

    public void run() {
        int i = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(pip));
        while (i < 10) {
            try {
                String line = br.readLine();
                System.out.println(line);
            } catch (IOException e) {
            }
            i++;
        }
        monitor.stop();
        sorter.stop();
    }
}