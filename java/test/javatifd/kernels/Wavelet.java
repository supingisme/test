/*
2017/7/5


the seismic wavelet

  Copyright 2017  China University of Petroleum (East China)( Rong Tao )
    Email: 2386499836@qq.com
*/


package kernels;

//import java.lang.Math.*;

public class Wavelet{

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

