import java.io.Serializable;

public class Consumi implements Serializable {
    private float consumo = 0.0F;

    public synchronized void setConsumi(float consumi) {
        this.consumo = consumi;
    }

    public synchronized float getConsumi() {
        return this.consumo;
    }
}