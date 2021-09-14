// Demonstrate FileWriter.
import java.io.*;
class Demo_04 {
        public static void main(String args[]) throws Exception {
                String source = "Now is the time for all good men\n"
                                + " to come to the aid of their country\n"
                                + " and pay their due taxes.";
                char buffer[] = new char[source.length()];
                source.getChars(0, source.length(), buffer, 0);
                FileWriter f0 = new FileWriter("test.txt");
                for (int i=0; i < buffer.length; i += 1) {
                        f0.write(buffer[i]);
                        }
                f0.close();
                FileWriter f1 = new FileWriter("file2.txt");
                f1.write(buffer);
                f1.close();
                FileWriter f2 = new FileWriter("file3.txt");
                f2.write(buffer,buffer.length-buffer.length/4,buffer.length/4);
                f2.close();
        }
}
