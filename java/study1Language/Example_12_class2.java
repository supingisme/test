/*
2017/5/3
Get cos of 3 angle in a trangle
*/
class ang{
	double a,b,c;
	void setDim(double x,double y,double z){
		a=x;
		b=y;
		c=z;
		if((a+b<c)||(b+c<a)||(a+c<b))
			System.out.println("ERROR: a+b<c...");	
	}
	void getAngle(){
		double cosa[]=new double[3];
		cosa[0]=(a*a+b*b-c*c)/(2*a*b);
		cosa[1]=(a*a+c*c-b*b)/(2*a*c);
		cosa[2]=(b*b+c*c-a*a)/(2*b*c);
		System.out.println("The cos of angle between a&b = "+cosa[0]);
		System.out.println("The cos of angle between a&c = "+cosa[1]);
		System.out.println("The cos of angle between c&b = "+cosa[2]);
	}
}
class Example_12{
	/***********main***********/
	public static void main(String args[])throws java.io.IOException{

		ang a=new ang();	
		a.setDim(3,4,7);
		a.getAngle();	
		
	}
}
