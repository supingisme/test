/*

这个应用程序使用了四个源文件。AddServerIntf.java是第一个源文件，在这个文件中
定义了服务器提供的远程接口。这个接口包括一个接受两个double参数然后返回其和的方
法。所有的远程接口必须继承Remote接口，这个接口是java.rmi包的一部分。Remote类没有
成员变量。它的目的就是简单的说明一个使用了远程方法的接口。所有的远程方法都可以
引发一个RemoteException异常。
*/


import java.rmi.*;
public interface AddServerIntf extends Remote {
        double add(double d1, double d2) throws RemoteException;
}
