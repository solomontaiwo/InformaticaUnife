
public class Squadra {

    protected int codice;
    protected String sport, nome;
    protected int vinte, perse;

    public Squadra(int codice, String sport, String nome, int vinte, int perse) {
        this.codice = codice;
        this.sport = sport;
        this.nome = nome;
        this.vinte = vinte;
        this.perse = perse;
    }

    public int getVinte() {
        return vinte;
    }
}
