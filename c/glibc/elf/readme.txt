在计算机科学中，是一种用于二进制文件、可执行文件、目标代码、共享库和核心转储格式文件。

是UNIX系统实验室（USL）作为应用程序二进制接口（Application Binary 
Interface，ABI）而开发和发布的，也是Linux的主要可执行文件格式。

1999年，被86open项目选为x86架构上的类Unix操作系统的二进制文件标准格式，用来取代COFF。
因其可扩展性与灵活性，也可应用在其它处理器、计算机系统架构的操作系统上。

ELF文件由4部分组成，分别是ELF头（ELF header）、程序头表（Program header table）、
节（Section）和节头表（Section header table）。
实际上，一个文件中不一定包含全部内容，而且它们的位置也未必如同所示这样安
排，只有ELF头的位置是固定的，其余各部分的位置、大小等信息由ELF头中的各项值来决定。