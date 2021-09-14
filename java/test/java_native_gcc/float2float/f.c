#include "f.h"

JNIEXPORT jfloat JNICALL Java_f_function
  (JNIEnv *env, jclass cla, jfloatArray in){

        int len = (*env)->GetArrayLength(env,in);
        
        jfloat* tmp = (*env)->GetFloatArrayElements(env,in,0);

        int i;
        float sum = 0.0;

        for(i=0;i<len;i++){
        
                sum += *(tmp+i);
        }

        return sum;
}
