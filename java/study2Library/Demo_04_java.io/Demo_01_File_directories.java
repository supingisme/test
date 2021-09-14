/*
2017/6/30
*/

import java.io.File;

class Demo_01{

        public static void main(String[]args){

                String dirname = "/home/Toa/java";
                File f1 = new File(dirname);

                if(f1.isDirectory()){
                        System.out.println("Directory of : " + dirname);
                        String s[] = f1.list();

                        for(int i=0;i<s.length;i++){

                                File f = new File(dirname+"/"+s[i]);
                                if(f.isDirectory()) System.out.println(s[i]+" is directory.");
                                else System.out.println(s[i]+ " is a file.");
                                }
                }else{
                        System.out.println(dirname+" is not a directory.");
                }
        }
}
