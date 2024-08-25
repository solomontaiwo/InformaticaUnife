package com.solomoncompany.hello;
        
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.TilePane;
import javafx.stage.Stage;

public class JavaFXMain extends Application {
    
    @Override
    public void start(Stage primaryStage) {
 
	    Button btn1 = new Button();
        Button btn2 = new Button();
        btn1.setText("Say 'HelloWorld'");
        btn1.setLayoutY(100);
        btn2.setText("222");

        btn1.setOnAction(new EventHandler<ActionEvent>() {
            
            @Override
            public void handle(ActionEvent event) {
                System.out.println("Hello World!");
            }
        });
        
        TilePane root = new TilePane();
        root.getChildren().add(btn1);
        root.getChildren().add(btn2);
                
        Scene scene = new Scene(root, 300, 250);
        
        primaryStage.setTitle("Hello World!");
        primaryStage.setScene(scene);
        primaryStage.show();
	
    }

    public static void main(String[] args) {
        launch(args);
    }
}
