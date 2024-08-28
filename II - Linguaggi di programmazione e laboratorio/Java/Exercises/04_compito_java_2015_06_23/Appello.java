public class Appello {
    protected int codice;
    protected String docente;
    protected String corso;
    protected int giorno, mese, anno;
    protected int ora;

    public Appello(int codice, String docente, String corso, int giorno, int mese, int anno, int ora) {
        this.codice = codice;
        this.docente = docente;
        this.corso = corso;
        this.giorno = giorno;
        this.mese = mese;
        this.anno = anno;
        this.ora = ora;
    }

    public int getOra() {
        return ora;
    }
}