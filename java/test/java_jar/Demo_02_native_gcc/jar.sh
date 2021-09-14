
javac hello.java

javah -jni hello

gcc -shared -fpic -o libmath.so hello.c

jar -cvfm rt.jar Manifest.txt *.class *.so 

java -jar rt.jar
