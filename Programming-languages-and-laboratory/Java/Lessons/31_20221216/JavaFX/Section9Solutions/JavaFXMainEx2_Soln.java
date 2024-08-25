import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

public class JavaFXMainEx2_Soln extends Application {
    
    @Override
    public void start(Stage primaryStage) {
                
        Group root = new Group();  
        Rectangle rect = new Rectangle(20,20,100,200);
        rect.setX(300);
        rect.setY(250);
        rect.setWidth(200);
        rect.setHeight(100);
        rect.setFill(Color.rgb(255, 0, 0));
        rect.setStroke(Color.rgb(0, 0, 255));
        rect.setStrokeWidth(10.0);
        root.getChildren().add(rect);
        Scene scene = new Scene(root, 800, 600,Color.rgb(0,127,127));       
        primaryStage.setTitle("Hello World!");
        primaryStage.setScene(scene);
        primaryStage.show();

    }

    public static void main(String[] args) {
        launch(args);
    }
}