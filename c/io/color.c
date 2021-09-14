#include <stdio.h>


#define line "Hello World"


int main()
{
	int font[] = {0,1,2,3,4,5,6,7,8,9};
	int fcolor[] = {30,31,32,33,34,35,36,37};
	int bcolor[] = {40,41,42,43,44,45,46,47};

#define _size(arr) (sizeof(arr)/sizeof(arr[0])) 

	int i=0, j=1, k = 7;
	//for(i=0;i<_size(font);i++)
	//	for(j=0;j<_size(fcolor);j++)
			for(k=0;k<_size(bcolor);k++)
				printf("(%d;%d;%d):\033[%d;%d;%dm%s\033[m\n", 
						font[i],fcolor[j],bcolor[k],font[i],fcolor[j],bcolor[k], line);

}
