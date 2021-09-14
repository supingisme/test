/*
  2017/4/28
*/
class Example_07
{
  public static double fun(double a,double b)
  {
	double c=Math.sqrt(a*a+b*b);
	return c;
  }

  public static void main(String args[])
   {
	double a=3.0,b=4.0;
	double c=fun(a,b);

	int x;
	x=1;

	if(x==1)
	{
		int y=200;
	}
	//y++;
	System.out.println("c = "+c);
   }
}
