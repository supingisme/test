#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/ide.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/gpio.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/semaphore.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_gpio.h>
#include <linux/timer.h>
#include <linux/irq.h>
#include <linux/of_irq.h>
#include <linux/interrupt.h>

#include <asm/mach/map.h>
#include <asm/uaccess.h>
#include <asm/io.h>

/* user buffer size */
#define BUFFER_SIZE			1

#define CHRDEV_CNT			1
#define CHRDEV_NAME			"interrupt"

/************************  cpu:imx6q gpio1_io22  ****************/

struct irq_examp{
	int gpio;
	int irqnum;
	irqreturn_t (*handler)(int, void*);	/* irq handler function */
};

struct newchar_dev{
	dev_t devid;
	struct cdev cdev;
	struct class *class;
	struct device *device;
	int major;
	int minor;
	struct device_node *nd;
	int gpio_num;
	int timeout;
	struct timer_list  timer;	/* for shake */
	struct irq_examp my_irq; 
};

struct newchar_dev char_dev;


static void timer_function(unsigned long arg)
{
	printk("irq happend !\n");
}

static irqreturn_t irq_handler(int irq, void *dev)
{
	struct newchar_dev *handler_dev = (struct newchar_dev *)dev;
	mod_timer(&handler_dev->timer, jiffies + msecs_to_jiffies(10));	/* 10ms shake */
	
	return IRQ_RETVAL(IRQ_HANDLED);
}


/*
 *description	:init gpio
 *param		:null
 *return		:0 success
 */
static int gpio_init(void)
{
	int ret;
	/* 1.get device node */
	char_dev.nd = of_find_node_by_path("/fxb_test");
	if(char_dev.nd == NULL){
		printk(" of_find_node_by_path fxb_test failed!\n");
		return -EINVAL;
	}

	/* 2.get gpio num */
	char_dev.gpio_num = of_get_named_gpio(char_dev.nd, "gpio", 0);
	if(char_dev.gpio_num < 0){
		printk(" of_get_named_gpio gpio number failed!\n");
		return -EINVAL;
	}

	/* 3.set direction and value  & request gpio*/
	gpio_request(char_dev.gpio_num, "irq test");
	ret = gpio_direction_input(char_dev.gpio_num);
	if(ret < 0){
		printk(" gpio_direction_input failed!\n");
		return -EINVAL;
	}
	
	char_dev.my_irq.handler = irq_handler;
	
	char_dev.my_irq.irqnum = gpio_to_irq(char_dev.gpio_num);
	ret = request_irq(char_dev.my_irq.irqnum, char_dev.my_irq.handler, IRQF_TRIGGER_RISING,
				"irq_test", &char_dev);
	if(ret < 0){
		printk(" request_irq failed %d\n", char_dev.my_irq.irqnum);
	}
	printk(" gpio num:%d    irq_num:%d\n", char_dev.gpio_num, char_dev.my_irq.irqnum);
	
	return 0;
}

static int char_open(struct inode *inode, struct file *filep)
{
	filep->private_data = &char_dev;	/* set private data */
	printk("char_open\n");
	return 0;
}
static ssize_t char_read(struct file *filep, char __user *buf, size_t size, loff_t *lofft)
{
	unsigned char data_buf[BUFFER_SIZE] = {0};
	int ret;

	data_buf[0] = gpio_get_value_cansleep(char_dev.gpio_num);

	ret = copy_to_user(buf, data_buf, 1);
	if(ret < 0){
		printk("char_read copy_to_user failed\n");
		return -EFAULT;
	}
	//gpio_set_value_cansleep(char_dev.gpio_num, 1);
	printk("char_read val %d\n", data_buf[0]);
	return 1;
}
static ssize_t char_write (struct file *filep, const char __user *buf, size_t size, loff_t *lofft)
{
	unsigned char data_buf[BUFFER_SIZE] = {0};
	int ret;

	ret = copy_from_user(data_buf, buf, size);
	if(ret < 0){
		printk("char_write copy_from_user failed\n");
		return -EFAULT;
	}

	gpio_set_value_cansleep(char_dev.gpio_num, data_buf[0]);
	
	printk("char_write val:%d\n", data_buf[0]);
	
	return size;
}

