/*
2017/5/4
*/
class Example_22{
	public static void main(String args[])throws java.io.IOException{
		String str="rongtao"+" ni hao ";
		str+=str;
		//str[2]="z";//error
		//System.out.println(str.length);//error
		System.out.println(str.length());//right
		System.out.println(str.equals(str));//right

		String str1[]=new String[2];
		String str2[]={"rong","tao"};
		str1[0]="rong";
		System.out.println(str1[0]+str2[1]);

		for(int i=0;i<args.length;i++)
			System.out.println("args.length= "+args.length+"  "+args[i]);
	}
}
