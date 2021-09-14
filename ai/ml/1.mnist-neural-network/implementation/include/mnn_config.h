#ifndef MNN_CONFIG_H
#define MNN_CONFIG_H

/* Input layer size */
#define N_INPUT_LAYER 784 //输入的28*28层

/* Output layer size */
#define N_OUTPUT_LAYER 10 //输出的层大小0~9

/* Number of training images/labels according to MNIST database */
#define N_TRAINING_IMAGES 60000//训练的图像个数

/* Number of test images/labels according to MNIST database */
#define N_TEST_IMAGES 10000//测试的图像个数

/* Number of rows of the images according to MNIST database */
#define N_ROWS_IMAGE 28 //图像的横向大小

/* Number of columns of the images according to MNIST database */
#define N_COLS_IMAGE 28 //图像的纵向大小

/* Number of entries for each image */
#define N_ENTRIES_IMAGE N_ROWS_IMAGE * N_COLS_IMAGE //28*28

/* Path training data */
#define PATH_TRAINING_DATA "../data/mnist-database-training/train-images-idx3-ubyte"//训练的images文件

/* Path training labels */
#define PATH_TRAINING_LABELS "../data/mnist-database-training/train-labels-idx1-ubyte"//测试的label文件

/* Path test data */
#define PATH_TEST_DATA "../data/mnist-database-test/t10k-images-idx3-ubyte"

/* Path test labels */
#define PATH_TEST_LABELS "../data/mnist-database-test/t10k-labels-idx1-ubyte"

/* Default path config file. User can specify own config file from the command line */
#define PATH_DEFAULT_CONFIG_FILE "default_configuration.conf"

#endif
