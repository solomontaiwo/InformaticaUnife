public class newEsempio {
    public static void main(String args[]){
        int n;
        newCounter c1;
        c1 = new newCounter();

        c1.reset();
        c1.inc();
        c1.inc();

        n = c1.set();

        System.out.println(n);

        c1.dec();

        n = c1.set();

        System.out.println(n);

    }
}