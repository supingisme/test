//a##################################################
//a#
//a#         TI media Forward
//a#
//a#    vti: Quasi-acoustic wave equation
//a#    tti: Elastic wave equation
//a#
//a#
//a#
//a##################################################
//a#
//a#                 start programming: 2017/7/5
//a#        bndr condition programming: 2017/7/10
//a#              tti elastic equation: 2017/7/11
//a#
//a#            change for my software: 2017/7/24
//a#
//a#
//a#                            by Rong Tao
//a##################################################

/*
        javac Toa_TIFD.java
        java -Djava.library.path=library/ Toa_TIFD


  Copyright 2017  China University of Petroleum (East China)( Rong Tao )
    Email: 2386499836@qq.com





javac writeFloat.java

javah -jni model

gcc -shared -fpic -o libmodel.so -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux model.c

java -Djava.library.path=. Main

  Copyright 2017  China University of Petroleum (East China)( Rong Tao )
    Email: 2386499836@qq.com



*/

import java.io.*;

interface FiniteDifferenceMethod{

        void FD(int sx, int sz, int mm, String FileOfSnap, int kt);
        void buffer(Wave wave);
        void addSource(Wave wave, Wavelet wavelet, int sx, int sz, int it);
        void absorbBndr(Wave wave,float qp);
}
class Wavelet{

        private float pi = 3.141592653f;

        public int nt;
        public float dt, fm;

        public float[] wlt;

        public Wavelet(){
                System.out.println("Please input source location. 'Wavelet(int nt, float dt, float fm)'");        
        }public Wavelet(int nt, float dt, float fm){

                this.nt = nt;
                this.dt = dt;
                this.fm = fm;
        }//end

        /* ricker wavelet */
        public void Ricker(float gain){

                wlt = new float[nt];
                for(int i = 0; i<nt;i++)wlt[i]=0.0f;

                int it;
                float tdelay, t, ts, x, xx;

                for(t = 0.0f, it = 0; it < nt ; t = (++it)*dt){

                        tdelay = 1.0f/fm;
                        ts = t - tdelay;

                        if(t <= 2*tdelay){

                                x = fm * ts;
                                xx = x * x;
                                wlt[it] = (float)(gain*(1-2*pi*pi*xx)*Math.exp(-(pi*pi*xx)));

                        }//end if
                }//end for

        }//end
        /* ricker wavelet */
        public void Gaussian(float gain){

                wlt = new float[nt];
                for(int i = 0; i<nt;i++)wlt[i]=0.0f;

                int it;
                float tdelay, t, ts, x;

                for(t = 0.0f, it = 0; it < nt ; t = (++it)*dt){

                        tdelay = 1.0f/fm;
                        ts = t - tdelay;

                        if(t <= 2*tdelay){

		                   x = (float)((-4.0f)*(fm*fm*pi*pi)/Math.log(0.1));
		                   wlt[it] = (float)(gain*(-2.0f)*(pi*pi*ts)*Math.exp(-x*ts*ts));

                        }//end if
                }//end for

        }//end
}

class Wave{

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
                                if(vtiPadModel.inner(nx,nz,nn,i)){
                                        float tmp = swap(txx[i]);
                                        fpSnap.writeFloat(tmp);  
                                        }
                        }//snap output
                        fpSnap.flush();
                        fpSnap.close(); 
  
                }catch(Exception e){  
                        e.printStackTrace();  
                    }
        }//write snap
        /* swap */
        public static float swap (float value){

                int intValue = Float.floatToRawIntBits (value);
                intValue = swap (intValue);
                return Float.intBitsToFloat (intValue);
          }
        public static int swap (int value){

                int b1 = (value >>  0) & 0xff;
                int b2 = (value >>  8) & 0xff;
                int b3 = (value >> 16) & 0xff;
                int b4 = (value >> 24) & 0xff;
                return b1 << 24 | b2 << 16 | b3 << 8 | b4 << 0;
          }
}


class ttiFD implements FiniteDifferenceMethod{

        private float[] stencil = {-205.0f/72.0f,8.0f/5.0f,-1.0f/5.0f,8.0f/315.0f,-1.0f/560.0f};
        private float[]      c4 = {0.0f,0.8f,-0.2f,0.038095f,-0.0035714f};


