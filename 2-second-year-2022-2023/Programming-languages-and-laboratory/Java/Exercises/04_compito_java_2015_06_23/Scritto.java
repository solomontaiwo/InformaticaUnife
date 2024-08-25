public class Scritto extends Appello {
    private String aula;
    private int durata;

    public Scritto(int codice, String docente, String corso, int giorno, int mese, int anno, int ora, String aula,
            int durata) {
        super(codice, docente, corso, giorno, mese, anno, ora);
        this.aula = aula;
        this.durata = durata;
    }

    public String toString() {
        return "scritto" + "\t" + codice + "\t" + docente + "\t" + corso + "\t" + giorno + "\t" + mese + "\t" + anno
                + "\t" + ora + "\t" + aula + "\t" + durata + "\t-";
    }
}