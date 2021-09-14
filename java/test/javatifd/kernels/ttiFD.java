/*

the vti acoustic wave funciton finite difference method


  Function:
        public ttiFD();
        public ttiFD(ttiModel model, Wave wave, Wavelet wavelet);

        public void FD(int sx, int sz, int mm, String FileOfSnap, int kt);
        public void buffer(Wave wave);
        public void addSource(Wave wave, Wavelet wavelet, int sx, int sz, int it);
        public void absorbBndr(Wave wave,float qp);


  Copyright 2017  China University of Petroleum (East China)( Rong Tao )
    Email: 2386499836@qq.com
*/

//import java.lang.Math.*;

package kernels;

public class ttiFD implements FiniteDifferenceMethod{

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
