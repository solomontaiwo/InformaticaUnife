package es6;

import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;

public class Monitor implements Runnable {
    
    private final AtomicBoolean running = new AtomicBoolean(false);
    private ThreadLoad tl = null;

    public Monitor(final ThreadLoad tl) {
        this.tl = tl;
    }

    public void run() {
        running.set(true);
        final Random random = new Random();
        while(running.get()) {
            try {
                
				// nextInt()
				// Returns a pseudorandom, uniformly distributed int value 
				// between 0 (inclusive) and the specified value (exclusive), 
				// drawn from this random number generator's sequence
				final int threadId = random.nextInt(9) + 1;
				
				// nextFloat()
				// Returns the next pseudorandom, uniformly distributed float value
				// between 0.0 and 1.0 from this random number generator's sequence
                final double cpuLoad = random.nextDouble() * 100;
                
				tl.setThreadLoad(threadId, cpuLoad);
                Thread.sleep(200);
            } catch(final InterruptedException e) {}
        }
    }

    public void stop() {
        if (running.get()) 
            running.set(false);
    }
	
}

