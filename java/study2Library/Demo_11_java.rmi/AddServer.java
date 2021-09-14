/*
第三个源文件是AddServer.java，在这个源文件中包括了服务器端的主程序。它的主要
功能是更新机器上的RMI注册表。这些是通过调用java.rmi包中Naming类的rebind()方法来实
现的。这个方法可以将一个名字和一个对象引用联系起来。rebind()的第一个参数是服务器
的名字，第二个参数是一个AddServerImpl类的实例的引用。
*/

import java.net.*;
import java.rmi.*;
public class AddServer {
        public static void main(String args[]) {
                try {
                        AddServerImpl addServerImpl = new AddServerImpl();
                        Naming.rebind("AddServer", addServerImpl);
                }
                catch(Exception e) {
                        System.out.println("Exception: " + e);
                }
        }
}
