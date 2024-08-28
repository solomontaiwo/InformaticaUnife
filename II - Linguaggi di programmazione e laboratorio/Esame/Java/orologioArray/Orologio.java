public class Orologio {
    private Counter[] c;

    public Orologio() {
        c = new Counter[2];
        for (int i = 0; i < 2; i++)
            c[i] = new Counter();
    }

    public void reset() {
        for (int i = 0; i < 2; i++) {
            c[i].reset();
        }
    }

    public void tic() {
        c[0].inc();
        if (c[0].getValue() == 60) {
            c[0].reset();
            c[1].inc();
        }

        if (c[1].getValue() == 24) {
            c[1].reset();
        }
    }

    public int getOre() {
        return c[1].getValue();
    }

    public int getMinuti() {
        return c[0].getValue();
    }
}