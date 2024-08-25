import java.io.Serializable;

public class Consumi implements Serializable {
    private float consumi = 0.0F;

    public synchronized float getConsumi() {
        return consumi;
    }

    public synchronized void setConsumi(float consumi) {
        this.consumi = consumi;
    }
}