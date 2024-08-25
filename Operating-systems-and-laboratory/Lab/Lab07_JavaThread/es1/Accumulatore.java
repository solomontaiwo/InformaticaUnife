package es1;

public class Accumulatore {
	
	private double accumulatore;
	public Accumulatore(double value) {
		accumulatore = value;
	}

	public void addValue(double value) {
		double temp = accumulatore;
		temp += value;
		try {
			Thread.sleep(200);
		} catch(InterruptedException e) {}
		accumulatore = temp;
	}

	public double getValue() {
		return accumulatore;
	}
  
}
