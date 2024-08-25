import javafx.scene.control.ScrollBar;

public class PopulationChanger {
    private final ScrollBar xscrollBar;
    private final int xBarWidth = 100;
    private final int xBarHeight = 15;
    
    public PopulationChanger(int value){
        xscrollBar = new ScrollBar();
        xscrollBar.setMin(Dorm.MIN_POPULATION);
        xscrollBar.setMax(Dorm.MAX_POPULATION);
        setValue(value);
        
        xscrollBar.setMinSize(xBarWidth, xBarHeight);
        xscrollBar.setPrefSize(xBarWidth, xBarHeight);
        xscrollBar.setMaxSize(xBarWidth, xBarHeight);
    }
    
    public ScrollBar getScrollBar(){
        return xscrollBar;
    }
    public void setValue(int value){
        xscrollBar.setValue(value);
    }
}
