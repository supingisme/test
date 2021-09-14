/*
   2017/4/29
*/
class Example_09
{
	public static void main(String args[])
	{
		System.out.println("Hello World!");

		int a,b,c,d,e,f,g;
		int x,y,z,i,j;

		a=1;b=2;c=3;d=4;

		x=a+b-c*d;
		y=b%b*c-d;
		z=a+b*c/d;

		x+=x;
		y%=b;
		z*=d;

		x++;
		++x;
		y--;
		--y;
		z++;
		--z;

		System.out.print("x="+x+"\ny="+y+"\nz="+z+"\n");
		
		int n,m,mn;
		n=0;
		m=1;
		mn=~n;
		System.out.println("mn="+mn);

		x=42;
		y=15;
		z=x|y;
		System.out.println("z = "+z);

		String binary[]={"0000","0001","0010","0011","0100","0101","0110","0111",
				     "1000","1001","1010","1011","1100","1101","1110","1111"};
		a=3;
		b=6;
		c=a|b;
		d=a&b;
		e=a^b;
		f=(~a&b)|(a&~b);
		g=~a&0x0f;
		System.out.println("a ="+binary[a]);
		System.out.println("b ="+binary[b]);
		System.out.println("c ="+binary[c]);
		System.out.println("d ="+binary[d]);
		System.out.println("e ="+binary[e]);
		System.out.println("f ="+binary[f]);
		System.out.println("g ="+binary[g]);


		b=a<<2;
		System.out.println("a = "+binary[a]+"  a<<2 ="+binary[b]);

		int num=0xFFFFFFE;
		for(i=0;i<4;i++){
			num=num<<1;
			System.out.println("num = "+num);
		}
		num=16;
		for(i=0;i<4;i++){
			num=num>>1;
			System.out.println("num = "+binary[num]);
		}
		num=-8;
		num=num>>1;
		System.out.println("num = "+num);

		boolean tr,fa,fl;
		tr=true;
		fa=false;
		fl=(a>num);
		if(fl)		
			System.out.println("fl = "+fl);

		num=a>b?a+b:a-b;
		System.out.println("a= "+a+"  b= "+b+" num = "+num);
	}
}
















