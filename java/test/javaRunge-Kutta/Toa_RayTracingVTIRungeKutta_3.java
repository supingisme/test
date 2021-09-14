

import java.io.Writer;
import java.io.FileWriter;


class RayStep{
        float t;		/* time */
        float x,z;		/* x,z coordinates */
        float q1,p1,q2,p2;	/* Cerveny's dynamic ray tracing solution */
        int kmah;		/* KMAH index */
        float c,s;		/* cos(angle) and sin(angle) */
        float v,dvdx,dvdz;	/* velocity and its derivatives */
}
class Ray{
        int nrs;		/* number of ray steps */
        RayStep[] rs;		/* array[nrs] of ray steps */
        int nc;			/* number of circles */
        int ic;			/* index of circle containing nearest step */
        float c;		/* array[nc] of circles */
}
class Vel2{
        int nx;		/* number of x samples */
        int nz;		/* number of z samples */
        int nxm;	/* number of x samples minus LTABLE */
        int nzm;	/* number of x samples minus LTABLE */
        float xs,xb,zs,zb;
        float[] sx = new float[3];
        float[] sz = new float[3];
        float[][] vu;
}

class Vel2derivatives{

        float v, vx, vz, vxx, vxz, vzz;
}

class Toa{

        public static float INITIAL = 99999999f;
        public static int NTABLE = 101;
        public static int LTABLE = 4;
        public static boolean tabled = false;

        public static float ltable = LTABLE*1f,ntblm1=NTABLE*1f-1f;
        public static int ix = 1-LTABLE/2-LTABLE,iz=1-LTABLE/2-LTABLE;
        public static float[][][] tbl = new float[3][NTABLE][LTABLE];

        public static int[] kx = {0,1,0,2,1,0};
        public static int[] kz = {0,0,1,0,1,2};

        public static void main(String[]args)throws java.io.IOException{

                int nx,nz,nt,ix,iz,irs,nxf,nxe,nzf,nze,ixo,izo,i,NRS,cntt,isx,ia,nxo,nzo,nsx,na;
                float sx,dx,sz,dz,dt,a,fxo,dxo,fzo,dzo,fx,fz,ft,v0,vd,vd1,px,pz,exo,r2,
                        r1,r1x,t1x,t2x,t2xz,xoc,zoc,xc,zc,terr,tc,norm2,curv,x1,c1,s1,
                        z1,Det,fac,r2x,v1,t1,t2,a1,ezo,xo,zo,sd,fsx,dsx,amin,amax,da,fa,l_x2,l_z2,len;
                float[] dvdx1,dvdz1,xx,zz,t,s,vv,cc,ss,tt;
                float[][] VP0,a1111,a3333,VS0,a1133,a1313,a1113,a3313,delta,epsilon,X,Y,N;
                
                Ray ray;



                /* get parameters for input alloc */
                nx = 301; dx = 5.0f;
                nz = 301; dz = 5.0f;


                /* get parameters for the parameter field*/
                nt = 2501;
                dt = 0.0003f;

                /* get parameters for the take-off angle of the ray at the source*/
                na=60;
                fa=0f;
                da=6f;

                /* get parameters defining source positions */
                nsx = 1;
                fsx = nx*dx/2.0f;
                dsx = nx*dx/2.0f;
                sz = (nz-1f)*dz/2f;

                /* output file */
                Writer fpraypath = new FileWriter("raypath.txt");
                Writer fplength = new FileWriter("length.txt");

                /* get parameters defining the output traveltime table*/
                fx = 0.0f;  
                fz = 0.0f; 
                fac = 0.01f;
                amin = 0f;
                amax = 180f;
                fxo = fx;
                nxo = nx;
                dxo = dx;
                fzo = fz;
                nzo = nz;
                dzo = dz;

                /* ensure takeoff point is within model */
                if (fsx<fx || fsx>(fx+dx*(nx-1)) 
                           || (fsx+dsx*(nsx-1))<fx 
                           || (fsx+dsx*(nsx-1))>(fx+dx*(nx-1))) 
                        {System.out.println("Shot point locations exceed model dimensions !\n");System.exit(0);}	

                /* allocate workspace */
                VP0 = new float[nx][nz];
                VS0 = new float[nx][nz];
                a1111 = new float[nx][nz];
                a3333 = new float[nx][nz];
                a1133 = new float[nx][nz];
                a1313 = new float[nx][nz];
                a1113 = new float[nx][nz];
                a3313 = new float[nx][nz];
                delta = new float[nx][nz];
                epsilon = new float[nx][nz];
                tt = new float[nt];
                xx = new float[nt];
                zz = new float[nt];
                t  = new float[nxo*nzo];
                s  = new float[nxo*nzo];
                cc = new float[nt];
                ss = new float[nt];
                vv = new float[nt];
                dvdx1 = new float[nt];
                dvdz1 = new float[nt];
                N  = new float[2][2];
                X  = new float[2][2];
                Y  = new float[2][2];


                for(ix=0;ix<nx;ix++)
                        for(iz=0;iz<nz;iz++){

                                VP0[ix][iz] = iz<170?2500.0f:5000.0f;
                                delta[ix][iz] = 0.2f;
                                epsilon[ix][iz] = 0.3f;
                                /* a3333 */a3333[ix][iz] = VP0[ix][iz]*VP0[ix][iz];
                                /* VS0   */VS0[ix][iz]   = 0.0f;//.5477*VP0[ix][iz];
                                /* a1313 */a1313[ix][iz] = VS0[ix][iz]*VS0[ix][iz];
                                /* a1113 */a1113[ix][iz] = 0f;
                                /* a3313 */a3313[ix][iz] = 0f;
                                /* a1111 */a1111[ix][iz] = a3333[ix][iz]*(1f+2f*epsilon[ix][iz]);
                                /* a1133 */a1133[ix][iz] = (float)Math.sqrt(2f*delta[ix][iz]*a3333[ix][iz]
                                                                        *(a3333[ix][iz]-a1313[ix][iz])
                                                        +(a3333[ix][iz]-a1313[ix][iz])*(a3333[ix][iz]-a1313[ix][iz]))
                                                        -a1313[ix][iz];

                    }

                /* is loop start */
                for(isx=0;isx<nsx;isx++) {
                        sx=fsx+isx*dsx;

                        for (ixo=0;ixo<nxo;ixo++)
                                for(izo=0;izo<nzo;izo++) {
                                        i = izo+ixo*nzo;
                                        t[i] = INITIAL;
                                        s[i] = INITIAL;
                              }

                        /* iterate over takeoff angle */
                        for(ia=0;ia<na;ia++) {
                                a=fa+ia*da;
                                len=0.0f;
                                ft=0;/* Assume 0s as initial time */
                                if(ia%10==0) System.out.println("isx = "+isx+", angle = "+a);

                                ray = makeRay(sx,sz,a,nt,dt,ft,a1111,a3333,a1133,a1313,a1113,a3313,nx,
                                                dx,fx,nz,dz,fz,amax,amin,0);

                                for(int l=0;l<ray.nrs;l++)
                                        fpraypath.write(ray.rs[l].x+"         "+ray.rs[l].z+"    \n");
                                fpraypath.write("-999999.9         -999999.9   \n");

                                for(int l=0;l<ray.nrs-1;l++){
                                        if(ray.rs[l+1].x>0
                                         &&ray.rs[l+1].x<dx*nx
                                         &&ray.rs[l+1].z>0
                                         &&ray.rs[l+1].z<dz*nz ){
                                                l_x2 = (ray.rs[l+1].x-ray.rs[l].x)*(ray.rs[l+1].x-ray.rs[l].x);
                                                l_z2 = (ray.rs[l+1].z-ray.rs[l].z)*(ray.rs[l+1].z-ray.rs[l].z);
                                                len += (float)(Math.sqrt(l_x2+l_z2));

                                        }else{continue;}
                                }//for
                                //System.out.println("length = "+len);
                                fplength.write(ia+"        "+len+"         "+ray.rs[ray.nrs-1].t+"   \n");
                        }//ia





                }//isx
                fpraypath.close();
                fplength.close();





        }//main


