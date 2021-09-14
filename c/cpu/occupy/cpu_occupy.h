#ifndef __CPU_OCCUPY_H
#define __CPU_OCCUPY_H 1

/**
 *  core_occupy - cpu和使用率结构
 *  
 *  param   cpuid   范围[-1 ~ Ncores] 
 *                  cpuid=-1, 标识所有核的平均使用率
 *                  cpuid=0,1,2,3... 对应核心的使用率
 *  
 *  param   occupy.integer  使用率的正数部分
 *          occupy.decimal  使用率的小数部分
 *          例如： 使用率为 20.234 %时:
 *                  occupy.integer=20
 *                  occupy.decimal=234
 */
struct core_occupy {
    int cpuid;
    struct {
        int integer, decimal;
    }occupy;
};

/**
 *  core_display_fn - 对使用率的操作
 *
 *   需要注意的是，该函数不可阻塞，不可与使用者资源有竞争
 *  
 *  param[in]   cpuid   见 struct core_occupy 说明
 *  param[in]   occ     见 struct core_occupy 说明
 *  param[in]   arg     使用者内存指针
 *  
 *  return 无所谓
 */
typedef int (*core_display_fn)(int cpuid, const struct core_occupy *occ, void *arg);

/**
 *  nr_cpu_cores - 获取系统总核心数
 *  
 *  return 大于0的整形
 */
int nr_cpu_cores();

/**
 *  cpu_cores_occupy_chk_init - 初始化CPU利用率查询功能
 *
 *   若该函数调用前调用了 cpu_cores_occupy_chk_display 将失败，该函数只能调用一次
 *
 *  return 0-成功， -1 失败
 */
int cpu_cores_occupy_chk_init();

/**
 *  cpu_cores_occupy_chk_display - 如何使用CPU利用率数据
 *
 *  param[in] display   函数指针，详见 core_display_fn 说明
 *  param[in] arg       使用者内存地址，将传递给 core_display_fn 的 arg 参数
 *                          arg 参数 详见 core_display_fn 说明
 */
int cpu_cores_occupy_chk_display(core_display_fn display, void *arg);



#endif /*<__CPU_OCCUPY_H>*/
