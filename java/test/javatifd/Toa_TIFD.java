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
//a#                 native swap_float: 2017/7/11
//a#
//a#
//a#                            by Rong Tao
//a##################################################

/*
        javac Toa_TIFD.java
        java -Djava.library.path=library/ Toa_TIFD


  Copyright 2017  China University of Petroleum (East China)( Rong Tao )
    Email: 2386499836@qq.com
*/

import kernels.vtiModel;//vti model
import kernels.ttiModel;//tti model

import kernels.vtiPadModel;//add boundary
import kernels.ttiPadModel;//add boundary

import kernels.vtiFD;//finite difference method
import kernels.ttiFD;//finite difference method

import kernels.Wave;//wavefield
import kernels.Wavelet;//seismic wavelet

class swap{

        /*(flag=) true: writeFloat2fwrite, flase: fwrite2writeFloat*/
        public static native void swap_float(String in, String out);
}

class Toa_TIFD{



        public static void main(String[]args)throws java.io.IOException{

                System.loadLibrary("swap");

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
                //model0.WriteModel("v0.dat","e0.dat", "d0.dat");
                //model0.ReadModel("v0.dat","e0.dat", "d0.dat");

                /* vtiModel pad(vtiModel m, int nx, int nz, int nn); */
                vtiModel model = vtiPadModel.pad(model0,nx,nz,nn);  
 
                /* initial and calculate the wave field */
                vtiFD vtifd = new vtiFD(model, wave, wavelet);

                /* void FD(int sx, int sz, int mm, String FileOfSnap, int itSnap) */
                vtifd.FD(sx,sz,4, "snap_vti.dat", nt*9/10);  
                swap.swap_float("snap_vti.dat", "snap_vti_swap.dat");

/*### TTI Forward ###*/

                /* Model (int nx,int nz,float dx,float dz); */
                ttiModel tmodel0 = new ttiModel(nx,nz,dx,dz);

                /* velocity, epsilon, delta, theta */
                tmodel0.InitModel(2000.0f,0.2f,0.1f,45.0f);
                //tmodel0.ShowModel();
                //tmodel0.WriteModel("v0.dat","e0.dat", "d0.dat","t0.dat");
                //tmodel0.ReadModel("v0.dat","e0.dat", "d0.dat","t0.dat");

                /* ttiModel pad(ttiModel m, int nx, int nz, int nn); */
                ttiModel tmodel = ttiPadModel.pad(tmodel0,nx,nz,nn);

                /* initial and calculate the wave field */
                ttiFD ttifd = new ttiFD(tmodel, wave, wavelet);

                /* void FD(int sx, int sz, int mm, String FileOfSnap, int itSnap) */
                ttifd.FD(sx,sz,4, "snap_tti.dat", nt*9/10); 

                swap.swap_float("snap_tti.dat", "snap_tti_swap.dat");

        }
}