        public static Ray makeRay (float x0, float z0, float a0, int nt, float dt, float ft,
                        float[][]a1111xz, float[][]a3333xz, float[][]a1133xz, float[][]a1313xz, 
                        float[][]a1113xz, float[][]a3313xz, 
                        int nx, float dx, float fx, int nz, float dz, float fz, 
                        float amax, float amin,int flagtrace){

                int it,kmah;
                float t,x,z,c,s,p1,q1,p2,q2,px,pz,px2,pz2,pxz,
                        lx,lz,cc,ss,
                        a1111,da1111dx,da1111dz,dda1111dxdx,dda1111dxdz,dda1111dzdz,
                        a3333,da3333dx,da3333dz,dda3333dxdx,dda3333dxdz,dda3333dzdz,
                        a1133,da1133dx,da1133dz,dda1133dxdx,dda1133dxdz,dda1133dzdz,
                        a1313,da1313dx,da1313dz,dda1313dxdx,dda1313dxdz,dda1313dzdz,
                        a1113,da1113dx,da1113dz,dda1113dxdx,dda1113dxdz,dda1113dzdz,
                        a3313,da3313dx,da3313dz,dda3313dxdx,dda3313dxdz,dda3313dzdz,
                        da1111dn,dda1111dndn,da3333dn,dda3333dndn,da1133dn,dda1133dndn,
                        da1313dn,dda1313dndn,da1113dn,dda1113dndn,da3313dn,dda3313dndn,
                        gamm11,gamm13,gamm33,vp2,vp,ovp,sqr;

                RayStep[] rs = new RayStep[nt];
                for(int i=0;i<nt;i++)rs[i] = new RayStep();
                Ray ray = new Ray();



                Vel2 a11112,a33332,a11332,a13132,a11132,a33132;

                /*Convert degrees to radians   度转换为弧度 */
                a0=a0*3.1415926f/180f; 
                amax=amax*3.1415926f/180f; 
                amin=amin*3.1415926f/180f;
                /* allocate and initialize velocities interpolator 分配和初始化速度插值       */
                a11112 = vel2Alloc(nx,dx,fx,nz,dz,fz,a1111xz);
                a33332 = vel2Alloc(nx,dx,fx,nz,dz,fz,a3333xz);
                a11332 = vel2Alloc(nx,dx,fx,nz,dz,fz,a1133xz);
                a13132 = vel2Alloc(nx,dx,fx,nz,dz,fz,a1313xz);
                a11132 = vel2Alloc(nx,dx,fx,nz,dz,fz,a1113xz);
                a33132 = vel2Alloc(nx,dx,fx,nz,dz,fz,a3313xz);

                /* last x and z in velocity model */
                lx = fx+(nx-1)*dx;
                lz = fz+(nz-1)*dz;
                /* ensure takeoff point is within model */
                if (x0<fx || x0>lx || z0<fz || z0>lz ) return null;
                /* cosine and sine of takeoff angle */
                c = (float)Math.cos(a0);
                s = (float)Math.sin(a0);
                cc = c*c;
                ss = s*s;


                Vel2derivatives vvv = new Vel2derivatives();
                /* velocities and derivatives at takeoff point */
                vvv = vel2Interp(a11112,x0,z0);
                a1111 = vvv.v;
                da1111dx = vvv.vx;
                da1111dz = vvv.vz;
                dda1111dxdx = vvv.vxx;
                dda1111dxdz = vvv.vxz;
                dda1111dzdz = vvv.vzz;
                da1111dn = da1111dx*c-da1111dz*s;
                dda1111dndn = dda1111dxdx*cc-2.0f*dda1111dxdz*s*c+dda1111dzdz*ss;

                vvv = vel2Interp(a33332,x0,z0);
                a3333 = vvv.v;
                da3333dx = vvv.vx;
                da3333dz = vvv.vz;
                dda3333dxdx = vvv.vxx;
                dda3333dxdz = vvv.vxz;
                dda3333dzdz = vvv.vzz;
                da3333dn = da3333dx*c-da3333dz*s;
                dda3333dndn = dda3333dxdx*cc-2.0f*dda3333dxdz*s*c+dda3333dzdz*ss;

                vel2Interp(a11332,x0,z0);
                a1133 = vvv.v;
                da1133dx = vvv.vx;
                da1133dz = vvv.vz;
                dda1133dxdx = vvv.vxx;
                dda1133dxdz = vvv.vxz;
                dda1133dzdz = vvv.vzz;
                da1133dn = da1133dx*c-da1133dz*s;
                dda1133dndn = dda1133dxdx*cc-2.0f*dda1133dxdz*s*c+dda1133dzdz*ss;

                vvv = vel2Interp(a13132,x0,z0);
                a1313 = vvv.v;
                da1313dx = vvv.vx;
                da1313dz = vvv.vz;
                dda1313dxdx = vvv.vxx;
                dda1313dxdz = vvv.vxz;
                dda1313dzdz = vvv.vzz;
                da1313dn = da1313dx*c-da1313dz*s;
                dda1313dndn = dda1313dxdx*cc-2.0f*dda1313dxdz*s*c+dda1313dzdz*ss;

                vel2Interp(a11132,x0,z0);
                a1113 = vvv.v;
                da1113dx = vvv.vx;
                da1113dz = vvv.vz;
                dda1113dxdx = vvv.vxx;
                dda1113dxdz = vvv.vxz;
                dda1113dzdz = vvv.vzz;
                da1113dn = da1113dx*c-da1113dz*s;
                dda1113dndn = dda1113dxdx*cc-2.0f*dda1113dxdz*s*c+dda1113dzdz*ss;

                vvv = vel2Interp(a33132,x0,z0);
                a3313 = vvv.v;
                da3313dx = vvv.vx;
                da3313dz = vvv.vz;
                dda3313dxdx = vvv.vxx;
                dda3313dxdz = vvv.vxz;
                dda3313dzdz = vvv.vzz;
                da3313dn = da3313dx*c-da3313dz*s;
                dda3313dndn = dda3313dxdx*cc-2.0f*dda3313dxdz*s*c+dda3313dzdz*ss;

                /*computing the phase velocity for a0 angle */
                gamm11 = a1111*ss+ a1313*cc +2*a1113*s*c;
                gamm33 = a3333*cc + a1313*ss+2*a3313*s*c;
                gamm13 = (a1133+a1313)*s*c+ a1113*ss+ a3313*cc;
                sqr    = (float)(Math.sqrt((gamm11+gamm33)*(gamm11+gamm33)-
                                4f*(gamm11*gamm33-gamm13*gamm13)));
                vp2    = gamm11+gamm33+sqr;
                vp     = (float)Math.sqrt(vp2*.5);
                ovp    = 1f/vp;
                px     = s*ovp;
                pz     = c*ovp;

                /* first ray step */
                rs[0].t = t = ft;
                rs[0].x = x = x0;
                rs[0].z = z = z0;
                rs[0].q1 = q1 = 1.0f;
                rs[0].p1 = p1 = 0.0f;
                rs[0].q2 = q2 = 0.0f;
                rs[0].p2 = p2 = 1.0f;
                rs[0].kmah = kmah = 0;
                rs[0].c = c;
                rs[0].s = s;
                rs[0].v = vp;
                rs[0].dvdx = .5f*da3333dx*vp/a3333;
                rs[0].dvdz = .5f*da3333dz*vp/a3333;

                /* loop over time steps */
                for (it=1; it<nt; ++it) {

                        /* variables used for Runge-Kutta integration */
                        float h=dt,hhalf=dt/2.0f,hsixth=dt/6.0f,
                                q2old,xt,zt,p1t,q1t,p2t,q2t,
                                dxn,dzn,dp1,dq1,dp2,dq2,
                                dxt,dzt,dp1t,dq1t,dp2t,dq2t,
                                dxm,dzm,dp1m,dq1m,dp2m,dq2m,
                                gamma11,gamma33,gamma13,g11,g13,g33,den,
                                sxfactor,szfactor,snfact,dpx,dpz,pxt,pzt,dpxt,
                                dpzt,dpxm,dpzm,dxdn,dzdn,snfactor,
                                dxx,dzz,dcdp1,dcdp3,dcdp13,ddcdnn,ddcdqq,
                                ddcdpn,dgamma11dpx,dgamma11dpz,dgamma33dpx,
                                dgamma33dpz,dgamma13dpx,dgamma13dpz,dg11dpx,
                                dg11dpz,dg33dpx,dg33dpz,dg13dpx,dg13dpz,ddxdpx,
                                ddzdpz,ddxdpz,dgamma11dn,dgamma33dn,dgamma13dn,
                                dg11dn,dg33dn,dg13dn,dsnfactordn,ddxdn,ddzdn;

                                /* if ray is out of bounds, break */
                                if (x<fx || x>lx || z<fz || z>lz 
                                         || c>(Math.cos(amin)+0.01) || c<(Math.cos(amax))-0.01) break;
                                /* remember old q2 */
                                q2old = q2;

                                /* step 1 of 4th-order Runge-Kutta */
                                /* step 1 of 4th-order Runge-Kutta */
                                px2   = px*px;
                                pz2   = pz*pz;
                                pxz   = px*pz;

                                /*anisotropy parameters*/
                                gamma11 = a1111*px2+ a1313*pz2 +2f*a1113*pxz;
                                gamma33 = a3333*pz2 + a1313*px2+2f*a3313*pxz;
                                gamma13 = (a1133+a1313)*pxz+ a1113*px2+ a3313*pz2;
                                den     = 1f/(gamma11+gamma33-2f);
                                g11     = (gamma33-1f)*den;
                                g33     = (gamma11-1f)*den;
                                g13     = -gamma13*den;
                                sxfactor = da1111dx*px2*g11+da3333dx*pz2*g33+
                                        2f*(da1133dx+da1313dx)*pxz*g13+da1313dx*(px2*g33+pz2*g11)+
                                        2f*da3313dx*(pz2*g13+pxz*g33)+2f*da1113dx*(pxz*g11+px2*g13);
                                szfactor = da1111dz*px2*g11+da3333dz*pz2*g33+
                                        2f*(da1133dz+da1313dz)*pxz*g13+da1313dz*(px2*g33+pz2*g11)+
                                        2f*da3313dz*(pz2*g13+pxz*g33)+2f*da1113dz*(pxz*g11+px2*g13);
                                snfact = sxfactor*c-szfactor*s;

                                /*computing ray velocities and derivatives*/
                                dxn =  (a1111*px*g11+(a1133+a1313)*pz*g13+a3313*pz*g33
                                        +a1113*(pz*g11+2f*px*g13)+a1313*g33*px);
                                dzn =  (a3333*pz*g33+(a1133+a1313)*px*g13+a1113*px*g11
                                        +a3313*(px*g33+2f*pz*g13)+a1313*g11*pz);

                                dgamma11dpx = 2f*a1111*px+2f*a1113*pz;
                                dgamma11dpz = 2f*a1313*pz+2f*a1113*px;
                                dgamma33dpx = 2f*a1313*px+2f*a3313*pz;
                                dgamma33dpz = 2f*a3333*pz+2f*a3313*px;
                                dgamma13dpx= (a1133+a1313)*pz+2f*a1113*px;
                                dgamma13dpz= (a1133+a1313)*px+2f*a3313*pz;
                                dgamma11dn = da1111dn*px2+ da1313dn*pz2 +2f*da1113dn*pxz;
                                dgamma33dn = da3333dn*pz2 + da1313dn*px2+2f*da3313dn*pxz;
                                dgamma13dn = (da1133dn+da1313dn)*pxz+ da1113dn*px2+ da3313dn*pz2;
                                dg11dpx = -(gamma33-1f)*(dgamma11dpx+dgamma33dpx-4f*dxn)*den*den+
                                        (dgamma33dpx-2f*dxn)*den;
                                dg11dpz = -(gamma33-1f)*(dgamma11dpz+dgamma33dpz-4f*dzn)*den*den+
                                        (dgamma33dpz-2f*dzn)*den;
                                dg33dpx = -(gamma11-1f)*(dgamma11dpx+dgamma33dpx-4f*dxn)*den*den+
                                        (dgamma11dpx-2f*dxn)*den;
                                dg33dpz = -(gamma11-1f)*(dgamma11dpz+dgamma33dpz-4f*dzn)*den*den+
                                        (dgamma11dpz-2f*dzn)*den;
                                dg13dpx = gamma13*(dgamma11dpx+dgamma33dpx-4f*dxn)*den*den-
                                        dgamma13dpx*den;
                                dg13dpz = gamma13*(dgamma11dpz+dgamma33dpz-4f*dzn)*den*den-
                                        dgamma13dpz*den;
                                dg11dn = -(gamma33-1f)*(dgamma11dn+dgamma33dn-2f*snfact)*den*den+
                                        (dgamma33dn-snfact)*den;
                                dg33dn = -(gamma11-1f)*(dgamma11dn+dgamma33dn-2f*snfact)*den*den+
                                        (dgamma11dn-snfact)*den;
                                dg13dn = gamma13*(dgamma11dn+dgamma33dn-2f*snfact)*den*den-
                                        dgamma13dn*den;
                                ddxdpx= a1111*px*dg11dpx+(a1133+a1313)*pz*dg13dpx+
                                        a3313*pz*dg33dpx+a1113*(pz*dg11dpx+2f*px*dg13dpx)
                                        +a1313*dg33dpx*px;
                                ddzdpz= a3333*pz*dg33dpz+(a1133+a1313)*px*dg13dpz+
                                        a1113*px*dg11dpz+a3313*(px*dg33dpz+2f*pz*dg13dpz)+
                                        a1313*dg11dpz*pz;
                                ddxdpz= a1111*px*dg11dpz+(a1133+a1313)*pz*dg13dpz+
                                        a3313*pz*dg33dpz+a1113*(pz*dg11dpz+2f*px*dg13dpz)+
                                        a1313*dg33dpz*px;
                                dsnfactordn = da1111dn*px2*dg11dn+da3333dn*pz2*dg33dn+
                                        2f*(da1133dn+da1313dn)*pxz*dg13dn+da1313dn*(px2*dg33dn+pz2*dg11dn)+
                                        2f*da3313dn*(pz2*dg13dn+pxz*dg33dn)+2f*da1113dn*(pxz*dg11dn+px2*dg13dn);
                                ddxdn =  (a1111*px*dg11dn+(a1133+a1313)*pz*dg13dn+a3313*pz*dg33dn
                                        +a1113*(pz*dg11dn+2f*px*dg13dn)+a1313*dg33dn*px);
                                ddzdn =  (a3333*pz*dg33dn+(a1133+a1313)*px*dg13dn+a1113*px*dg11dn
                                        +a3313*(px*dg33dn+2f*pz*dg13dn)+a1313*dg11dn*pz);

                                /*evaluating change in slowness and amplitude along ray*/
                                dpx = -0.5f*sxfactor;
                                dpz = -0.5f*szfactor;

                                dcdp1  = a1111*g11+a1313*g33+2*a1113*g13+ddxdpx-dxn*dxn;
                                dcdp3  = a3333*g33+a1313*g11+2*a3313*g13+ddzdpz-dzn*dzn;
                                dcdp13 = a1133*g13+a1313*g13+a1113*g11+a3313*g33+ddxdpz-dxn*dzn;
                                ddcdqq = dcdp1*cc-2.0f*dcdp13*s*c+dcdp3*ss;
                                dxdn   =  (da1111dn*px*g11+(da1133dn+da1313dn)*pz*g13+da3313dn*pz*g33
                                        +da1113dn*(pz*g11+2*px*g13)+da1313dn*g33*px);
                                dzdn   =  (da3333dn*pz*g33+(da1133dn+da1313dn)*px*g13+da1113dn*px*g11
                                        +da3313dn*(px*g33+2*pz*g13)+da1313dn*g11*pz);
                                ddcdpn = dxdn*c-dzdn*s-.5f*dxn*sxfactor*cc+
                                        .5f*(dxn*szfactor+dzn*sxfactor)*s*c-.5f*dzn*szfactor*ss
                                        +ddxdn*c-ddzdn*s;
                                snfactor = dda1111dndn*px2*g11+dda3333dndn*pz2*g33+
                                        2*(dda1133dndn+dda1313dndn)*pxz*g13+
                                        dda1313dndn*(px2*g33+pz2*g11)+
                                        2*dda3313dndn*(pz2*g13+pxz*g33)+
                                        2*dda1113dndn*(pxz*g11+px2*g13);
                                ddcdnn = 0.5f*snfactor-.25f*sxfactor*sxfactor*cc+
                                        .5f*sxfactor*szfactor*s*c-.25f*szfactor*szfactor*ss
                                        +.5f*dsnfactordn;

                                dp1 = -ddcdnn*q1-ddcdpn*p1;
                                dq1 = ddcdqq*p1+ddcdpn*q1;
                                dp2 = -ddcdnn*q2-ddcdpn*p2;
                                dq2 = ddcdqq*p2+ddcdpn*q2;
                                xt = x+hhalf*dxn;
                                zt = z+hhalf*dzn;
                                pxt = px+hhalf*dpx;
                                pzt = pz+hhalf*dpz;
                                p1t = p1+hhalf*dp1;
                                q1t = q1+hhalf*dq1;
                                p2t = p2+hhalf*dp2;
                                q2t = q2+hhalf*dq2;
                                vp  = (float)(1f/Math.sqrt(pxt*pxt+pzt*pzt));
                                s   = pxt*vp;
                                c   = pzt*vp;
                                ss  = s*s;
                                cc  = c*c;


                                /* velocities and derivatives at takeoff point */
                                vvv = vel2Interp(a11112,x0,z0);
                                a1111 = vvv.v;
                                da1111dx = vvv.vx;
                                da1111dz = vvv.vz;
                                dda1111dxdx = vvv.vxx;
                                dda1111dxdz = vvv.vxz;
                                dda1111dzdz = vvv.vzz;
                                da1111dn = da1111dx*c-da1111dz*s;
                                dda1111dndn = dda1111dxdx*cc-2.0f*dda1111dxdz*s*c+dda1111dzdz*ss;

                                vvv = vel2Interp(a33332,x0,z0);
                                a3333 = vvv.v;
                                da3333dx = vvv.vx;
                                da3333dz = vvv.vz;
                                dda3333dxdx = vvv.vxx;
                                dda3333dxdz = vvv.vxz;
                                dda3333dzdz = vvv.vzz;
                                da3333dn = da3333dx*c-da3333dz*s;
                                dda3333dndn = dda3333dxdx*cc-2.0f*dda3333dxdz*s*c+dda3333dzdz*ss;

                                vel2Interp(a11332,x0,z0);
                                a1133 = vvv.v;
                                da1133dx = vvv.vx;
                                da1133dz = vvv.vz;
                                dda1133dxdx = vvv.vxx;
                                dda1133dxdz = vvv.vxz;
                                dda1133dzdz = vvv.vzz;
                                da1133dn = da1133dx*c-da1133dz*s;
                                dda1133dndn = dda1133dxdx*cc-2.0f*dda1133dxdz*s*c+dda1133dzdz*ss;

                                vvv = vel2Interp(a13132,x0,z0);
                                a1313 = vvv.v;
                                da1313dx = vvv.vx;
                                da1313dz = vvv.vz;
                                dda1313dxdx = vvv.vxx;
                                dda1313dxdz = vvv.vxz;
                                dda1313dzdz = vvv.vzz;
                                da1313dn = da1313dx*c-da1313dz*s;
                                dda1313dndn = dda1313dxdx*cc-2.0f*dda1313dxdz*s*c+dda1313dzdz*ss;

                                vel2Interp(a11132,x0,z0);
                                a1113 = vvv.v;
                                da1113dx = vvv.vx;
                                da1113dz = vvv.vz;
                                dda1113dxdx = vvv.vxx;
                                dda1113dxdz = vvv.vxz;
                                dda1113dzdz = vvv.vzz;
                                da1113dn = da1113dx*c-da1113dz*s;
                                dda1113dndn = dda1113dxdx*cc-2.0f*dda1113dxdz*s*c+dda1113dzdz*ss;

                                vvv = vel2Interp(a33132,x0,z0);
                                a3313 = vvv.v;
                                da3313dx = vvv.vx;
                                da3313dz = vvv.vz;
                                dda3313dxdx = vvv.vxx;
                                dda3313dxdz = vvv.vxz;
                                dda3313dzdz = vvv.vzz;
                                da3313dn = da3313dx*c-da3313dz*s;
                                dda3313dndn = dda3313dxdx*cc-2.0f*dda3313dxdz*s*c+dda3313dzdz*ss;


                                /* step 2 of 4th-order Runge-Kutta */
                                /* step 2 of 4th-order Runge-Kutta */
                                px2   = pxt*pxt;
                                pz2   = pzt*pzt;
                                pxz   = pxt*pzt;
                                /*anisotropy parameters*/
                                gamma11 = a1111*px2+ a1313*pz2 +2*a1113*pxz;
                                gamma33 = a3333*pz2 + a1313*px2+2*a3313*pxz;
                                gamma13 = (a1133+a1313)*pxz+ a1113*px2+ a3313*pz2;
                                den     = 1/(gamma11+gamma33-2);
                                g11     = (gamma33-1)*den;
                                g33     = (gamma11-1)*den;
                                g13     = -gamma13*den;
                                sxfactor = da1111dx*px2*g11+da3333dx*pz2*g33+
                                        2*(da1133dx+da1313dx)*pxz*g13+da1313dx*(px2*g33+pz2*g11)+
                                        2*da3313dx*(pz2*g13+pxz*g33)+2*da1113dx*(pxz*g11+px2*g13);
                                szfactor = da1111dz*px2*g11+da3333dz*pz2*g33+
                                        2*(da1133dz+da1313dz)*pxz*g13+da1313dz*(px2*g33+pz2*g11)+
                                        2*da3313dz*(pz2*g13+pxz*g33)+2*da1113dz*(pxz*g11+px2*g13);
                                snfact = sxfactor*c-szfactor*s;
                                /*computing ray velocities and derivatives*/
                                dxt =  (a1111*pxt*g11+(a1133+a1313)*pzt*g13+a3313*pzt*g33
                                        +a1113*(pzt*g11+2*pxt*g13)+a1313*g33*pxt);
                                dzt =  (a3333*pzt*g33+(a1133+a1313)*pxt*g13+a1113*pxt*g11
                                        +a3313*(pxt*g33+2*pzt*g13)+a1313*g11*pzt);
                                dpxt = -0.5f*sxfactor;
                                dpzt = -0.5f*szfactor;


                                dgamma11dpx = 2*a1111*pxt+2*a1113*pzt;
                                dgamma11dpz = 2*a1313*pzt+2*a1113*pxt;
                                dgamma33dpx = 2*a1313*pxt+2*a3313*pzt;
                                dgamma33dpz = 2*a3333*pzt+2*a3313*pxt;
                                dgamma13dpx= (a1133+a1313)*pzt+2*a1113*pxt;
                                dgamma13dpz= (a1133+a1313)*pxt+2*a3313*pzt;
                                dgamma11dn = da1111dn*px2+ da1313dn*pz2 +2*da1113dn*pxz;
                                dgamma33dn = da3333dn*pz2 + da1313dn*px2+2*da3313dn*pxz;
                                dgamma13dn = (da1133dn+da1313dn)*pxz+ da1113dn*px2+ da3313dn*pz2;
                                dg11dpx = -(gamma33-1)*(dgamma11dpx+dgamma33dpx-4*dxt)*den*den+
                                        (dgamma33dpx-2*dxt)*den;
                                dg11dpz = -(gamma33-1)*(dgamma11dpz+dgamma33dpz-4*dzt)*den*den+
                                        (dgamma33dpz-2*dzt)*den;
                                dg33dpx = -(gamma11-1)*(dgamma11dpx+dgamma33dpx-4*dxt)*den*den+
                                        (dgamma11dpx-2*dxt)*den;
                                dg33dpz = -(gamma11-1)*(dgamma11dpz+dgamma33dpz-4*dzt)*den*den+
                                        (dgamma11dpz-2*dzt)*den;
                                dg13dpx = gamma13*(dgamma11dpx+dgamma33dpx-4*dxt)*den*den-
                                        dgamma13dpx*den;
                                dg13dpz = gamma13*(dgamma11dpz+dgamma33dpz-4*dzt)*den*den-
                                        dgamma13dpz*den;
                                dg11dn = -(gamma33-1)*(dgamma11dn+dgamma33dn-2*snfact)*den*den+
                                        (dgamma33dn-snfact)*den;
                                dg33dn = -(gamma11-1)*(dgamma11dn+dgamma33dn-2*snfact)*den*den+
                                        (dgamma11dn-snfact)*den;
                                dg13dn = gamma13*(dgamma11dn+dgamma33dn-2*snfact)*den*den-
                                        dgamma13dn*den;
                                ddxdpx=   a1111*pxt*dg11dpx+(a1133+a1313)*pzt*dg13dpx+
                                        a3313*pzt*dg33dpx+a1113*(pzt*dg11dpx+2*pxt*dg13dpx)
                                        +a1313*dg33dpx*pxt;
                                ddzdpz= a3333*pzt*dg33dpz+(a1133+a1313)*pxt*dg13dpz+
                                        a1113*pxt*dg11dpz+a3313*(pxt*dg33dpz+2*pzt*dg13dpz)+
                                        a1313*dg11dpz*pzt;
                                ddxdpz= a1111*pxt*dg11dpz+(a1133+a1313)*pzt*dg13dpz+
                                        a3313*pzt*dg33dpz+a1113*(pzt*dg11dpz+2*pxt*dg13dpz)+
                                        a1313*dg33dpz*pxt;
                                dsnfactordn = da1111dn*px2*dg11dn+da3333dn*pz2*dg33dn+
                                        2*(da1133dn+da1313dn)*pxz*dg13dn+da1313dn*(px2*dg33dn+pz2*dg11dn)+
                                        2*da3313dn*(pz2*dg13dn+pxz*dg33dn)+2*da1113dn*(pxz*dg11dn+px2*dg13dn);
                                ddxdn =  (a1111*pxt*dg11dn+(a1133+a1313)*pzt*dg13dn+a3313*pzt*dg33dn
                                        +a1113*(pzt*dg11dn+2*pxt*dg13dn)+a1313*dg33dn*pxt);
                                ddzdn =  (a3333*pzt*dg33dn+(a1133+a1313)*pxt*dg13dn+a1113*pxt*dg11dn
                                        +a3313*(pxt*dg33dn+2*pzt*dg13dn)+a1313*dg11dn*pzt);
		
                                dcdp1  = a1111*g11+a1313*g33+2*a1113*g13+ddxdpx-dxt*dxt;
                                dcdp3  = a3333*g33+a1313*g11+2*a3313*g13+ddzdpz-dzt*dzt;
                                dcdp13 = a1133*g13+a1313*g13+a1113*g11+a3313*g33+ddxdpz-dxt*dzt;
                                ddcdqq = dcdp1*cc-2.0f*dcdp13*s*c+dcdp3*ss;
                                dxdn   =  (da1111dn*pxt*g11+(da1133dn+da1313dn)*pzt*g13+
                                        da3313dn*pzt*g33+da1113dn*(pzt*g11+2*pxt*g13)+
                                        da1313dn*g33*pxt);
                                dzdn   =  (da3333dn*pzt*g33+(da1133dn+da1313dn)*pxt*g13+
                                        da1113dn*pxt*g11+da3313dn*(pxt*g33+2*pzt*g13)+
                                        da1313dn*g11*pzt);
                                ddcdpn = dxdn*c-dzdn*s-.5f*dxt*sxfactor*cc+
                                        .5f*(dxt*szfactor+dzt*sxfactor)*s*c-.5f*dzt*szfactor*ss
                                        +ddxdn*c-ddzdn*s;
                                snfactor = dda1111dndn*px2*g11+dda3333dndn*pz2*g33+
                                        2*(dda1133dndn+dda1313dndn)*pxz*g13+
                                        dda1313dndn*(px2*g33+pz2*g11)+
                                        2*dda3313dndn*(pz2*g13+pxz*g33)+
                                        2*dda1113dndn*(pxz*g11+px2*g13);
                                ddcdnn = 0.5f*snfactor-.25f*sxfactor*sxfactor*cc+
                                        .5f*sxfactor*szfactor*s*c-.25f*szfactor*szfactor*ss
                                        +.5f*dsnfactordn;

                                dp1t = -ddcdnn*q1t-ddcdpn*p1t;
                                dq1t = ddcdqq*p1t+ddcdpn*q1t;
                                dp2t = -ddcdnn*q2t-ddcdpn*p2t;
                                dq2t = ddcdqq*p2t+ddcdpn*q2t;
                                xt = x+hhalf*dxt;
                                zt = z+hhalf*dzt;
                                pxt = px+hhalf*dpxt;
                                pzt = pz+hhalf*dpzt;
                                p1t = p1+hhalf*dp1t;
                                q1t = q1+hhalf*dq1t;
                                p2t = p2+hhalf*dp2t;
                                q2t = q2+hhalf*dq2t;
                                vp  = (float)(1f/Math.sqrt(pxt*pxt+pzt*pzt));
                                s   = pxt*vp;
                                c   = pzt*vp;
                                ss  = s*s;
                                cc  = c*c;
		

                                /* velocities and derivatives at takeoff point */
                                vvv = vel2Interp(a11112,x0,z0);
                                a1111 = vvv.v;
                                da1111dx = vvv.vx;
                                da1111dz = vvv.vz;
                                dda1111dxdx = vvv.vxx;
                                dda1111dxdz = vvv.vxz;
                                dda1111dzdz = vvv.vzz;
                                da1111dn = da1111dx*c-da1111dz*s;
                                dda1111dndn = dda1111dxdx*cc-2.0f*dda1111dxdz*s*c+dda1111dzdz*ss;

                                vvv = vel2Interp(a33332,x0,z0);
                                a3333 = vvv.v;
                                da3333dx = vvv.vx;
                                da3333dz = vvv.vz;
                                dda3333dxdx = vvv.vxx;
                                dda3333dxdz = vvv.vxz;
                                dda3333dzdz = vvv.vzz;
                                da3333dn = da3333dx*c-da3333dz*s;
                                dda3333dndn = dda3333dxdx*cc-2.0f*dda3333dxdz*s*c+dda3333dzdz*ss;

                                vel2Interp(a11332,x0,z0);
                                a1133 = vvv.v;
                                da1133dx = vvv.vx;
                                da1133dz = vvv.vz;
                                dda1133dxdx = vvv.vxx;
                                dda1133dxdz = vvv.vxz;
                                dda1133dzdz = vvv.vzz;
                                da1133dn = da1133dx*c-da1133dz*s;
                                dda1133dndn = dda1133dxdx*cc-2.0f*dda1133dxdz*s*c+dda1133dzdz*ss;

                                vvv = vel2Interp(a13132,x0,z0);
                                a1313 = vvv.v;
                                da1313dx = vvv.vx;
                                da1313dz = vvv.vz;
                                dda1313dxdx = vvv.vxx;
                                dda1313dxdz = vvv.vxz;
                                dda1313dzdz = vvv.vzz;
                                da1313dn = da1313dx*c-da1313dz*s;
                                dda1313dndn = dda1313dxdx*cc-2.0f*dda1313dxdz*s*c+dda1313dzdz*ss;

                                vel2Interp(a11132,x0,z0);
                                a1113 = vvv.v;
                                da1113dx = vvv.vx;
                                da1113dz = vvv.vz;
                                dda1113dxdx = vvv.vxx;
                                dda1113dxdz = vvv.vxz;
                                dda1113dzdz = vvv.vzz;
                                da1113dn = da1113dx*c-da1113dz*s;
                                dda1113dndn = dda1113dxdx*cc-2.0f*dda1113dxdz*s*c+dda1113dzdz*ss;

                                vvv = vel2Interp(a33132,x0,z0);
                                a3313 = vvv.v;
                                da3313dx = vvv.vx;
                                da3313dz = vvv.vz;
                                dda3313dxdx = vvv.vxx;
                                dda3313dxdz = vvv.vxz;
                                dda3313dzdz = vvv.vzz;
                                da3313dn = da3313dx*c-da3313dz*s;
                                dda3313dndn = dda3313dxdx*cc-2.0f*dda3313dxdz*s*c+dda3313dzdz*ss;


                                /* step 3 of 4th-order Runge-Kutta */
                                px2   = pxt*pxt;
                                pz2   = pzt*pzt;
                                pxz   = pxt*pzt;

                                /*anisotropy parameters*/
                                gamma11 = a1111*px2+ a1313*pz2 +2*a1113*pxz;
                                gamma33 = a3333*pz2 + a1313*px2+2*a3313*pxz;
                                gamma13 = (a1133+a1313)*pxz+ a1113*px2+ a3313*pz2;
                                den     = 1/(gamma11+gamma33-2);
                                g11     = (gamma33-1)*den;
                                g33     = (gamma11-1)*den;
                                g13     = -gamma13*den;
                                sxfactor = da1111dx*px2*g11+da3333dx*pz2*g33+
                                        2*(da1133dx+da1313dx)*pxz*g13+da1313dx*(px2*g33+pz2*g11)+
                                        2*da3313dx*(pz2*g13+pxz*g33)+2*da1113dx*(pxz*g11+px2*g13);
                                szfactor = da1111dz*px2*g11+da3333dz*pz2*g33+
                                        2*(da1133dz+da1313dz)*pxz*g13+da1313dz*(px2*g33+pz2*g11)+
                                        2*da3313dz*(pz2*g13+pxz*g33)+2*da1113dz*(pxz*g11+px2*g13);
                                snfact = sxfactor*c-szfactor*s;

		
                                /*computing ray velocities and derivatives*/
                                dxm =  (a1111*pxt*g11+(a1133+a1313)*pzt*g13+a3313*pzt*g33
                                        +a1113*(pzt*g11+2*pxt*g13)+a1313*g33*pxt);
                                dzm =  (a3333*pzt*g33+(a1133+a1313)*pxt*g13+a1113*pxt*g11
                                        +a3313*(pxt*g33+2*pzt*g13)+a1313*g11*pzt);
                                dpxm = -0.5f*sxfactor;
                                dpzm = -0.5f*szfactor;

                                dgamma11dpx = 2*a1111*pxt+2*a1113*pzt;
                                dgamma11dpz = 2*a1313*pzt+2*a1113*pxt;
                                dgamma33dpx = 2*a1313*pxt+2*a3313*pzt;
                                dgamma33dpz = 2*a3333*pzt+2*a3313*pxt;
                                dgamma13dpx= (a1133+a1313)*pzt+2*a1113*pxt;
                                dgamma13dpz= (a1133+a1313)*pxt+2*a3313*pzt;
                                dgamma11dn = da1111dn*px2+ da1313dn*pz2 +2*da1113dn*pxz;
                                dgamma33dn = da3333dn*pz2 + da1313dn*px2+2*da3313dn*pxz;
                                dgamma13dn = (da1133dn+da1313dn)*pxz+ da1113dn*px2+ da3313dn*pz2;
                                dg11dpx = -(gamma33-1)*(dgamma11dpx+dgamma33dpx-4*dxm)*den*den+
                                        (dgamma33dpx-2*dxm)*den;
                                dg11dpz = -(gamma33-1)*(dgamma11dpz+dgamma33dpz-4*dzm)*den*den+
                                        (dgamma33dpz-2*dzm)*den;
                                dg33dpx = -(gamma11-1)*(dgamma11dpx+dgamma33dpx-4*dxm)*den*den+
                                        (dgamma11dpx-2*dxm)*den;
                                dg33dpz = -(gamma11-1)*(dgamma11dpz+dgamma33dpz-4*dzm)*den*den+
                                        (dgamma11dpz-2*dzm)*den;
                                dg13dpx = gamma13*(dgamma11dpx+dgamma33dpx-4*dxm)*den*den-
                                        dgamma13dpx*den;
                                dg13dpz = gamma13*(dgamma11dpz+dgamma33dpz-4*dzm)*den*den-
                                        dgamma13dpz*den;
                                dg11dn = -(gamma33-1)*(dgamma11dn+dgamma33dn-2*snfact)*den*den+
                                        (dgamma33dn-snfact)*den;
                                dg33dn = -(gamma11-1)*(dgamma11dn+dgamma33dn-2*snfact)*den*den+
                                        (dgamma11dn-snfact)*den;
                                dg13dn = gamma13*(dgamma11dn+dgamma33dn-2*snfact)*den*den-
                                        dgamma13dn*den;
                                ddxdpx=   a1111*pxt*dg11dpx+(a1133+a1313)*pzt*dg13dpx+
                                        a3313*pzt*dg33dpx+a1113*(pzt*dg11dpx+2*pxt*dg13dpx)
                                        +a1313*dg33dpx*pxt;
                                ddzdpz= a3333*pzt*dg33dpz+(a1133+a1313)*pxt*dg13dpz+
                                        a1113*pxt*dg11dpz+a3313*(pxt*dg33dpz+2*pzt*dg13dpz)+
                                        a1313*dg11dpz*pzt;
                                ddxdpz= a1111*pxt*dg11dpz+(a1133+a1313)*pzt*dg13dpz+
                                        a3313*pzt*dg33dpz+a1113*(pzt*dg11dpz+2*pxt*dg13dpz)+
                                        a1313*dg33dpz*pxt;
                                dsnfactordn = da1111dn*px2*dg11dn+da3333dn*pz2*dg33dn+
                                        2*(da1133dn+da1313dn)*pxz*dg13dn+da1313dn*(px2*dg33dn+pz2*dg11dn)+
                                        2*da3313dn*(pz2*dg13dn+pxz*dg33dn)+2*da1113dn*(pxz*dg11dn+px2*dg13dn);
                                ddxdn =  (a1111*pxt*dg11dn+(a1133+a1313)*pzt*dg13dn+a3313*pzt*dg33dn
                                        +a1113*(pzt*dg11dn+2*pxt*dg13dn)+a1313*dg33dn*pxt);
                                ddzdn =  (a3333*pzt*dg33dn+(a1133+a1313)*pxt*dg13dn+a1113*pxt*dg11dn
                                        +a3313*(pxt*dg33dn+2*pzt*dg13dn)+a1313*dg11dn*pzt);

		
                                dcdp1  = a1111*g11+a1313*g33+2*a1113*g13+ddxdpx-dxm*dxm;
                                dcdp3  = a3333*g33+a1313*g11+2*a3313*g13+ddzdpz-dzm*dzm;
                                dcdp13 = a1133*g13+a1313*g13+a1113*g11+a3313*g33+ddxdpz-dxm*dzm;
                                ddcdqq = dcdp1*cc-2.0f*dcdp13*s*c+dcdp3*ss;
                                dxdn   =  (da1111dn*pxt*g11+(da1133dn+da1313dn)*pzt*g13+
                                        da3313dn*pzt*g33+da1113dn*(pzt*g11+2*pxt*g13)+
                                        da1313dn*g33*pxt);
                                dzdn   =  (da3333dn*pzt*g33+(da1133dn+da1313dn)*pxt*g13+
                                        da1113dn*pxt*g11+da3313dn*(pxt*g33+2*pzt*g13)+
                                        da1313dn*g11*pzt);
                                ddcdpn = dxdn*c-dzdn*s-.5f*dxm*sxfactor*cc+
                                        .5f*(dxm*szfactor+dzm*sxfactor)*s*c-.5f*dzm*szfactor*ss
                                        +ddxdn*c-ddzdn*s;
                                snfactor = dda1111dndn*px2*g11+dda3333dndn*pz2*g33+
                                        2*(dda1133dndn+dda1313dndn)*pxz*g13+
                                        dda1313dndn*(px2*g33+pz2*g11)+
                                        2*dda3313dndn*(pz2*g13+pxz*g33)+
                                        2*dda1113dndn*(pxz*g11+px2*g13);
                                ddcdnn = 0.5f*snfactor-.25f*sxfactor*sxfactor*cc+
                                        .5f*sxfactor*szfactor*s*c-.25f*szfactor*szfactor*ss
                                        +.5f*dsnfactordn;

                                dp1m = -ddcdnn*q1t-ddcdpn*p1t;
                                dq1m = ddcdqq*p1t+ddcdpn*q1t;
                                dp2m = -ddcdnn*q2t-ddcdpn*p2t;
                                dq2m = ddcdqq*p2t+ddcdpn*q2t;
                                xt = x+hhalf*dxn;
                                zt = z+hhalf*dzn;
                                pxt = px+h*dpxm;
                                pzt = pz+h*dpzm;
                                p1t = p1+h*dp1m;
                                q1t = q1+h*dq1m;
                                p2t = p2+h*dp2m;
                                q2t = q2+h*dq2m;
                                dxm += dxt;
                                dzm += dzt;
                                dpxm += dpxt;
                                dpzm += dpzt;
                                dp1m += dp1t;
                                dq1m += dq1t;
                                dp2m += dp2t;
                                dq2m += dq2t;
                                vp  = (float)(1f/Math.sqrt(pxt*pxt+pzt*pzt));
                                s   = pxt*vp;
                                c   = pzt*vp;
                                ss  = s*s;
                                cc  = c*c;
		

                                /* velocities and derivatives at takeoff point */
                                vvv = vel2Interp(a11112,x0,z0);
                                a1111 = vvv.v;
                                da1111dx = vvv.vx;
                                da1111dz = vvv.vz;
                                dda1111dxdx = vvv.vxx;
                                dda1111dxdz = vvv.vxz;
                                dda1111dzdz = vvv.vzz;
                                da1111dn = da1111dx*c-da1111dz*s;
                                dda1111dndn = dda1111dxdx*cc-2.0f*dda1111dxdz*s*c+dda1111dzdz*ss;

                                vvv = vel2Interp(a33332,x0,z0);
                                a3333 = vvv.v;
                                da3333dx = vvv.vx;
                                da3333dz = vvv.vz;
                                dda3333dxdx = vvv.vxx;
                                dda3333dxdz = vvv.vxz;
                                dda3333dzdz = vvv.vzz;
                                da3333dn = da3333dx*c-da3333dz*s;
                                dda3333dndn = dda3333dxdx*cc-2.0f*dda3333dxdz*s*c+dda3333dzdz*ss;

                                vel2Interp(a11332,x0,z0);
                                a1133 = vvv.v;
                                da1133dx = vvv.vx;
                                da1133dz = vvv.vz;
                                dda1133dxdx = vvv.vxx;
                                dda1133dxdz = vvv.vxz;
                                dda1133dzdz = vvv.vzz;
                                da1133dn = da1133dx*c-da1133dz*s;
                                dda1133dndn = dda1133dxdx*cc-2.0f*dda1133dxdz*s*c+dda1133dzdz*ss;

                                vvv = vel2Interp(a13132,x0,z0);
                                a1313 = vvv.v;
                                da1313dx = vvv.vx;
                                da1313dz = vvv.vz;
                                dda1313dxdx = vvv.vxx;
                                dda1313dxdz = vvv.vxz;
                                dda1313dzdz = vvv.vzz;
                                da1313dn = da1313dx*c-da1313dz*s;
                                dda1313dndn = dda1313dxdx*cc-2.0f*dda1313dxdz*s*c+dda1313dzdz*ss;

                                vel2Interp(a11132,x0,z0);
                                a1113 = vvv.v;
                                da1113dx = vvv.vx;
                                da1113dz = vvv.vz;
                                dda1113dxdx = vvv.vxx;
                                dda1113dxdz = vvv.vxz;
                                dda1113dzdz = vvv.vzz;
                                da1113dn = da1113dx*c-da1113dz*s;
                                dda1113dndn = dda1113dxdx*cc-2.0f*dda1113dxdz*s*c+dda1113dzdz*ss;

                                vvv = vel2Interp(a33132,x0,z0);
                                a3313 = vvv.v;
                                da3313dx = vvv.vx;
                                da3313dz = vvv.vz;
                                dda3313dxdx = vvv.vxx;
                                dda3313dxdz = vvv.vxz;
                                dda3313dzdz = vvv.vzz;
                                da3313dn = da3313dx*c-da3313dz*s;
                                dda3313dndn = dda3313dxdx*cc-2.0f*dda3313dxdz*s*c+dda3313dzdz*ss;


                                /* step 4 of 4th-order Runge-Kutta */
                                /* step 4 of 4th-order Runge-Kutta */
                                px2   = pxt*pxt;
                                pz2   = pzt*pzt;
                                pxz   = pxt*pzt;



                                /*anisotropy parameters*/
                                gamma11 = a1111*px2+ a1313*pz2 +2*a1113*pxz;
                                gamma33 = a3333*pz2 + a1313*px2+2*a3313*pxz;
                                gamma13 = (a1133+a1313)*pxz+ a1113*px2+ a3313*pz2;
                                den     = 1/(gamma11+gamma33-2);
                                g11     = (gamma33-1)*den;
                                g33     = (gamma11-1)*den;
                                g13     = -gamma13*den;
                                sxfactor = da1111dx*px2*g11+da3333dx*pz2*g33+
                                        2*(da1133dx+da1313dx)*pxz*g13+da1313dx*(px2*g33+pz2*g11)+
                                        2*da3313dx*(pz2*g13+pxz*g33)+2*da1113dx*(pxz*g11+px2*g13);
                                szfactor = da1111dz*px2*g11+da3333dz*pz2*g33+
                                        2*(da1133dz+da1313dz)*pxz*g13+da1313dz*(px2*g33+pz2*g11)+
                                        2*da3313dz*(pz2*g13+pxz*g33)+2*da1113dz*(pxz*g11+px2*g13);
                                snfact = sxfactor*c-szfactor*s;
		
                                /*computing ray velocities and derivatives*/
                                dxt =  (a1111*pxt*g11+(a1133+a1313)*pzt*g13+a3313*pzt*g33
                                        +a1113*(pzt*g11+2*pxt*g13)+a1313*g33*pxt);
                                dzt =  (a3333*pzt*g33+(a1133+a1313)*pxt*g13+a1113*pxt*g11
                                        +a3313*(pxt*g33+2*pzt*g13)+a1313*g11*pzt);
                                dpxt = -0.5f*sxfactor;
                                dpzt = -0.5f*szfactor;

                                dgamma11dpx = 2*a1111*pxt+2*a1113*pzt;
                                dgamma11dpz = 2*a1313*pzt+2*a1113*pxt;
                                dgamma33dpx = 2*a1313*pxt+2*a3313*pzt;
                                dgamma33dpz = 2*a3333*pzt+2*a3313*pxt;
                                dgamma13dpx= (a1133+a1313)*pzt+2*a1113*pxt;
                                dgamma13dpz= (a1133+a1313)*pxt+2*a3313*pzt;
                                dgamma11dn = da1111dn*px2+ da1313dn*pz2 +2*da1113dn*pxz;
                                dgamma33dn = da3333dn*pz2 + da1313dn*px2+2*da3313dn*pxz;
                                dgamma13dn = (da1133dn+da1313dn)*pxz+ da1113dn*px2+ da3313dn*pz2;
                                dg11dpx = -(gamma33-1)*(dgamma11dpx+dgamma33dpx-4*dxt)*den*den+
                                        (dgamma33dpx-2*dxt)*den;
                                dg11dpz = -(gamma33-1)*(dgamma11dpz+dgamma33dpz-4*dzt)*den*den+
                                        (dgamma33dpz-2*dzt)*den;
                                dg33dpx = -(gamma11-1)*(dgamma11dpx+dgamma33dpx-4*dxt)*den*den+
                                        (dgamma11dpx-2*dxt)*den;
                                dg33dpz = -(gamma11-1)*(dgamma11dpz+dgamma33dpz-4*dzt)*den*den+
                                        (dgamma11dpz-2*dzt)*den;
                                dg13dpx = gamma13*(dgamma11dpx+dgamma33dpx-4*dxt)*den*den-
                                        dgamma13dpx*den;
                                dg13dpz = gamma13*(dgamma11dpz+dgamma33dpz-4*dzt)*den*den-
                                        dgamma13dpz*den;
                                dg11dn = -(gamma33-1)*(dgamma11dn+dgamma33dn-2*snfact)*den*den+
                                        (dgamma33dn-snfact)*den;
                                dg33dn = -(gamma11-1)*(dgamma11dn+dgamma33dn-2*snfact)*den*den+
                                        (dgamma11dn-snfact)*den;
                                dg13dn = gamma13*(dgamma11dn+dgamma33dn-2*snfact)*den*den-
                                        dgamma13dn*den;
                                ddxdpx=   a1111*pxt*dg11dpx+(a1133+a1313)*pzt*dg13dpx+
                                        a3313*pzt*dg33dpx+a1113*(pzt*dg11dpx+2*pxt*dg13dpx)
                                        +a1313*dg33dpx*pxt;
                                ddzdpz= a3333*pzt*dg33dpz+(a1133+a1313)*pxt*dg13dpz+
                                        a1113*pxt*dg11dpz+a3313*(pxt*dg33dpz+2*pzt*dg13dpz)+
                                        a1313*dg11dpz*pzt;
                                ddxdpz= a1111*pxt*dg11dpz+(a1133+a1313)*pzt*dg13dpz+
                                        a3313*pzt*dg33dpz+a1113*(pzt*dg11dpz+2*pxt*dg13dpz)+
                                        a1313*dg33dpz*pxt;
                                dsnfactordn = da1111dn*px2*dg11dn+da3333dn*pz2*dg33dn+
                                        2*(da1133dn+da1313dn)*pxz*dg13dn+da1313dn*(px2*dg33dn+pz2*dg11dn)+
                                        2*da3313dn*(pz2*dg13dn+pxz*dg33dn)+2*da1113dn*(pxz*dg11dn+px2*dg13dn);
                                ddxdn =  (a1111*pxt*dg11dn+(a1133+a1313)*pzt*dg13dn+a3313*pzt*dg33dn
                                        +a1113*(pzt*dg11dn+2*pxt*dg13dn)+a1313*dg33dn*pxt);
                                ddzdn =  (a3333*pzt*dg33dn+(a1133+a1313)*pxt*dg13dn+a1113*pxt*dg11dn
                                        +a3313*(pxt*dg33dn+2*pzt*dg13dn)+a1313*dg11dn*pzt);

		
                                dcdp1  = a1111*g11+a1313*g33+2*a1113*g13+ddxdpx-dxt*dxt;
                                dcdp3  = a3333*g33+a1313*g11+2*a3313*g13+ddzdpz-dzt*dzt;
                                dcdp13 = a1133*g13+a1313*g13+a1113*g11+a3313*g33+ddxdpz-dxt*dzt;
                                ddcdqq = dcdp1*cc-2.0f*dcdp13*s*c+dcdp3*ss;
                                dxdn   =  (da1111dn*pxt*g11+(da1133dn+da1313dn)*pzt*g13+
                                        da3313dn*pzt*g33+da1113dn*(pzt*g11+2*pxt*g13)+
                                        da1313dn*g33*pxt);
                                dzdn   =  (da3333dn*pzt*g33+(da1133dn+da1313dn)*pxt*g13+
                                        da1113dn*pxt*g11+da3313dn*(pxt*g33+2*pzt*g13)+
                                        da1313dn*g11*pzt);
                                ddcdpn = dxdn*c-dzdn*s-.5f*dxt*sxfactor*cc+
                                        .5f*(dxt*szfactor+dzt*sxfactor)*s*c-.5f*dzt*szfactor*ss
                                        +ddxdn*c-ddzdn*s;
                                snfactor = dda1111dndn*px2*g11+dda3333dndn*pz2*g33+
                                        2*(dda1133dndn+dda1313dndn)*pxz*g13+
                                        dda1313dndn*(px2*g33+pz2*g11)+
                                        2*dda3313dndn*(pz2*g13+pxz*g33)+
                                        2*dda1113dndn*(pxz*g11+px2*g13);
                                ddcdnn = 0.5f*snfactor-.25f*sxfactor*sxfactor*cc+
                                        .5f*sxfactor*szfactor*s*c-.25f*szfactor*szfactor*ss
                                        +.5f*dsnfactordn;

                                dp1t = -ddcdnn*q1t-ddcdpn*p1t;
                                dq1t = ddcdqq*p1t+ddcdpn*q1t;
                                dp2t = -ddcdnn*q2t-ddcdpn*p2t;
                                dq2t = ddcdqq*p2t+ddcdpn*q2t;
                                dxx  = hsixth*(dxn+dxt+2.0f*dxm);
                                dzz  = hsixth*(dzn+dzt+2.0f*dzm);
                                x += dxx;
                                z += dzz;
                                px += hsixth*(dpx+dpxt+2.0f*dpxm);
                                pz += hsixth*(dpz+dpzt+2.0f*dpzm);
                                p1 += hsixth*(dp1+dp1t+2.0f*dp1m);
                                q1 += hsixth*(dq1+dq1t+2.0f*dq1m);
                                p2 += hsixth*(dp2+dp2t+2.0f*dp2m);
                                q2 += hsixth*(dq2+dq2t+2.0f*dq2m);
                                vp  = (float)(1f/Math.sqrt(px*px+pz*pz));
                                s   = px*vp;
                                c   = pz*vp;
                                ss  = s*s;
                                cc  = c*c;
		


                                /* velocities and derivatives at takeoff point */
                                vvv = vel2Interp(a11112,x0,z0);
                                a1111 = vvv.v;
                                da1111dx = vvv.vx;
                                da1111dz = vvv.vz;
                                dda1111dxdx = vvv.vxx;
                                dda1111dxdz = vvv.vxz;
                                dda1111dzdz = vvv.vzz;
                                da1111dn = da1111dx*c-da1111dz*s;
                                dda1111dndn = dda1111dxdx*cc-2.0f*dda1111dxdz*s*c+dda1111dzdz*ss;

                                vvv = vel2Interp(a33332,x0,z0);
                                a3333 = vvv.v;
                                da3333dx = vvv.vx;
                                da3333dz = vvv.vz;
                                dda3333dxdx = vvv.vxx;
                                dda3333dxdz = vvv.vxz;
                                dda3333dzdz = vvv.vzz;
                                da3333dn = da3333dx*c-da3333dz*s;
                                dda3333dndn = dda3333dxdx*cc-2.0f*dda3333dxdz*s*c+dda3333dzdz*ss;

                                vel2Interp(a11332,x0,z0);
                                a1133 = vvv.v;
                                da1133dx = vvv.vx;
                                da1133dz = vvv.vz;
                                dda1133dxdx = vvv.vxx;
                                dda1133dxdz = vvv.vxz;
                                dda1133dzdz = vvv.vzz;
                                da1133dn = da1133dx*c-da1133dz*s;
                                dda1133dndn = dda1133dxdx*cc-2.0f*dda1133dxdz*s*c+dda1133dzdz*ss;

                                vvv = vel2Interp(a13132,x0,z0);
                                a1313 = vvv.v;
                                da1313dx = vvv.vx;
                                da1313dz = vvv.vz;
                                dda1313dxdx = vvv.vxx;
                                dda1313dxdz = vvv.vxz;
                                dda1313dzdz = vvv.vzz;
                                da1313dn = da1313dx*c-da1313dz*s;
                                dda1313dndn = dda1313dxdx*cc-2.0f*dda1313dxdz*s*c+dda1313dzdz*ss;

                                vel2Interp(a11132,x0,z0);
                                a1113 = vvv.v;
                                da1113dx = vvv.vx;
                                da1113dz = vvv.vz;
                                dda1113dxdx = vvv.vxx;
                                dda1113dxdz = vvv.vxz;
                                dda1113dzdz = vvv.vzz;
                                da1113dn = da1113dx*c-da1113dz*s;
                                dda1113dndn = dda1113dxdx*cc-2.0f*dda1113dxdz*s*c+dda1113dzdz*ss;

                                vvv = vel2Interp(a33132,x0,z0);
                                a3313 = vvv.v;
                                da3313dx = vvv.vx;
                                da3313dz = vvv.vz;
                                dda3313dxdx = vvv.vxx;
                                dda3313dxdz = vvv.vxz;
                                dda3313dzdz = vvv.vzz;
                                da3313dn = da3313dx*c-da3313dz*s;
                                dda3313dndn = dda3313dxdx*cc-2.0f*dda3313dxdz*s*c+dda3313dzdz*ss;



                                /* update time */
                                t  += dt;

                                /* update kmah index */
                                if ((q2<=0.0 && q2old>0.0) || (q2>=0.0 && q2old<0.0)) kmah++;

                                /* save ray parameters */
                                rs[it].t = t;
                                rs[it].x = x;
                                rs[it].z = z;
                                rs[it].c = c;
                                rs[it].s = s;
                                rs[it].q1 = q1;
                                rs[it].p1 = p1;
                                rs[it].q2 = q2;
                                rs[it].p2 = p2;
                                rs[it].kmah = kmah;
                                rs[it].v = vp;
                                rs[it].dvdx = .5f*da3333dx*vp/a3333;
                                rs[it].dvdz = .5f*da3333dz*vp/a3333;

                                //System.out.println("x = "+x+", z = "+z);



                }//it

                /* return ray */
                ray.nrs = it;
                ray.rs = rs;
                ray.nc = 0;
                ray.c = 0f;

                return ray;
        }//makeRay


