#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>

#define RTE_EXEC_ENV_LINUX
	
	static int32_t
rdmsr(int msr, uint64_t *val)
{
#ifdef RTE_EXEC_ENV_LINUX
	int fd;
	int ret;

	fd = open("/dev/cpu/0/msr", O_RDONLY);
	if (fd < 0)
		return fd;

	ret = pread(fd, val, sizeof(uint64_t), msr);

	close(fd);

	return ret;
#else
	RTE_SET_USED(msr);
	RTE_SET_USED(val);

	return -1;
#endif
}

int main()
{
	int ret;
	uint64_t tsc_hz = 0;

	ret = rdmsr(0xCE, &tsc_hz);

	printf("ret = %d, tsc_hz = %ld\n",ret, tsc_hz);
}
