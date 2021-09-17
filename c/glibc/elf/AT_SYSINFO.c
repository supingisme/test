/**
 *  http://articles.manugarg.com/aboutelfauxiliaryvectors
 *
 *  [root@localhost ~]# gcc -o ats ats.c
 *  [root@localhost ~]# ./ats
 *  AT_SYSINFO: 0xc24400
 *
 *  [root@localhost ~]# LD_SHOW_AUXV=1 ./ats | grep AT_SYSINFO
 *  AT_SYSINFO:      0xdd9400
 *  AT_SYSINFO_EHDR: 0xdd9000
 *  AT_SYSINFO is: 0xdd9400
 */
#include <stdio.h>
#include <elf.h>

int main(int argc, char* argv[], char* envp[])
{
        Elf32_auxv_t *auxv;
        while (*envp++ != NULL); /* from stack diagram above: *envp = NULL marks end of envp */

        for (auxv = (Elf32_auxv_t *)envp; auxv->a_type != AT_NULL; auxv++)
        /* auxv->a_type = AT_NULL marks the end of auxv */
        {
                if (auxv->a_type == AT_SYSINFO)
                        printf("AT_SYSINFO is: 0x%x\n", auxv->a_un.a_val);
        }
}
