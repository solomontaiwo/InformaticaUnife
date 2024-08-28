package es6;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PipedOutputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class Sorter implements Runnable {
    private Thread t = null;
    private AtomicBoolean running = new AtomicBoolean(false);
    private ThreadLoad tl = null;
    private PipedOutputStream pop = null;

    public Sorter(ThreadLoad tl, PipedOutputStream pop) {
        this.tl = tl;
        this.pop = pop;
    }

    public void run() {
        running.set(true);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pop));
        while (running.get()) {
            try {
                Integer ti = tl.getMaximumThreadId();
                if (ti == null) {
                    continue;
                }
                Double cpuLoad = tl.getCpuLoad(ti);
                if (cpuLoad == null) {
                    continue;
                }
                String result = "Thread " + ti + " con cpuLoad: " + cpuLoad;
                bw.write(result);
                bw.newLine();
                bw.flush();

                Thread.sleep(150);
            } catch (InterruptedException | IOException e) {
            }
        }
    }

    public void stop() {
        if (running.get()) {
            running.set(false);
        }
    }
}