static int char_release(struct inode *inode, struct file *filep)
{
	printk("char_release\n");
	return 0;
}
static struct file_operations chardev_fops = {
	.owner = THIS_MODULE,
	.open = char_open,
	.read = char_read,
	.write = char_write,
	.release = char_release,
};

static int __init chardev_init(void)
{
	int ret;
	
	ret = gpio_init();
	if(ret != 0){
		printk("gpio init dailed\n");
		return ret;
	}

	/* 1.create device number */
	if(char_dev.major){
		char_dev.devid = MKDEV(char_dev.major, 0);
		ret = register_chrdev_region(char_dev.devid, CHRDEV_CNT, CHRDEV_NAME);
		if(ret != 0){
			printk("register_chrdev_region failed\n");
			return -EFAULT;
		}
	}else{
		ret = alloc_chrdev_region(&char_dev.devid, 0, CHRDEV_CNT, CHRDEV_NAME);
		if(ret != 0){
			printk("alloc_chrdev_region failed\n");
			return -EFAULT;
		}
		char_dev.major = MAJOR(char_dev.devid);
		char_dev.minor = MINOR(char_dev.devid);
	}
	printk("major:%d  minor:%d\n", char_dev.major, char_dev.minor);

	/* 2.init cdev */
	char_dev.cdev.owner = THIS_MODULE;
	cdev_init(&char_dev.cdev, &chardev_fops);

	/* 3.add cdev */
	ret = cdev_add(&char_dev.cdev, char_dev.devid, CHRDEV_CNT);
	if(ret != 0){
		printk("cdev_add_failed\n");
		goto cdev_add_failed;
	}

	/* 4.class create */
	char_dev.class = class_create(THIS_MODULE, CHRDEV_NAME);
	if(IS_ERR(char_dev.class)){
		printk("class_create_failed\n");
		goto class_create_failed;
	}

	/* 5.device create */
	char_dev.device = device_create( char_dev.class, NULL, char_dev.devid, NULL,CHRDEV_NAME);
	if(IS_ERR(char_dev.device)){
		printk("device_create_failed\n");
		goto device_create_failed;
	}

	/* init timer */
	init_timer(&char_dev.timer);
	char_dev.timer.function = timer_function;

	printk("chardev_init\n");
	return 0;

device_create_failed:
	class_destroy(char_dev.class);
class_create_failed:
	cdev_del(&char_dev.cdev);
cdev_add_failed:
	unregister_chrdev_region(char_dev.devid, CHRDEV_CNT);
	return -1;
}

static void __exit chardev_exit(void)
{
	
	del_timer_sync(&char_dev.timer);
	gpio_set_value_cansleep(char_dev.gpio_num, 0);
	device_destroy(char_dev.class, char_dev.devid);
	class_destroy(char_dev.class);
	cdev_del(&char_dev.cdev);
	unregister_chrdev_region(char_dev.devid, CHRDEV_CNT);
	free_irq(char_dev.my_irq.irqnum, &char_dev);
	gpio_free(char_dev.gpio_num);
	printk("chardev_exit\n");
}

module_init(chardev_init);
module_exit(chardev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("fanxiaobo-77035154@qq.com");



/* dts

under root node:

	fxb_test {
		#address-cells = <1>;
		#size-cells = <1>;
		compatible = "cqsound,fxb";
		pinctrl-names = "default";
		pinctrl-0 = <&pinctrl_fxb>;
		gpio = <&gpio1 22 GPIO_ACTIVE_LOW>;
		status = "okay";
	};

iomuxc:
		pinctrl_fxb: gpiotest {
			fsl,pins = <
				MX6QDL_PAD_ENET_MDIO__GPIO1_IO22 0x80000000
			>;
	};

*/
