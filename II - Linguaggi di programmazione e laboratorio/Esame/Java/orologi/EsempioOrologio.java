public class EsempioOrologio {
    public static void main(String args[]){
        Orologio o;
        o = new Orologio();
        o.tic();
        o.tic();
        System.out.println(o.getOre());
        System.out.println(o.getMinuti());
        o.reset();
    }
}