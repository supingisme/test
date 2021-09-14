
Chapter 9. Inline Assembly Code

Today, few programmers use assembly language. Higher-level languages such as C and C++ run
on nearly all architectures and yield higher productivity when writing and maintaining code. For
occasions when programmers need to use assembly instructions in their programs, the GNU
Compiler Collection permits programmers to add architecture-dependent assembly language
instructions to their programs.
GCC's inline assembly statements should not be used indiscriminately. Assembly language
instructions are architecture-dependent, so, for example, programs using x86 instructions cannot be
compiled on PowerPC computers. To use them, you'll require a facility in the assembly language
for your architecture. However, inline assembly statements permit you to access hardware directly
and can also yield faster code.
An asm instruction allows you to insert assembly instructions into C and C++ programs. For
example, this instruction
asm ("fsin" : "=t" (answer) : "0" (angle));
is an x86-specific way of coding this C statement: [1]
[1] The expression sin (angle) is usually implemented as a function call into the math library, but if you specify the -O1 or higher optimization flag,
GCC is smart enough to replace the function call with a single fsin assembly instruction.
answer = sin (angle);
Observe that unlike ordinary assembly code instructions, asm statements permit you to specify
input and output operands using C syntax.
To read more about the x86 instruction set, which we will use in this chapter, see
http://developer.intel.com/design/pentiumii/manuals/ and http://www.x86-64.org/documentation.

/usr/include/asm/io.h
/usr/src/linux/arch/i386/kernel/process.s


When to Use Assembly Code

Although asm statements can be abused, they allow your programs to access the computer hardware
directly, and they can produce programs that execute quickly. You can use them when writing
operating system code that directly needs to interact with hardware. For example,
/usr/include/asm/io.h contains assembly instructions to access input/output ports directly. The
Linux source code file /usr/src/linux/arch/i386/kernel/process.s provides another
example, using hlt in idle loop code. See other Linux source code files in /usr/src/linux/arch/
and /usr/src/linux/drivers/.












