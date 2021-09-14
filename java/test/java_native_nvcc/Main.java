

class NativeMethod{

        public native void writefloat(int nx,int nz);
}

public class Main{

        public static void main(String[] args){

                System.loadLibrary("NativeMethod");

                NativeMethod nm = new NativeMethod();
                nm.writefloat(100,100);
          }

}
