/*
第二个源文件是AddServerImpl.java，它实现了远程接口。Add()方法的实现是很简单的。
所有远程对象必须扩展UnicastRemoteObject类，在这个类中提供了对象可以被远程调用的
功能。

*/

import java.rmi.*;
import java.rmi.server.*;
public class AddServerImpl extends UnicastRemoteObject implements AddServerIntf {
        public AddServerImpl() throws RemoteException {}
        public double add(double d1, double d2) throws RemoteException {
                return d1 + d2;
        }
}
