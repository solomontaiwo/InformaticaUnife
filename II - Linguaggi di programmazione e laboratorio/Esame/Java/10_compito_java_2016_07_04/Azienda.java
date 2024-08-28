import java.util.*;

public class Azienda extends Cliente {

    private float premioPiuTasse;
    private String ragioneSociale;

    public Azienda(int c, String nome, float p, Filiale att, List<Filiale> pass, float pt) {
        super("azienda", c, p, att, pass);
        ragioneSociale = nome;
        premioPiuTasse = pt;
    }

    public String toString() {
        return tipo + "\t" + ragioneSociale + "\t" + super.toString() + "\t" + premioPiuTasse;
    }
}