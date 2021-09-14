/*
2017/5/4
*/
class stack{
	private int stck[];
	private int tos;

	/*Initialize top-of-stack*/
	stack(int size){
		stck=new int[size];
		tos=-1;
	}
	/*Push an item onto the stack*/
	void push(int item){
		if(tos==stck.length-1)
			System.out.println("Stack is full.");
		else
			stck[++tos]=item;
	}
	/*Pop an item from the stack*/
	int pop(){
		if(tos<0){
			System.out.println("Stack underflow.");
			return 0;
		}else
			return stck[tos--];
	}
}
class Example_20{
	public static void main(String args[])throws java.io.IOException{
		int i;
		stack s1=new stack(20);

		i=0;
		do{
			s1.push(i);
			i++;
		}while(i<20);

		i=0;
		do{
			System.out.println("s1:"+s1.pop());
			i++;
		}while(i<20);

	
		int a[][]=new int[4][3];
		System.out.println("lenght of a is "+a.length);



		

	}
}
