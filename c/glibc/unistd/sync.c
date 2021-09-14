#include <unistd.h>

/**
 *	sync函数只是将所有修改过的块缓冲区排入写队列，然后就返回，它并不等待实际写磁盘操作结束。
 *	通常称为update的系统守护进程会周期性地（一般每隔30秒）调用sync函数。
 *	这就保证了定期冲洗内核的块缓冲区。命令sync(1)也调用sync函数。
 */

//sync - schedule file system updates
void sync(void);

int main()
{
	sync();
	return 0;
}
