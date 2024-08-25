public class Prenotazione {
    protected int codiceCampo, oraInizio;

    public Prenotazione(int codiceCampo, int oraInizio) {
        this.codiceCampo = codiceCampo;
        this.oraInizio = oraInizio;
    }

    public String toString() {
        return "(" + codiceCampo + "," + oraInizio + ")";
    }
}