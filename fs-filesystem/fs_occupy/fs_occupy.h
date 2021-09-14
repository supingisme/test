/**
 *  fs_occupy - 遍历系统文件系统，并查询其磁盘使用率（有效磁盘）
 *  
 *  日期：2020年10月15日
 *  作者：荣涛
 */
#ifndef __FS_OCCUPY_H
#define __FS_OCCUPY_H 1

#include <stdio.h>

/**
 *  struct fs_occupy_info - 文件系统使用率查询信息结构
 *  
 *  fs_name - 文件系统名称，例如 /dev/mapper/centos-root
 *  fs_mnt_dir - 文件系统挂载点
 *              # df  
 *              文件系统                     1K-块       已用       可用      已用% 挂载点
 *              /dev/mapper/centos-root  36678148 35066696  1611452   96%   /
 *
 *  fs_type - 文件系统类型 xfs ext4 rootfs 等
 *  
 *  
 *  occupy  occupy.integer  使用率的正数部分
 *          occupy.decimal  使用率的小数部分
 *          例如： 使用率为 20.234 %时:
 *                  occupy.integer=20
 *                  occupy.decimal=234
 */
struct fs_occupy_info {
   char fs_name[64];   /* name of mounted file system */
   char fs_mnt_dir[128];      /* file system path prefix */
   char fs_type[64];     /* mount type (see mntent.h) */

   unsigned long int totalMB;
   unsigned long int freeMB;

   struct {
        int integer;
        int decimal;
   }occupy;
};


/**
 *  fs_info_ops_fn - 有效文件系统使用率查询回调函数
 *  
 *  info - 参见 struct fs_occupy_info 
 */
typedef void (*fs_info_ops_fn)(const struct fs_occupy_info *info);


/** 
 *  fs_storage_occupy - 查询有效文件系统使用率
 *      
 *   该接口会轮询调用 display 有效文件系统个数次，每次将 struct fs_occupy_info 结构
 *  传递给 fs_info_ops_fn 回调函数。
 */
void fs_storage_occupy(fs_info_ops_fn display);


#endif /*<__FS_OCCUPY_H>*/
