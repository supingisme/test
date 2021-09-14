/*
2017/7/5


the vti wavefield

  Copyright 2017  China University of Petroleum (East China)( Rong Tao )
    Email: 2386499836@qq.com
*/

package kernels;

import java.io.*;

public class Wave{

        public int nx,nz,nn;

        public float[] P0;
        public float[] P1;
        public float[] Q0;
        public float[] Q1;
        
        public Wave(){
                nx = nz = 100;
                nn = 50;
        }public Wave(int dim,int nn){
                nx = nz = dim;
                this.nn = nn;
        }public Wave(int nx,int nz,int nn){
                this.nx = nx;
                this.nz = nz;
                this.nn = nn;
          }
        public void Init_Wave(){
                P0 = new float[(nx+2*nn)*(nz+2*nn)];
                P1 = new float[(nx+2*nn)*(nz+2*nn)];
                Q0 = new float[(nx+2*nn)*(nz+2*nn)];
                Q1 = new float[(nx+2*nn)*(nz+2*nn)];
                for(int i = 0; i < (nx+2*nn)*(nz+2*nn); i++){
                        P0[i] = 0.0f;
                        P1[i] = 0.0f;
                        Q0[i] = 0.0f;
                        Q1[i] = 0.0f;
                }//end
        }//initial Wave
        public void Write_snap(String FileNameOfSnap, float[] txx){

                /*Writer writer = new OutputStreamWriter(new FileOutputStream(file), "UTF-8");*/

                DataOutputStream fpSnap = null;
                try{  
                        if(!new File(FileNameOfSnap).exists()){  
                                new File(FileNameOfSnap).createNewFile();  
                              }       

                        fpSnap = new DataOutputStream(new FileOutputStream(new File(FileNameOfSnap)));  
                }catch(Exception e){  
                        e.printStackTrace();  
                    }
                try{  
                        for(int i=0;i<(nx+2*nn)*(nz+2*nn);i++){
                                int ix = i/(nz+2*nn);
                                int iz = i%(nz+2*nn);
                                if(vtiPadModel.inner(nx,nz,nn,i))
                                        fpSnap.writeFloat(txx[i]);  
                        }//snap output
                        fpSnap.flush();
                        fpSnap.close(); 
  
                }catch(Exception e){  
                        e.printStackTrace();  
                    }
        }//write snap
}
