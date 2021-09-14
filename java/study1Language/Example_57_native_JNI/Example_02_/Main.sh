javac Main.java
javah -jni Main
gcc -shared -fpic -o libMMain.so -I${JAVA_HOME}/include \
  -I${JAVA_HOME}/include/linux Main.c
java -Djava.library.path=. Main

rm *~ *class *so
