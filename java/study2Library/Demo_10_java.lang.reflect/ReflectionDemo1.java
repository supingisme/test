// Demonstrate reflection.
/*
接下来的这个应用程序演示了如何简单的使用Java自省功能。这个程序输出了
java.awt.Dimension类中的构造函数、成员属性和方法的信息。该程序开始时通过使用class
对象的forname方法获得了一个java.awt.Dimension类的对象。在获得这个对象之后，
getConstructors( )，getFields( )和getMethods( )方法被用来分析这个类的对象，它们分别返回
了用来提供相应对象信息的Constructor，Field和Method对象的数组。在Constructor，Field
和Method类中定义了一些可以用来获得一个对象信息的方法。然而，它们都支持toString( )
方法。因此，将Constructor，Field和Method对象作为参数来调用println( )方法是最简单的，
下面的例子正是这样做的。
*/

import java.lang.reflect.*;

public class ReflectionDemo1 {
        public static void main(String args[]) {
                try {
                        Class c = Class.forName("java.awt.Dimension");
                        System.out.println("Constructors:");
                        Constructor constructors[] = c.getConstructors();
                        for(int i = 0; i < constructors.length; i++) {
                                System.out.println(" " + constructors[i]);
                                }
                        System.out.println("Fields:");
                        Field fields[] = c.getFields();
                        for(int i = 0; i < fields.length; i++) {
                                System.out.println(" " + fields[i]);
                        }
                        System.out.println("Methods:");
                        Method methods[] = c.getMethods();
                        for(int i = 0; i < methods.length; i++) {
                                System.out.println(" " + methods[i]);
                        }
                }
                catch(Exception e) {
                        System.out.println("Exception: " + e);
                }
        }
}
