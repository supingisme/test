
/*
sudo apt-get install build-essential openjdk-7-jdk
export JAVA_HOME='/usr/lib/jvm/java-7-openjdk-amd64'
javac Main.java
javah -jni Main
gcc -shared -fpic -o libMain.so -I${JAVA_HOME}/include \
  -I${JAVA_HOME}/include/linux Main.c
java -Djava.library.path=. Main
*/
public class Main {
    public native int square(int i);
    public native int sum(int i,int j);
    public native float volume (float i,float j,float k);
    public static void main(String[] args) {
        System.loadLibrary("MMain");
        System.out.println("square = "+new Main().square(2));
        System.out.println("sum = "+new Main().sum(1,2));
        System.out.println("volume = "+new Main().volume(0.9f,0.9f,0.9f));
    }
}
