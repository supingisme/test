#include <jni.h>
#include "Main.h"
/*
sudo apt-get install build-essential openjdk-7-jdk
export JAVA_HOME='/usr/lib/jvm/java-7-openjdk-amd64'
javac Main.java
javah -jni Main
gcc -shared -fpic -o libMain.so -I${JAVA_HOME}/include \
  -I${JAVA_HOME}/include/linux Main.c
java -Djava.library.path=. Main
*/

JNIEXPORT jint JNICALL Java_Main_square(
    JNIEnv *env, jobject obj, jint i) {
  return i * i * i;
}
JNIEXPORT jint JNICALL Java_Main_sum
  (JNIEnv *env, jobject obj, jint i, jint j){
  return i + j;
}
JNIEXPORT jfloat JNICALL Java_Main_volume
  (JNIEnv *env, jobject obj, jfloat i, jfloat j, jfloat k){
  return i*j*k;
}
