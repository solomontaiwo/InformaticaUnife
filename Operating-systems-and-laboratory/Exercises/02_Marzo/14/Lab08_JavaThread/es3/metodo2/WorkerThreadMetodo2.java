package es3.metodo2;

import java.util.concurrent.atomic.AtomicBoolean;

public class WorkerThreadMetodo2 implements Runnable {
    private final AtomicBoolean running = new AtomicBoolean(false);

    private int i;

    public WorkerThreadMetodo2(int i) {
        this.i = i;
    }

    public void stop() {
        running.set(false);
    }

    public void interrupt() {
        running.set(false);
        Thread.currentThread().interrupt();
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