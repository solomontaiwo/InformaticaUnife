public class Cliente {
    protected int codice;
    protected String indirizzo;
    protected int giorno, mese, anno;

    public Cliente(int codice, String indirizzo, int giorno, int mese, int anno) {
        this.codice = codice;
        this.indirizzo = indirizzo;
        this.giorno = giorno;
        this.mese = mese;
        this.anno = anno;
    }
}