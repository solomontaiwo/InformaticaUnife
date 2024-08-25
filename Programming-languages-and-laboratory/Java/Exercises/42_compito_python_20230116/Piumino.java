public class Piumino extends Articolo {
    private int peso;

    public Piumino(int codice, String tipo, String marca, String taglia, int peso, String modello, float costo,
            int sconto_in_percentuale) {
        super(codice, tipo, marca, taglia, modello, costo, sconto_in_percentuale);
        this.peso = peso;
    }

    public String toString() {
        return super.toString() + "\t-\t" + peso + "\t" + costo + "\t" + sconto_in_percentuale;
    }
}