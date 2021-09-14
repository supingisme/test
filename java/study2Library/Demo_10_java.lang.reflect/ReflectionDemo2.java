// Show public methods.
/*
接下来的这个例子使用了Java的自省功能来获得一个类的公用方法。这个程序首先实
例化A类。getClass()方法被应用到这个对象的引用，并且返回对于A类的class对象。然后，
通过调用后面这个对象的方法来获得一个Method对象数组，这个数组只用来描述A类中说
明的方法。从超类继承来的方法例如Object将不在其中。
然后处理Methods对象数组中的每一个元素。getModifiers( )方法返回了一个整数，这个
整数包括了那些用来描述这个元素访问修饰符的标志。Modifier类提供了一系列的可以用来
检查这个值的方法，它们在表24-3中列出。例如，当它的参数包括了public访问控制值时，
静态方法isPublic( ) 返回true，否则就返回false。在接下来的程序中，如果方法支持public
访问，它的名字将通过getName( )方法获得，然后打印出来。
*/
import java.lang.reflect.*;
        public class ReflectionDemo2 {
                public static void main(String args[]) {
                        try {
                                A a = new A();
                                Class c = a.getClass();
                                System.out.println("Public Methods:");
                                Method methods[] = c.getDeclaredMethods();
                                for(int i = 0; i < methods.length; i++) {
                                        int modifiers = methods[i].getModifiers();
                                        if(Modifier.isPublic(modifiers)) {
                                                System.out.println(" " + methods[i].getName());
                                        }
                                }
                        }
                        catch(Exception e) {
                                System.out.println("Exception: " + e);
                        }
                }
        }
        class A {
                public void a1() {}
                public void a2() {}
                protected void a3() {}
                private void a4() {}
        }
