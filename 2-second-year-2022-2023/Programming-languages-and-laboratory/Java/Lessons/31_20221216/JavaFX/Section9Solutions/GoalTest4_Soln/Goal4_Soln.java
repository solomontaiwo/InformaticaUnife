import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.media.AudioClip;

public class Goal4_Soln {
    private Image dukeImage;
    private ImageView dukeImageView;
    private Image gloveImage;
    private ImageView gloveImageView;
    private AudioClip tone;

    public Goal(double x, double y){
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
        
        GoalTest4_Soln.root.getChildren().addAll(dukeImageView, gloveImageView);
        interactions();
    }
    
    private void interactions(){
        dukeImageView.setOnMousePressed((MouseEvent me) -> {
            tone.play();
        });
        
        dukeImageView.setOnMouseDragged((MouseEvent me) -> {
            System.out.println(me.getSceneX() +", " +me.getSceneY());
        });
    }
}