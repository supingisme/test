/*
2017/5/3
finalize();
*/
import java.awt.Image;
import java.io.File;

class Box{
	double width,height,depth;
	Box(double width,double height,double depth){
		this.width=width;
		this.height=height;
		this.depth=depth;
	}
	void volume(){
		System.out.println("Volume = "+width*height*depth);
	}
	void setDim(double w,double h,double d){
		height=h;
		width=w;
		depth=d;
	}
	protected void finalize(){
		System.out.println("Finalization of code!");//finalization code here
	}
}
class Example_14{
	public static void main(String args[])throws java.io.IOException{
		Box box=new Box(1,2,3);
		box.finalize();
		box.volume();
		box.finalize();
	}
}
