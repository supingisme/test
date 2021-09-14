/*
  hear is another short example 
  call this file "example2.java"
*/
class Example_06
{
  public static void main(String args[])
   {
      int vel;
	long days;
	long sec;
	long dis;

	short s=1;;
	double d;

	char c=89;//Y

	boolean flag;



	flag=true;

	d=1.111111;
	

	vel=186000;
	days=365;
	sec=days*24*60*60;
	dis=sec*vel;

	System.out.println("\nIn " + days +" light run " + dis + ".miles");
	
	System.out.println("\nshort = "+s+",double = "+d+",char = "+(++c));

	if(flag)System.out.print("The flag is true\n");
/* zi mian liang */
	System.out.println("\n#### ziminalaing ###");
	long octal,hexadecimal;

	double f1;

	String str;

	str="Hello World!";

	f1=6.022E23;

	octal=017;
	hexadecimal=0xffL;

	System.out.println("octal = "+octal+",hexadecimal = "+hexadecimal);

	System.out.println("str = "+str);

	byte by;

	by=2;

	System.out.println("by = "+by);
   }
}









