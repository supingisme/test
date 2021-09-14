/*
第四个源文件是AddClient.java，这个文件实现了这个分布式应用程序的客户端。
AddClient.java需要三个命令行参数。第一个是服务器机器的名字或者是IP地址。第二个和
第三个是那两个用于计算的数。
应用程序首先形成一个URL形式的字符串。这个URL使用了RMI协议。这个字符串包
括服务器的IP地址或者名字和字符串“AddServer”。然后这个程序调用Naming类的lookup( )
方法。这个方法以一个RMI的URL为参数，返回一个AddServerIntf对象的引用。接着，所
有的远程方法就可以通过它来调用了。
接下来，这个程序显示了它的参数，然后调用远程方法add()，最后从这个方法返回两
数相加之和，然后打印出来。
*/

import java.rmi.*;
public class AddClient {
        public static void main(String args[]) {
                try {
                        String addServerURL = "rmi://" + args[0] + "/AddServer";
                        AddServerIntf addServerIntf = (AddServerIntf)Naming.lookup(addServerURL);
                        System.out.println("The first number is: " + args[1]);
                        double d1 = Double.valueOf(args[1]).doubleValue();
                        System.out.println("The second number is: " + args[2]);
                        double d2 = Double.valueOf(args[2]).doubleValue();
                        System.out.println("The sum is: " + addServerIntf.add(d1, d2));
                }
                catch(Exception e) {
                        System.out.println("Exception: " + e);
                }
        }
}
