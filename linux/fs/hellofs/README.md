https://github.com/accelazh/hellofs


Hellofs-示例内核文件系统实现
===

一个非常简单的Linux内核文件系统，用于学习目的。
它演示了如何实现从超级块，索引节点，目录到文件操作的VFS文件系统。
该许可证是GPL，因为某些内核功能要求它可用。

Hellofs是在Centos 7.1.1503内核3.10.0-229.1.2.el7.x86_64上编写和测试的。
请注意，从内核版本3.11开始，与目录操作有关的某些代码已更改，例如readdir。
它是根据Sankar的Simplefs（提交5d00eebd）重写的。
感谢伟大的Simplefs！实际上，我发现有关编写内核FS的大多数资源已经过时了（他们一直在谈论2.6）。
但是内核正在以如此快的速度开发（现在是4.x！）。一个有效的例子是很宝贵的！

我对Simplefs所做的主要修改是

对代码结构进行了全面改革，使它们更易于理解。
删除了与日记（jbd2）相关的代码，因为我的内核构建不支持它们。
使用位图分配索引节点和数据块，它们应该更具可伸缩性。
Hellofs的磁盘布局为

超级块（1个块）
索引节点位图（1个块）
数据块位图（1个块）
索引节点表（可变长度）
数据块表（可变长度）
一个磁盘块包含多个inode。一个数据块对应一个磁盘块（大小相同）。为了简单起见，每个索引节点仅包含一个数据块。



Hellofs - An example kernel filesystem implementation
===

A very simple linux kernel filesystem for learning purpose. It demonstrates how to implement a VFS filesystem, from superblock, inode, dir to file operations. The license is GPL because some kernel functions require it to be available.

Hellofs is written and tested on Centos 7.1.1503 kernel [3.10.0-229.1.2.el7.x86_64](http://lxr.free-electrons.com/source/?v=3.10). Note that from kernel version 3.11 some code related to dir operations are changed, for example [readdir](https://github.com/psankar/simplefs/blob/5d00eebd45ff9402848acfbbdbad4282393dd60a/simple.c#L212). It is rewritten based on Sankar's [Simplefs (commit 5d00eebd)](https://github.com/psankar/simplefs/tree/5d00eebd45ff9402848acfbbdbad4282393dd60a)). Thanks to the greate [Simplefs](https://github.com/psankar/simplefs)! Actually I found most resources about writting kernel FS are outdated (they are always talking about 2.6). But kernel is being developed in such rapid pace (it is 4.x now!). An working example is precious!

Major modifications that I made on Simplefs are

  * Total overhaul of the code structure to make them easier to understand.
  * Removed journal ([jbd2](https://github.com/psankar/simplefs/blob/5d00eebd45ff9402848acfbbdbad4282393dd60a/simple.c#L18)) related code since my kernel build doesn't support them.
  * Use bitmap to allocate inodes and data blocks, which should be more scalable.

The on-disk layout of Hellofs is 

  * superblock (1 block)
  * inode bitmap (1 block)
  * data block bitmap (1 block)
  * inode table (variable length)
  * data block table (variable length)

One disk block contains multiple inodes. One data block corresponds to one disk block (and of the same size). Each inode contains only one data block for simplicity.

To run test cases

```
cd hellofs
sudo ./hellofs-test.sh | grep "Test finished successfully"
```

