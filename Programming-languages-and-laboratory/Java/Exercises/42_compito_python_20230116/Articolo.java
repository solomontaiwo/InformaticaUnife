public class Articolo {
    protected int codice;
    protected String tipo;
    protected String marca;
    protected String taglia;
    protected String modello;
    protected float costo;
    protected int sconto_in_percentuale;

    public Articolo(int codice, String tipo, String marca, String taglia, String modello, float costo,
            int sconto_in_percentuale) {
        this.codice = codice;
        this.tipo = tipo;
        this.marca = marca;
        this.taglia = taglia;
        this.modello = modello;
        this.costo = costo;
        this.sconto_in_percentuale = sconto_in_percentuale;

    }

    public String toString() {
        return tipo + "\t" + codice + "\t" + marca + "\t" + modello + "\t" + taglia;
    }
}