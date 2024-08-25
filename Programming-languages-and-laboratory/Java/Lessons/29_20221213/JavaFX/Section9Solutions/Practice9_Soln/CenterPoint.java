import java.util.ArrayList;
import javafx.scene.effect.DropShadow;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;

public class CenterPoint {
    private final static ArrayList<CenterPoint> allPoints = new ArrayList<>();
    private boolean isBuildings = true; //Is Dorms or people
    Dorm[] dorms;
    
    public int xLocation;
    public int yLocation;
    public String text;
    private int distance;
    
    public Circle point = new Circle();
    public Color fillColor = Color.BLACK;
    public Color outlineColor = Color.YELLOW;
    
    public Text display = new Text();
    
    public CenterPoint(String s, boolean isBuildings, Dorm... dorms){
        text = s + "\nDistance: ";
        this.isBuildings = isBuildings;
        this.dorms = dorms;
        
        display.setFill(Color.RED);
        DropShadow dropShadow = new DropShadow();
        dropShadow.setRadius(4);
        dropShadow.setSpread(1);
        dropShadow.setColor(Color.BLACK);
        display.setEffect(dropShadow);
        display.setFont(Font.font("Default", FontWeight.BOLD, 16));
        
        JavaFXApp.root.getChildren().addAll(point, display);
        allPoints.add(this);
        
        calculateCenter();
        updateDrawing();
    }
    
    public void updateDrawing(){ //it's interesting copying this from Dorm.java    
        point.setCenterX(xLocation);  //no SetX
        point.setCenterY(yLocation);
        point.setRadius(10);  
        point.setFill(fillColor);
        point.setStroke(outlineColor);
        
        display.setText(text +distance);
        display.setX(xLocation -20);
        display.setY(yLocation + point.getRadius() +15);
    }
    public void calculateCenter(){
        if(isBuildings){
            calculateDormCenter();
        }
        else{
            calculatePeopleCenter();
        }
        distance = calculateDistance(dorms[0]);
    }
    private void calculateDormCenter(){
        int pop = 0;
        int xWeight = 0;
        int yWeight = 0;
        
        for (Dorm dorm : dorms) {
            xWeight += dorm.xLocation * dorm.population;
            yWeight += dorm.yLocation * dorm.population;
            pop += dorm.population;
        }
        
        xLocation = xWeight/pop;
        yLocation = yWeight/pop;
    }
    private void calculatePeopleCenter(){
        int xWeight = 0;
        int yWeight = 0;
        
        for (Dorm dorm : dorms) {
            xWeight += dorm.xLocation;
            yWeight += dorm.yLocation;
        }
        
        xLocation = xWeight/dorms.length;
        yLocation = yWeight/dorms.length;
    }
    private int calculateDistance(Dorm dorm){
        return (int) Math.sqrt(Math.pow(dorm.xLocation - xLocation, 2) + Math.pow(dorm.yLocation - yLocation, 2));
    }
    
    public static final void updateAllPoint(){
        for(CenterPoint point: allPoints){
            point.calculateCenter();
            point.updateDrawing();
            point.point.toFront();
            point.display.toFront();
        }
    }
}
