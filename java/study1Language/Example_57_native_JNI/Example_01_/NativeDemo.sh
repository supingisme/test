javac NativeDemo.java
javah -jni NativeDemo
gcc -shared -fpic -o libNativeDemo.so -I${JAVA_HOME}/include \
  -I${JAVA_HOME}/include/linux NativeDemo.c
java -Djava.library.path=. NativeDemo

rm *~ *class *so
