public class Giocatore {
    protected int codiceSquadra;
    protected String cognome;
    protected int eta;
    protected int numeroMaglia;
    protected String ruolo;
    protected Boolean titolare;

    public Giocatore(int codiceSquadra, String cognome, int eta, int numeroMaglia, String ruolo, Boolean titolare) {
        this.codiceSquadra = codiceSquadra;
        this.cognome = cognome;
        this.eta = eta;
        this.numeroMaglia = numeroMaglia;
        this.ruolo = ruolo;
        this.titolare = titolare;
    }
}