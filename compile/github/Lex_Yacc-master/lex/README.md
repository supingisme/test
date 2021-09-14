Lex 编程可以分为三步：
以 Lex 可以理解的格式指定模式相关的动作。  wordcount.lex
在这一文件上运行 Lex，生成扫描器的 C 代码。 lex wordcount.lex
编译和链接 C 代码，生成可执行的扫描器。    gcc lex.yy.c

这是一个统计单词个数的lex编程demo

