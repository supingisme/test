/*
2017/5/25

boolean equals(Object str);
boolean equalsIgnoreCase(object str);

boolean regionMatches(int startIndex, String str2, int str2StartIndex, int numChars)
boolean regionMatches(boolean ignoreCase, int startIndex, String str2, int str2StartIndex, int numChars)

boolean startsWith(String str)
boolean endsWith(String str)

"equals()" compare with "=="

int compareTo(String str);
int compareToIgnoreCase(String str)
*/
class Demo_01{
	public static void main(String[]args){
		
		/* equals, equalsIgnoreCase */	
	/*	String s1 = "abc";
		String s2 = "a"+"b"+"C";
		String s3 = new String(s2);
		System.out.println(s1.equals(s2));
		System.out.println(s1.equalsIgnoreCase(s2));  */

		/* regionMatches */
	/*	String s1 = "abcdefghi";
		String s2 = "cdeCDE";
		System.out.println(s1.regionMatches(2,s2,0,3));
		System.out.println(s1.regionMatches(2,s2,3,3));
		System.out.println(s1.regionMatches(true,2,s2,3,3));
		System.out.println(s1.regionMatches(false,2,s2,3,3));  */

		/* startsWith, endsWith */
	/*	String str = "abc";
		System.out.println(str.startsWith("ab"));
		System.out.println(str.endsWith("bc"));  */

		/* equals, == */
	/*	String s1 = "rong";
		String s2 = new String(s1);
		System.out.println(s1.equals(s2));
		System.out.println(s1==s2); */

		/* compareTo() */
		String s1 = "abca";
		String s2 = "abcA";
		System.out.println(s1.compareTo(s2));
		System.out.println(s1.compareToIgnoreCase(s2));
	}
}
