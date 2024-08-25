public class Campo {
    protected int codice;
    protected String sport, nome;
    protected float larghezza, lunghezza, costo;
    protected int prenotazioni;

    public Campo(int codice, String sport, String nome, float larghezza, float lunghezza, float costo) {
        this.codice = codice;
        this.sport = sport;
        this.nome = nome;
        this.larghezza = larghezza;
        this.lunghezza = lunghezza;
        this.costo = costo;
        prenotazioni = 0;
    }
    
    public void addPrenotazione() {
    	prenotazioni++;
    }
    
    public float incasso() {
    	return prenotazioni*costo;
    }
    
    public String toString() {
    	return nome + "\t" + codice + "\t" + larghezza + "\t" + lunghezza + "\t";
    }
}