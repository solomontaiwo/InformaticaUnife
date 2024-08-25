import java.io.Serializable;

public class Messaggio implements Serializable {
    private int pezziProdotti = 0;
    private float fIndicator = 0.0F;

    public Messaggio(int pezziProdotti, float fIndicator) {
        this.pezziProdotti = pezziProdotti;
        this.fIndicator = fIndicator;
    }

    public int getPezziProdotti() {
        return this.pezziProdotti;
    }

    public float getFIndicator() {
        return this.fIndicator;
    }
}