/*
2017/5/11
*/
import java.util.Random;

class Example_33{
	public static void main(String args[]){

		/*int a,b;
		try{
			a=0;
			b=1/a;
			System.out.println("Not print.");
		}catch(ArithmeticException e){
			System.out.println("e = "+e);
		}
		System.out.println("After catch statement.");

		Random r=new Random();
		for(int i=0;i<100;i++)
		{
			a=r.nextInt();
			try{
				b=12345/a;
			}catch(ArithmeticException e){
				//System.out.println("ERROR: "+e);
			}
			System.out.println("a = "+a);
		}*/

		/*int len=args.length;
		int[] c=new int[len];
		
		try{
			System.out.println("args = "+args[0]);
			a=1;
			c[0]=1/a;
			c[len-1]=1/a;
		}catch(ArithmeticException e){
			System.out.println("ERROR: "+e);
		}catch(ArrayIndexOutOfBoundsException e){
			System.out.println("ERROR: "+e);
		}*/

		int len=args.length,b;
		try{
			len=args.length;
			b=1/(len-1);
			System.out.println("args.length = "+len);
			try{
				if(len==2)len=1/(len-2);
			}catch(ArithmeticException e){
				System.out.println("ERROR: inner catch: "+e);
			}
		}catch(ArithmeticException e){
			System.out.println("ERROR: outer catch: "+e);
		}





	}
}
