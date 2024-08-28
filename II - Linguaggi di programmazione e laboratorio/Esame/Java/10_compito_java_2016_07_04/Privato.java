import java.util.*;

public class Privato extends Cliente {

    private String nomeCognome;

    public Privato(int c, String nome, float p, Filiale att, List<Filiale> pass) {
        super("privato", c, p, att, pass);
        nomeCognome = nome;
    }

    public String toString() {
        return tipo + "\t" + nomeCognome + "\t" + super.toString();
    }

}