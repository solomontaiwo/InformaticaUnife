package es1.withrunnable;

import es1.Accumulatore;

class CounterThread implements Runnable {
    private Accumulatore acc;

    public CounterThread(Accumulatore accumulatore) {
        acc = accumulatore;
    }

    public void run() {
        double value = Math.random();
        acc.addValue(value);
        System.out.println("Thread: " + Thread.currentThread() + " accumulatore: " + acc.getValue());
    }
}