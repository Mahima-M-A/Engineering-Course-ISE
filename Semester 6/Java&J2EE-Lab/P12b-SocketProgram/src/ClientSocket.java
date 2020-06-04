import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.FileReader;
import java.net.Socket;

public class ClientSocket {
	public static void main(String[] args) {
		try {
			Socket socket = new Socket("localhost", 1500);
			BufferedReader reader = new BufferedReader(new FileReader("hello.txt"));
			String lines = reader.readLine(); 
			DataOutputStream output = new DataOutputStream(socket.getOutputStream()); 
			output.writeUTF(lines); 
            System.out.println("File Transferred"); 
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
