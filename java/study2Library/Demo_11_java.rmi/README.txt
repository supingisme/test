24.3.1 一个使用了RMI技术的简单的客户机/服务器应用程序
下面一步一步的说明了如何创建一个简单的使用RMI技术的客户机/服务器应用程序。
服务器从一个客户端获得一个请求，然后处理它并且返回一个结果。在这个例子中，收到
的是两个数字。服务器把它们相加，然后返回它们的和。
第一步：输入并且编译源代码
这个应用程序使用了四个源文件。AddServerIntf.java是第一个源文件，在这个文件中
定义了服务器提供的远程接口。这个接口包括一个接受两个double参数然后返回其和的方
法。所有的远程接口必须继承Remote接口，这个接口是java.rmi包的一部分。Remote类没有
成员变量。它的目的就是简单的说明一个使用了远程方法的接口。所有的远程方法都可以
引发一个RemoteException异常。
import java.rmi.*;
public interface AddServerIntf extends Remote {
double add(double d1, double d2) throws RemoteException;
}
第二个源文件是AddServerImpl.java，它实现了远程接口。Add()方法的实现是很简单的。
所有远程对象必须扩展UnicastRemoteObject类，在这个类中提供了对象可以被远程调用的
功能。
import java.rmi.*;
import java.rmi.server.*;
public class AddServerImpl extends UnicastRemoteObject
implements AddServerIntf {
public AddServerImpl() throws RemoteException {
}
public double add(double d1, double d2) throws RemoteException {
return d1 + d2;
}
}
第三个源文件是AddServer.java，在这个源文件中包括了服务器端的主程序。它的主要
功能是更新机器上的RMI注册表。这些是通过调用java.rmi包中Naming类的rebind()方法来实
现的。这个方法可以将一个名字和一个对象引用联系起来。rebind()的第一个参数是服务器
的名字，第二个参数是一个AddServerImpl类的实例的引用。
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
第四个源文件是AddClient.java，这个文件实现了这个分布式应用程序的客户端。
AddClient.java需要三个命令行参数。第一个是服务器机器的名字或者是IP地址。第二个和
第三个是那两个用于计算的数。
应用程序首先形成一个URL形式的字符串。这个URL使用了RMI协议。这个字符串包
括服务器的IP地址或者名字和字符串“AddServer”。然后这个程序调用Naming类的lookup( )
方法。这个方法以一个RMI的URL为参数，返回一个AddServerIntf对象的引用。接着，所
有的远程方法就可以通过它来调用了。
接下来，这个程序显示了它的参数，然后调用远程方法add()，最后从这个方法返回两
数相加之和，然后打印出来。
import java.rmi.*;
public class AddClient {
public static void main(String args[]) {
try {
String addServerURL = "rmi://" + args[0] + "/AddServer";
AddServerIntf addServerIntf =
(AddServerIntf)Naming.lookup(addServerURL);
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
在你输入了所有代码之后，用javac编译这四个源程序。
第二步：生成存根和主框架
在你可以使用客户端和服务器之前，你必须产生必要的存根（stub）。你同样也可能
需要产生一个主框架。在RMI上下文中，一个存根是一个存放在客户端机器上的Java对象，
它的功能是提供和远程服务器相同的接口。由客户端初始化的远程方法实际上就是存根。
这个存根和RMI系统的其他部分一起工作产生一个要送到远程机器的请求。
一个远程方法可以接受那些简单类型或者对象参数。在后一种情况中，这个对象可能
包括别的对象的引用。所有这些信息必须被发送到远程机器。作为远程方法调用的一个参
数，一个对象必须被序列化之后再被送到远程机器。在第17章中，序列化的功能也递归处
理了所有被引用的对象。
在Java 2中，主框架（Skeletons）不再被需要。然而，它们在Java 1.1的RMI模型中是必
要的。正是由于这个原因，为了兼容Java 1.1和Java 2，主框架仍然是需要的。一个主框架
是一个存放在服务器机器上的Java对象。它和Java 1.1的RMI系统的其他部分一起工作来接
受请求，执行逆序列化和调用服务器上相应的代码。与Java 1.1不同，主框架机制对于Java 2
的代码不是必须的。因为许多读者想产生主框架，所以下面的例子使用了主框架。
如果一个响应必须要返回给客户端，进程按相反的方向进行工作。请注意，如果一个
对象被返回给客户端，那么也使用序列化和逆序列化功能。
为了产生存根和主框架，你需要用远程方法调用编译器（RMI compiler），它可以像
下面这样在命令行被调用：
rmic AddServerImpl
这个命令生产了两个新的文件：AddServerImpl_Skel.class( 主框架) 和AddServer
Impl_Stub.class(存根)。当使用rmic时，请确信设置CLASSPATH包括了当前目录。正如你所
看到的，默认情况下，rmic同时产生一个存根和一个主框架文件。如果你不需要主框架，
你可以有选择的放弃它。
第三步：安装文件到客户端和服务器
复制AddClient.class，AddServerImpl_Stub.class和AddServerIntf.class到客户端机器上的
一个目录中。复制AddServerIntf.class, AddServerImpl.class, AddServerImpl_Skel.class,
AddServerImpl_Stub.class和AddServer.class到服务器的一个目录中。
注意：RMI可以动态地加载类，但是它们不能被目前的例子使用。相反，所有的被
客户端和服务器程序使用的文件必须安装在这些机器上。
第四步：在服务器端启动rmi 的注册程序
JDK提供了一个叫做rmiregistry的程序，这个程序在服务器上执行。它可以映射名字到
对象的引用。首先，检查包括当前文件夹的CLASSPATH环境变量。然后，用命令行启动
RMI注册，方式如下所示：
start rmiregistry
当这个命令行返回时，你将看到产生了一个新的窗口。你需要保持这个窗口打开，直
到你用RMI的例子做完了试验。
第五步：启动服务器
服务器的程序使用下面的命令行启动：
java AddServer
重新调用AddServer代码创建AddServerImpl的实例并且用“AddServer”这个名字注册
这个对象。
第六步：启动客户端
AddClient程序需要三个参数：服务器的名字或IP，两个加数。你可以通过以下两种方
式中的一种从命令行来调用它。
java AddClient server1 8 9
java AddClient 11.12.13.14 8 9
在第一种方式中，提供服务器的名字，在第二种方式中则使用了它的IP地址。
你可以尝试不用远程服务器来执行这个例子。你可以将所有的程序安装在一台机器上，
启动rmiregistry，启动AddSever，然后用下面的方式执行AddClient。
java AddClient 127.0.0.1 8 9
在这里，地址127.0.0.1是本机的回送地址。用这个地址可以让你练习RMI的机制而不
用安装一个远程的计算机。
无论那一种情况，这个例子的输出都如下所示：
The first number is: 8
The second number is: 9
The sum is: 17
