/**
 * 包含正传、反传、更新等函数
 *
 */
#include "mnn_network.h"

/*执行网络
  主函数中调用的*/
void
execute_network (mnn_network_configuration* net_configuration, 
                 /*configuration： mmn_network* net : 784, vector, 10
                                  mmn_training_parameters * training_params : 
                                                        size_epochs, 
                                                        size_mini_batches, 
                                                        learning_rate*/
                 mnn_network_options* net_options)
                /*options: output_file, load_file (weight, biases)
                            image_file, js_file
                            int training */
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
{
    int k, j, 
        correct_predictions,  //准确预测值
        max_correct_predictions, //最大的准确预测值
        improvement_predictions, //提高的预测值
        save_params; //保存参数

    size_t length_layers; //层的长度
    char str_prediction[1024], //预测的string
         str_progress[1024]; //提高的string

    mnn_vector* biases, //阀值
              * best_biases; //最好的阀值

    mnn_matrix* weights, //权重
              * best_weights, //最好的权重
              * training_data, //训练数据
              * test_data; //测试数据

    int* training_labels, //训练label
       * test_labels; //测试label

    /* Print some info about the network, training parameters and input/output file */
    print_info_network (net_configuration, net_options);

    /* Init biases and weights */
    /* If we don't specify load file, all values are random */
    /* length_layers = |biases| = |weights| */
    length_layers = net_configuration->net->sizes_hidden_neurons.length + 1;

    /*如果net options的load file为真则从文件中加载“阀值”*/
    /*mnn_vector* 
       a 如果load-file：从文件中加载biases和weight，否则设定一个随机的值*/
    biases  = (!net_options->load_file) ? load_biases_randomly (net_configuration->net)
                                        : load_biases_in_the_file (net_configuration->net, 
                                                                   net_options->training,  
                                                                   net_options->load_file);
    /*如果net options的load file为真则从文件中加载“权重”*/
    /*mnn_matrix* */
    weights = (!net_options->load_file) ? load_weights_randomly (net_configuration->net)
                                        : load_weights_in_the_file (net_configuration->net,  
                                                                    net_options->training,  
                                                                    net_options->load_file);
    if (!biases || ! weights) {//不能加载biases或weights（NULL）
        print_error ((!biases)  ? "Impossible to load biases.\n" : "");
        print_error ((!weights) ? "Impossible to load weights.\n" : "");

        exit (-1);
    }//if
    /*如果加载成功会运行到这里，并打印成功信息*/
    print_success ((!net_options->load_file) ? "Weights and biases set randomly.\n" 
                                             : "Weights and biases loaded from the file.\n");

    /* Init best_biases and best_weights 
        给这两个指针分配内存空间（按照net中制定的大小）*/
    best_biases  = get_pointer_biases (net_configuration->net);
    best_weights = get_pointer_weights (net_configuration->net);

    /* Train the network if the option '--train' ('--save-parameters also) was specified 
            如果命令行中有--train，则执行如下信息，main函数中的说明为：
        net_options->training = (!index_training) ? ((index_save_parameters) ? 1 : 0) : 1;*/
    if (net_options->training) {
        /* Load data (training and test) and labels (training and test) */
        if ((training_data = (load_training_data ())))//mnn_matrix*
            print_success ("Training data loaded.\n");

        if ((training_labels = (load_training_labels ())))//int*
            print_success ("Training labels loaded.\n");

        if ((test_data = (load_test_data ())))//mnn_matrix
            print_success ("Test data loaded.\n");

        if ((test_labels = (load_test_labels ())))//int *
            print_success ("Test labels loaded.\n");

        /* Setting "max_correct_predictions" variable to 
            know when we must modify biases and weights */
        /*test_network返回测试数据中准确的个数*/
        max_correct_predictions = (net_options->load_file) 
                                    ? test_network (net_configuration->net, 
                                                    test_data,  
                                                    test_labels,  
                                                    weights,  
                                                    biases) : -1;

        /* Update values based on biases and weights 
            tmp  就是把weight的值赋给best_weights*/
        update_best_parameters (length_layers, weights, biases, best_weights, best_biases);
        /* If there is not an improvement of the parameters, 
            the file won't update even if option '--save-parameters' is specified */
        save_params = 0;
        /* Train the network */
        for (k = 0; k < net_configuration->training_params->size_epochs; k++) {
            j = improvement_predictions = 0;
            while (j < N_TRAINING_IMAGES) {
                update_mini_batch (net_configuration,
                                   training_data,
                                   training_labels,
                                   weights,
                                   biases,
                                   j);

                j += net_configuration->training_params->size_mini_batches;
            }//while j - N_TRAINING_IMAGES

            correct_predictions = test_network (net_configuration->net, 
                                                test_data,  
                                                test_labels,  
                                                weights,  
                                                biases);

            if (correct_predictions > max_correct_predictions) {
                max_correct_predictions = correct_predictions;

                update_best_parameters (length_layers, 
                                        weights,  
                                        biases,  
                                        best_weights,  
                                        best_biases);

                improvement_predictions = save_params = 1;
            }
            sprintf (str_progress, "Epoch [%d, %zu] complete: %d/%d", k + 1,
                                   net_configuration
                                        ->training_params
                                            ->size_epochs, 
                                   correct_predictions, 
                                   N_TEST_IMAGES);
            strcat (str_progress, (improvement_predictions) ? 
                                    " (new high value).\n" : ".\n");

            print_info (str_progress);

            memset (&str_progress[0], 0, sizeof (str_progress));
        }//for k 训练次数的循环

        for (k = 0; k < N_TRAINING_IMAGES; k++)
            free_matrix (training_data[k]);
        free (training_data);

        for (k = 0; k < N_TEST_IMAGES; k++)
            free_matrix (test_data[k]);
        free (test_data);

        free (training_labels);
        free (test_labels);
    }//if 是否训练的判断结束

    /* Save parameters */
    if (net_options->output_file) {
        if (!save_params)
            print_warning ("The file won't update since there has"\
                           " not been an improvement of the parameters.\n");
        else {
            if (save_weights_and_biases (net_configuration->net, 
                                         best_weights,  
                                         best_biases,  
                                         net_options->output_file))
                print_success ("Weights and biases were saved successfully.\n");
            else
                print_error ("Impossible to save weights and biases in the output file.\n");
        }
    }

    /* Export parameters with Javascript syntax */
    if (net_options->js_file) {
        if (!save_params)
            print_warning ("The Javascript file won't update since "\
                           "there has not been an improvement of the parameters.\n");
        else {
            if (save_weights_and_biases_into_js_file (net_configuration->net, 
                                                      best_weights, 
                                                      best_biases, 
                                                      net_options->js_file))
                print_success ("Weights and biases were saved "\
                               "successfully in Javascript format.\n");
            else
                print_error ("Impossible to save weights and biases, "\
                              "in Javascript format, in the output file.\n");
        }
    }

    /* Predict output */
    if (net_options->image_file) {
        sprintf (str_prediction, "Image should contain number %d.\n",
                                 predict_output_image (net_configuration->net, 
                                                       net_options->image_file,  
                                                       weights,  
                                                       biases));

        print_info (str_prediction);
    }

    /* Free pointers */
    for (k = 0; k < length_layers; k++) {
        free_vector (biases[k]);
        free_matrix (weights[k]);
    }
    free (biases);
    free (weights);

    for (k = 0; k < length_layers; k++) {
        free_vector (best_biases[k]);
        free_matrix (best_weights[k]);
    }
    free (best_biases);
    free (best_weights);
}

