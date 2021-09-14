/*
	2017/4/28
*/
class Example_08
{
	public static int sum(int m[])
	{
		int i,ss=0;
		for(i=0;i<100;i++)ss+=m[i];
		return ss;
	}
	public static void main(String args[])
	{
		int n[],m[]={3,4},num[],i,j,s;
		n=new int[2];
		num=new int[100];

		n[0]=9;
		System.out.println("n:"+n[0]+n[1]+"m:"+m[0]+m[1]);

		for(i=0;i<100;i++)num[i]=i+1;
		s=sum(num);
		System.out.println("sum = "+s);

		int nn[][];
		nn=new int[2][2];
		for(i=0;i<2;i++){
		  for(j=0;j<2;j++){
			nn[i][j]=i+j;
			System.out.print("   nn["+i+"]["+j+"] = "+nn[i][j]);
		  }
		  System.out.println();
		}

		int mm[][]=new int[2][];
		mm[0]=new int[2];
		mm[1]=new int[2];
		for(i=0;i<2;i++){
		  for(j=0;j<2;j++){
			mm[i][j]=i+j;
			System.out.print("   mm["+i+"]["+j+"] = "+mm[i][j]);
		  }
		  System.out.println();
		}
		
		double xx[][]={
                               {0*0,1*0,2*0,3*0},
                               {0*1,1*1,2*1,3*1},
                               {0*2,1*2,2*2,3*2},
                               {0*3,1*3,2*3,3*3}};
		for(i=0;i<4;i++){
		  for(j=0;j<4;j++){
			System.out.print("   xx["+i+"]["+j+"] = "+xx[i][j]);
		  }
		  System.out.println();
		}

		int a1[]= new int[2];
		int[] a2=new int[2];

		char t1[][]=new char[2][2];
		char[][] t2=new char[2][2];

		String str="Hello World!";
		System.out.println(str);
	}








}
