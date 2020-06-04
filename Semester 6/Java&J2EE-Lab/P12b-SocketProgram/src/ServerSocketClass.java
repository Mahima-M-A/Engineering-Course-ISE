import java.io.DataInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.ServerSocket;

public class ServerSocketClass {
	public static void main(String[] args) {
		try { 
	        ServerSocket server = new ServerSocket(1500); 
	        Socket socket = server.accept(); 
	        DataInputStream input = new DataInputStream(socket.getInputStream()); 
	        String data = input.readUTF(); 
	        System.out.println("File Received"); 
	        FileOutputStream output = new FileOutputStream("hi.txt"); 
	        output.write(data.getBytes());
	        
	       } catch (IOException e) { 
	         e.printStackTrace(); 
	       }
	}
}
