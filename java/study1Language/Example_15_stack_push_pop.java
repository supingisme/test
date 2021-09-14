/*
2017/5/3
*/
class stack{
	int stck[]=new int[10];
	int tos;

	/*Initialize top-of-stack*/
	stack(){
		tos=-1;
	}
	/*Push an item onto the stack*/
	void push(int item){
		if(tos==9)
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
class Example_15{
	public static void main(String args[])throws java.io.IOException{
		int i;
		stack s1=new stack();

		for(i=-1;i<11;i++)
			s1.push(i);
		for(i=-1;i<11;i++)
			System.out.println("s1:"+s1.pop());		

	}
}
