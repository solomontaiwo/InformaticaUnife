import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

public class Goal1_Soln {
    private Image dukeImage;
    private ImageView dukeImageView;

    public Goal1_Soln(double x, double y){
        dukeImage = new Image(getClass().getResource("Duke.png").toString());
        dukeImageView = new ImageView(dukeImage);
        
        dukeImageView.setX(x);
        dukeImageView.setY(y);
        
        GoalTest1_Soln.root.getChildren().addAll(dukeImageView);
        interactions();
    }
    
    private void interactions(){
        //Exercise 4   
        
    }
}
