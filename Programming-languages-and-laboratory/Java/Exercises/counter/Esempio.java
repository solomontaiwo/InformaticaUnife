package Java.counter;

public class Esempio {
       public static void main(String args[]) {
        int n;
        Counter c1;
        c1 = new Counter();
        c1.reset();
        c1.inc();
        n = c1.getValue();
        System.out.println(n);
    }
}