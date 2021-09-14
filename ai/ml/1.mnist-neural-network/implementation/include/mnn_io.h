/**
 * 该程序用于在终端输出一个警告、错误、信息...
 *
 */
#ifndef MNN_IO_H
#define MNN_IO_H

#include <stdio.h>
#include <string.h>

#define ANSI_CYAN    "\x1b[36m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_RED     "\x1b[31m"
#define ANSI_YELLOW  "\x1b[33m"
#define ANSI_RESET   "\x1b[0m"

void print_error (char* message);//打印一个错误信息

void print_warning (char* message);//打印一个警告信息

void print_info (char* message);//打印一个信息

void print_success (char* message);//打印一个成功信息

#endif
