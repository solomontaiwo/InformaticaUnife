package es2.buffered;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedInputStream;

// Questa classe legge uno stream in input
// e lo redireziona sullo stdout
public class ToOutput implements Runnable {

    private Thread t = null;
    private PipedInputStream pis = null;

    ToOutput(PipedInputStream pis) {
        this.pis = pis;
    }

    // re-define start to launch the thread
    public void start() {
        t = new Thread(this);
        t.start();
    }

    @Override
    public void run() {
        System.out.println(Thread.currentThread() + " Hello, this is ToOutput");
        try {
            String line = null;
            BufferedReader br = new BufferedReader(new InputStreamReader(pis));
            while ((line = br.readLine()) != null) {
                System.out.println("ToOutput: " + line);
            }
        } 
		catch (IOException e){
			e.printStackTrace();
		}

    }
}