/**
 * 主函数文件
 *
 *   处理命令行参数，运行神经网络
 */
#include "mnn_main.h"

int
main (int argc, char** argv)
{
    int index_config_file,     //for "--config-file"
        index_save_parameters, //for "--save-parameters"
        index_load_parameters, //for "--load-parameters"
        index_image,           //for "--image"
        index_training,        //for "--train"
        index_show_image,      //for "--show-image"
        index_export_js;       //for "--export-javascript"

/**  结构体类型
 * mnn_vector:       int, double*
 * mnn_matrix:       int, int, double**
 * mnn_network:      int, mnn_vector, int
 * mnn_network_options:        char*, char*, char*, char*, int
 * mnn_training_parameters:    int, int, double
 * mnn_network_configuration:  mnn_network*, mnn_training_parameters*
 * mnn_backpagation_data:      mnn_vector*, mnn_matrix*
 */
    mnn_network* net; 
    mnn_network_options* net_options;
    mnn_network_configuration* net_configuration;
    char response = 0;

    /* User specify "--help" or "--show-image" option 
            如果有“--help”显示help信息，然后退出 */
    if (contains_option (argv, argc, "--help") || argc == 1)
        usage (argv[0]);
    /*显示txt到termninal，显示完退出*/
    if ((index_show_image = contains_option (argv, argc, "--show-image"))) {
        /*a如果argv里面没有路径，请添加显示的txt路径*/
        if ((index_show_image + 1) >= argc)
            __exit ("If you specify \"--show-image\" option, "\
                    "you must specify a file");
        /*a如果文件不存在，退出*/
        if (!file_exists (argv[index_show_image + 1]))
            __exit ("If you specify \"--show-image\" option, "\
                    "you must specify an existing file");
        /*a显示这个txt中的图片 28*28 */
        show_image (argv[index_show_image + 1]);
    }

    /* Get index of *argv based on the option specified */
    index_config_file     = contains_option (argv, argc, "--config-file");
    index_save_parameters = contains_option (argv, argc, "--save-parameters");
    index_load_parameters = contains_option (argv, argc, "--load-parameters");
    index_image           = contains_option (argv, argc, "--image");
    index_training        = contains_option (argv, argc, "--train");
    index_export_js       = contains_option (argv, argc, "--export-parameters");

    /* No valid options */
    if (!index_config_file && 
        !index_save_parameters && 
        !index_load_parameters && 
        !index_image && 
        !index_training && 
        !index_export_js && 
        !index_show_image)
        __exit ("No valid options. You should use '--help' option");

    /* Initialize options of the network 
        mnn_network_options:        char*, char*, char*, char*, int*/
    net_options = (mnn_network_options *) malloc (sizeof (mnn_network_options));
    if (!net_options)
        __exit ("'main' function ('mnn_main.c'), impossible to allocate net_options");

    /* We train the network if we specify "--train" and/or "--save-parameters" */
    net_options->training = (!index_training) ? ((index_save_parameters) ? 1 : 0) : 1;

    /* Handle '--save-parameters' option */
    net_options->output_file = NULL;
    if (index_save_parameters) {
        if ((index_save_parameters + 1) >= argc) {
            free (net_options);

            __exit ("If you specify \"--save-parameters\" option, "
                    "you must specify a file");
        }//if

        if (file_exists (argv[index_save_parameters + 1])) {
            do {
                print_warning ("Output file already exists. "\
                               "Do you want to overwrite it [y/n]?   ");
                response = getchar (); getchar ();
            } while (response != 'y' && response != 'n');

            if (response == 'n' && index_training == 0) {
                free (net_options);

                exit (0);
            }//if
        }//if

        //a如果response==y， 或者==0（直接回车），则给output file赋值
        net_options->output_file = (response == 'y' || response == 0) 
                                    ? argv[index_save_parameters + 1] 
                                     : NULL;
    }

    /* Handle '--load-parameters' option */
    net_options->load_file = NULL;
    /*a有加载参数*/
    if (index_load_parameters) {
        /*a有加载参数后有文件路径*/
        if ((index_load_parameters + 1) >= argc) {
            free (net_options);

            __exit ("If you specify \"--load-parameters\" option, "\
                    "you must specify a file");
        }//if
        /*a有加载参数后有文件，且该文件存在，不存在则退出*/
        if (!file_exists (argv[index_load_parameters + 1])) {
            free (net_options);

            __exit ("If you specify \"--load-parameters\" option, "\
                    "you must specify an existing file");
        }//if
        /*a给load file赋值*/
        net_options->load_file = argv[index_load_parameters + 1];
    }

    /* Handle '--image' option 
        a需要预测的图像的输入路径，txt文件double类型内容*/
    net_options->image_file = NULL;
    if (index_image) {
        if ((index_image + 1) >= argc) {
            free (net_options);

            __exit ("If you specify \"--image\" option, "\
                    "you must specify a file");
        }//if

        if (!file_exists (argv[index_image + 1])) {
            free (net_options);

            __exit ("If you specify \"--image\" option, "\
                    "you must specify an existing file");
        }//if

        if (!index_load_parameters && !net_options->training)
            print_warning ("Random values for weights and "\
                           "biases should predict wrong number.\n");

        net_options->image_file = argv[index_image + 1];
    }//if

    /* Handle '--export-parameters' option 
        a以javascript格式输出参数文件 */
    net_options->js_file = NULL;
    if (index_export_js) {
        if ((index_export_js + 1) >= argc) {
            free (net_options);

            __exit ("If you specify \"--export-parameters\" option,"\
                    " you must specify a file");
        }//if

        /* File exists */
        response = 0;
        if (file_exists (argv[index_export_js + 1])) {
            do {
                print_warning ("Javascript file already exists. "\
                               "Do you want to overwrite it [y/n]?   ");
                response = getchar (); getchar ();
            } while (response != 'y' && response != 'n');

            if (response == 'n' && net_options->training == 0) {
                free (net_options);

                exit (0);
            }//if
        }//if
        /*a给javascript文件名赋值 */
        net_options->js_file = (response == 'y' || response == 0) 
                                ? argv[index_export_js + 1] 
                                 : NULL;
    }//if

    /* Parsing of the command line terminates with success */
    /* Create the network： mnn_network: int, mnn_vector, int*/
    net = (mnn_network *) malloc (sizeof (mnn_network));
    if (!net) {
        free (net_options);

        __exit ("'main' function ('mnn_main.c'), "\
                "impossible to allocate net");
    }//if

    /* mnn_config.h contains constants */
    net->size_input_neurons  = N_INPUT_LAYER;//28*28 = 784
    net->size_output_neurons = N_OUTPUT_LAYER;//0~9 = 10

    /* Create network configuration with training parameters 
        mnn_network_configuration:  mnn_network*, mnn_training_parameters*  */
    net_configuration = (mnn_network_configuration *) 
                          malloc (sizeof (mnn_network_configuration));
    if (!net_configuration) {
        free (net_options);
        free (net);

        __exit ("'main' function ('mnn_main.c'), "\
                "impossible to allocate net_configuration");
    }//if

    /* Set "net" pointer */
    net_configuration->net = net;

    /* Set all fields of net_configuration struct */
    /* Handle '--config-file' option */
    if (index_config_file) {
        if ((index_config_file + 1) >= argc) {
            free (net_options);
            free (net);

            __exit ("If you specify \"--config-file\" option, "\
                    "you must specify a file");
        }//if

        if (!file_exists (argv[index_config_file + 1])) {
            free (net_options);
            free (net);

            __exit ("If you specify \"--config-file\" option, "\
                    "you must specify an existing file");
        }//if
    }//if

    /* Setting parameters based on the config file and execute network 
        a 从配置文件中读入训练次数、层数等信息 */
    if (parse_config_file (net_configuration, (index_config_file) 
                                                ? argv[index_config_file + 1] 
                                                    : NULL)) {
        /* Config file has been parsed successfully, so we can train the network */
        print_success ("Config file loaded successfully.\n");
        /*a 执行这个网络*/
        execute_network (net_configuration, net_options);
    }//if

    /* Free pointers */
    free (net_options);
    free_vector (net_configuration->net->sizes_hidden_neurons);
    free (net_configuration->net);
    free (net_configuration->training_params);
    free (net_configuration);

    return 0;
}

