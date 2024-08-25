public class Orologio {
    private Counter ore, min;

    public Orologio() {
        ore = new Counter();
        min = new Counter();
    }

    public void reset() {
        ore.reset();
        min.reset();
    }

    public void tic() {
        min.inc();
        if (min.getValue() == 60) {
            min.reset();
            ore.inc();
        }
        if (ore.getValue() == 24) {
            ore.reset();
        }
    }

    public int getOre() {
        return ore.getValue();
    }

    public int getMinuti() {
        return min.getValue();
    }

}