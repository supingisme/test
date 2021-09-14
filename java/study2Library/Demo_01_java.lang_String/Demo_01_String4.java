/*
2017/5/31
*/
// Demonstrate toUpperCase() and toLowerCase().
class Demo_01 {
	public static void main(String args[])
	{
	/*	String s = "This is a test.";
		System.out.println("Original: " + s);
		String upper = s.toUpperCase();
		String lower = s.toLowerCase();
		System.out.println("Uppercase: " + upper);
		System.out.println("Lowercase: " + lower);	*/

	/*	StringBuffer sb = new StringBuffer("Hello");
		System.out.println("buffer = " + sb);
		System.out.println("length = " + sb.length());  //当前StringBuffer的长度
		System.out.println("capacity = " + sb.capacity());// 总的分配容量	*/

	/*	StringBuffer sb = new StringBuffer("Hello");
		System.out.println("buffer before = " + sb);
		System.out.println("charAt(1) before = " + sb.charAt(1));//得到单个字符的值
		sb.setCharAt(1, 'i');//给StringBuffer中的字符置值
		sb.setLength(2);//在StringBuffer对象内设置缓冲区的大小
		System.out.println("buffer after = " + sb);
		System.out.println("charAt(1) after = " + sb.charAt(1));	*/

	/*	String s;
		int a = 42;
		StringBuffer sb = new StringBuffer(40);
		//append( )方法将任一其他类型数据的字符串形式连接到调用StringBuffer对象的后面。
		s = sb.append("a = ").append(a).append("!").toString();
		System.out.println(s);		*/

	/*	StringBuffer sb = new StringBuffer("I Java!");
		sb.insert(2, "like ");//将一个字符串插入另一个字符串中
		System.out.println(sb);	*/

	/*	StringBuffer s = new StringBuffer("abcdef");
		System.out.println(s);
		s.reverse();//将StringBuffer对象内的字符串翻转
		System.out.println(s);	*/

	/*	StringBuffer sb = new StringBuffer("This is a test.");
		sb.delete(4, 7);//删除字符串   startIndex到endIndex-1
		System.out.println("After delete: " + sb);
		sb.deleteCharAt(0);//删除字符
		System.out.println("After deleteCharAt: " + sb);	*/

	/*	StringBuffer sb = new StringBuffer("This is a test.");
		System.out.println("Before replace: " + sb);
		//在StringBuffer中增加的另一个方法是replace( )
		//它完成在StringBuffer内部用一组字符代替另一组字符的功能。
		sb.replace(5, 7, "was woshi ");
		System.out.println("After replace: " + sb);	*/

		StringBuffer str1 = new StringBuffer("abcdefghijklmn");
		String str2 ;
		str2 = str1.substring(0,3);
		System.out.println("str1 = "+str1);
		System.out.println("str2 = "+str2);

	}
}





