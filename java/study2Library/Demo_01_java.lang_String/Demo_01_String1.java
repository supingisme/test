/*
2017/5/25

String str = new String();
String str = new String(char[]);
String str = new String(String str);
String str = new String(String str, int where, int length);
String str = new String(byte ascii[], int where, int length);
String str = "rong" + "tao";

int length();

String toString();

char charAt(int where);

void getChars(int sourceStart, int sourceStart, char target[], int targetStart);
			(sourceStart) ---- (sourceStart-1)

byte[] getBytes();

char[] toCharArray();

*/
class Box{
	float a;
	float b;
	Box(float a,float b){
		this.a=a;
		this.b=b;
	}
	public String toString(){
		return "a = "+a+", b = "+b;
	}
}
class Demo_01{
	public static void main(String[]args){
		//char ch[] = new char[3];
		// ch = {'a','b','c'};  // error
		//ch[0] = 'a';
		//ch[1] = 'b';
		//ch[2] = 'c';

		//byte ascii[]={65,66,67,68,69,70};

		//String str = new String(ch);
		//String str = new String(ch,1,2);
		//String str = new String(ascii,2,3);
		//String str = "This is a test code ."+
		//		"I don't know what are you talking about."+
		//		"Do you think so.";
		//int a = 65;
		//String str = "rong tao "+(a+1);

		//System.out.println("str = "+str+" , len = "+str.length()+", "+str.equals(str));// int length();

		//Box b = new Box(1.2f,1.3f);
		//System.out.println(b.toString().charAt(0));

		String str = "abc";
		//char buf[] = new char[4];
		//str.getChars(0,4,buf,0);
		//System.out.println(buf);
		//System.out.println(str.getBytes());
		char ch[] = str.toCharArray();
		System.out.println(ch);

	}
}
