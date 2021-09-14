javac Main.java

javah -jni NativeMethod

nvcc -o libNativeMethod.so -shared -Xcompiler -fPIC NativeMethod.cu -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux

java -Djava.library.path=. Main

