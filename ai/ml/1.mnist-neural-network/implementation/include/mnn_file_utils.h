/**
 * 该程序用于读取mnist数据集
 *
 *     labels -> int
 *      28*28 -> mnn_matrix -> double
 */
#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdio.h>

#include "mnn_config.h"
#include "mnn_utils.h"
#include "mnn_data_structure.h"

int* load_training_labels (void);//加载训练数据的labels

int* load_test_labels (void);//加载测试数据的labels

int* load_labels (const char* file);//加载labels

mnn_matrix* load_training_data (void);//加载一个28*28的训练数据

mnn_matrix* load_test_data (void);//加载一个28*28的测试数据

mnn_matrix* load_data (const char* file);//加载数据

int file_exists (const char* file);//判断文件是否存在

#endif
