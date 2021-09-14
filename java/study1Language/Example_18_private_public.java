/*
2017/5/4
*/
class stack{
	private int stck[]=new int[10];
	private int tos;

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
class Example_18{
	public static void main(String args[])throws java.io.IOException{
		int i;
		stack s1=new stack();

		i=0;
		do{
			s1.push(i);
			i++;
		}while(i<10);

		i=0;
		do{
			System.out.println("s1:"+s1.pop());
			i++;
		}while(i<10);		

	}
}
