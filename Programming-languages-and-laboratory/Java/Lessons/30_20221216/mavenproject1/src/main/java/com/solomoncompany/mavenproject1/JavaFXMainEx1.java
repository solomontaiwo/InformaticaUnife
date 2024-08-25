package com.solomoncompany.mavenproject1;
        
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class JavaFXMainEx1 extends Application {
    
    @Override
    public void start(Stage primaryStage) {
        //remove code from here 
	
        Group root = new Group();
        
        Scene scene = new Scene(root, 300, 250);
        
        primaryStage.setTitle("Hello World!");
        primaryStage.setScene(scene);
        primaryStage.show();
		//to here to add your own code
    }

    public static void main(String[] args) {
        launch(args);
    }
}
