/*
2017/5/3
*/
class Box{
	double width;
	double height;
	double depth;
	
	/*Box(){
		width=10;
		height=10;
		depth=10;
	}*/
	Box(double width,double height,double depth){
		this.width=width;
		this.height=height;
		this.depth=depth;
	}

	void volume(){
		System.out.println("volume ="+width*height*depth);
	}
	void setDim(double w,double h,double d){
		width=w;
		height=h;
		depth=d;
	}
}
class Example_13{
	public static void main(String args[])throws java.io.IOException{

		Box box=new Box(3,4,5);
		box.volume();
		box.setDim(1,2,3);
		box.volume();

	}
}
