/**
 * 包含正传、反传、更新等函数
 *
 */
#ifndef MNN_NETWORK_H
#define MNN_NETWORK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "mnn_config.h"
#include "mnn_utils.h"
#include "mnn_file_utils.h"
#include "mnn_data_structure.h"
#include "mnn_io.h"
#include "mnn_network_utils.h"

/*
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
    mnn_vector sizes_hidden_neurons; //隐藏层神经元
    size_t size_output_neurons;//输出神经元大小
} mnn_network;
typedef struct mnn_network_options_//网络选项
{
    char* output_file;//输出文件
    char* load_file; //加载文件
    char* image_file;//图像文件
    char* js_file;   //javascript文件
    int training;   //训练（次数？）
} mnn_network_options;
typedef struct mnn_network_configuration_//mnn网络配置
{
    mnn_network* net; //mnn网络（输入、输出神经元大小）+隐藏神经元
    mnn_training_parameters* training_params; //训练参数（训练次数、一批次的最小size、学习率）
} mnn_network_configuration;
*/

/*执行网络*/
void execute_network (mnn_network_configuration* net_configuration, //网络配置
                      mnn_network_options* net_options); 
/*更新最小批次*/
void update_mini_batch (mnn_network_configuration* net_configuration, //网络配置
                        mnn_matrix* training_data,  //训练数据
                        int* training_labels, //训练数据的labels
                        mnn_matrix* weights, //权重
                        mnn_vector* biases, //阀值
                        int index);
/*反向传播 （bp神经网络？）*/
mnn_backpropagation_data  backpropagation (mnn_network* net, //网络
                                          mnn_matrix x,  //矩阵
                                          int y,  //
                                          mnn_matrix* weights,//权重  
                                          mnn_vector* biases);//阀值
/*正传*/
int forward (mnn_network* net, //网络
             mnn_matrix x,  //矩阵
             mnn_matrix* weights,  //权重
             mnn_vector* biases);//阀值
/*评价*/
int evaluate (mnn_matrix m);
/*测试网络*/
int test_network (mnn_network* net, //网络
                  mnn_matrix* test_data, //矩阵
                  int* test_labels, //测试labels
                  mnn_matrix* weights, //权重
                  mnn_vector* biases); //阀值

/*预测输出图像*/
int predict_output_image (mnn_network* net, //网络
                          char* image_file, //文件路径
                          mnn_matrix* weights, //权重
                          mnn_vector* biases); //阀值
/*更新最好的参数*/
void update_best_parameters (size_t length_layers, //层的长度
                             mnn_matrix* weights, //权重
                             mnn_vector* biases,  //阀值
                             mnn_matrix* best_weights, //更好的权重
                             mnn_vector* best_biases); //更好的阀值

#endif
