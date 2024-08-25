import java.io.Serializable;

public class Misure implements Serializable {
    private float temperatura = 0.0F;
    private int umidita = 0;

    public Misure(float temperatura, int umidita) {
        this.temperatura = temperatura;
        this.umidita = umidita;
    }

    public int getUmidita() {
        return umidita;
    }

    public void setUmidita(int umidita) {
        this.umidita = umidita;
    }

    public float getTemperatura() {
        return temperatura;
    }

    public void setTemperatura(float temperatura) {
        this.temperatura = temperatura;
    }
}