        ttiModel model;
        Wave wave;
        Wavelet wavelet;

        public ttiFD(){
                System.out.println("Please change the ttiFD class struct function.");
        }public ttiFD(ttiModel model, Wave wave, Wavelet wavelet){
                this.model = model;
                this.wave = wave;
                this.wavelet = wavelet;
        }//end struct function

        public void FD(int sx, int sz, int mm, String FileOfSnap, int kt){


                float Pxx,Qzz,Pzz,Qxx,Pxz,Qxz,c11,c13,c33,c44,cc,ss,s2;


                float dttxx = wavelet.dt*wavelet.dt/(model.dx*model.dx);
                float dttzz = wavelet.dt*wavelet.dt/(model.dz*model.dz);
                float dttxz = wavelet.dt*wavelet.dt/(model.dx*model.dz);

                int i, j, id, im, it, imx, imz;

                for( it = 0; it < wavelet.nt; it++) {

                        if(it%10==0)System.out.println(it);

                        addSource(wave, wavelet, sx+wave.nn, sz+wave.nn, it);

                        for(i=mm; i<(model.nx-mm); i++) {

                                for(j=mm;j<(model.nz-mm); j++) { 

                                        id = i * model.nz + j;

                                        Pxx = stencil[0]*wave.P1[id];
                                        Pzz = stencil[0]*wave.P1[id];
                                        Qzz = stencil[0]*wave.Q1[id];
                                        Qxx = stencil[0]*wave.Q1[id];

                                        for(im=1;im<=mm;im++) {

                                                Pxx+=stencil[im]*(wave.P1[id+im*model.nz]+wave.P1[id-im*model.nz]);
                                                Pzz+=stencil[im]*(wave.P1[id+im]    +wave.P1[id-im]);
                                                Qzz+=stencil[im]*(wave.Q1[id+im]    +wave.Q1[id-im]);
                                                Qxx+=stencil[im]*(wave.Q1[id+im*model.nz]+wave.Q1[id-im*model.nz]);

                                        }//end

                                        Pxz=0.0f;
                                        Qxz=0.0f; 
                                        for(imz=0;imz<=mm;imz++) {
                                                for(imx=0;imx<=mm;imx++) {

                            Pxz+=c4[imx]*c4[imz]*(wave.P1[id+imx*model.nz+imz]+wave.P1[id-imx*model.nz-imz]
                                                 -wave.P1[id-imx*model.nz+imz]-wave.P1[id+imx*model.nz-imz]);
                            Qxz+=c4[imx]*c4[imz]*(wave.Q1[id+imx*model.nz+imz]+wave.Q1[id-imx*model.nz-imz]
                                                 -wave.Q1[id-imx*model.nz+imz]-wave.Q1[id+imx*model.nz-imz]);
                                                }//imx
                                        }//imz

                                        Pxx *= dttxx;
                                        Pzz *= dttzz;
                                        Pxz *= dttxz;
                                        Qzz *= dttzz;
                                        Qxx *= dttxx;
                                        Qxz *= dttxz;

                                        cc = (float)(Math.cos(model.theta[id])*Math.cos(model.theta[id]));
                                        ss = (float)(Math.sin(model.theta[id])*Math.sin(model.theta[id]));
                                        s2 = (float)(Math.sin(model.theta[id]*2.0f));

                                        c11=model.velocity[id]*model.velocity[id]*(1.0f+2.0f*model.epsilon[id]);
                                        c13=model.velocity[id]*model.velocity[id]*(1.0f+2.0f*model.delta[id]);
                                        //c13=sqrtf((2*dd*vp[id]*vp[id]+(vp[id]*vp[id]-vs[id]*vs[id]))
                                        //                *(vp[id]*vp[id]-vs[id]*vs[id]))-vs[id]*vs[id];
                                        c33=model.velocity[id]*model.velocity[id];
                                        c44=model.velocity[id]*model.velocity[id]*0.36f;


                       wave.P0[id] = 2.0f*wave.P1[id] - wave.P0[id]  
                                                     + c11*(cc*Pxx + ss*Pzz - s2*Pxz)
                                                     + c33*(ss*Qxx + cc*Qzz + s2*Qxz)
                                                     + c44*(ss*Pxx + cc*Pzz + s2*Pxz - ss*Qxx - cc*Qzz - s2*Qxz);

                       wave.Q0[id] = 2.0f*wave.Q1[id] - wave.Q0[id]  
                                                     + c13*(cc*Pxx + ss*Pzz - s2*Pxz)
                                                     + c33*(ss*Qxx + cc*Qzz + s2*Qxz)
                                                     - c44*(cc*Pxx + ss*Pzz - s2*Pxz - cc*Qxx - ss*Qzz + s2*Qxz);


                                }//end j
                        }//end i

                buffer(wave);

                if(it == kt){
                        wave.Write_snap(FileOfSnap,wave.P0);

                     /*   for(int k=0;k< model.nx ;k++){
                                for(int l=0;l< model.nz ;l++)
                                        System.out.print(wave.P0[model.nz*k+l]+"   ");
                                System.out.print("\n");
                        }//end snap  */

                }//end if

                absorbBndr(wave,-0.15f);

                }//end it

        }//end FD

