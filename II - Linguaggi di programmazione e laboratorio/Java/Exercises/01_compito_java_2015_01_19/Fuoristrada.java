public class Fuoristrada extends Auto {
    int marce;

    public Fuoristrada(String m, String pr, int p, int cod, int mar) {
        super(m, pr, p, cod);
        marce = mar;
    }

    public String toString() {
        return codice + "\t" + produttore + "\t" + modello + "\t-\t" + marce;
    }
}