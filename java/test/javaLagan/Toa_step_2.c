//##################################################################
//##
//##          STEP2:       Raytrcing_2D  
//##
//##     Ps:  adapt to plane and fluctuate
//##          *Initial code comes from Doc.Qin Ning
//##                
//##                         plane :     2016.4.13   RongTao
//##                       fluctuate:    2016.4.14   RongTao
//##################################################################
#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
#include "/home/Toa/hc/cjbsegy.h"
#include "/home/Toa/hc/fft.c"
#include "/home/Toa/hc/alloc.c"
#include "/home/Toa/hc/complex.c"

void main()
{

   void step2_readpar(char fn1[],char fn2[],int *nx,int *nz,
                   float *dx,float *dz,float *s,int *nray0,int *nshot,
                   float *dangle,float *fangle);
   void step2_Raytracing_2D_plane(char fn1[],
                   int nx,int nz,float dx,float dz,float s,
                   int nray,int nshot,int nray0,int ngrid,float dangle,
                   float fangle); 
 

    int ngrid;
    int nx,nz,nray0,nshot,nray;
    float dx,dz,s,dangle,fangle;

    int i,j;
   
    char fn1[250],fn2[250];


       step2_readpar(fn1,fn2,&nx,&nz,&dx,&dz,&s,
                  &nray0,&nshot,&dangle,&fangle);

     nray=nray0*nshot;
     ngrid=(nx-1)*(nz-1);





        step2_Raytracing_2D_plane(fn1,nx,nz,dx,dz,s,nray,
                                 nshot,nray0,ngrid,dangle,fangle);

}


//*******************************************************************************//

//*******************************************************************************//
//===============================================================================//
//===============================================================================//
//==              Subroutine of raytrcing_2D plane surface                     ==//
//===============================================================================//
//==                          parameter instruction                            ==//
//===============================================================================//
//==                                        fn11:step2_raypath_x_z1.txt         ==//
//==                                        fn22:step2_igrid1.txt               ==//
//==                                        fn33:step2_length1.txt              ==//
//==                                        fn44:step2_row_ngrid_per_ray_add1.txt==//
//==                                        fn55:step2_kk_ngrid_all_ray1.txt     ==//
//==                                        fn66:step2_nj_raynum_per_grid1.txt  ==//
//==                                        v0_1:velocity model               ==//
//===============================================================================//
//===============================================================================//
void step2_Raytracing_2D_plane(char fn1[],int nx,
                   int nz,float dx,float dz,float s,
                   int nray,int nshot,int nray0,int ngrid,float dangle,
                   float fangle)
{
  void step2_determin_shotpoint(float *p_x0,float *p_z0,int nshot,float dx,
                                float dz,float *dip);
  void step2_cal_gridpoint(int *ip_lux,int *ip_ldx,int *ip_rux,int *ip_rdx,
                           int *ip_luz,int *ip_ldz,int *ip_ruz,int *ip_rdz,
                           float dx,float dz,float p_x,float p_z);
  void step2_cal_gridvel(float *v,float *l_x,float *l_z,float **v0_1,
                         int nx,int nz,float dx,float dz,
                         int ip_lux,int ip_ldx,int ip_rux,int ip_rdx,
                         int ip_luz,int ip_ldz,int ip_ruz,int ip_rdz);
  void step2_cal_path(float p_x,float p_z,float s,
                      float n_x,float n_z,float l_x,float l_z,
                      float *p_xend,float *p_zend,float *n_xnew,float *n_znew,
                      float *time,float v);
  void step2_determin_gridnum(float p_x,float p_z,int nx,float dx,float dz,
                              int *igrid);


     float pai=3.141592653;

     float p_x,p_z,n_x,n_z,l_x,l_z,n_x0,n_z0;
     float p_xend,p_zend;
     float n_xnew,n_znew;

     float *p_x0,*p_z0;
     float **v0_1;
     float *dip;

     int ix,iz,i,j,k;
     int ip_lux,ip_ldx,ip_rux,ip_rdx;
     int ip_luz,ip_ldz,ip_ruz,ip_rdz;
     int istep,igrid,iray,irayon,ishot;

     float angle;
     float beta,sita;

     float anglefircor,time,v;


     p_x0=alloc1float(nshot+1);        zero1float(p_x0,nshot+1);
     p_z0=alloc1float(nshot+1);        zero1float(p_z0,nshot+1);
     v0_1=alloc2float(nz+1,nx+1);     zero2float(v0_1,nz+1,nx+1);
     dip=alloc1float(nshot+1);         zero1float(dip,nshot+1);


     
     FILE *fpvel;

     if((fpvel=fopen(fn1,"rb"))==NULL)
     { printf("Open file error ! <%s>\n",fn1);exit(1);}

     for(ix=1;ix<=nx;ix++)
     {
        for(iz=1;iz<=nz;iz++)
        {
           fread(&v0_1[ix][iz],4L,1,fpvel);
        }
     }

     for(ix=1;ix<=nx;ix++)
        for(iz=1;iz<=nz;iz++)
            v0_1[ix][iz]=v0_1[ix][iz];



     step2_determin_shotpoint(p_x0,p_z0,nshot,dx,dz,dip);

    for(iray=1;iray<=nray;iray++)
    {

       irayon=iray%nray0;
  
       if(irayon==0)
       {
          ishot=(iray-irayon)/nray0;

          anglefircor=fangle+atan(dip[ishot])*180.0/pai;
          angle=anglefircor+(nray0-1)*dangle;            //** qin code

       }else
       {
          ishot=(iray-irayon)/nray0+1;

          anglefircor=fangle+atan(dip[ishot])*180.0/pai;
          angle=anglefircor+(irayon-1)*dangle;            //** qin code 
       }
       
       p_x=p_x0[ishot];
       p_z=p_z0[ishot];

       istep=0;

       angle=angle*pai/180.0;
 
       n_x0=cos(angle);
       n_z0=sin(angle);
       n_x=n_x0;
       n_z=n_z0;

       time=0.0;

       do
       {
         istep+=1;

         step2_cal_gridpoint(&ip_lux,&ip_ldx,&ip_rux,&ip_rdx,
                             &ip_luz,&ip_ldz,&ip_ruz,&ip_rdz,
                              dx,dz,p_x,p_z);

         step2_cal_gridvel(&v,&l_x,&l_z,v0_1,nx,nz,dx,dz,
                           ip_lux,ip_ldx,ip_rux,ip_rdx,
                           ip_luz,ip_ldz,ip_ruz,ip_rdz);

         step2_cal_path(p_x,p_z,s,n_x,n_z,l_x,l_z,
                       &p_xend,&p_zend,&n_xnew,&n_znew,&time,v);
    
         step2_determin_gridnum(p_x,p_z,nx,dx,dz,&igrid);
         

            p_x=p_xend;
	      p_z=p_zend;
	      n_x=n_xnew;
	      n_z=n_znew;

       }while((p_xend>0.0)&&(p_xend<((nx-1)*dx))&&
               (p_zend>0.0)&&(p_zend<(nz-1)*dz));
       
       //***********************//
       //** end of loop iray  **//   
       //***********************//
     }//loop iray end


}

