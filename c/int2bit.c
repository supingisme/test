#include <stdio.h>

#define Int_to_BitStr(nbits, i) \
	({\
		char __bitstr[nbits+1] = {0};\
		int __i = 0;\
		for(__i=0;__i<nbits;__i++) {\
			__bitstr[nbits-1-__i] = i&(1<<__i)?'1':'0';\
		}\
		__bitstr;\
	 })

int main()
{
	int i = 0x00f1;
	printf("%d,%x,%s\n", i,i,Int_to_BitStr(7, i));
}
