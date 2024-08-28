public class Auto {
    protected String modello, produttore;
    protected int peso, codice;

    public Auto(String m, String pr, int p, int cod) {
        modello = m;
        produttore = pr;
        peso = p;
        codice = cod;
    }

    public int getPeso() {
        return this.peso;
    }

    public String getProduttore() {
        return this.produttore;
    }

    public String getModello() {
        return this.modello;
    }
}