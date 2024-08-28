package goaltest;

import javafx.scene.image.Image;
import javafx.scene.image.ImageView;

public class Goal {
    
    private Image dukeImage;
    private ImageView dukeImageView;
    private Image gloveImage;
    private ImageView gloveImageView;

    public Goal(double x, double y){
        
        dukeImage = new Image(getClass().getResource("Images/Duke.png").toString());
        GoalTest.root.getChildren().addAll();
        interactions();
    }
    
    private void interactions(){
        //Exercise 4   
        
    }
}
