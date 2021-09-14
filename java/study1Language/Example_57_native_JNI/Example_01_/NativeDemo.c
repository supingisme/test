/* This file contains the C version of the
test() method.
*/
/*
sudo apt-get install build-essential openjdk-7-jdk
export JAVA_HOME='/usr/lib/jvm/java-7-openjdk-amd64'
javac Main.java
javah -jni Main
gcc -shared -fpic -o libMain.so -I${JAVA_HOME}/include \
  -I${JAVA_HOME}/include/linux Main.c
java -Djava.library.path=. Main
*/
#include <jni.h>
#include "NativeDemo.h"
#include <stdio.h>
JNIEXPORT void JNICALL Java_NativeDemo_test(JNIEnv *env, jobject obj)
{
	jclass cls;
	jfieldID fid;
	jint i;
	printf("Starting the native method.\n");
	cls = (*env)->GetObjectClass(env, obj);
	fid = (*env)->GetFieldID(env, cls, "i", "I");
	if(fid == 0) {
		printf("Could not get field id.\n");
		return;
	}
	i = (*env)->GetIntField(env, obj, fid);
	printf("i = %d\n", i);
	(*env)->SetIntField(env, obj, fid, 2*i);
	printf("Ending the native method.\n");
}
JNIEXPORT void JNICALL Java_NativeDemo_test2
  (JNIEnv *env, jobject obj, jint i){
	printf("i = %d\n",i);
}
