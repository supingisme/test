/*
2017.5.3
*/
class Example_10{
	public static void main(String args[])
	throws java.io.IOException{
	
		int x,y,z,i=0;
		x=1;
		y=2;
		z=4;
		if(x>y)System.out.println("x>y");
		else if(x==y)System.out.println("x==y");
		else System.out.println("x<y");

		z=(int)System.in.read()-48;
		System.out.println("z="+z);
		switch(z){
			case 1:System.out.println("z=1");break;
			case 2:System.out.println("z=2");break;
			case 3:System.out.println("z=3");break;
			case 4:System.out.println("z=4");break;
			case 5:System.out.println("z=5");break;
			default:System.out.println("z is greater than 5");
		}
		do{
			switch(i){
				case 0:
				case 1:
				case 2:
				case 3:
					System.out.println("i <= 3");break;
				case 4:
				case 5:
				case 6:
					System.out.println("i > 3 && i <= 6");break;
				default:
					System.out.println("i > 6");
			}
			i++;
		}while(i<10);
		while(--i>0){
			System.out.println("i = "+i);
		}

		rong:{
			tao:{
				break rong;
			}
		}
		
	}
}















