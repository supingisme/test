/**
 * 二进制读写文件
 */
import java.io.*;

class write{

    public void writeMethod0() {
        FileOutputStream out;
        DataOutputStream dos;
        try {
            out = new FileOutputStream("kuka0.dat");
            dos = new DataOutputStream(out);
            dos.writeFloat(3f);
            dos.writeFloat(4f);
            dos.writeFloat(5f);
            dos.close();
        } catch (Exception e) {
            System.out.println(e.toString());
        }
    }


      public void writeMethod1()
	{
		String fileName="kuka1.dat";
		float value0=255;
		float value1=0;
		float value2=-1;
		try
		{
			DataOutputStream out=new DataOutputStream(new FileOutputStream(fileName));
			out.writeFloat(value0);
			out.writeFloat(value1);
			out.writeFloat(value2);
			out.close();
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}
	public void writeMethod2()
	{
		String fileName="kuka2.dat";
		try
		{
			DataOutputStream out=new DataOutputStream(
								 new BufferedOutputStream(
								 new FileOutputStream(fileName)));
			out.writeFloat(1.0f);
			out.writeFloat(2.2f);
			out.writeFloat(3.2f);
			out.writeFloat(4.2f);
			out.writeFloat(5.2f);
			out.writeFloat(6.2f);

			out.close();
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}
}

class read{

      public void readMethod1()
	{
		String fileName="kuka1.dat";
		int sum=0;
		try
		{
			DataInputStream in=new DataInputStream(
							   new BufferedInputStream(
							   new FileInputStream(fileName)));
			sum+=in.readInt();
			sum+=in.readInt();
			sum+=in.readInt();
			System.out.println("The sum is:"+sum);
			in.close();
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public void readMethod2()
	{
		try
		{
			FileInputStream stream=new FileInputStream("kuka.dat");
			int c;
			while((c=stream.read())!=-1)
			{
				System.out.println(c);
			}
		} catch (Exception e)
		{
			e.printStackTrace();
		}
	}
}

class Demo_08
{
        public static void main(String[]args){

                write w =new write();
                w.writeMethod0();
                w.writeMethod1();
                w.writeMethod2();

        }	
}
