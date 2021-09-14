// Use a BufferedReader to read characters from the console.
import java.io.*;
class Example_50 {
	public static void main(String args[])throws IOException{
		char c;
		int a;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter characters, 'q' to quit.");
		// read characters
		do {
			//c = (char) br.read();
			a = br.read();
			c = (char)a;
			System.out.println("a = "+a+", c = "+c);
		} while(c != 'q');
	}
}
