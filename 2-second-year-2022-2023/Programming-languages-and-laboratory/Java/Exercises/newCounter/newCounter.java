public class newCounter{
    private int val;

    public void reset(){
        val = 0;
    }

    public void inc(){
        val++;
    }

    public void dec(){
        val--;
    }

    public int set(){
        return val;
    }
}