//********************************************************************************//
void step2_determin_gridnum(float p_x,float p_z,int nx,float dx,float dz,
                              int *igrid)
{
  void determin_igrid(int ix,int iz,int nx,int *igrid);

    int igridxnum,igridznum;

    igridxnum=(int)(p_x/dx)+1;
    igridznum=(int)(p_z/dz)+1;
 
    determin_igrid(igridxnum,igridznum,nx,igrid);

}
//********************************************************************************//
void determin_igrid(int ix,int iz,int nx,int *igrid)
{
    if((iz==1)&&(ix==1))
       *igrid=1;
    else if((iz==1)&&(ix!=1))
       *igrid=ix-1;
    else if((iz!=1)&&(ix==1))
       *igrid=(iz-2)*(nx-1)+ix;
    else
       *igrid=(iz-2)*(nx-1)+(ix-1);
}
//********************************************************************************//
void step2_cal_path(float p_x,float p_z,float s,float n_x,float n_z,float l_x,float l_z,
                    float *p_xend,float *p_zend,float *n_xnew,float *n_znew,
                    float *time,float v)
{
     float dotmult_ln,dotmult_ll;

     dotmult_ln=l_x*n_x+l_z*n_z;
     dotmult_ll=l_x*l_x+l_z*l_z;
	   
      *p_xend=p_x+n_x*s*(1+dotmult_ln*0.5*s/v)-0.5*l_x*s*s/v
              -n_x*s*s*s*(dotmult_ll-dotmult_ln*dotmult_ln)/(6.0*v*v);

      *p_zend=p_z+n_z*s*(1+dotmult_ln*0.5*s/v)-0.5*l_z*s*s/v
              -n_z*s*s*s*(dotmult_ll-dotmult_ln*dotmult_ln)/(6.0*v*v);

      *n_xnew=n_x*(1+dotmult_ln*s/v)-l_x*s/v
              -n_x*s*s*(dotmult_ll-dotmult_ln*dotmult_ln)/(2.0*v*v);

      *n_znew=n_z*(1+dotmult_ln*s/v)-l_z*s/v
              -n_z*s*s*(dotmult_ll-dotmult_ln*dotmult_ln)/(2.0*v*v);

      *time=s/v*(1+s*s*(dotmult_ll+dotmult_ln*dotmult_ln)
            /(6*v*v)-dotmult_ln*s/(2*v));

}
//********************************************************************************//
void step2_cal_gridvel(float *v,float *l_x,float *l_z,float **v0,
                         int nx,int nz,float dx,float dz,
                         int ip_lux,int ip_ldx,int ip_rux,int ip_rdx,
                         int ip_luz,int ip_ldz,int ip_ruz,int ip_rdz)
{
     float l_x1,l_x2,l_z1,l_z2;

     l_x1=(v0[ip_rux][ip_ruz]-v0[ip_lux][ip_luz])/dx;
     l_x2=(v0[ip_rdx][ip_rdz]-v0[ip_ldx][ip_ldz])/dx;
     *l_x=(l_x1+l_x2)/2.0;

     l_z1=(v0[ip_ldx][ip_ldz]-v0[ip_lux][ip_luz])/dz;
     l_z2=(v0[ip_rdx][ip_rdz]-v0[ip_rux][ip_ruz])/dz;
     *l_z=(l_z1+l_z2)/2.0;

     *v=v0[ip_rux][ip_ruz]+v0[ip_lux][ip_luz]+v0[ip_rdx][ip_rdz]
           +v0[ip_ldx][ip_ldz];
     *v=*v/4.0; 
}
//********************************************************************************//
void step2_cal_gridpoint(int *ip_lux,int *ip_ldx,int *ip_rux,int *ip_rdx,
                           int *ip_luz,int *ip_ldz,int *ip_ruz,int *ip_rdz,
                           float dx,float dz,float p_x,float p_z)
