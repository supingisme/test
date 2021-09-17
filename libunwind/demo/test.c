#include <stdio.h>
#include <unistd.h>


void ddd(int n) {
	    if (n == 0) sleep(3000);
	    else ddd(n - 1);
}

void ccc() {
	    ddd(10);
}

void bbb() {
	    ccc();
}

void aaa() {
	    bbb();
}

int main() {
	    aaa();
	    return 0;
}
