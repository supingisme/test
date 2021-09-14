/**
 * 该文件包含：阀值和权重的操作函数
 *
 *  PS：从parameters文件中读取或者使用随机的biases和weights
 */
#ifndef MNN_NETWORK_UTILS_H
#define MNN_NETWORK_UTILS_H
/*utils 工具*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "mnn_config.h"
#include "mnn_utils.h"
#include "mnn_file_utils.h"
#include "mnn_data_structure.h"
#include "mnn_io.h"

/*从文件中加载阈值、阀值*/
mnn_vector* load_biases_in_the_file (mnn_network* net, 
                                     int train, 
                                     const char* file);
/*加载一个随机的阈值、阀值*/
mnn_vector* load_biases_randomly (mnn_network* net);
/*获取阈值、阀值点*/
mnn_vector* get_pointer_biases (mnn_network* net);

/*从文件加载权重*/
mnn_matrix* load_weights_in_the_file (mnn_network* net, 
                                      int train,  
                                      const char* file);
/*随机加载权重*/
mnn_matrix* load_weights_randomly (mnn_network* net);
/*获取权重点*/
mnn_matrix* get_pointer_weights (mnn_network* net);

/*检查文件格式的准确性*/
FILE* check_correct_format_of_the_file (mnn_network* net, 
                                        int train, 
                                        const char* file);
/*保存权重和阈值、阀值*/
int save_weights_and_biases (mnn_network* net, 
                             mnn_matrix* weights, 
                             mnn_vector* biases, 
                             const char* file);
/*保存权重和阈值、阀值到javascript文件中*/
int save_weights_and_biases_into_js_file (mnn_network* net, 
                                          mnn_matrix* weights, 
                                          mnn_vector* biases, 
                                          const char* file);
/*打印网络的信息*/
void print_info_network (mnn_network_configuration* net_configuration, 
                         mnn_network_options* net_options);

#endif
