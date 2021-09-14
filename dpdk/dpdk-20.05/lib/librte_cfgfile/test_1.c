/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2010-2014 Intel Corporation.
 * Copyright (c) 2009, Olivier MATZ <zer0@droids-corp.org>
 * All rights reserved.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <netinet/in.h>
#include <termios.h>
#include <sys/socket.h>

#include "rte_cfgfile.h"

int main(int argc, char **argv)
{
	int ret;

    struct rte_cfgfile *cfg1 = rte_cfgfile_load("config.ini", CFG_FLAG_GLOBAL_SECTION);

    const char *name = rte_cfgfile_get_entry(cfg1, "RTOAX", "name");
    printf("name = %s\n", name);
    const char *age = rte_cfgfile_get_entry(cfg1, "RTOAX", "age");
    printf("age = %s\n", age);



    rte_cfgfile_close(cfg1);
    
	return 0;
}

