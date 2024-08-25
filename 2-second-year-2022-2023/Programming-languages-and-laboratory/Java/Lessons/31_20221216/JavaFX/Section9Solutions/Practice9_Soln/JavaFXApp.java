import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class JavaFXApp extends Application {
    public static Group root = new Group();
    
    @Override
    public void start(Stage primaryStage) {
        
        Scene scene = new Scene(root, 800, 650, Color.WHITE);
        
        primaryStage.setTitle("Campus");
        primaryStage.setScene(scene);
        primaryStage.show();
        
        Image background = new Image(getClass().getResourceAsStream("Images/Campus.png"));
        ImageView backgroundView = new ImageView(background);
        backgroundView.setPreserveRatio(true);
        backgroundView.setFitWidth(800);
        root.getChildren().add(backgroundView);
        backgroundView.toBack();
    }


    public static void main(String[] args) {
        Dorm dorm1 = new Dorm(50,  50, Dorm.MIN_POPULATION +(int) (Math.random() * (Dorm.MAX_POPULATION - Dorm.MIN_POPULATION)), "Dorm 1", Color.rgb(0,0,255,.5) );
        Dorm dorm2 = new Dorm(100, 50, Dorm.MIN_POPULATION +(int) (Math.random() * (Dorm.MAX_POPULATION - Dorm.MIN_POPULATION)), "Dorm 2", Color.rgb(0,255,0,.5));
        Dorm dorm3 = new Dorm(150, 50, Dorm.MIN_POPULATION +(int) (Math.random() * (Dorm.MAX_POPULATION - Dorm.MIN_POPULATION)), "Dorm 3", Color.rgb(255,0,0,.5));
        Dorm dorm4 = new Dorm(200, 50, Dorm.MIN_POPULATION +(int) (Math.random() * (Dorm.MAX_POPULATION - Dorm.MIN_POPULATION)), "Dorm 4", Color.rgb(255,255,0,.5));
        Dorm dorm5 = new Dorm(250, 50, Dorm.MIN_POPULATION +(int) (Math.random() * (Dorm.MAX_POPULATION - Dorm.MIN_POPULATION)), "Dorm 5", Color.rgb(255,0,255,.5));
        Dorm dorm6 = new Dorm(300, 50, Dorm.MIN_POPULATION +(int) (Math.random() * (Dorm.MAX_POPULATION - Dorm.MIN_POPULATION)), "Dorm 6", Color.rgb(128,64,64,.5));
        
        CenterPoint allDorms = new CenterPoint("All Dorms", true, dorm1, dorm2, dorm3, dorm4, dorm5, dorm6);
        CenterPoint studyGroup = new CenterPoint("Study Group", false, dorm1, dorm2, dorm4);

        launch(args);
    }
    
}
