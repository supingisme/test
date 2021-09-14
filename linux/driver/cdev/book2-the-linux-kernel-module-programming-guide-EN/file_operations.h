/**
 *	The file_operations Structure
 *	The file_operations structure is defined in linux/fs.h, and holds pointers to functions defined by the
 *	driver that perform various operations on the device. Each field of the structure corresponds to the address of
 *	some function defined by the driver to handle a requested operation.
 *	For example, every character driver needs to define a function that reads from the device. The file_operations
 *	structure holds the address of the module's function that performs that operation. Here is what the definition
 *	looks like for kernel 2.6.5:
 */
struct file_operations {
	struct module *owner;
	loff_t(*llseek) (struct file *, loff_t, int);
	ssize_t(*read) (struct file *, char __user *, size_t, loff_t *);
	ssize_t(*aio_read) (struct kiocb *, char __user *, size_t, loff_t);
	ssize_t(*write) (struct file *, const char __user *, size_t, loff_t *);
	ssize_t(*aio_write) (struct kiocb *, const char __user *, size_t,
			loff_t);
	int (*readdir) (struct file *, void *, filldir_t);
	unsigned int (*poll) (struct file *, struct poll_table_struct *);
	int (*ioctl) (struct inode *, struct file *, unsigned int,
			unsigned long);
	int (*mmap) (struct file *, struct vm_area_struct *);
	int (*open) (struct inode *, struct file *);
	int (*flush) (struct file *);
	int (*release) (struct inode *, struct file *);
	int (*fsync) (struct file *, struct dentry *, int datasync);
	int (*aio_fsync) (struct kiocb *, int datasync);
	int (*fasync) (int, struct file *, int);
	int (*lock) (struct file *, int, struct file_lock *);
	ssize_t(*readv) (struct file *, const struct iovec *, unsigned long,
			loff_t *);
	ssize_t(*writev) (struct file *, const struct iovec *, unsigned long,
			loff_t *);
	ssize_t(*sendfile) (struct file *, loff_t *, size_t, read_actor_t,
			void __user *);
	ssize_t(*sendpage) (struct file *, struct page *, int, size_t,
			loff_t *, int);
	unsigned long (*get_unmapped_area) (struct file *, unsigned long,
			unsigned long, unsigned long,
			unsigned long);
};

struct file_operations fops = {
	  read: device_read,
	  write: device_write,
	  open: device_open,
	  release: device_release
};

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};


