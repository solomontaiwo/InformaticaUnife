public class Consumi {
    private float consumi = 0.0F;

    public synchronized void setConsumi(float consumi) {
        this.consumi = consumi;
    }

    public synchronized float getConsumi() {
        return consumi;
    }
}