void
update_mini_batch (mnn_network_configuration* net_configuration, 
                   mnn_matrix* training_data,  
                   int* training_labels,
                   mnn_matrix* weights,  
                   mnn_vector* biases,  
                   int index)
{
    int k, j, i, z, end_index, app_k;
    mnn_vector* b_app;
    mnn_matrix* w_app;
    mnn_backpropagation_data backprop_data;
/*
typedef struct mnn_backpropagation_data_//mnn反馈数据
{
    mnn_vector* biases_; //阀值
    mnn_matrix* weights_; //权重
} mnn_backpropagation_data;
*/
    size_t length_layers;

    /* Init biases and weights */
    /* length_layers = |biases| = |weights| */
    length_layers = net_configuration->net->sizes_hidden_neurons.length + 1;
    /* Each value is 0 */
    b_app = get_pointer_biases (net_configuration->net);
    w_app = get_pointer_weights (net_configuration->net);

    /*每一个batches为一批，*/
    end_index = index + net_configuration->training_params->size_mini_batches;
    for (k = index; k < end_index; k++) {
        //a确定这个app_k 不超过训练数据的总个数
        app_k = (k >= N_TRAINING_IMAGES) ? (N_TRAINING_IMAGES - 1) : k;
        //a进行反传，求取backpropagation（weights和biases）
        backprop_data = backpropagation (net_configuration->net, 
                                         training_data[app_k],  
                                         training_labels[app_k],  
                                         weights,  
                                         biases);

        for (j = 0; j < length_layers; j++) {
            /* Update biases */
            for (i = 0; i < b_app[j].length; i++)
                b_app[j].values[i] += backprop_data.biases_[j].values[i];

            /* Update weights */
            for (i = 0; i < w_app[j].rows; i++)
                for (z = 0; z < w_app[j].cols; z++)
                    w_app[j].values[i][z] += backprop_data.weights_[j].values[i][z];
        }//for j

        /* Free backpropagation data */
        for (j = 0; j < length_layers; j++) {
            free_vector (backprop_data.biases_[j]);
            free_matrix (backprop_data.weights_[j]);
        }//for
        free (backprop_data.biases_);
        free (backprop_data.weights_);
    }//for k  index - end_index

    /* Update biases and weights */
    for (k = 0; k < length_layers; k++) {
        /* Update biases */
        __assert ("'update_mini_batch' function ('mnn_network.c'), "\
                  "b_app.length != biases.length",
                  b_app[k].length == biases[k].length);

        for (j = 0; j < biases[k].length; j++)
            biases[k].values[j] -= (double) (net_configuration
                                                ->training_params
                                                ->learning_rate 
                                    /(double) net_configuration
                                                ->training_params
                                                ->size_mini_batches) 
                                    * b_app[k].values[j];

        /* Update weights */
        __assert ("'update_mini_batch' function ('mnn_network.c'), w_app.rows != weights.rows",
            w_app[k].rows == weights[k].rows);
        __assert ("'update_mini_batch' function ('mnn_network.c'), w_app.cols != weights.cols",
            w_app[k].cols == weights[k].cols);

        for (j = 0; j < weights[k].rows; j++)
            for (i = 0; i < weights[k].cols; i++)
                weights[k].values[j][i] -= (double) (net_configuration
                                                        ->training_params
                                                        ->learning_rate 
                                            /(double) net_configuration
                                                        ->training_params
                                                        ->size_mini_batches) 
                                            * w_app[k].values[j][i];
    }

    /* Free pointers */
    for (k = 0; k < length_layers; k++) {
        free_vector (b_app[k]);
        free_matrix (w_app[k]);
    }
    free (b_app);
    free (w_app);
}

