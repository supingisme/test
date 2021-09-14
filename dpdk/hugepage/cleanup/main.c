/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2010-2014 Intel Corporation
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <sys/queue.h>
#include <unistd.h> //sleep

#include <rte_memory.h>
#include <rte_launch.h>
#include <rte_eal.h>
#include <rte_per_lcore.h>
#include <rte_lcore.h>
#include <rte_debug.h>

void release_hugepage(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	release_hugepage(argc, argv);
	return 0;
}

void release_hugepage(int argc, char *argv[])
{
//	int argc = 2;
//	char *argv[] = {"release_hugepage", "--huge-unlink"};
	int ret = rte_eal_init(argc, argv);
	if (ret < 0)
		rte_panic("Cannot init EAL\n");
}



