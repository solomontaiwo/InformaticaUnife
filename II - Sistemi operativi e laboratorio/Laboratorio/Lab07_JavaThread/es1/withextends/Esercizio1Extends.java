package es1.withextends;

import es1.Accumulatore;

public class Esercizio1Extends {
  
	// massimo numero di Thread
	final static int N = 25;

	public static void main(String args[]) {
		Accumulatore acc = new Accumulatore(0.0);
   
		CounterThread ct[] = new CounterThread[N];
		for (int i = 0; i < N; i++) {
			ct[i] = new CounterThread(acc);
			ct[i].start();
		}
 
		for(int i=0; i < N; i++) {
			try {
				ct[i].join();
			} catch(InterruptedException e) {
				e.printStackTrace();
			} 
		}
	
		System.out.println("Thread MAIN accumulatore vale: " + acc.getValue());
	}
  
}
