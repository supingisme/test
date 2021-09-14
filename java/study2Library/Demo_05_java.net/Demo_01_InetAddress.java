// Demonstrate InetAddress.
import java.net.*;

class Demo_01
{
        public static void main(String args[]) throws UnknownHostException {

                InetAddress Address = InetAddress.getLocalHost();
                System.out.println(Address);
                Address = InetAddress.getByName("www.baidu.com");
                System.out.println(Address);
                InetAddress SW[] = InetAddress.getAllByName("www.baidu.com");
                for (int i=0; i<SW.length; i++)
                        System.out.println(SW[i]);
          }
}
