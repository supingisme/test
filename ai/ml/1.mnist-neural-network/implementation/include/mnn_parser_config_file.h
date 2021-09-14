/**
 * 读取参数配置文件: 对应头文件mnn_parser_config_file.h
 *
 *    2018.05注释
 */
#ifndef MNN_PARSER_CONFIG_FILE_H
#define MNN_PARSER_CONFIG_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "mnn_config.h"
#include "mnn_utils.h"
#include "mnn_file_utils.h"
#include "mnn_data_structure.h"
#include "mnn_io.h"
/**
 * 读取参数配置文件头文件
 *    2018.05注释
 */
//剖析器
#define N_PARAMETERS 4
/*#define DEBUG_PARSER*/

typedef struct mnn_token_
{
    char* value;
    size_t size;
} mnn_token;

/* Global variable used to track current line of the file 
        (initialized it in "parse_config_file" function) */
int line;

/*剖析配置文件*/
int parse_config_file (mnn_network_configuration* net_configuration, 
                       const char* path_config_file);

/*token（计算机术语）：令牌、标记*/
mnn_token get_token (FILE* fp, 
                     size_t length);

/*剖析文件指针的类别（bracket：支架、括弧、类别、等级）*/
void parse_open_bracket (FILE* fp);

/*剖析参数*/
void parse_parameters (FILE* fp, 
                       char** params, 
                       mnn_network_configuration* net_configuration);

/*操作参数*/
void handle_parameter (FILE* fp, 
                       char* param_value, 
                       mnn_network_configuration* net_configuration);

/*操作隐藏层的参数*/
void handle_hidden_layers_parameter (FILE* fp, 
                                     mnn_network_configuration* net_configuration);

/*操作学习率的参数*/
void handle_learning_rate_parameter (FILE* fp, 
                                     mnn_network_configuration* net_configuration);

/*操作训练次数参数（epochs：训练次数、新时期）*/
void handle_epochs_parameter (FILE* fp, 
                              mnn_network_configuration* net_configuration);

/*操作最小批次的参数*/
void handle_mini_batches_parameter (FILE* fp, 
                                    mnn_network_configuration* net_configuration);

/*关闭文件指针*/
void parse_close_bracket (FILE* fp);

/*判断是否为数字*/
int is_number (char character);

/*判断是有效的alpha字符*/
int is_valid_alpha_character (char character);

/*判断是否为跳过的字符*/
int is_skip_character (char character);

/*执行参数*/
char** setup_parameters (void);

#endif
