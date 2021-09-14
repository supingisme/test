#include <stdio.h>

#define __OMDU_CELL_RELY_ON_OK 0x7f
#define CELL_RELY_OK(all_rely)  (((all_rely&__OMDU_CELL_RELY_ON_OK)-__OMDU_CELL_RELY_ON_OK)==0)
//error，我现在还不想看，2019.11.22


int main()
{
	int all = 0x0f0f;
	int bit = 0x0ff0;

	printf("%x\n", 0xffff&bit);
	printf("%x\n", all&(~bit));


	int i = 0x7a;
	printf("%0#8x, %0#8x\n",i&__OMDU_CELL_RELY_ON_OK-__OMDU_CELL_RELY_ON_OK, CELL_RELY_OK(i));

	for(i=1;i<0xff;i+=1)
	{
		if(CELL_RELY_OK(i))
		{
			printf("%0#4x is OK\n", i);
		}
	}
}
