import java.io.DataInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.ServerSocket;

public class ServerSocketClass {
	public static void main(String[] args) {
		try { 
	        ServerSocket ss = new ServerSocket(1999); 
	        Socket s = ss.accept(); 
	        DataInputStream dis = new DataInputStream(s.getInputStream()); 
	        String k = dis.readUTF(); 
	        System.out.println("File Transferred"); 
	        FileOutputStream fos = new FileOutputStream("hi.txt"); 
	        byte[] b = k.getBytes(); 
	        fos.write(b);
	        
	       } catch (IOException ie) { 
	         ie.printStackTrace(); 
	       }
	}
}
