/*
2017/7/5


the vti model

  Copyright 2017  China University of Petroleum (East China)( Rong Tao )
    Email: 2386499836@qq.com
*/
package kernels;

import java.io.*;

/* vtiModel */
public class vtiModel{

        public int nx;
        public int nz;

        public float dx;
        public float dz;

        public float[] velocity, epsilon, delta;

        public vtiModel(){
                nx=nz=100;
                dx=dz=5.0f;
        }public vtiModel(int dim, float interval){
                nx=nz=dim;
                dx=dz=interval;
        }public vtiModel(int nx,int nz,float dx,float dz){
                this.nx=nx;
                this.nz=nz;
                this.dx=dx;
                this.dz=dz;
        }//struct function ending

        public void InitModel(float v, float e, float d){
                velocity = new float[nx*nz];
                 epsilon = new float[nx*nz];
                   delta = new float[nx*nz];
                for(int i = 0; i < nx*nz; i++) {
                        velocity[i] = v;
                         epsilon[i] = e;
                           delta[i] = d;
                    }
        }//initial the vtiModel
        public void ShowModel(){
                for(int i=0;i<nx*nz;i++){
                        if((i%nz)==0)System.out.println();
                        System.out.print(velocity[i]+ "   ");
                        if(i==nx*nz-1)System.out.println();
                    }
                for(int i=0;i<nx*nz;i++){
                        if((i%nz)==0)System.out.println();
                        System.out.print(epsilon[i]+ "   ");
                        if(i==nx*nz-1)System.out.println();
                    }
                for(int i=0;i<nx*nz;i++){
                        if((i%nz)==0)System.out.println();
                        System.out.print(delta[i]+ "   ");
                        if(i==nx*nz-1)System.out.println();
                    }
        }//show the vtiModel value

        public void WriteModel(String FileNameOfVelocity, String FileNameOfEpsilon, String FileNameOfDelta){

                DataOutputStream fpVelocity = null, fpEpsilon = null, fpDelta = null;
                try{  
                        if(!new File(FileNameOfVelocity).exists()){  
                                new File(FileNameOfVelocity).createNewFile();  
                              }    
                        if(!new File(FileNameOfEpsilon).exists()){  
                                new File(FileNameOfEpsilon).createNewFile();  
                              } 
                        if(!new File(FileNameOfDelta).exists()){  
                                new File(FileNameOfDelta).createNewFile();  
                              }    
                        fpVelocity = new DataOutputStream(new FileOutputStream(new File(FileNameOfVelocity))); 
                         fpEpsilon = new DataOutputStream(new FileOutputStream(new File(FileNameOfEpsilon))); 
                           fpDelta = new DataOutputStream(new FileOutputStream(new File(FileNameOfDelta)));  
                }catch(Exception e){  
                        e.printStackTrace();  
                    }
                try{  
                        for(int i=0;i<nx*nz;i++)fpVelocity.writeFloat(velocity[i]); 
                        for(int i=0;i<nx*nz;i++) fpEpsilon.writeFloat(epsilon[i]); 
                        for(int i=0;i<nx*nz;i++)   fpDelta.writeFloat(delta[i]);   
                        fpVelocity.flush();   fpVelocity.close(); 
                         fpEpsilon.flush();    fpEpsilon.close(); 
                           fpDelta.flush();      fpDelta.close();   
                }catch(Exception e){  
                        e.printStackTrace();  
                    }
        }//write vtiModel

        public void ReadModel(String FileNameOfVelocity, String FileNameOfEpsilon, String FileNameOfDelta){

                DataInputStream fpVelocity = null, fpEpsilon = null, fpDelta = null;
                try{    
                        if(!new File(FileNameOfVelocity).exists()){  
                                System.out.println("The "+FileNameOfVelocity+" file dont't exists");
                                return;  
                              } 
                        if(!new File(FileNameOfEpsilon).exists()){  
                                System.out.println("The "+FileNameOfEpsilon+" file dont't exists");
                                return;  
                              } 
                        if(!new File(FileNameOfDelta).exists()){  
                                System.out.println("The "+FileNameOfDelta+" file dont't exists");
                                return;  
                              } 
                        fpVelocity = new DataInputStream(new FileInputStream(new File(FileNameOfVelocity)));
                         fpEpsilon = new DataInputStream(new FileInputStream(new File(FileNameOfEpsilon)));
                           fpDelta = new DataInputStream(new FileInputStream(new File(FileNameOfDelta))); 
                        int i = 0, j =0 , k =0 ;
                        while(fpVelocity.available()>0&&fpEpsilon.available()>0&&fpDelta.available()>0
                                &&i<nx*nz&&j<nx*nz&&k<nx*nz){   
                                velocity[i++] = fpVelocity.readFloat(); 
                                 epsilon[j++] =  fpEpsilon.readFloat(); 
                                   delta[k++] =    fpDelta.readFloat();  
                              } 
                }catch(Exception e){  
                        e.printStackTrace();  
                    }
        }//read vtiModel
}


