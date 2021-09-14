/*
2017/5/24
*/
import java.io.*;

class Example_51{
	public static void main(String[]args)throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	/*	String str;

		do{
			str = br.readLine();
			System.out.println(str);
		}while(!str.equals("stop"));   */

		String str[]=new String[5];

		for ( int i = 0 ; i < 5 ; i ++ ){
			str[i]=br.readLine();
			if(str[i].equals("stop"))break;
		}
		for ( int i = 0 ; i < 5 ; i ++ ) {
			if(str[i].equals("stop"))break;
			System.out.println(str[i]);
		}
	}
}
