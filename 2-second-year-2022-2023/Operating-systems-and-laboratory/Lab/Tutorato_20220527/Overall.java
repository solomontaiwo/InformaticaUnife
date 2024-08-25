package esame;

public class Overall {
    private int corretti = 0;
    private int difettosi = 0;

    public synchronized int getCorretti(){
        return this.corretti;
    }

    public synchronized int getDifettosi(){
        return this.difettosi;
    }

    public synchronized void incrementaCorretti(){
        this.corretti++;
    }

    public synchronized void incrementaDifettosi(){
        this.difettosi++;
    }
}
