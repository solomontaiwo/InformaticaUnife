import java.util.*;

public class Furgone extends Veicolo {
    private int posti;
    private boolean rimorchio, carico;

    public Furgone(int codice, String targa, String modello, String marca, double costo, int posti, boolean rimorchio, boolean carico) {
        super(codice, targa, modello, marca, costo);
        this.posti = posti;
        this.rimorchio = rimorchio;
        this.carico = carico;
    }

    public String toString() {
        return "furgone\t" + super.toString() + "\t-\t-\t-\t" + rimorchio + "\t" + posti + "\t" + carico;
    }
}