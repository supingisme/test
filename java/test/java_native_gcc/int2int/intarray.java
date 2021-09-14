
class int2int{

        public static native int function(int[] i);

        public static void main(String[]args){
                
                System.loadLibrary("int2int");

                int[] in = {1,2,3,4,5};
                System.out.println(function(in));
          }
}       
