import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.paint.CycleMethod;
import javafx.scene.paint.LinearGradient;
import javafx.scene.paint.Stop;
import javafx.scene.shape.Polygon;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

public class JavaFXMainEx3_Soln extends Application {
    
    @Override
    public void start(Stage primaryStage) {
                
        Group root = new Group();  
        LinearGradient gradient1 = new LinearGradient(0, 0, 1, 0, true, CycleMethod.NO_CYCLE, 
            new Stop[] {new Stop(0, Color.DODGERBLUE),
            new Stop(1, Color.BLACK)
        });

//        Rectangle rect = new Rectangle(20,20,100,200);
//        rect.setX(300);
//        rect.setY(250);
//        rect.setWidth(200);
//        rect.setHeight(100);
//        rect.setFill(gradient1);
//        rect.setStroke(Color.rgb(0, 0, 255));
//        rect.setStrokeWidth(10.0);
        
        Polygon polygon1=new Polygon(new double[]{
            80.0,10.0,
            80.0,80.0,
            10.0,80.0
        });
        polygon1.setLayoutX(50);
        polygon1.setLayoutY(50);
        
        polygon1.setFill(gradient1);
//        root.getChildren().add(rect);
        root.getChildren().add(polygon1);
        Scene scene = new Scene(root, 800, 600,Color.rgb(0,0,0));       
        primaryStage.setTitle("Hello World!");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}