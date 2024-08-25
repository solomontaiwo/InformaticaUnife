import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.media.AudioClip;

public class Goal3_Soln {
    private Image dukeImage;
    private ImageView dukeImageView;
    private Image gloveImage;
    private ImageView gloveImageView;
    private AudioClip tone;

    public Goal3_Soln(double x, double y){
        dukeImage = new Image(getClass().getResource("Duke.png").toString());
        dukeImageView = new ImageView(dukeImage);
        gloveImage = new Image(getClass().getResource("Glove.png").toString());
        gloveImageView = new ImageView(gloveImage);
        
        tone = new AudioClip(getClass().getResource("Note5.wav").toString());
        
        gloveImageView.setPreserveRatio(true);
        gloveImageView.setFitWidth(38);
        
        dukeImageView.setX(x);
        dukeImageView.setY(y);
        gloveImageView.setX(x +13);
        gloveImageView.setY(y -10);
        
        GoalTest3_Soln.root.getChildren().addAll(dukeImageView, gloveImageView);
        interactions();
    }
    
    private void interactions(){
        //Exercise 4   
        
    }
}
