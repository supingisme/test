// Demonstrate URL.
import java.net.*;
class Demo_03 {
        public static void main(String args[]) throws MalformedURLException {
                URL hp = new URL("http://www.osborne.com/download");
                System.out.println("Protocol: " + hp.getProtocol());
                System.out.println("Port: " + hp.getPort());
                System.out.println("Host: " + hp.getHost());
                System.out.println("File: " + hp.getFile());
                System.out.println("Ext:" + hp.toExternalForm());
          }
}