//#################### use the pointer 
{
          *ip_lux=(int)(p_x/dx)+1;
	  *ip_luz=(int)(p_z/dz)+1;

	  *ip_ldx=*ip_lux;
	  *ip_ldz=*ip_luz+1;

	  *ip_rux=*ip_lux+1;
	  *ip_ruz=*ip_luz;

	  *ip_rdx=*ip_lux+1;
	  *ip_rdz=*ip_luz+1;
}
//********************************************************************************//
void step2_determin_shotpoint(float *p_x0,float *p_z0,int nshot,float dx,
                                float dz,float *dip)
{
      int *shotx,*shotz;
      int ishot;

      shotx=alloc1int(nshot+1);   zero1int(shotx,nshot+1);
      shotz=alloc1int(nshot+1);   zero1int(shotz,nshot+1);
      
      FILE *fp;
      if((fp=fopen("step1_shot_location1.txt","r"))==NULL)
      { printf("Open file error ! <step1_shot_location1.txt>\n");exit(1);}
     
      for(ishot=1;ishot<=nshot;ishot++)
         fscanf(fp,"%d%d%e\n",&shotx[ishot],&shotz[ishot],&dip[ishot]);

      

      for(ishot=1;ishot<=nshot;ishot++)
      {
         p_x0[ishot]=(shotx[ishot]-1)*dx*1.0;
         p_z0[ishot]=(shotz[ishot]-1)*dz*1.0;
      }

      free1int(shotx);
      free1int(shotz);
      //printf("------%d,%d,%e,%f,%f \n",shotx[1],shotz[1],dip[1],p_x0[1],p_z0[1]);
}
//********************************************************************************//
void step2_readpar(char fn1[],char fn2[],int *nx,int *nz,
                   float *dx,float *dz,float *s,int *nray0,int *nshot,
                   float *dangle,float *fangle)
{
      FILE *fp;
     char cc[250];

     if((fp=fopen("tomo-2.par","r"))==NULL)
      {printf("Open file error !\n");exit(1);}
      fscanf(fp,"%s%s\n",cc,fn1);
      fscanf(fp,"%s%s\n",cc,fn2);
      fscanf(fp,"%s%d\n",cc,nx);
      fscanf(fp,"%s%d\n",cc,nz);
      fscanf(fp,"%s%f\n",cc,dx);
      fscanf(fp,"%s%f\n",cc,dz);
      fscanf(fp,"%s%f\n",cc,s);
      fscanf(fp,"%s%d\n",cc,nray0);
      fscanf(fp,"%s%d\n",cc,nshot);
      fscanf(fp,"%s%f\n",cc,dangle);
      fscanf(fp,"%s%f\n",cc,fangle);

      fclose(fp);
}

