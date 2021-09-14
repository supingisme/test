/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 09月 19日 星期四 08:43:11 CST. */


/**
 *	On most operating systems, when you write to a file, the data is not immediately written to disk.
 *	Instead, the operating system caches the written data in a memory buffer, to reduce the number of
 *	required disk writes and improve program responsiveness. When the buffer fills or some other
 *	condition occurs (for instance, enough time elapses), the system writes the cached data to disk all at
 *	one time.
 *	Linux provides caching of this type as well. Normally, this is a great boon to performance.
 *	However, this behavior can make programs that depend on the integrity of disk-based records
 *	unreliable. If the system goes down suddenly—for instance, due to a kernel crash or power
 *	outage—any data written by a program that is in the memory cache but has not yet been written to
 *	disk is lost.
 *	For example, suppose that you are writing a transaction-processing program that keeps a journal
 *	file. The journal file contains records of all transactions that have been processed so that if a system
 *	failure occurs, the state of the transaction data can be reconstructed. It is obviously important to
 *	preserve the integrity of the journal file— whenever a transaction is processed, its journal entry
 *	should be sent to the disk drive immediately.
 *	To help you implement this, Linux provides the fsync system call. It takes one argument, a
 *	writable file descriptor, and flushes to disk any data written to this file. The fsync call doesn't
 *	return until the data has physically been written.
 *	The function in Listing 8.3 illustrates the use of fsync. It writes a single-line entry to a journal file.
 */

#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/**
 *	2、fsync函数
 *	fsync函数只对由文件描述符filedes指定的单一文件起作用，并且等待写磁盘操作结束，然后返回。
 *	fsync可用于数据库这样的应用程序，这种应用程序需要确保将修改过的块立即写到磁盘上。
 *
 *	3、fdatasync函数
 *	fdatasync函数类似于fsync，但它只影响文件的数据部分。而除数据外，fsync还会同步更新文件的属性。
 *	对于提供事务支持的数据库，在事务提交时，都要确保事务日志（包含该事务所有的修改操作以及一个提交记录）
 *	完全写到硬盘上，才认定事务提交成功并返回给应用层。
 */


const char* journal_filename = "journal.log";
void write_journal_entry (char* entry)
{
	int fd = open (journal_filename, O_WRONLY | O_CREAT | O_APPEND, 0660);
	write (fd, entry, strlen (entry));
	write (fd, "\n", 1);

	/**
	 *	写文件时候不是立刻写到硬盘中的，而是先写到内存缓冲buffer中。
	 */
	fsync(fd); //同步整个文件，
	fdatasync (fd); //只同步数据，不包括属性等
	close (fd);
}

int main() {
	write_journal_entry("rongtao");
}


