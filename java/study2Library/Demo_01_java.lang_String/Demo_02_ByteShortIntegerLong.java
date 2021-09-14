import java.io.*;
class Demo_02 {
	public static void main(String args[])
	throws IOException
	{
	/*	// create a BufferedReader using System.in
		BufferedReader br = new
		BufferedReader(new InputStreamReader(System.in));
		String str;
		int i;
		int sum=0;
		System.out.println("Enter numbers, 0 to quit.");
		do {
			str = br.readLine();
			try{
				i = Integer.parseInt(str);
				System.out.println("i = "+i+", str = "+str);
			}catch(NumberFormatException e){
				System.out.println("Invalid format. "+e);
				i = 0;
			}
			sum += 1;
			System.out.println("Current sum is : "+sum);
		}while(i != 0);	*/

	/*	int num = 31;
		System.out.println(num + " in binary: " +
						Integer.toBinaryString(num));
		System.out.println(num + " in octal: " +
						Integer.toOctalString(num));
		System.out.println(num + " in hexadecimal: " +
						Integer.toHexString(num));	*/

		char a[] = {'a', 'b', '5', '?', 'A', ' '};
		for(int i=0; i<a.length; i++) {
			if(Character.isDigit(a[i]))
				System.out.println("i = "+i+a[i] + " is a digit.");
			if(Character.isLetter(a[i]))
				System.out.println("i = "+i+a[i] + " is a letter.");
			if(Character.isWhitespace(a[i]))
				System.out.println("i = "+i+a[i] + " is whitespace.");
			if(Character.isUpperCase(a[i]))
				System.out.println("i = "+i+a[i] + " is uppercase.");
			if(Character.isLowerCase(a[i]))
				System.out.println("i = "+i+a[i] + " is lowercase.");
		}
	}
}
