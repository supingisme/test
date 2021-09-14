/*
2017/7/11

javac writeFloat.java

javah -jni model

gcc -shared -fpic -o libmodel.so -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux model.c

java -Djava.library.path=. Main

  Copyright 2017  China University of Petroleum (East China)( Rong Tao )
    Email: 2386499836@qq.com

*/

//package library;

public class swap{

        /*void swap_float_4(float *tnf4) {
                int *tni4=(int *)tnf4;
                *tni4=(((*tni4>>24)&0xff) | ((*tni4&0xff)<<24) |
                        ((*tni4>>8)&0xff00) | ((*tni4&0xff00)<<8));
        }*///end
        public static native void swap_float(String in, String out);

}



