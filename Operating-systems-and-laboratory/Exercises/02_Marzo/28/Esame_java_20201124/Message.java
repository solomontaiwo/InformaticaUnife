import java.io.Serializable;

public class Message implements Serializable {

    private int pezziProdotti = 0;
    private float fIndicator = 0F;
    
    public Message(int pezziProdotti, float fIndicator) {
        this.pezziProdotti = pezziProdotti;
        this.fIndicator = fIndicator;
    }

    public int getPezziProdotti() {
        return this.pezziProdotti;
    }

    public float getFIndicator() {
        return this.fIndicator;
    }    

}