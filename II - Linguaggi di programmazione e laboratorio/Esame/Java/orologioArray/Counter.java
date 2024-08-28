public class Counter {
    private int val;

    public void reset() {
        val = 0;
    }

    public void inc() {
        val++;
    }

    public int getValue() {
        return val;
    }
}