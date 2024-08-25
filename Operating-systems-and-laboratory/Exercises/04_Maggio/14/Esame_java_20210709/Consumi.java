public class Consumi {
    private float consumi = 0.0F;

    public synchronized float getConsumi() {
        return this.consumi;
    }

    public synchronized void setConsumi(float consumi) {
        this.consumi = consumi;
    }
}