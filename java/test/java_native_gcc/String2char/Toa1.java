
class Toa1_String2char{

        public static native void function(String[] name);

        public static void main(String[]args){

                System.loadLibrary("Toa1");

                String[] name = {"rong","tao","shinidaye","..","nihaoma","\n\n\n","rontrao"};

                function(name);
        }
}