        public static Vel2derivatives vel2Interp (Vel2 vel2, float x, float z) {
        /*a****************************************************************************
        Interpolation of a velocity function v(x,z) and its derivatives.
           速度插值
        *a*****************************************************************************
        Input:
        vel2		pointer to interpolator as returned by vel2Alloc()
        x		x coordinate at which to interpolate v(x,z) and derivatives
        z		z coordinate at which to interpolate v(x,z) and derivatives
        *a****************************************************************************
        Output:
        v		v(x,z)
        vx		dv/dx
        vz		dv/dz
        vxx		ddv/dxdx
        vxz		ddv/dxdz
        vzz		ddv/dzdz
        *a****************************************************************************/
                Vel2derivatives vvv = new Vel2derivatives();


                int nx=vel2.nx,nz=vel2.nz,nxm=vel2.nxm,nzm=vel2.nzm;
                float xs=vel2.xs,xb=vel2.xb,zs=vel2.zs,zb=vel2.zb;
                float[] sx = vel2.sx;
                float[] sz = vel2.sz;
                float[][] vu = vel2.vu;
                int i,jx,lx,mx,jz,lz,mz,jmx,jmz,mmx,mmz;
                float ax,bx,az,bz,sum;
                float[] px = new float[LTABLE];
                float[] pz = new float[LTABLE];
                float[] vd = new float[6];

                /* determine offsets into vu and interpolation coefficients */
                ax = xb+x*xs;
                jx = (int)ax;
                bx = ax-jx;
                lx = (int)( ((bx>=0.0f)?(bx*ntblm1+0.5f):((bx+1.0f)*ntblm1-0.5f)) *LTABLE);
                mx = ix+jx;
                az = zb+z*zs;
                jz = (int)az;
                bz = az-jz;
                lz = (int)( ((bz>=0.0f)?(bz*ntblm1+0.5f):((bz+1.0f)*ntblm1-0.5f)) *LTABLE);
                mz = iz+jz;

                /* if totally within input array, use fast method */
                if (mx>=0 && mx<=nxm && mz>=0 && mz<=nzm) {
                        for (i=0; i<6; ++i) {
                                px[0] = tbl[kx[i]][lx/LTABLE][0];
                                px[1] = tbl[kx[i]][lx/LTABLE][1];
                                px[2] = tbl[kx[i]][lx/LTABLE][2];
                                px[3] = tbl[kx[i]][lx/LTABLE][3];
                                pz[0] = tbl[kz[i]][lz/LTABLE][0];
                                pz[1] = tbl[kz[i]][lz/LTABLE][1];
                                pz[2] = tbl[kz[i]][lz/LTABLE][2];
                                pz[3] = tbl[kz[i]][lz/LTABLE][3];
                                vd[i] = sx[kx[i]]*sz[kz[i]]*(
                                        vu[mx][mz]*px[0]*pz[0]+
                                        vu[mx][mz+1]*px[0]*pz[1]+
                                        vu[mx][mz+2]*px[0]*pz[2]+
                                        vu[mx][mz+3]*px[0]*pz[3]+
                                        vu[mx+1][mz]*px[1]*pz[0]+
                                        vu[mx+1][mz+1]*px[1]*pz[1]+
                                        vu[mx+1][mz+2]*px[1]*pz[2]+
                                        vu[mx+1][mz+3]*px[1]*pz[3]+
                                        vu[mx+2][mz]*px[2]*pz[0]+
                                        vu[mx+2][mz+1]*px[2]*pz[1]+
                                        vu[mx+2][mz+2]*px[2]*pz[2]+
                                        vu[mx+2][mz+3]*px[2]*pz[3]+
                                        vu[mx+3][mz]*px[3]*pz[0]+
                                        vu[mx+3][mz+1]*px[3]*pz[1]+
                                        vu[mx+3][mz+2]*px[3]*pz[2]+
                                        vu[mx+3][mz+3]*px[3]*pz[3]);
                        }//for
		
                /* else handle end effects with constant extrapolation */
                } else {
                        for (i=0; i<6; ++i) {
                                px[0] = tbl[kx[i]][lx/LTABLE][0];
                                px[1] = tbl[kx[i]][lx/LTABLE][1];
                                px[2] = tbl[kx[i]][lx/LTABLE][2];
                                px[3] = tbl[kx[i]][lx/LTABLE][3];
                                pz[0] = tbl[kz[i]][lz/LTABLE][0];
                                pz[1] = tbl[kz[i]][lz/LTABLE][1];
                                pz[2] = tbl[kz[i]][lz/LTABLE][2];
                                pz[3] = tbl[kz[i]][lz/LTABLE][3];
                                for (jx=0,jmx=mx,sum=0.0f; jx<4; ++jx,++jmx) {
                                        mmx = jmx;
                                        if (mmx<0) mmx = 0;
                                        else if (mmx>=nx) mmx = nx-1;
                                        for (jz=0,jmz=mz; jz<4; ++jz,++jmz) {
                                                mmz = jmz;
                                                if (mmz<0) mmz = 0;
                                                else if (mmz>=nz) mmz = nz-1;
                                                sum += vu[mmx][mmz]*px[jx]*pz[jz];
                                        }//for jz
                                }//for jx
                                vd[i] = sx[kx[i]]*sz[kz[i]]*sum;
                        }//for
                }//if

                for(i=0;i<6;i++)System.out.println("vd["+i+"] = "+vd[i]);

                /* set output variables */
                vvv.v = vd[0];
                vvv.vx = vd[1];
                vvv.vz = vd[2];
                vvv.vxx = vd[3];
                vvv.vxz = vd[4];
                vvv.vzz = vd[5];

                return vvv;

        }//vel2Interp