/*
  反馈？ BP神经网络的那个反传？？
*/
mnn_backpropagation_data
backpropagation (mnn_network* net, 
                 mnn_matrix x, 
                 int y, 
                 mnn_matrix* weights, 
                 mnn_vector* biases)
{
    mnn_backpropagation_data backprop_data;
    int k, j, i;
    size_t length_layers;
    mnn_matrix app, app_T;

    mnn_matrix* z_k,
              * a_k,
              * delta_k;

    /* Init biases and weights */
    /* length_layers = |biases| = |weights| */
    length_layers = net->sizes_hidden_neurons.length + 1;
    /* Each value is 0 */
    backprop_data.biases_  = get_pointer_biases (net);
    backprop_data.weights_ = (mnn_matrix *) 
                              malloc (sizeof (mnn_matrix) * length_layers);
    if (!backprop_data.weights_)
        __exit ("'backpropagation' function ('mnn_network.c'), "\
                "impossible to allocate backprop_data.weights_");

    /* Setting z pointer */
    z_k = (mnn_matrix *) malloc (sizeof (mnn_matrix) * length_layers);
    if (!z_k)
        __exit ("'backpropagation' function ('mnn_network.c'), "\
                "impossible to allocate z_k");

    /* Setting activation pointer */
    /* (length_layers + 1) because a(1) = x (where x is the input) */
    a_k = (mnn_matrix *) malloc (sizeof (mnn_matrix) * (length_layers + 1));
    if (!a_k)
        __exit ("'backpropagation' function ('mnn_network.c'), "\
                "impossible to allocate a_k");
    /* Setting a(1) */
    a_k[0] = allocate_matrix (net->size_input_neurons, 1);
    for (k = 0; k < N_ROWS_IMAGE; k++)
        for (j = 0; j < N_COLS_IMAGE; j++)
            a_k[0].values[(k * N_ROWS_IMAGE) + j][0] = x.values[k][j];

    /* Setting delta pointer */
    delta_k = (mnn_matrix *) malloc (sizeof (mnn_matrix) * length_layers);
    if (!delta_k)
        __exit ("'backpropagation' function ('mnn_network.c'), "\
                "impossible to allocate delta_k");

    /* Calculation of z_k and a_k => forward propagation */
    for (k = 0; k < length_layers; k++) {
        /* "matrix_dot_matrix" function allocates matrix */
        z_k[k] = matrix_dot_matrix (weights[k], a_k[k]);

        /* Sum biases of the k-th layer */
        __assert ("'backpropagation' function ('mnn_network.c'), "\
                  "z_k and biases", 
                  z_k[k].rows == biases[k].length);
        for (j = 0; j < z_k[k].rows; j++)
            for (i = 0; i < z_k[k].cols; i++)
                z_k[k].values[j][i] += biases[k].values[j];

        /* "matrix_sigmoid" function allocates matrix */
        a_k[k + 1] = matrix_sigmoid (z_k[k]);
    }

    /* Backpropagation */
    /* Handle the last layer */
    delta_k[length_layers - 1] = allocate_matrix (a_k[length_layers].rows, 
                                                  a_k[length_layers].cols);

    for (k = 0; k < delta_k[length_layers - 1].rows; k++)
        for (j = 0; j < delta_k[length_layers - 1].cols; j++)
            delta_k[length_layers - 1].values[k][j] = a_k[length_layers].values[k][j] 
                                                        - ((y == k) ? 1 : 0);

    __assert ("'backpropagation' function ('mnn_network.c'), "\
                "delta output layer rows", 
                delta_k[length_layers - 1].rows == z_k[length_layers - 1].rows);
    __assert ("'backpropagation' function ('mnn_network.c'), "\
                "delta output layer cols", 
                delta_k[length_layers - 1].cols == z_k[length_layers - 1].cols);

    for (k = 0; k < delta_k[length_layers - 1].rows; k++)
        for (j = 0; j < delta_k[length_layers - 1].cols; j++)//求导数
            delta_k[length_layers - 1].values[k][j] *= sigmoid_prime_to_number (z_k[length_layers - 1].values[k][j]);

    app = matrix_transpose (a_k[length_layers - 1]);
    backprop_data.weights_[length_layers - 1] = matrix_dot_matrix (delta_k[length_layers - 1], app);
    free_matrix (app);

    /* Handle others layers */
    for (k = (length_layers - 2); k >= 0; k--) {
        app   = matrix_sigmoid_prime (z_k[k]);
        app_T = matrix_transpose (weights[k + 1]);

        delta_k[k] = matrix_dot_matrix (app_T, delta_k[k + 1]);
        __assert ("'backpropagation' function ('mnn_network.c'), "\
                  "delta output k-th rows", 
                  app.rows == delta_k[k].rows);
        __assert ("'backpropagation' function ('mnn_network.c'), "\
                  "delta output k-th cols", 
                  app.cols == delta_k[k].cols);

        for (j = 0; j < delta_k[k].rows; j++)
            for (i = 0; i < delta_k[k].cols; i++)
                delta_k[k].values[j][i] *= app.values[j][i];
        free_matrix (app);
        free_matrix (app_T);

        app_T = matrix_transpose (a_k[k]);
        backprop_data.weights_[k] = matrix_dot_matrix (delta_k[k], app_T);
        free_matrix (app_T);
    }

    for (k = 0; k < length_layers; k++) {
        __assert ("'backpropagation' function ('mnn_network.c'), "\
                  "delta_k biases_k", 
                  backprop_data.biases_[k].length == delta_k[k].rows);

        for (j = 0; j < backprop_data.biases_[k].length; j++)
            backprop_data.biases_[k].values[j] = delta_k[k].values[j][0];
    }

    /* Free pointers */
    for (k = 0; k < length_layers; k++) {
        free_matrix (z_k[k]);
        free_matrix (a_k[k]);
        free_matrix (delta_k[k]);
    }
    free_matrix (a_k[k]);

    free (z_k);
    free (a_k);
    free (delta_k);

    return backprop_data;
}

