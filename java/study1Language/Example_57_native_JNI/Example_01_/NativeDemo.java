// A simple example that uses a native method.
/*
sudo apt-get install build-essential openjdk-7-jdk
export JAVA_HOME='/usr/lib/jvm/java-7-openjdk-amd64'
javac Main.java
javah -jni Main
gcc -shared -fpic -o libMain.so -I${JAVA_HOME}/include \
  -I${JAVA_HOME}/include/linux Main.c
java -Djava.library.path=. Main
*/
public class NativeDemo {
	int i;
	public static void main(String args[]) {
		NativeDemo ob = new NativeDemo();
		ob.i = 10;
		System.out.println("This is ob.i before the native method:" + ob.i);
		ob.test(); // call a native method
		System.out.println("This is ob.i after the native method:" + ob.i);
	
		new NativeDemo().test2(31);
	}
	// declare native method
	public native void test() ;
	public native void test2(int a) ;
	// load DLL that contains static method
	static { 
		System.loadLibrary("NativeDemo");
	}
}
