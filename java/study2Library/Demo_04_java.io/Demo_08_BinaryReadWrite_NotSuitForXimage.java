
import java.io.*;

class Demo_08_BinaryReadWrite {  
    private DataInputStream dis=null;  
    private DataOutputStream dos=null;  
    private String s_FilePath="unicode5.5.dat";   
      
    public Demo_08_BinaryReadWrite() {  
        // TODO Auto-generated constructor stub  
        init();  
    }  
    private void init(){  
        try{  
            if(!new File(s_FilePath).exists()){  
                new File(s_FilePath).createNewFile();  
               }  
            dis=new DataInputStream(new FileInputStream(new File(s_FilePath)));  
            dos=new DataOutputStream(new FileOutputStream(new File(s_FilePath)));  
        }catch(Exception e){  
            e.printStackTrace();  
        }  
    }  
    public void writeBinaryStream(){  
        try{  
            if(dos!=null){  
                for(int i=0;i<100;i++)for(int j=0;j<100;j++){  
  
                    Float f;  
                    if(i>25&&i<75&&j>25&&j<75)f=5.5f;
                    else f=15.1115f;
                    dos.writeFloat(f);  
  
                    }  
                dos.flush();  
                dos.close();  
            }  
        }catch(Exception e){  
            e.printStackTrace();  
        }  
    }  
    public void readBinaryStream(){  
        try{  
            if(dis!=null){  
                while(dis.available()>0){  
                    System.out.println(dis.available());   
                    System.out.println(dis.readFloat());   
                }  
            }  
        }catch(Exception e){  
            e.printStackTrace();  
        }  
    }  
    public static void main(String[] args) throws IOException {  
        Demo_08_BinaryReadWrite bin=new Demo_08_BinaryReadWrite();  
        bin.writeBinaryStream();  
        bin.readBinaryStream();  
    }  
} 
