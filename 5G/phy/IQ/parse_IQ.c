#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define PI 3.141592653

FILE *iq_fp = NULL;

typedef struct __I {
	float r;
    float i;
} __attribute__((packed)) _I; 

#define __XY    20

#define __X (__XY*2+1)
#define __Y __X
#define _X_ ((__X-1)/2)
#define _Y_ ((__Y-1)/2)

#define __D 555


static unsigned long int IQ_panel[__X][__X] ={0};
unsigned long int IQ_cnt_max = 0;

void add_IQ(_I *i) 
{
    
    int x = ((int)(i->i * _X_ ))% (_X_+1);
    int y = ((int)(i->r * _Y_ ))% (_Y_+1);

    IQ_panel[x+_X_][y+_Y_] ++;
    
    if(IQ_cnt_max < IQ_panel[x+_X_][y+_Y_])
        if(x!=_X_ && y!=_Y_)
            IQ_cnt_max = IQ_panel[x+_X_][y+_Y_];
}

void show_IQ()
{
    FILE *fp = fopen("iq-out.txt", "w");
    int ix, iy;
    for(ix=0;ix<__X;ix++) {
        printf("%3d:", ix);
        for(iy=0;iy<__Y;iy++){
            if(IQ_panel[ix][iy]!=0){
//                if(IQ_panel[ix][iy] < (IQ_cnt_max/__D)) 
//                    printf("\033[31m \033[m");
//                else if(IQ_panel[ix][iy] >= (IQ_cnt_max*1/__D) && IQ_panel[ix][iy] < (IQ_cnt_max*2/__D)) 
//                    printf("\033[32m$\033[m");
//                else if(IQ_panel[ix][iy] >= (IQ_cnt_max*2/__D) && IQ_panel[ix][iy] < (IQ_cnt_max*3/__D)) 
//                    printf("\033[33m%\033[m");
//                else if(IQ_panel[ix][iy] >= (IQ_cnt_max*3/__D) && IQ_panel[ix][iy] < (IQ_cnt_max*4/__D)) 
//                    printf("\033[34m#\033[m");
//                else if(IQ_panel[ix][iy] >= (IQ_cnt_max*4/__D) && IQ_panel[ix][iy] < (IQ_cnt_max*5/__D)) 
//                    printf("\033[35m&\033[m");
//                else if(IQ_panel[ix][iy] >= (IQ_cnt_max*5/__D) && IQ_panel[ix][iy] < (IQ_cnt_max*6/__D)) 
//                    printf("\033[36m&\033[m");
//                else if(IQ_panel[ix][iy] >= (IQ_cnt_max*6/__D) && IQ_panel[ix][iy] < (IQ_cnt_max*7/__D)) 
//                    printf("\033[37m&\033[m");
//                else 
//                    printf("\033[38m@\033[m");
                printf("\033[34m#\033[m");
            } else {
                printf(" ");
            }
            if(IQ_panel[ix][iy]!=0)
            fprintf(fp, "%3d       %3d     %ld     \n", ix, iy, IQ_panel[ix][iy]);
        }
        printf("\n");
    }
        
    fclose(fp);
}

int main()
{
	iq_fp = fopen("iq-in.bin", "r");

    FILE *newfp = fopen("iq-out.bin", "w");
    
    unsigned long int cnt = 0;

	uint32_t i;
	while(fread(&i, 4, 1, iq_fp)) {	
        
		short _r = (short)(i>>16)&0xffff;
		short _i = (short)i&0xffff;
        _I I;
        I.r = _r*1.0/8192.8;
        I.i = _i*1.0/8192.8;
        
//        if(_r != 0.0) {
//            float arc = atanf(I.i /I.r)*360/(2*PI);
//            printf("(%6.3f+%6.3fi) cnt = %8ld arc = %7.3f\n", I.r, I.i , cnt, arc);
//
//        }
        fwrite(&i, 4, 1, newfp);
        add_IQ(&I);
        
        cnt++;

	}

    printf("Totla %ld \n", cnt);

    show_IQ();
    
    fclose(iq_fp);
    fclose(newfp);
	return 0;
}
