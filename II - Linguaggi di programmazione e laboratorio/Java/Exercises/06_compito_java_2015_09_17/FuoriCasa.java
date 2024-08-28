import java.util.*;

public class FuoriCasa extends Partita {
    private String citta;

    public FuoriCasa(String data, String ora, String risultato, int vittoria, String citta) {
        super(data, ora, risultato, vittoria);
        this.citta = citta;
    }

    public String toString() {
        return "-\t" + citta + "\t" + data + "\t" + ora + "\t" + risultato;
    }

    public String getCitta() {
        return this.citta;
    }
}