        public void buffer(Wave wave){

                float tmp;                
                for(int l =0 ;l<model.nx*model.nz; l++){
                        tmp = wave.P1[l]; wave.P1[l] = wave.P0[l]; wave.P0[l] = tmp;
                        tmp = wave.Q1[l]; wave.Q1[l] = wave.Q0[l]; wave.Q0[l] = tmp;
                }//end for

        }//end
        public void addSource(Wave wave, Wavelet wavelet, int sx, int sz, int it){

                wave.P0[sx*(wave.nz+2*wave.nn)+sz] += wavelet.wlt[it];
                wave.Q0[sx*(wave.nz+2*wave.nn)+sz] += wavelet.wlt[it];
        }//end

        public void absorbBndr(Wave wave,float qp){

                int ix,iz,id;
                for(ix=0;ix<wave.nx+2*wave.nn;ix++){
                        for(iz=0;iz<wave.nz+2*wave.nn;iz++){

                                id = ix*(wave.nz+2*wave.nn) + iz;

                                if(ix<wave.nn){

               wave.P0[id]=(float)( qp*Math.pow((wave.nn-ix)/(1.0*wave.nn),2) + 1 )*wave.P0[id];
               wave.P1[id]=(float)( qp*Math.pow((wave.nn-ix)/(1.0*wave.nn),2) + 1 )*wave.P1[id];
               wave.Q0[id]=(float)( qp*Math.pow((wave.nn-ix)/(1.0*wave.nn),2) + 1 )*wave.Q0[id];
               wave.Q1[id]=(float)( qp*Math.pow((wave.nn-ix)/(1.0*wave.nn),2) + 1 )*wave.Q1[id];

                                }else if(ix>=wave.nx+wave.nn){

               wave.P0[id]=(float)( qp*Math.pow((ix-wave.nn-wave.nx)/(1.0*wave.nn),2) + 1 )*wave.P0[id];
               wave.P1[id]=(float)( qp*Math.pow((ix-wave.nn-wave.nx)/(1.0*wave.nn),2) + 1 )*wave.P1[id];
               wave.Q0[id]=(float)( qp*Math.pow((ix-wave.nn-wave.nx)/(1.0*wave.nn),2) + 1 )*wave.Q0[id];
               wave.Q1[id]=(float)( qp*Math.pow((ix-wave.nn-wave.nx)/(1.0*wave.nn),2) + 1 )*wave.Q1[id];

                                }if(iz<wave.nn){

               wave.P0[id]=(float)( qp*Math.pow((wave.nn-iz)/(1.0*wave.nn),2) + 1 )*wave.P0[id];
               wave.P1[id]=(float)( qp*Math.pow((wave.nn-iz)/(1.0*wave.nn),2) + 1 )*wave.P1[id];
               wave.Q0[id]=(float)( qp*Math.pow((wave.nn-iz)/(1.0*wave.nn),2) + 1 )*wave.Q0[id];
               wave.Q1[id]=(float)( qp*Math.pow((wave.nn-iz)/(1.0*wave.nn),2) + 1 )*wave.Q1[id];

                                }else if(iz>=wave.nz+wave.nn){

               wave.P0[id]=(float)( qp*Math.pow((iz-wave.nn-wave.nz)/(1.0*wave.nn),2) + 1 )*wave.P0[id];
               wave.P1[id]=(float)( qp*Math.pow((iz-wave.nn-wave.nz)/(1.0*wave.nn),2) + 1 )*wave.P1[id];
               wave.Q0[id]=(float)( qp*Math.pow((iz-wave.nn-wave.nz)/(1.0*wave.nn),2) + 1 )*wave.Q0[id];
               wave.Q1[id]=(float)( qp*Math.pow((iz-wave.nn-wave.nz)/(1.0*wave.nn),2) + 1 )*wave.Q1[id];

                                }//if
                        }//iz
                }//ix


        }//end
        

}

