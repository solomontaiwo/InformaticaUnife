package es1.withextends;

import es1.Accumulatore;

public class CounterThread extends Thread {
	
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