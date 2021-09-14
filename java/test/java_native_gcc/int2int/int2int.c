
#include "int2int.h"

JNIEXPORT jint JNICALL Java_int2int_function
  (JNIEnv *env, jclass cla, jintArray in){

        jsize len = (*env)->GetArrayLength(env,in);

        jint *tmp = (*env)->GetIntArrayElements(env,in,0);

        int i =0 ;
        int sum =0;
        for(i=0;i<len;i++){
        
                sum += *(tmp+i);
        }
        return sum;
}
