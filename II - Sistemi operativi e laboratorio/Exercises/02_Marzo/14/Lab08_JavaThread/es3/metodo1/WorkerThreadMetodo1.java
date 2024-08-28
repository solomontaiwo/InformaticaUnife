package es3.metodo1;

import java.util.concurrent.atomic.AtomicBoolean;

public class WorkerThreadMetodo1 implements Runnable {
    private final AtomicBoolean running = new AtomicBoolean(false);

    private int i;

    public WorkerThreadMetodo1(int i) {
        this.i = i;
    }

    public void stop() {
        running.set(false);
    }

    public void run() {
        running.set(true);
        while (running.get()) {
            try {
                System.out.println("Thread: " + i);
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                e.printStackTrace();
            }
        }
    }
}