/*显示usage信息*/
void
usage (char* argv_0)
{
    printf ("Usage: %s [Options]\n\n", argv_0);
    printf ("Options:\n");
    printf ("   --help                      Print this help\n");
    printf ("   --config-file <file>        Specify config file to load\n");
    printf ("                               (if you don't specify this option, \"default_configuration.conf\" will be loaded)\n");
    printf ("   --load-parameters <file>    Load weights and biases contained in the file\n");
    printf ("                               (you must use '--save-parameters' option in a previous execution)\n");
    printf ("   --save-parameters <file>    Save weights and biases in the file\n");
    printf ("   --image <file>              Predict number of the image\n");
    printf ("                               (file's name and its content must respect some constrains)\n");
    printf ("   --train                     Train the neural network\n");
    printf ("                               (if you use \"--save-parameters\", this option will be implicit)\n");
    printf ("   --show-image <file>         Show specified image\n");
    printf ("   --export-parameters <file>  Save weights and biases as matrices and arrays in the file with Javascript syntax\n");

    printf ("\nSuch as:\n"\
            "   1.train weight&biases into parameters.txt\n"\
            "       ./mnn_main --train --save-parameters <params file>\n"\
            "   2.use parameter file predict digits\n"\
            "       ./mnn_main --load-parameters <params file> --image <digit file>\n"\
            "   3. show digit in terminal\n"\
            "       ./mnn_main --show-image <digit file>\n");

    exit (0);
}

/*确定对应参数的argc的index位置*/
int
contains_option (char** options, int n_options, char* option)
{
    int k;

    for (k = 1; k < n_options; k++)
        if (!strcmp (options[k], option))
            return k;

    return 0;
}

/*显示一个txt的图片
./mnn_main --show-image ../data/mnist-test-images-to-file/3_880.txt
a............................
a............................
a............................
a............................
a...........########.........
a...........#########........
a...........#########........
a...........##########.......
a................#####.......
a...............######.......
a.............#######........
a.............#######........
a.............#######........
a.............#######........
a.............#######........
a...............#####........
a...............#####........
a......#........#####........
a.....##......#######........
a.....####...########........
a.....##############.........
a.....############...........
a.....###########............
a......#########.............
a............................
a............................
a............................
a............................
*/
void
show_image (char* image)
{
    FILE* fp;

    int res, index;

    double value;

    /* We already checked in the "main" function if file exists */
    fp = fopen (image, "r");

    index = 0;
    while ((res = fscanf (fp, "%lf", &value)) != EOF) {
        if (res == 1) {
            index++;
            printf ((value > 0) ? "#" : ".");
            printf ((index % N_COLS_IMAGE == 0) ? "\n" : "");

        } else { //读取不成功-- 读不到 %lf
            print_error ("'show_image' function ('mnn_main.c'), file format is not correct.\n");

            fclose (fp); 
            exit (-1);
        }
    }
    fclose (fp);

    __assert ("'show_image' function ('mnn_main.c'), index incorrect value", 
                index == (N_ROWS_IMAGE * N_COLS_IMAGE));
    //exit(0);
}
