/*
2017/5/6
*/
class area{
	double x,y;
	area(){
		x=y=10.0;
	}
	area(double len){
		x=y=len;
	}
	area(double x,double y){
		this.x=x;
		this.y=y;
	}
	void square(String str){
		System.out.println(str+"square = "+(x*y));
	}
	
}
class cube extends area{
	double z;
	cube(){
		x=y=z=10;
	}
	cube(double len){
		x=y=z=len;
	}
	cube(double x,double y,double z){
		this.x=x;
		this.y=y;
		this.z=z;
	}
	void volume(String str){
		System.out.println(str+"volume = "+(x*y*z));
	}
}
class Example_24{
	public static void main(String args[])throws java.io.IOException{

		area a=new area(1);
		a.square("a's ");

		cube b=new cube(2);
		b.square("b's ");
		b.volume("b's ");

		a=b;
		a.square("a's ");




	}
}
