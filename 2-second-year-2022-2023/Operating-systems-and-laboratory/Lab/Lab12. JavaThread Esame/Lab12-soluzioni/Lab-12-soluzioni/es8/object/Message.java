package es8.object;

import java.io.Serializable;

public class Message implements Serializable{

    private String message = null;

    public Message(String message) {
        this.message = message;
    }

    public String getMessage() {
        return this.message;
    }
}