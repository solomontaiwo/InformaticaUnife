package es9;

public class ControlloProduzione {

    private int semilavorati = 0;
    private int finiti = 0;
	
	// prodotti semilavorati
    public synchronized void increaseSemilavorati() {
        int temp = semilavorati;
        temp++;
        semilavorati = temp;
    }
    public synchronized void decreaseSemilavorati() {
        int temp = semilavorati;
        temp--;
        semilavorati = temp;
    }
    public synchronized int getSemilavorati() {
        return semilavorati;
    }

	// prodotti finiti
    public synchronized void increaseFiniti() {
        int tmp = finiti;
        tmp++;
        System.out.println("tmp: " + tmp);
        finiti = tmp;
    }
    public synchronized void decreaseFiniti() {
        int temp = finiti;
        temp--;
        finiti = temp;
    }
    public synchronized int getFiniti() {
        return finiti;
    }
}