        public static Vel2 vel2Alloc (int nx, float dx, float fx,
                         int nz, float dz, float fz, float[][]v){
        /*a****************************************************************************
        Allocate and initialize an interpolator for v(x,z) and its derivatives.
        *a*****************************************************************************
        Input:
        nx		number of x samples
        dx		x sampling interval
        fx		first x sample
        nz		number of z samples
        dz		z sampling interval
        fz		first z sample
        v		array[nx][nz] of uniformly sampled v(x,z)
        a*****************************************************************************
        Returned:	pointer to interpolator
        *a****************************************************************************/
                Vel2 vel2;
                /* allocate space */
                vel2 = new Vel2();
                /* set state variables used for interpolation 设置状态变量用于插值         */
                vel2.nx = nx;
                vel2.nxm = nx-LTABLE;
                vel2.xs = 1.0f/dx;
                vel2.xb = ltable-fx*vel2.xs;
                vel2.sx[0] = 1.0f;
                vel2.sx[1] = vel2.xs;
                vel2.sx[2] = vel2.xs*vel2.xs;
                vel2.nz = nz;
                vel2.nzm = nz-LTABLE;
                vel2.zs = 1.0f/dz;
                vel2.zb = ltable-fz*vel2.zs;
                vel2.sz[0] = 1.0f;
                vel2.sz[1] = vel2.zs;
                vel2.sz[2] = vel2.zs*vel2.zs;
                vel2.vu = v;
                /* if necessary, build interpolator coefficient tables 如果有必要,构建插值系数表          */
                if (!tabled) buildTables();
                return vel2;
        }//vel2Alloc