class vtiFD implements FiniteDifferenceMethod{

        private float[] stencil = {-205.0f/72.0f,8.0f/5.0f,-1.0f/5.0f,8.0f/315.0f,-1.0f/560.0f};
        private float pi = 3.141592653f;

        vtiModel model;
        Wave wave;
        Wavelet wavelet;

        public vtiFD(){
                System.out.println("Please change the vtiFD class struct function.");
        }public vtiFD(vtiModel model, Wave wave, Wavelet wavelet){
                this.model = model;
                this.wave = wave;
                this.wavelet = wavelet;
        }//end struct function

        public void FD(int sx, int sz, int mm, String FileOfSnap, int kt){

                float dt2x2 = wavelet.dt*wavelet.dt/(model.dx*model.dx);
                float dt2z2 = wavelet.dt*wavelet.dt/(model.dz*model.dz);

                //System.out.println("dt2x2 = "+dt2x2);

                int i, j, id, im, it;

                float xx,zz,flag;


                for( it = 0; it < wavelet.nt; it++) {

                        if(it%10==0)System.out.println(it);

                        addSource(wave, wavelet, sx+wave.nn, sz+wave.nn, it);

                        for(i=mm; i<(model.nx-mm); i++) {

                                for(j=mm;j<(model.nz-mm); j++) { 

                                        id = i * model.nz + j;

                                        xx = stencil[0] * wave.P1[id];
                                        zz = stencil[0] * wave.Q1[id];

                                        for(im=1;im<=mm;im++) {

               xx += stencil[im]*(wave.P1[id+im * model.nz]+wave.P1[id-im * model.nz]);

               zz += stencil[im]*(wave.Q1[id+im]+wave.Q1[id-im]);

                                        }//end

                                        //System.out.println(xx);

                                        xx *= dt2x2;
                                        zz *= dt2z2;

               wave.P0[id] =( 2.0f*wave.P1[id] - wave.P0[id] 
                                        + xx*model.velocity[id]*model.velocity[id]*(1.0f+2.0f*model.epsilon[id]) 
                                        + zz*model.velocity[id]*model.velocity[id] );

               wave.Q0[id] =( 2.0f*wave.Q1[id] - wave.Q0[id] 
                                        + xx*model.velocity[id]*model.velocity[id]*(1.0f+2.0f* model.delta [id]) 
                                        + zz*model.velocity[id]*model.velocity[id] );


                                }//end j
                        }//end i

                buffer(wave);

                if(it == kt){
                        wave.Write_snap(FileOfSnap,wave.P0);

                     /*   for(int k=0;k< model.nx ;k++){
                                for(int l=0;l< model.nz ;l++)
                                        System.out.print(wave.P0[model.nz*k+l]+"   ");
                                System.out.print("\n");
                        }//end snap  */

                }//end if

                absorbBndr(wave,-0.15f);

                }//end it
        }//end FD

        public void buffer(Wave wave){

                float tmp;                
                for(int l =0 ;l<model.nx*model.nz; l++){
                        tmp = wave.P1[l]; wave.P1[l] = wave.P0[l]; wave.P0[l] = tmp;
                        tmp = wave.Q1[l]; wave.Q1[l] = wave.Q0[l]; wave.Q0[l] = tmp;
                }//end for

        }//end
        public void addSource(Wave wave, Wavelet wavelet, int sx, int sz, int it){

                wave.P0[sx*(wave.nz+2*wave.nn)+sz] += wavelet.wlt[it];
                wave.Q0[sx*(wave.nz+2*wave.nn)+sz] += wavelet.wlt[it];
        }//end

