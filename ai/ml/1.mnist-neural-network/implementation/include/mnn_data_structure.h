/**
 * 该程序用于声明数据类型的结构体和函数体
 *
 * mnn_vector:       int, double*
 * mnn_matrix:       int, int, double**
 * mnn_network:      int, mnn_vector, int
 * mnn_network_options:        char*, char*, char*, char*, int
 * mnn_training_parameters:    int, int, double
 * mnn_network_configuration:  mnn_network*, mnn_training_parameters*
 * mnn_backpagation_data:      mnn_vector*, mnn_matrix*
 *
 * and some allocation of those struct function
 */
#ifndef MNN_DATA_STRUCTURE_H
#define MNN_DATA_STRUCTURE_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "mnn_utils.h"

/*
mnn_vector : size_t    length
             double*   values
mnn_matrix : size_t    rows
             size_t    cols
             double ** values
*/

typedef struct mnn_vector_//mnt向量
{
    size_t length;//长度
    double* values;//双精度浮点指针
} mnn_vector;

typedef struct mnn_matrix_//mnn矩阵
{
    size_t rows;//行
    size_t cols;//列
    double** values;//双精度二维浮点指针
} mnn_matrix;

typedef struct mnn_network_//mnn网络
{
    size_t size_input_neurons;//输入神经元大小
    /* Possibility to use one or more hidden layer/s. 
       Values will be casted to int */
    mnn_vector sizes_hidden_neurons; //隐藏层神经元
    size_t size_output_neurons;//输出神经元大小
} mnn_network;

typedef struct mnn_network_options_//网络选项
{
    char* output_file;//输出权重和阀值的文件名
    char* load_file; //加载权重和阀值的文件名
    char* image_file;//图像文件
    char* js_file;   //javascript文件
    int training;   //训练（次数？no）是否训练Yes
                    //a 训练或保存权重，都会让他等于1
} mnn_network_options;

typedef struct mnn_training_parameters_//mnn训练参数
{
    size_t size_epochs;   //训练次数
    size_t size_mini_batches; //一批的最小size
    double learning_rate;  //学习率（步长？）
} mnn_training_parameters;

typedef struct mnn_network_configuration_//mnn网络配置
{
    mnn_network* net; //mnn网络（输入、输出神经元大小）+隐藏神经元
    mnn_training_parameters* training_params; //训练参数（训练次数、一批次的最小size、学习率）
} mnn_network_configuration;

typedef struct mnn_backpropagation_data_//mnn反馈数据
{
    mnn_vector* biases_; //阀值
    mnn_matrix* weights_; //权重
} mnn_backpropagation_data;

mnn_vector allocate_vector (size_t length);//分配一个mnn向量

mnn_matrix allocate_matrix (size_t rows, size_t cols);//分配一个mnn矩阵

mnn_matrix matrix_dot_matrix (mnn_matrix m_1, mnn_matrix m_2);//点矩阵

mnn_matrix matrix_sigmoid (mnn_matrix m);//sigmoid函数：-1（<0); 1(>0)

mnn_matrix matrix_sigmoid_prime (mnn_matrix m);//最好的sigmoid函数

mnn_matrix matrix_transpose (mnn_matrix m);//矩阵转置

void print_vector (mnn_vector v);//打印一个向量

void print_matrix (mnn_matrix m);//打印一个矩阵

void free_vector (mnn_vector v);//释放内存

void free_matrix (mnn_matrix m);//释放内存

#endif