/*正传*/
int
forward (mnn_network* net,    //一个神经网络
         mnn_matrix x,        //matrix  输入的这个28*28的数据
         mnn_matrix* weights, //权重
         mnn_vector* biases)  //阀值
{
    int k, j, i, res;
    mnn_matrix a_k, 
               app, 
               app_s;
    size_t length_layers;//神经网络层数

    length_layers = net->sizes_hidden_neurons.length + 1;

    /* Set input matrix */
    a_k = allocate_matrix (N_ROWS_IMAGE * N_COLS_IMAGE, 1);//一维的matrix
    for (k = 0; k < N_ROWS_IMAGE; k++)
        for (j = 0; j < N_COLS_IMAGE; j++)
            //a_k：一维的matrix数据
            a_k.values[(k * N_ROWS_IMAGE) + j][0] = x.values[k][j];

    /* Forward */
    for (k = 0; k < length_layers; k++) {
        //[k][j] = [k][i]*[i][j] 矩阵点乘
        app = matrix_dot_matrix (weights[k], a_k);

        __assert ("'forward' function ('mnn_network.c'), biases", 
                    app.rows == biases[k].length);

        for (j = 0; j < app.rows; j++)
            for (i = 0; i < app.cols; i++)
                app.values[j][i] += biases[k].values[j];

        /*对app乘以sigmoid函数*/
        app_s = matrix_sigmoid (app);

        free_matrix (a_k);
        free_matrix (app);

        a_k = allocate_matrix (app_s.rows, app_s.cols);
        for (j = 0; j < a_k.rows; j++)
            for (i = 0; i < a_k.cols; i++)
                a_k.values[j][i] = app_s.values[j][i];
        free_matrix (app_s);
    }//for length_layers

    /*a_k: 最终的输出。若[2,3,4,8,4,6,0]， 则返回3*/
    res = evaluate (a_k);

    free_matrix (a_k);

    return res;
}

