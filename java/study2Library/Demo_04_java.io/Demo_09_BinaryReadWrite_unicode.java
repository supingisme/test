/*
2017/7/5
use follow command to turn 'unicode' to 'ascii'
iconv -f ucs-2be -t utf-16 unicode2.dat > ascii.dat
iconv -f ucs-2be -t utf-16 unicode2.dat > ascii.dat
iconv -f ucs-2be -t utf-16 unicode2.dat > ascii.dat
iconv -f ucs-2be -t utf-16 unicode2.dat > ascii.dat
iconv -f ucs-2be -t utf-16 unicode2.dat > ascii.dat
*/


import java.io.*;

/* model */
class model{

        int nx;
        int nz;

        float[] val;

        model(){
                nx=nz=100;
        }model(int dim){
                nx=nz=dim;
        }model(int nx,int nz){
                this.nx=nx;
                this.nz=nz;
        }//struct function ending

        void Init_model(float v){
                val = new float[nx*nz];
                for(int i = 0; i < nx*nz; i++) val[i] = v;
        }//initial the model
        void Set_model(){

                for(int i =0 ;i <nx*nz; i++){
                     int ix = i/nz;
                     int iz = i%nz;

                     if(iz>nz/2-1){
                          val[i] = 2000.0f;
                     }else{
                          val[i] = 1000.0f;
                     }//val
                }//i

        }//set the model value
        void Show_model(){
                for(int i=0;i<nx*nz;i++){
                        if((i%nz)==0)System.out.println();
                        System.out.print(val[i]+ "  ");
                        if(i==nx*nz-1)System.out.println();
                    }
        }//show the model value

        void Write_model(String FileName){

                DataOutputStream fp = null;
                try{  
                        if(!new File(FileName).exists()){  
                                new File(FileName).createNewFile();  
                              }    
                        fp = new DataOutputStream(new FileOutputStream(new File(FileName)));  
                }catch(Exception e){  
                        e.printStackTrace();  
                    }
                try{  
                        for(int i=0;i<nx*nz;i++)fp.writeFloat(val[i]);   
                        fp.flush();  
                        fp.close();   
                }catch(Exception e){  
                        e.printStackTrace();  
                    }
        }//write model
        void Write_model(String FileName, float[] vv){

                DataOutputStream fp = null;
                try{  
                        if(!new File(FileName).exists()){  
                                new File(FileName).createNewFile();  
                              }    
                        fp = new DataOutputStream(new FileOutputStream(new File(FileName)));  
                }catch(Exception e){  
                        e.printStackTrace();  
                    }
                try{  
                        for(int i=0;i<val.length;i++)fp.writeFloat(vv[i]);   
                        fp.flush();  
                        fp.close();   
                }catch(Exception e){  
                        e.printStackTrace();  
                    }
        }//write model
        void Read_model(String FileName){

                DataInputStream fp = null;
                try{    
                        if(!new File(FileName).exists()){  
                                System.out.println("The "+FileName+" file dont't exists");
                                return;  
                              } 
                        fp = new DataInputStream(new FileInputStream(new File(FileName))); 
                        int i = 0;
                        while(fp.available()>0&&i<nx*nz){   
                                val[i++] = fp.readFloat();  
                              } 
                }catch(Exception e){  
                        e.printStackTrace();  
                    }
        }//write model
}

class Demo_09{

        public static void main(String[]args){

                int nx = 6;
                int nz = 6;

                model v0 = new model(nx,nz);
                v0.Init_model(1000.0f);
                v0.Set_model();
                v0.Show_model();
                v0.Write_model("unicode1.dat");

                v0.Read_model("unicode3.dat");
                v0.Show_model();


        }
}
