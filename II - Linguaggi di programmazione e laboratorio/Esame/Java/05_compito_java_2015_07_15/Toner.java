import java.util.*;

public class Toner extends Prodotto {
    private String modelloStampante;

    public Toner(int codice, String modello, String produttore, int giorno, int mese, int anno, int prezzo, String modelloStampante) {
        super(codice, modello, produttore, giorno, mese, anno, prezzo);
        this.modelloStampante = modelloStampante;
    }

    public String toString(){
        return "Toner\t" + codice + "\t" + modello + "\t" + produttore + "\t" + giorno + "\t" + mese + "\t" + anno + "\t" + prezzo + "\t" + modelloStampante + "\t-";
    }
}