/*
2017/7/10


the boundary 

  Copyright 2017  China University of Petroleum (East China)( Rong Tao )
    Email: 2386499836@qq.com
*/

package kernels;

public class ttiPadModel extends vtiPadModel{

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
