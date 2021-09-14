/**
 * 该程序用于在终端输出一个警告、错误、信息...
 *
 */
#include "mnn_io.h"

//#define ANSI_CYAN    "\x1b[36m"
//#define ANSI_GREEN   "\x1b[32m"
//#define ANSI_RED     "\x1b[31m"
//#define ANSI_YELLOW  "\x1b[33m"
//#define ANSI_RESET   "\x1b[0m"

/*打印一个错误信息*/
void
print_error (char* message)
{
    if (message && strlen (message) > 0)
        printf (ANSI_RED "   [Error]  " ANSI_RESET "%s", message);
}

/*打印一个警告信息*/
void
print_warning (char* message)
{
    if (message && strlen (message) > 0)
        printf (ANSI_YELLOW "   [Warning]  " ANSI_RESET "%s", message);
}

/*打印一个信息*/
void
print_info (char* message)
{
    if (message && strlen (message) > 0)
        printf (ANSI_CYAN "   [Info]  " ANSI_RESET "%s", message);
}

/*打印一个成功信息*/
void
print_success (char* message)
{
    if (message && strlen (message) > 0)
        printf (ANSI_GREEN "   [Success]  " ANSI_RESET "%s", message);
}
