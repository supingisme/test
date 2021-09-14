/*
2017/5/25

搜索字符或子字符串首次出现。
int indexOf(int ch)
int indexOf(String str)
int indexOf(int ch, int startIndex)
int indexOf(String str, int startIndex)

搜索字符或子字符串的最后一次出现
int lastIndexOf(int ch)
int lastIndexOf(String str)
int lastIndexOf(int ch, int startIndex)
int lastIndexOf(String str, int startIndex)

截取子字符串
String substring(int startIndex)
String substring(int startIndex, int endIndex)

连接两个字符串
String concat(String str)

另一个字符代替调用字符串中一个字符的所有具体值
String replace(char original, char replacement)

trim( )方法返回一个调用字符串的拷贝，该字符串是将位于调用字符串前面和后面的空
白符删除后的剩余部分
String trim( )

*/
class Demo_01{
	public static void main(String[]args){

		/* indexOf(), lastIndexOf() */
	/*	String str = "abcdeacdfgc";
		System.out.println(str.indexOf("cd"));
		System.out.println(str.lastIndexOf('c'));  */

		/* trim() */
		String str = "    woshi ni da ye    ";
		System.out.println(str+"\n"+str.trim());
	}
}
