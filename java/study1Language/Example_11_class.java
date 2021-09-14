/*
2017.5.3
*/
class Box{
	double width;
	double height;
	double depth;
	void volume(){
		System.out.print("Volume = ");
		System.out.println(width*height*depth);
		//return width*height*depth;
	}
	void setDim(double w,double h,double d)
	throws java.io.IOException{
		width=(int)System.in.read()-48;
		height=h;
		depth=d;
		System.out.print("width="+width+",height="+height+",depth="+depth);
		System.out.println();
	}
	
}
class Example_11{
	public static void main(String args[])
	throws java.io.IOException{

		Box mybox1=new Box();
		mybox1.width=12;
		mybox1.height=21;
		mybox1.depth=35;
		mybox1.volume();
		mybox1.setDim(1,2,3);
		mybox1.volume();
	}
}
