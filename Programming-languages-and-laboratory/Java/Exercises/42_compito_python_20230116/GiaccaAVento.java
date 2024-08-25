public class GiaccaAVento extends Articolo {
    private int tasche;

    public GiaccaAVento(int codice, String tipo, String marca, String taglia, String modello, float costo, int tasche,
            int sconto_in_percentuale) {
        super(codice, tipo, marca, taglia, modello, costo, sconto_in_percentuale);
        this.tasche = tasche;
    }

    public String toString() {
        return super.toString() + "\t" + tasche + "\t-\t" + costo + "\t" + sconto_in_percentuale;
    }
}