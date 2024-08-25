import java.util.*;

public class Privato extends Cliente {

    private String nome;

    public Privato(int codice, String indirizzo, int giorno, int mese, int anno, String nome) {
        super(codice, indirizzo, giorno, mese, anno);
        this.nome = nome;
    }

    public String toString() {
        return "privato\t" + codice + "\t" + nome + "\t-\t" + indirizzo + "\t" + giorno + "-" + mese + "-" + anno + "\t-";
    }
}