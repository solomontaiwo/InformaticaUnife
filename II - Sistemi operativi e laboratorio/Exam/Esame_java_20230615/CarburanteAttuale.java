import java.io.*;

public class CarburanteAttuale implements Serializable {
    private int carburante = 0;
    private long timestamp = 0L;

    public CarburanteAttuale(int carburante, long timestamp) {
        this.carburante = carburante;
        this.timestamp = timestamp;
    }

    public int getCarburante() {
        return this.carburante;
    }

    public long getTimestamp() {
        return this.timestamp;
    }
}