/*
2017/7/3
*/
import java.io.*;

class Demo_02{
        
        public static void main(String[]args)throws Exception{

                int size;
                InputStream f = new FileInputStream("tmp.txt");
                System.out.println("Total Available Bytes: "+(size = f.available()));

                int n = size/40;
                System.out.println("First "+n+" bytes of the file one read() at a time");
        
                for(int i=0;i<n;i++){
        
                        System.out.print((char)f.read());
                }
                System.out.println("\nStill Available: "+f.available());
                System.out.println("Reading the next " + n +
                                " with one read(b[])");
                byte b[] = new byte[n];
                if (f.read(b) != n) {
                        System.err.println("couldn't read " + n + " bytes.");
                }
                System.out.println(new String(b, 0, n));
                System.out.println("\nStill Available: " + (size = f.available()));
                System.out.println("Skipping half of remaining bytes with skip()");
                f.skip(size/2);
                System.out.println("Still Available: " + f.available());
                System.out.println("Reading " + n/2 + " into the end of array");
                if (f.read(b, n/2, n/2) != n/2) {
                        System.err.println("couldn't read " + n/2 + " bytes.");
                }
                System.out.println(new String(b, 0, b.length));
                System.out.println("\nStill Available: " + f.available());
                f.close();

                System.out.println("#######################");
                A a = new A();
                a.a("tmp.txt");
        }
}
class A{/* output txt file */

        static void a(String filename) throws Exception{

                InputStream f = new FileInputStream(filename);
                int size = f.available();///
                for(int i=0;i<size/4;i++){
                        System.out.print((char)f.read());
                }
                System.out.println("\n!!!!!!!!!!!!!!\n");
                byte byt[] =new byte[50];
                for(int i=size/4;i<size/2;i++){
                        System.out.print((char)f.read(byt));
                }
                f.close();
                
        }
}


