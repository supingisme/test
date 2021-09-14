/*
2017/5/24
*/
import java.io.*;

class Example_54{
	public static void main(String[]args)throws Exception{
		int i;

		FileInputStream fin;
		FileOutputStream fout;

		try{
			try{
				fin = new FileInputStream(args[0]);
				fout= new FileOutputStream(args[1]);
			}catch(Exception e){
				System.out.println(e);
				return;
			}
		}catch(ArrayIndexOutOfBoundsException e){
			System.out.println(e);
			return;
		}
		do{
			i = fin.read();
			if(i != -1)fout.write(i);
			if(i != -1)System.out.print((char)i);
		}while(i != -1);
		//System.out.println("\n");
		fin.close();
		fout.close();
	}
}