        /* hermite polynomials */
        static float h00 (float x) {return 2.0f*x*x*x-3.0f*x*x+1.0f;}
        static float h01 (float x) {return 6.0f*x*x-6.0f*x;}
        static float h02 (float x) {return 12.0f*x-6.0f;}
        static float h10 (float x) {return -2.0f*x*x*x+3.0f*x*x;}
        static float h11 (float x) {return -6.0f*x*x+6.0f*x;}
        static float h12 (float x) {return -12.0f*x+6.0f;}
        static float k00 (float x) {return x*x*x-2.0f*x*x+x;}
        static float k01 (float x) {return 3.0f*x*x-4.0f*x+1.0f;}
        static float k02 (float x) {return 6.0f*x-4.0f;}
        static float k10 (float x) {return x*x*x-x*x;}
        static float k11 (float x) {return 3.0f*x*x-2.0f*x;}
        static float k12 (float x) {return 6.0f*x-2.0f;}
        /* function to build interpolation tables */
        static void buildTables() {
                int i;
                float x;
                /* tabulate interpolator for 0th derivative */
                for (i=0; i<NTABLE; ++i) {
                        x = (float)i/(NTABLE-1.0f);
                        tbl[0][i][0] = -0.5f*k00(x);
                        tbl[0][i][1] = h00(x)-0.5f*k10(x);
                        tbl[0][i][2] = h10(x)+0.5f*k00(x);
                        tbl[0][i][3] = 0.5f*k10(x);
                        tbl[1][i][0] = -0.5f*k01(x);
                        tbl[1][i][1] = h01(x)-0.5f*k11(x);
                        tbl[1][i][2] = h11(x)+0.5f*k01(x);
                        tbl[1][i][3] = 0.5f*k11(x);
                        tbl[2][i][0] = -0.5f*k02(x);
                        tbl[2][i][1] = h02(x)-0.5f*k12(x);
                        tbl[2][i][2] = h12(x)+0.5f*k02(x);
                        tbl[2][i][3] = 0.5f*k12(x);
                }//for
	
                /* remember that tables have been built */
                tabled = true;
        }//buildTables


}//Toa class
