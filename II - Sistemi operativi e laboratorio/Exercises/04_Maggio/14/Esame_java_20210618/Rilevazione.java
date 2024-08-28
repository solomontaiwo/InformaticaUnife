import java.io.Serializable;

public class Rilevazione implements Serializable {
    private int valore = 0;
    private long timestamp = 0L;

    public Rilevazione(int valore, long timestamp) {
        this.valore = valore;
        this.timestamp = timestamp;
    }

    public synchronized int getValore() {
        return this.valore;
    }

    public synchronized long getTimestamp() {
        return this.timestamp;
    }

    public synchronized void setValore(int valore) {
        this.valore = valore;
    }

    public synchronized void setTimestamp(long timestamp) {
        this.timestamp = timestamp;
    }

}
