package es3.metodo2;

import java.util.concurrent.atomic.AtomicBoolean;

public class WorkerThreadMetodo2 implements Runnable {
	    
	// AtomicBoolean, "A boolean value that may be updated atomically"
	// to prevent conflicts in setting and checking the variable from different threads
	// https://docs.oracle.com/javase/7/docs/api/java/util/concurrent/atomic/AtomicBoolean.html
    private final AtomicBoolean running = new AtomicBoolean(false);
	
	private int i;
	public WorkerThreadMetodo2(int i){
		this.i = i;
	}
	
    // stop the sub-thread
    public void stop() {
        running.set(false);
    }

    public void interrupt() {
        running.set(false);
        Thread.currentThread().interrupt();
    }

    public void run() {
        running.set(true);
        while(running.get()) {
            try {
				System.out.println("Thread: " + i);
                Thread.sleep(1000);
            }
			catch(InterruptedException e) {
                System.out.println(Thread.currentThread() + " interrupted, terminating...");
            }
        }
    }

}