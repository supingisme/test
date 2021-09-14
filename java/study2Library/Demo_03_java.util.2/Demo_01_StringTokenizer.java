/*
2017/6/30 Rong Tao
*/

//Demonstrate StringTokenizer
import java.util.StringTokenizer;

class Demo_01{

        static String in = "title = Java : The Complete Reference;" +
                                "author = Schildt;"+
                               "publisher = Osborne/McGraw-Hill;" +
                                "copyright = 2001";

        public static void main(String[]args){

                StringTokenizer st = new StringTokenizer(in,"=;");

                while(st.hasMoreTokens()){
                        String key = st.nextToken();
                        String val = st.nextToken();
                        System.out.println(key+"\t"+val);
                }
        }
}
