/*
2017/7/10


the tti model

  Copyright 2017  China University of Petroleum (East China)( Rong Tao )
    Email: 2386499836@qq.com
*/
package kernels;

import java.io.*;

public class ttiModel extends vtiModel{

        public float[] theta;

        public ttiModel(){
                super();
        }public ttiModel(int dim, float interval){
                super(dim,interval);
        }public ttiModel(int nx,int nz,float dx,float dz){
                super(nx,nz,dx,dz);
        }//ending of struct function

        public void InitModel(float v, float e, float d, float t){

                super.InitModel(v,e,d);
                theta = new float[nx*nz];
                for(int i = 0; i < nx*nz; i++) {
                        theta[i] = t;
                    }
        }//initial the ttiModel

        public void ShowModel(){

                super.ShowModel();
                for(int i=0;i<nx*nz;i++){
                        if((i%nz)==0)System.out.println();
                        System.out.print(theta[i]+ "   ");
                        if(i==nx*nz-1)System.out.println();
                    }
        }//show the ttiModel value

        public void WriteModel(String FileNameOfVelocity, String FileNameOfEpsilon,
                                 String FileNameOfDelta, String FileNameOfTheta){

                super.WriteModel(FileNameOfVelocity, FileNameOfEpsilon, FileNameOfDelta);

                DataOutputStream fpTheta = null;
                try{  
                        if(!new File(FileNameOfTheta).exists()){  
                                new File(FileNameOfTheta).createNewFile();  
                              }       
                        fpTheta = new DataOutputStream(new FileOutputStream(new File(FileNameOfTheta)));  
                }catch(Exception e){  
                        e.printStackTrace();  
                    }
                try{  
                        for(int i=0;i<nx*nz;i++)fpTheta.writeFloat(theta[i]); 
  
                        fpTheta.flush();   fpTheta.close(); 
  
                }catch(Exception e){  
                        e.printStackTrace();  
                    }
        }//write ttiModel
        public void ReadModel(String FileNameOfVelocity, String FileNameOfEpsilon,
                                 String FileNameOfDelta, String FileNameOfTheta){

                super.ReadModel(FileNameOfVelocity, FileNameOfEpsilon, FileNameOfDelta);

                DataInputStream fpTheta = null;
                try{    
                        if(!new File(FileNameOfTheta).exists()){  
                                System.out.println("The "+FileNameOfTheta+" file dont't exists");
                                return;  
                              }  
                        fpTheta = new DataInputStream(new FileInputStream(new File(FileNameOfTheta)));
                        int i = 0;
                        while(fpTheta.available()>0&&i<nx*nz){   
                                theta[i++] = fpTheta.readFloat(); 
 
                              } 
                }catch(Exception e){  
                        e.printStackTrace();  
                    }
        }//read ttiModel

}