        public void absorbBndr(Wave wave,float qp){

                int ix,iz,id;
                for(ix=0;ix<wave.nx+2*wave.nn;ix++){
                        for(iz=0;iz<wave.nz+2*wave.nn;iz++){

                                id = ix*(wave.nz+2*wave.nn) + iz;

                                if(ix<wave.nn){

               wave.P0[id]=(float)( qp*Math.pow((wave.nn-ix)/(1.0f*wave.nn),2.0f) + 1.0f )*wave.P0[id];
               wave.P1[id]=(float)( qp*Math.pow((wave.nn-ix)/(1.0f*wave.nn),2.0f) + 1.0f )*wave.P1[id];
               wave.Q0[id]=(float)( qp*Math.pow((wave.nn-ix)/(1.0f*wave.nn),2.0f) + 1.0f )*wave.Q0[id];
               wave.Q1[id]=(float)( qp*Math.pow((wave.nn-ix)/(1.0f*wave.nn),2.0f) + 1.0f )*wave.Q1[id];

                                }else if(ix>=wave.nx+wave.nn){

               wave.P0[id]=(float)( qp*Math.pow((ix-wave.nn-wave.nx)/(1.0f*wave.nn),2.0f) + 1.0f )*wave.P0[id];
               wave.P1[id]=(float)( qp*Math.pow((ix-wave.nn-wave.nx)/(1.0f*wave.nn),2.0f) + 1.0f )*wave.P1[id];
               wave.Q0[id]=(float)( qp*Math.pow((ix-wave.nn-wave.nx)/(1.0f*wave.nn),2.0f) + 1.0f )*wave.Q0[id];
               wave.Q1[id]=(float)( qp*Math.pow((ix-wave.nn-wave.nx)/(1.0f*wave.nn),2.0f) + 1.0f )*wave.Q1[id];

                                }if(iz<wave.nn){

               wave.P0[id]=(float)( qp*Math.pow((wave.nn-iz)/(1.0f*wave.nn),2.0f) + 1.0f )*wave.P0[id];
               wave.P1[id]=(float)( qp*Math.pow((wave.nn-iz)/(1.0f*wave.nn),2.0f) + 1.0f )*wave.P1[id];
               wave.Q0[id]=(float)( qp*Math.pow((wave.nn-iz)/(1.0f*wave.nn),2.0f) + 1.0f )*wave.Q0[id];
               wave.Q1[id]=(float)( qp*Math.pow((wave.nn-iz)/(1.0f*wave.nn),2.0f) + 1.0f )*wave.Q1[id];

                                }else if(iz>=wave.nz+wave.nn){

               wave.P0[id]=(float)( qp*Math.pow((iz-wave.nn-wave.nz)/(1.0f*wave.nn),2.0f) + 1.0f )*wave.P0[id];
               wave.P1[id]=(float)( qp*Math.pow((iz-wave.nn-wave.nz)/(1.0f*wave.nn),2.0f) + 1.0f )*wave.P1[id];
               wave.Q0[id]=(float)( qp*Math.pow((iz-wave.nn-wave.nz)/(1.0f*wave.nn),2.0f) + 1.0f )*wave.Q0[id];
               wave.Q1[id]=(float)( qp*Math.pow((iz-wave.nn-wave.nz)/(1.0f*wave.nn),2.0f) + 1.0f )*wave.Q1[id];

                                }//if
                        }//iz
                }//ix


        }//end
}

class ttiPadModel extends vtiPadModel{

        ttiPadModel(){
                super();
          }

