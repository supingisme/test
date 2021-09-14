/*
2017/6/30 Rong Tao
*/

//BitSet Demonstration
import java.util.BitSet;

class Demo_02{
        
        public static void main(String[]args){
                BitSet bits1 = new BitSet(16);
                BitSet bits2 = new BitSet(16);
                
                //set some bits
                for(int i = 0 ; i<16;i++){
                        if((i%2)==0)bits1.set(i);
                        if((i%5)==0)bits2.set(i);
                    }
                System.out.println("Initial pattern in bits1: ");
                System.out.println(bits1);
                System.out.println("\nInitial pattern in bits2: ");
                System.out.println(bits2);

                //AND bits
                bits2.and(bits1);
                System.out.println("\n1 AND 2 : "+bits2);
                //OR bits
                bits2.or(bits1);
                System.out.println("\n1 OR 2 : "+bits2);
                //XOR bits
                bits2.xor(bits1);
                System.out.println("\n1 XOR 2 : "+bits2);
        }
}
