public class Prodotto {
    protected int codice;
    protected String titolo;
    protected String autori;
    protected int prezzo;

    public Prodotto(int codice, String titolo, String autori, int prezzo) {
        this.codice = codice;
        this.titolo = titolo;
        this.autori = autori;
        this.prezzo = prezzo;
    }

    public int getPrezzo() {
        return prezzo;
    }
}