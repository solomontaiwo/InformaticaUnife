import java.io.Serializable;

public class Misure implements Serializable {
    private float temperatura = 0;
    private int umidita = 0;

    public Misure(float temperatura, int umidita) {
        this.temperatura = temperatura;
        this.umidita = umidita;
    }

    public float getTemperatura() {
        return this.temperatura;
    }

    public int getUmidita() {
        return this.umidita;
    }

    public void setTemperatura(float temperatura) {
        this.temperatura = temperatura;
    }

    public void setUmidita(int umidita) {
        this.umidita = umidita;
    }
}