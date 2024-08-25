import java.awt.geom.Point2D;
import javafx.scene.effect.DropShadow;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;

public class Dorm {
    public static final int MIN_POPULATION = 50;
    public static final int MAX_POPULATION = 400;
    
    public int xLocation;
    public int yLocation;
    public int population;
    public String text;
    
    private Point2D.Double iconGrabPosition = new Point2D.Double(0,0);
    private Point2D.Double mouseGrabPosition = new Point2D.Double(0,0);
    private Point2D.Double mouseReleasePosition = new Point2D.Double(0,0);
    PopulationChanger popChanger;
    
    public Rectangle dormRect = new Rectangle();
    public Color fillColor;
    public Color outlineColor = Color.YELLOW;
    //changing these colors doesn't change the rectangle, which is a separate object
    //If you change it's position, make sure it's the dorm and not the rect

    public Text display = new Text();
    
    
    public Dorm(int x, int y, int pop, String s, Color c){
        xLocation = x;
        yLocation = y;
        population = pop;
        text = s;
        fillColor = c;
        
        display.setFill(Color.RED);
        DropShadow dropShadow = new DropShadow();
        dropShadow.setRadius(4);
        dropShadow.setSpread(1);
        dropShadow.setColor(Color.BLACK);
        display.setEffect(dropShadow);
        display.setFont(Font.font("Default", FontWeight.BOLD, 16));

        JavaFXApp.root.getChildren().addAll(dormRect, display);
        interactions();
        updateDrawing();
    }
    
    public void updateDrawing(){
        dormRect.setWidth(150*(1.0*population/MAX_POPULATION));
        dormRect.setHeight(150*(1.0*population/MAX_POPULATION));    //nothing showed when it was /300 =P
        dormRect.setLayoutX(xLocation -dormRect.getWidth()/2);
        dormRect.setLayoutY(yLocation -dormRect.getHeight()/2);
        dormRect.setFill(fillColor);
        dormRect.setStroke(outlineColor);
        
        display.setText(text +":\n" +population);
        display.setLayoutX(dormRect.getLayoutX() -40);
        display.setLayoutY(dormRect.getLayoutY() + dormRect.getHeight() +15);
        display.setTextAlignment(TextAlignment.CENTER);
        display.setWrappingWidth(dormRect.getWidth() +80);
    }
    
    private void interactions(){
        //Start MouseHover 
        dormRect.setOnMouseEntered((MouseEvent me) -> {
            highlight();
        });
        //Stop MouseHover
        dormRect.setOnMouseExited((MouseEvent me) -> {
            unhighlight();
        });
        dormRect.setOnMousePressed((MouseEvent me) -> {
            mouseGrabPosition.x = me.getSceneX();
            mouseGrabPosition.y = me.getSceneY();
            iconGrabPosition.x = xLocation;
            iconGrabPosition.y = yLocation;
            dormRect.toFront();
        });
        dormRect.setOnMouseDragged((MouseEvent me) -> {
            mouseReleasePosition.x = me.getSceneX();
            mouseReleasePosition.y = me.getSceneY();
            xLocation = (int) (me.getSceneX() -mouseGrabPosition.x +iconGrabPosition.x);
            yLocation = (int) (me.getSceneY() -mouseGrabPosition.y +iconGrabPosition.y);
            updateDrawing();
            CenterPoint.updateAllPoint();
        });
        display.setOnMousePressed((MouseEvent me) -> {
            if(popChanger == null){
                mouseGrabPosition.x = me.getSceneX();
                iconGrabPosition.x = population;
                popChanger = new PopulationChanger(population);
                popChanger.getScrollBar().setLayoutX(dormRect.getLayoutX());
                popChanger.getScrollBar().setLayoutY(dormRect.getLayoutY() +dormRect.getHeight() +40);
                JavaFXApp.root.getChildren().add(popChanger.getScrollBar());
            }
        });
        display.setOnMouseDragged((MouseEvent me) -> {
            mouseReleasePosition.x = me.getSceneX();
            int newValue = (int) (2*me.getSceneX() -2*mouseGrabPosition.x +iconGrabPosition.x);
            if(newValue < MIN_POPULATION){
                newValue = MIN_POPULATION;
            }
            else if(newValue > MAX_POPULATION){
                newValue = MAX_POPULATION;
            }
            popChanger.setValue(newValue);
            population = newValue;
            updateDrawing();
            CenterPoint.updateAllPoint();
            popChanger.getScrollBar().setLayoutY(dormRect.getLayoutY() +dormRect.getHeight() +40);
        });
        display.setOnMouseReleased((MouseEvent me) -> {
            popChanger.getScrollBar().toBack(); //To get around bug where scollbar art doesn't go away
            if(popChanger != null){
                JavaFXApp.root.getChildren().remove(popChanger.getScrollBar());
                popChanger = null;
            }
        });
    }

    private void highlight(){
        DropShadow dropShadow = new DropShadow();
        dropShadow.setRadius(15);
        dropShadow.setColor(Color.rgb(255, 253, 153));
        dormRect.setEffect(dropShadow);
    }
    private void unhighlight(){
        dormRect.setEffect(null);
    }  
}