/*
 返回矩阵中最大值对应的坐标，例如
    [2,3,4,8,4,6,0] 则返回3
*/
int
evaluate (mnn_matrix m)
{
    __assert ("'evaluate' function ('mnn_network.c'), m.rows <= 0", m.rows > 0);
    __assert ("'evaluate' function ('mnn_network.c'), m.cols <= 0", m.cols > 0);

    int k, j, result;
    double max;

    result = 0;
    max    = m.values[0][0];
    for (k = 0; k < m.rows; k++) {
        for (j = 0; j < m.cols; j++) { //m.cols = 1 maybe？！
            if (m.values[k][j] > max) {
                max    = m.values[k][j];
                result = (k * m.cols) + j;
            }
        }
    }
    __assert ("'evaluate' function ('mnn_network.c'), "\
              "result incorrect value", 
               result >= 0 && result <= 9);
    
    return result;
}

/*此函数返回一个准确预测的个数
 例如测试100个数，准确的为91，则返回91*/
int
test_network (mnn_network* net, 
              mnn_matrix* test_data, 
              int* test_labels, 
              mnn_matrix* weights, 
              mnn_vector* biases)
{
    int k, result, correct_predictions;
    //N_TEST_IMAGES 测试数据的个数
    for (k = 0, correct_predictions = 0; k < N_TEST_IMAGES; k++) {
        result = forward (net, test_data[k], weights, biases);

        __assert ("'test_network' function ('mnn_network.c'), "\
                  "result incorrect value", 
                   result >= 0 && result <= 9);

        if (test_labels[k] == result)
            correct_predictions++;
    }

    return correct_predictions;
}

int
predict_output_image (mnn_network* net, 
                      char* image_file,  
                      mnn_matrix* weights,  
                      mnn_vector* biases)
{
    FILE* fp;
    double value_pixel;
    int res_read, row_k, col_k, index, result;
    mnn_matrix x;

    x = allocate_matrix (N_ROWS_IMAGE, N_COLS_IMAGE);

    fp = fopen (image_file, "r");
    if (!fp)
        __exit ("'predict_output_image' function ('mnn_network.c'), "\
                "impossibile to open the file");

    row_k = col_k = index = 0;
    while ((res_read = fscanf (fp, "%lf", &value_pixel)) != EOF) {
        if (res_read == 1) {
            if (row_k * col_k == N_ROWS_IMAGE * N_COLS_IMAGE) {
                print_error ("'predict_output_image' function ('mnn_network.c'), "\
                             "maximum size for the image is 28x28.\n");

                fclose (fp); exit (-1);
            }
            x.values[row_k][col_k++] = value_pixel;

            index++;

            if (col_k == N_COLS_IMAGE) {
                col_k = 0;
                row_k++;
            }
        }
        else {
            print_error ("'predict_output_image' function ('mnn_network.c'),"\
                          " file format is not correct.\n");

            fclose (fp); exit (-1);
        }
    }
    fclose (fp);
    __assert ("'backpropagation' function ('mnn_network.c'), index incorrect value", 
                index == (N_ROWS_IMAGE * N_COLS_IMAGE));

    result = forward (net, x, weights, biases);

    free_matrix (x);

    return result;
}

/*就是一个简单的赋值，给best_biases用biases赋值*/
void
update_best_parameters (size_t length_layers, 
                        mnn_matrix* weights,  
                        mnn_vector* biases,  
                        mnn_matrix* best_weights,  
                        mnn_vector* best_biases)
{
    int k, j, i;

    for (k = 0; k < length_layers; k++) {
        /* Update biases */
        for (j = 0; j < best_biases[k].length; j++)
            best_biases[k].values[j] = biases[k].values[j];

        /* Update weights */
        for (j = 0; j < best_weights[k].rows; j++)
            for (i = 0; i < best_weights[k].cols; i++)
                best_weights[k].values[j][i] = weights[k].values[j][i];
    }
}
