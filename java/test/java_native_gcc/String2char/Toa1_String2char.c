#include "Toa1_String2char.h"
#include <stdlib.h>

JNIEXPORT void JNICALL Java_Toa1_1String2char_function
  (JNIEnv *env, jclass class, jobjectArray str){

        jstring jstr;
        jsize len = (*env)->GetArrayLength(env,str);
        char **pstr = (char **)malloc(sizeof(char*)*len);
        
        int i = 0;
        for(i=0;i<len;i++){

                jstr = (*env)->GetObjectArrayElement(env,str,i);
                pstr[i] = (char*)(*env)->GetStringUTFChars(env,jstr,0);
                printf("str = %s\n",pstr[i]);
          }
        
        //HVite(len,pstr);
}

