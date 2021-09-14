#include <stdio.h>

#define __weak __attribute__((weak))
//变量加上weak时，是弱符号。函数加上weak时，是弱引用，可以不实现。
//给函数加上weak属性时，即使函数没定义，函数被调用也可以编译成功。
//当有两个函数同名时，则使用强符号（也叫全局符号,即没有加weak的函数）来代替弱符号（加weak的函数）。

int func() __weak;

int main()
{
	func();
}
