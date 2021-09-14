
# lex and yacc

lex的叫做“词法分析 lexical analysis,也可以叫符号提取，yacc叫做syntactic analysis 语法分析(https://github.com/weiweikaikai/Lex_Yacc)

如同 Lex 一样, 一个 Yacc 程序也用双百分号分为三段。 它们是：声明、语法规则和 C 代码。

用 Yacc 来创建一个编译器包括四个步骤：

通过在语法文件上运行 Yacc 生成一个解析器。 说明语法： 编写一个 .y 的语法文件（同时说明 C 在这里要进行的动作）。 编写一个词法分析器来处理输入并将标记传递给解析器。 这可以使用 Lex 来完成。lex Name.lex 编写一个函数，通过调用 yyparse() 来开始解析。 编写错误处理例程（如 yyerror()）。 编译 Yacc 生成的代码以及其他相关的源文件。yacc -d Name.y 将目标文件链接到适当的可执行解析器库。gcc -o name *.c


