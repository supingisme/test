
class RungeKutta{

        public static native float[] rungekutta(String[] file, int[] parasint, float[] parasfloat);

        private static float[][][] raypath;

        public static void main(String[]args){

                System.loadLibrary("RungeKutta");


                String FNv = "vel.dat";
                String FNd = "delta.dat";
                String FNe = "epsilon.dat";
                String FNt = "time.dat";
                String FNp = "raypath.txt";
                String FNl = "length.txt";


                int nx,nz,nt,na,nsx;
                float dx,dz,dt,fa,da,fsx,dsx,sz;

                nx = 51;
                nz = 51;
                dx = 5.0f;
                dz = 5.0f;
                
                nt = 201;
                dt = 0.0005f;
                
                na = 90;
                fa = 315f;
                da = 1f;
        
                nsx = 1;
                fsx = nx*dx/2f;
                dsx = 1f;
                sz = 1f;

                raypath = new float[nsx*na][2][nt];

                /*vel, delta, epsilon, time, raypath, length*/
                String[] file = {FNv,FNd,FNe,FNt,FNp,FNl};
                /*nt ,nx, nz, na, nsx*/
                int[] parasint = {nt, nx, nz, na, nsx};
                /*dx, dz, dt, fa, da, fsx, dsx, sz*/
                float[] parasfloat = {dx, dz, dt, fa, da, fsx, dsx, sz};

                float[]tmp = rungekutta(file,parasint,parasfloat);

                for(int iray=0;iray<nsx*na;iray++){
                        System.out.println("------------------------");
                        for(int it = 0;it<nt;it++){
                                raypath[iray][0][it] = tmp[iray*2*nt+it];
                                raypath[iray][1][it] = tmp[iray*2*nt+nt+it];
                                System.out.println("x = "+raypath[iray][0][it]+", z = "+raypath[iray][1][it]);
                              }
                    }
         }


}
