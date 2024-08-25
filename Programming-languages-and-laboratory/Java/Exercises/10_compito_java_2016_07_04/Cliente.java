import java.util.*;

public class Cliente {

    protected String tipo;
    protected int cod;
    protected float premio;
    protected Filiale filialeAttuale;
    protected List<Filiale> filialiPassate;

    public Cliente(String t, int c, float p, Filiale att, List<Filiale> pass) {
        cod = c;
        tipo = t;
        premio = p;
        filialeAttuale = att;
        filialiPassate = pass;
        att.addClAtt(this);
        for (Filiale f : pass) {
            f.addClPass(this);
        }

    }

    public String toString() {
        return cod + "\t" + filialeAttuale.getNome() + "\t" + premio;
    }
}