#include <stdio.h>

#include "fs_occupy.h"

void fs_display(const struct fs_occupy_info *info)
{
    printf("%-25s %-10s %-16s %ldMb/%ldMb  %3d.%2d%%\n", 
            info->fs_name, 
            info->fs_type, 
            info->fs_mnt_dir,
            info->freeMB,
            info->totalMB,
            info->occupy.integer,
            info->occupy.decimal);
}

int main(void)
{
    printf("\n-------------------------------------\n");
    fs_storage_occupy(fs_display);
}

