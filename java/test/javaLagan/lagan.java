import java.io.*;

class laganRayTracing{

        private float pi = 3.141592653f;

        private int nx,nz,nshot,nray,ngrid;
        private float dx,dz,s,dangle,fangle;

        private float[] v0;

        private String raypath;

        laganRayTracing(){
                
                nx = nz = 301;
                dx = dz = 5f;
                s = 0.5f;
                fangle = 0f;
                dangle = 4f;
                nray = 2;
                ngrid = nx * nz;

                raypath = "raypath.txt";

                v0 = new float [ngrid];
                for(int i=0;i<ngrid;i++){
                        v0[i] = 2000.0f;
                        if(i>150*nz)v0[i] = 3000f;
                    }
          }
        public void makeRay()throws java.io.IOException{

                float p_x,p_z,n_x,n_z,l_x,l_z;
                float p_xend,p_zend;
                float n_xnew,n_znew;

                float p_x0, p_z0, dip;

                int ip_lux,ip_ldx,ip_rux,ip_rdx;
                int ip_luz,ip_ldz,ip_ruz,ip_rdz;
                int irayon,ishot;

                float angle,time,v;

                p_x0 = (nx-1)*dx / 3;
                p_z0 = (nz-1)*dz / 2;

                p_x = p_x0;
                p_z = p_z0;

                Writer rayfp = new FileWriter(raypath);

                for(int iray = 0; iray < nray; iray++){

                        p_x = p_x0;
                        p_z = p_z0;

                        angle = fangle + iray*dangle;
                        angle = angle*pi/180.0f;
        
                        //System.out.println(angle);

                        n_x = (float)Math.cos(angle);
                        n_z = (float)Math.sin(angle);

                        time = 0.0f;


                        do{
                                /* cal_gridpoint */
                                ip_lux = (int)(p_x/dx);
                                ip_luz = (int)(p_z/dz);

                                ip_ldx = ip_lux;
                                ip_ldz = ip_luz+1;

                                ip_rux = ip_lux+1;
                                ip_ruz = ip_luz;

                                ip_rdx = ip_lux+1;
                                ip_rdz = ip_luz+1;


                                /* cal_gridvel */
                                float l_x1 = (v0[ip_rux*nz + ip_ruz]-v0[ip_lux*nz + ip_luz])/dx;
                                float l_x2 = (v0[ip_rdx*nz + ip_rdz]-v0[ip_ldx*nz + ip_ldz])/dx;
                                l_x = ( l_x1+l_x2 ) / 2.0f;

                                float l_z1=(v0[ip_ldx*nz + ip_ldz]-v0[ip_lux*nz + ip_luz])/dz;
                                float l_z2=(v0[ip_rdx*nz + ip_rdz]-v0[ip_rux*nz + ip_ruz])/dz;
                                l_z=(l_z1+l_z2)/2.0f;

                                v=v0[ip_rux*nz + ip_ruz]+v0[ip_lux*nz + ip_luz]+v0[ip_rdx*nz + ip_rdz]
                                        +v0[ip_ldx*nz + ip_ldz];
                                v=v/4.0f;

                                //System.out.println(v);

                                /* cal_path */
                                float dotmult_ln=l_x*n_x+l_z*n_z;
                                float dotmult_ll=l_x*l_x+l_z*l_z;
                                p_xend=p_x+n_x*s*(1f+dotmult_ln*0.5f*s/v)-0.5f*l_x*s*s/v
                                        -n_x*s*s*s*(dotmult_ll-dotmult_ln*dotmult_ln)/(6.0f*v*v);

                                p_zend=p_z+n_z*s*(1f+dotmult_ln*0.5f*s/v)-0.5f*l_z*s*s/v
                                        -n_z*s*s*s*(dotmult_ll-dotmult_ln*dotmult_ln)/(6.0f*v*v);

                                n_xnew=n_x*(1f+dotmult_ln*s/v)-l_x*s/v
                                        -n_x*s*s*(dotmult_ll-dotmult_ln*dotmult_ln)/(2.0f*v*v);

                                n_znew=n_z*(1f+dotmult_ln*s/v)-l_z*s/v
                                        -n_z*s*s*(dotmult_ll-dotmult_ln*dotmult_ln)/(2.0f*v*v);

                                time+=s/v*(1f+s*s*(dotmult_ll+dotmult_ln*dotmult_ln)
                                        /(6f*v*v)-dotmult_ln*s/(2f*v));

                                /* buffer */
                                p_x = p_xend;
                                p_z = p_zend;
                                n_x = n_xnew;
                                n_z = n_znew;

                                rayfp.write(p_x+"         "+p_z+"        \n");
                                //System.out.println(p_x+"         "+p_z+"        ");
                        
                        }while((p_xend>=0.0f)&&(p_xend<((nx-1f)*dx))&&(p_zend>=0.0f)&&(p_zend<(nz-1f)*dz));

                        rayfp.write("-999999.9      -999999.9   \n");
                    }
                rayfp.close();
          }

        public static void main(String[]args)throws java.io.IOException{
        
                laganRayTracing l = new laganRayTracing();
                l.makeRay();
          }
}