        public static ttiModel pad(ttiModel m, int nx, int nz, int nn){

                int nnx = nx + 2*nn;
                int nnz = nz + 2*nn;

                ttiModel mm = new ttiModel(nnx,nnz,m.dx,m.dz);
                mm.InitModel(0.0f, 0.0f, 0.0f, 0.0f);

                for(int i = 0; i<nnx*nnz;i++){
                        if(inner(nx,nz,nn,i))  { 
                                mm.velocity[i]=m.velocity[(i/nnz-nn)*nz+i%nnz-nn];
                                 mm.epsilon[i]= m.epsilon[(i/nnz-nn)*nz+i%nnz-nn];
                                   mm.delta[i]=   m.delta[(i/nnz-nn)*nz+i%nnz-nn];
                                   mm.theta[i]=   m.theta[(i/nnz-nn)*nz+i%nnz-nn];
                              }
                    }
                for(int i = 0; i<nnx*nnz;i++){
                        if(upper(nx,nz,nn,i)){
                                mm.velocity[i]=mm.velocity[(i/nnz)*nnz+nn];
                                 mm.epsilon[i]= mm.epsilon[(i/nnz)*nnz+nn];
                                   mm.delta[i]=   mm.delta[(i/nnz)*nnz+nn];
                                   mm.theta[i]=   mm.theta[(i/nnz)*nnz+nn];
                              }
                    }
                for(int i = 0; i<nnx*nnz;i++){
                        if(downner(nx,nz,nn,i)){
                                mm.velocity[i]=mm.velocity[(i/nnz)*nnz+nn+nz-1];
                                 mm.epsilon[i]= mm.epsilon[(i/nnz)*nnz+nn+nz-1];
                                   mm.delta[i]=   mm.delta[(i/nnz)*nnz+nn+nz-1];
                                   mm.theta[i]=   mm.theta[(i/nnz)*nnz+nn+nz-1];
                              }
                    }
                for(int i = 0; i<nnx*nnz;i++){
                        if(lefter(nx,nz,nn,i)){
                                mm.velocity[i]=mm.velocity[nn*nnz+i%nnz];
                                 mm.epsilon[i]= mm.epsilon[nn*nnz+i%nnz];
                                   mm.delta[i]=   mm.delta[nn*nnz+i%nnz];
                                   mm.theta[i]=   mm.theta[nn*nnz+i%nnz];
                              }
                    }
                for(int i = 0; i<nnx*nnz;i++){
                        if(righter(nx,nz,nn,i)){
                                mm.velocity[i]=mm.velocity[(nn+nx-1)*nnz+i%nnz];
                                 mm.epsilon[i]= mm.epsilon[(nn+nx-1)*nnz+i%nnz];
                                   mm.delta[i]=   mm.delta[(nn+nx-1)*nnz+i%nnz];
                                   mm.theta[i]=   mm.theta[(nn+nx-1)*nnz+i%nnz];
                              }
                    }


                return mm;

        }
}

class vtiPadModel{

        vtiPadModel(){
                System.out.println("PadModel");
          }
        public static vtiModel pad(vtiModel m, int nx, int nz, int nn){

                int nnx = nx + 2*nn;
                int nnz = nz + 2*nn;

                vtiModel mm = new vtiModel(nnx,nnz,m.dx,m.dz);
                mm.InitModel(0.0f, 0.0f, 0.0f);

                for(int i = 0; i<nnx*nnz;i++){
                        if(inner(nx,nz,nn,i))  { 
                                mm.velocity[i]=m.velocity[(i/nnz-nn)*nz+i%nnz-nn];
                                 mm.epsilon[i]= m.epsilon[(i/nnz-nn)*nz+i%nnz-nn];
                                   mm.delta[i]=   m.delta[(i/nnz-nn)*nz+i%nnz-nn];
                              }
                    }
                for(int i = 0; i<nnx*nnz;i++){
                        if(upper(nx,nz,nn,i)){
                                mm.velocity[i]=mm.velocity[(i/nnz)*nnz+nn];
                                 mm.epsilon[i]= mm.epsilon[(i/nnz)*nnz+nn];
                                   mm.delta[i]=   mm.delta[(i/nnz)*nnz+nn];
                              }
                    }
                for(int i = 0; i<nnx*nnz;i++){
                        if(downner(nx,nz,nn,i)){
                                mm.velocity[i]=mm.velocity[(i/nnz)*nnz+nn+nz-1];
                                 mm.epsilon[i]= mm.epsilon[(i/nnz)*nnz+nn+nz-1];
                                   mm.delta[i]=   mm.delta[(i/nnz)*nnz+nn+nz-1];
                              }
                    }
                for(int i = 0; i<nnx*nnz;i++){
                        if(lefter(nx,nz,nn,i)){
                                mm.velocity[i]=mm.velocity[nn*nnz+i%nnz];
                                 mm.epsilon[i]= mm.epsilon[nn*nnz+i%nnz];
                                   mm.delta[i]=   mm.delta[nn*nnz+i%nnz];
                              }
                    }
                for(int i = 0; i<nnx*nnz;i++){
                        if(righter(nx,nz,nn,i)){
                                mm.velocity[i]=mm.velocity[(nn+nx-1)*nnz+i%nnz];
                                 mm.epsilon[i]= mm.epsilon[(nn+nx-1)*nnz+i%nnz];
                                   mm.delta[i]=   mm.delta[(nn+nx-1)*nnz+i%nnz];
                              }
                    }


                return mm;
          }

