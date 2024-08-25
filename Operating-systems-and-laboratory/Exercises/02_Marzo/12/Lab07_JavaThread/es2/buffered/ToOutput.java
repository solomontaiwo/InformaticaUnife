package es2.buffered;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedInputStream;
import java.nio.channels.Pipe;
import java.nio.charset.Charset;
import java.util.Arrays;

public class ToOutput implements Runnable {
    private Thread t = null;
    private PipedInputStream pis = null;

    ToOutput(PipedInputStream pis) {
        this.pis = pis;
    }

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

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}