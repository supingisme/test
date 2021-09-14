/**********************************************************************************************************************
** 
** Copyright (c) 2008-2018 ICT/CAS.
** All rights reserved.
**
** File name: ptsTalkKerMod.c
** Description: 
**
** Current Version: 
** $Revision$ 
** Author: Rong Tao
** Date: 2020.01
**
***********************************************************************************************************************/
/* Dependencies ------------------------------------------------------------------------------------------------------*/
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/delay.h>
    
/* Constants ---------------------------------------------------------------------------------------------------------*/
#define PTSTALK_MAJOR	    231
#define PTSTALK_DEV_NAME    "ptsTalkMod"

/* Types -------------------------------------------------------------------------------------------------------------*/
static int ptsTalk_open(struct inode *inode, struct file *file);
static ssize_t ptsTalk_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos);
static ssize_t ptsTalk_read(struct file *file, char __user *buf, size_t count, loff_t *ppos);

/* Macros ------------------------------------------------------------------------------------------------------------*/
/* Globals -----------------------------------------------------------------------------------------------------------*/
static struct file_operations ptsTalk_flops = {
	.owner  = THIS_MODULE,
	.open   = ptsTalk_open,
	.write  = ptsTalk_write,
	.read   = ptsTalk_read,
};
    

/* Functions ---------------------------------------------------------------------------------------------------------*/
typedef enum {
    PTSTALK_DEBUG,   
    PTSTALK_INFO,  
    PTSTALK_DEFAULT,  
    PTSTALK_NOTICE,  
    PTSTALK_EMERG,  
    PTSTALK_ALERT,  
    PTSTALK_WARNING, 
    PTSTALK_ERR,  
}ptsTalk_log_lv;

static struct {
    int level;
    char *str;
} ptsTalk_log_prefix[] __attribute__((unused)) = {
    {PTSTALK_DEBUG,    KERN_DEBUG},
    {PTSTALK_INFO,     KERN_INFO},
    {PTSTALK_DEFAULT,  KERN_DEFAULT},
    {PTSTALK_NOTICE,   KERN_NOTICE},
    {PTSTALK_EMERG,    KERN_EMERG},
    {PTSTALK_ALERT,    KERN_ALERT},
    {PTSTALK_WARNING,  KERN_WARNING},
    {PTSTALK_ERR,      KERN_ERR},
};

static inline int __attribute__((unused)) __ptsTalk_log(ptsTalk_log_lv level, const char *func, int line, const char *fmt, ...)
{
    int n=0;
#define PTSTALK_LOG_PREFIX_FMT "[ptsTalk %s | %s:%d] "
    va_list va;
    va_start(va, fmt);
    n = printk(PTSTALK_LOG_PREFIX_FMT, ptsTalk_log_prefix[level].str, func, line);
    n += vprintk(fmt, va);
    va_end(va);
    
    return n;
}

#define ptsTalk_debug(fmt...)      __ptsTalk_log(PTSTALK_DEBUG, __func__, __LINE__, fmt)
#define ptsTalk_info(fmt...)       __ptsTalk_log(PTSTALK_INFO, __func__, __LINE__, fmt)
#define ptsTalk_default(fmt...)    __ptsTalk_log(PTSTALK_DEFAULT, __func__, __LINE__, fmt)
#define ptsTalk_notice(fmt...)     __ptsTalk_log(PTSTALK_NOTICE, __func__, __LINE__, fmt)
#define ptsTalk_emerg(fmt...)      __ptsTalk_log(PTSTALK_EMERG, __func__, __LINE__, fmt)
#define ptsTalk_alert(fmt...)      __ptsTalk_log(PTSTALK_ALERT, __func__, __LINE__, fmt)
#define ptsTalk_warning(fmt...)    __ptsTalk_log(PTSTALK_WARNING, __func__, __LINE__, fmt)
#define ptsTalk_err(fmt...)        __ptsTalk_log(PTSTALK_ERR, __func__, __LINE__, fmt)

static int ptsTalk_open(struct inode *inode, struct file *file)
{
	ptsTalk_emerg("\n");
	return 0;
}

static ssize_t ptsTalk_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
	ptsTalk_emerg("\n");
	return 0;
}

static ssize_t ptsTalk_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
	ptsTalk_emerg("\n");
	return 0;
}

static int __init ptsTalk_init(void)
{
	int ret = register_chrdev(PTSTALK_MAJOR, PTSTALK_DEV_NAME, &ptsTalk_flops);
	if(ret < 0)
	{
		ptsTalk_emerg(" can't register major number.\n");
		return ret;
	}
	ptsTalk_emerg(" initialized.\n");
	return 0;
}

static void __exit ptsTalk_exit(void)
{
	unregister_chrdev(PTSTALK_MAJOR, PTSTALK_DEV_NAME);
	ptsTalk_emerg(" removed.\n");
}


module_init(ptsTalk_init);
module_exit(ptsTalk_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rong Tao");

