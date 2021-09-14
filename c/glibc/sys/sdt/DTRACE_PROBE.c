#include <sys/sdt.h>

//tplist -l ./a.out
int main() {
	DTRACE_PROBE("hello-usdt", "probe-main");
}

#if 0
$ readelf -n ./a.out
[...]
Displaying notes found at file offset 0x0000105c with length 0x00000048:
  所有者             Data size	Description
  stapsdt              0x00000033	NT_STAPSDT (SystemTap probe descriptors)
    Provider: "hello-usdt"
    Name: "probe-main"
    Location: 0x00000000004004f1, Base: 0x0000000000400590, Semaphore: 0x0000000000000000
    Arguments: 
#endif 
