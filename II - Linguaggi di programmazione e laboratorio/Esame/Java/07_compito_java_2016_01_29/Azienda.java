import java.util.*;

public class Azienda extends Cliente {
    private String ragioneSociale;
    private int fatturato;

    public Azienda(int codice, String indirizzo, int giorno, int mese, int anno, String ragioneSociale, int fatturato) {
        super(codice, indirizzo, giorno, mese, anno);
        this.ragioneSociale = ragioneSociale;
        this.fatturato = fatturato;
    }

    public String toString() {
        return "azienda\t" + codice + "\t-\t" + ragioneSociale + "\t" + indirizzo + "\t" + giorno + "-" + mese + "-" + anno + "\t" + fatturato;
    }
}