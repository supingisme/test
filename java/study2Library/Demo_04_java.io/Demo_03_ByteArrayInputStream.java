// Demonstrate ByteArrayInputStream.


import java.io.*;
class Demo_03 {
        public static void main(String args[]) throws IOException {
                String tmp = "abc";
                byte b[] = tmp.getBytes();
                ByteArrayInputStream in = new ByteArrayInputStream(b);
                for (int i=0; i<2; i++) {
                        int c;
                        while ((c = in.read()) != -1) {
                                if (i == 0) {
                                        System.out.print((char) c);
                                } else {
                                        System.out.print(Character.toUpperCase((char) c));
                                        }
                                }
                        System.out.println();
                        in.reset();
                        }
                System.out.println("___________");
                C.c();
          }
}

class C{

        static void c() throws IOException{

                String str = "rong tao shini daye";
                byte b[] = str.getBytes();
                ByteArrayInputStream in = new ByteArrayInputStream(b);
                for(int i=0;i<2;i++){
                        int c;
                        while((c = in.read())!=-1){
                                if(i==0) System.out.print((char)c);
                                else System.out.print(Character.toUpperCase((char)c));
                                }
                        System.out.println();
                        in.reset();
                }
        }
}
