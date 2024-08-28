public class Orale extends Appello {
    private int studenti;

    public Orale(int codice, String docente, String corso, int giorno, int mese, int anno, int ora, int studenti) {
        super(codice, docente, corso, giorno, mese, anno, ora);
        this.studenti = studenti;
    }

    public String toString() {
        return "orale" + "\t" + codice + "\t" + docente + "\t" + corso + "\t" + giorno + "\t" + mese + "\t" + anno + "\t" + ora + "\t-\t-\t" + studenti;
    }
}