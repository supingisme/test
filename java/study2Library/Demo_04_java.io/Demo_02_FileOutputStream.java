// Demonstrate FileOutputStream.
import java.io.*;
class Demo_02 {
        public static void main(String args[]) throws Exception {
                String source = "Now is the time for all good men\n"
                        + " to come to the aid of their country\n"
                        + " and pay their due taxes.";
                byte buf[] = source.getBytes();
                OutputStream f0 = new FileOutputStream("file1.txt");
                for (int i=0; i < buf.length; i += 2) {
                        f0.write(buf[i]);
                }
                f0.close();
                OutputStream f1 = new FileOutputStream("file2.txt");
                f1.write(buf);
                f1.close();
                OutputStream f2 = new FileOutputStream("file3.txt");
                f2.write(buf,buf.length-buf.length/4,buf.length/4);
                f2.close();

                B.b("file4.txt");
        }
}
class B{

        static void b(String filename) throws Exception{

                String str = "1234567890" +
                                        "abcdefghijklmnopqrstuvwxyz";

                byte buffer[] = str.getBytes();

                OutputStream f = new FileOutputStream(filename);
                for(int i=0;i<buffer.length;i++){
                        f.write(buffer[i]);
                }
                f.write(buffer);
        }
}
