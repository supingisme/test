/*
2017/6/30
*/

import java.io.File;

class Demo_01{
       
        static void print(String in){
                System.out.println(in);
        }
        public static void main(String[]args){

                File f1 = new File("/home/Toa/java/Java2.Library/Demo_14_java.io/rong.txt");
                
                print("File name : "+f1.getName());
                print("AbsPath: "+f1.getAbsolutePath());
                print("Path: "+f1.getPath());
                print("Parent: "+f1.getParent());

                print(f1.exists() ? "exists" : "does not exist");
                print(f1.canWrite() ? "is writeable" : "is not writeable");
                print(f1.canRead() ? "is readable" : "is not readable");
                print("is " + (f1.isDirectory() ? "" : "not" + " a directory"));
                print(f1.isFile() ? "is normal file" : "might be a named pipe");
                print(f1.isAbsolute() ? "is absolute" : "is not absolute");
                print("File last modified: " + f1.lastModified());
                print("File size: " + f1.length() + " Bytes");
                
        }
}
