import java.util.*;

public class Stampante extends Prodotto {
    private int peso;

    public Stampante(int codice, String modello, String produttore, int giorno, int mese, int anno, int prezzo, int peso) {
        super(codice, modello, produttore, giorno, mese, anno, prezzo);
        this.peso = peso;
    }

    public String toString(){
        return "Stampante\t" + codice + "\t" + modello + "\t" + produttore + " \t" + giorno + "\t" + mese + "\t" + anno + "\t" + prezzo + "\t-\t" + peso;
    }
}