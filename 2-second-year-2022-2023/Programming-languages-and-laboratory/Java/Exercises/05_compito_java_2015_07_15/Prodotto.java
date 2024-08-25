public class Prodotto {
    protected int codice;
    protected String modello;
    protected String produttore;
    protected int giorno, mese, anno;
    protected int prezzo;

    public Prodotto(int codice, String modello, String produttore, int giorno, int mese, int anno, int prezzo) {
        this.codice = codice;
        this.modello = modello;
        this.produttore = produttore;
        this.giorno = giorno;
        this.mese = mese;
        this.anno = anno;
        this.prezzo = prezzo;
    }
}