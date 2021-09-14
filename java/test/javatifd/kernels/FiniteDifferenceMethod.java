/*

finite difference method interface


  Copyright 2017  China University of Petroleum (East China)( Rong Tao )
    Email: 2386499836@qq.com

*/


package kernels;

interface FiniteDifferenceMethod{

        void FD(int sx, int sz, int mm, String FileOfSnap, int kt);
        void buffer(Wave wave);
        void addSource(Wave wave, Wavelet wavelet, int sx, int sz, int it);
        void absorbBndr(Wave wave,float qp);

}
