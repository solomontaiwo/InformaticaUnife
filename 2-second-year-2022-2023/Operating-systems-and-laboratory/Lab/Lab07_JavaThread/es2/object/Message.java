package es2.object;

import java.io.Serializable;

public class Message implements Serializable {
	
    private String mess;
    public Message(String mess){
        this.mess = mess;
    }
	
    public String getMess(){
        return mess;
    }
	
}
