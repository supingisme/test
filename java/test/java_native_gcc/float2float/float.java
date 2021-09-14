
class f{

        public static native float function(float[]in);

        public static void main(String[]args){

                float [] i = {1f,2f,3f,4f};

                System.loadLibrary("float2float");

                System.out.println(function(i));
        }
}
