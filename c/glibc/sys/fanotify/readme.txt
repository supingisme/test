fanotify(fscking all notification and file access system)
是一个notifier，对文件系统变化产生通知的机制。

NOTE:
	0. *** 一个遍历文件系统的代码库： fs-filesystem/fs_occupy/ ***
	1. *** Glibc检测文件系统修改记录： test/c/glibc/sys/fanotify ***
	2. *** Glibc检测文件修改操作： test/c/glibc/sys/inotify