import java.util.*;

public class InCasa extends Partita {
    private String palazzetto;

    public InCasa(String data, String ora, String risultato, int vittoria, String palazzetto) {
        super(data, ora, risultato, vittoria);
        this.palazzetto = palazzetto;
    }

    public String toString() {
        return palazzetto + "\t-\t" + data + "\t" + ora + "\t" + risultato;
    }
}