        static boolean inner(int nx, int nz, int nn, int i){

                int ix = i/(nz+2*nn);
                int iz = i%(nz+2*nn);

                if(ix>=nn&&ix<(nn+nx)&&iz>=nn&&iz<(nz+nn))return true;
                else return false;
          }
        static boolean upper(int nx, int nz, int nn, int i){

                int iz = i%(nz+2*nn);

                if(iz<nn)return true;
                else return false;
          }
        static boolean downner(int nx, int nz, int nn, int i){

                int iz = i%(nz+2*nn);

                if(iz>=nn+nz)return true;
                else return false;
          }
        static boolean lefter(int nx, int nz, int nn, int i){

                int ix = i/(nz+2*nn);

                if(ix<nn)return true;
                else return false;
          }
        static boolean righter(int nx, int nz, int nn, int i){

                int ix = i/(nz+2*nn);

                if(ix>=nn+nx)return true;
                else return false;
          }
}

/* vtiModel */
class vtiModel{

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
}

class ttiModel extends vtiModel{

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
}

class Toa_TIFD{

        public static void main(String[]args)throws java.io.IOException{

                int nn = 20;

                int nx = 200;
                int nz = 200;

                float dx = 5.0f;
                float dz = 5.0f;

                int sx = nx/2;
                int sz = nz/2;

                int nt = 301;
                float dt = 0.001f;//s
                float fm = 60.0f;


                /* initial the wave(P0,P1,Q0,Q1) */
                Wave wave = new Wave(nx, nz, nn);
                wave.Init_Wave();
                //wave.Write_snap("snap.dat",wave.P0);     

                /* get the wavelet<Gaussian or Ricker> */
                Wavelet wavelet = new Wavelet(nt,dt, fm); 
                wavelet.Ricker(1.0f);/* Ricker(float gain); */


/*### VTI Forward ###*/

                /* Model (int nx,int nz,float dx,float dz); */
                vtiModel model0 = new vtiModel(nx,nz,dx,dz);
                /* velocity, epsilon, delta */
                model0.InitModel(2000.0f, 0.2f, 0.1f);
                /* vtiModel pad(vtiModel m, int nx, int nz, int nn); */
                vtiModel model = vtiPadModel.pad(model0,nx,nz,nn);  
                /* initial and calculate the wave field */
                vtiFD vtifd = new vtiFD(model, wave, wavelet);
                /* void FD(int sx, int sz, int mm, String FileOfSnap, int itSnap) */
                vtifd.FD(sx,sz,4, "snap_vti.dat", nt*9/10);  


/*### TTI Forward ###*/

                /* Model (int nx,int nz,float dx,float dz); */
                //ttiModel tmodel0 = new ttiModel(nx,nz,dx,dz);
                /* velocity, epsilon, delta, theta */
                //tmodel0.InitModel(2000.0f,0.2f,0.1f,45.0f);
                /* ttiModel pad(ttiModel m, int nx, int nz, int nn); */
                //ttiModel tmodel = ttiPadModel.pad(tmodel0,nx,nz,nn);
                /* initial and calculate the wave field */
                //ttiFD ttifd = new ttiFD(tmodel, wave, wavelet);
                /* void FD(int sx, int sz, int mm, String FileOfSnap, int itSnap) */
                //ttifd.FD(sx,sz,4, "snap_tti.dat", nt*9/10); 

        }
}
