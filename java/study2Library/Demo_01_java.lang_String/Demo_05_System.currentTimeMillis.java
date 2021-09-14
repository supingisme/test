/*
2017/5/31
*/
class Demo_05{
	public static void main(String[]args){
		long start,end;
		int sum=0;
		start = System.currentTimeMillis();
		for(int i =0 ; i<78676896;i++) 
			if(i%10000==0)System.out.println("i = "+i);
		end = System.currentTimeMillis();
		System.out.println("Time : "+(end - start));
	}
}
