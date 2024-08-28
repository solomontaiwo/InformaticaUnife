public class Pallavolo extends Squadra {
    private float setVintiMedia;

    public Pallavolo(String nome, int codice, String sport, int vinte, int perse, float setVintiMedia) {
        super(nome, codice, sport, vinte, perse);
        this.setVintiMedia = setVintiMedia;
    }

    public String toString() {
        return super.toString() + "\t-\t" + setVintiMedia + "\t" + "pallavolo";
    }
}