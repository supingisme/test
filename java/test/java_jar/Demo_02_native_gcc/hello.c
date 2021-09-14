#include"hello.h"

/*
 * Class:     hello
 * Method:    sum
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_hello_sum
  (JNIEnv *env, jclass class, jint i, jint j)
{
        return i+j;
}

