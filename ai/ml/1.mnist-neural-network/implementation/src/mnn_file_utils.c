/**
 * 该程序用于读取mnist数据集
 *
 *     labels -> int
 *      28*28 -> mnn_matrix -> double
 */
#include "mnn_file_utils.h"

//#define PATH_TRAINING_DATA "../data/mnist-database-training/train-images-idx3-ubyte"
//#define PATH_TRAINING_LABELS "../data/mnist-database-training/train-labels-idx1-ubyte"

/*加载训练文件labels*/
int*
load_training_labels (void)
{
    /**/
    __assert ("'load_training_labels' function ('mnn_file_utils.c'),"\
              " file does not exist", 
              file_exists (PATH_TRAINING_LABELS));

    return load_labels (PATH_TRAINING_LABELS);
}

/*加载测试文件labels*/
int*
load_test_labels (void)
{
    __assert ("'load_test_labels' function ('mnn_file_utils.c'),"\
              " file does not exist", 
              file_exists (PATH_TEST_LABELS));

    return load_labels (PATH_TEST_LABELS);
}

/*加载labels*/
int*
load_labels (const char* file)
{
    int magic_number, //magic number
        n_items, //nums
        counter_labels, //labels
        expected_magic_number, //期望magic number
        expected_n_items; //期望nums
    int* labels;
    FILE* fp;
    unsigned char label_x;

    /* Get expected values */
    expected_magic_number = 2049;
    expected_n_items      = (!strcmp (file, PATH_TRAINING_LABELS)) ? 60000 : 10000;

    /* File format for "Labels" */
    /* [offset] [type]          [value]          [description] */
    /* 0000     32 bit integer  0x00000801(2049) magic number (MSB first) */
    /* 0004     32 bit integer  60000            number of items */
    /* 0008     unsigned byte   ??               label */
    /* 0009     unsigned byte   ??               label */
    /* ........  */
    /* xxxx     unsigned byte   ??               label */
    /* The labels values are 0 to 9. */
    fp = fopen (file, "rb"); /* We already check if file exists */

    /* Get magic number */
    fread ((char *) &magic_number, sizeof (magic_number), 1, fp);
    magic_number = reverse_int (magic_number);
    __assert ("'load_labels' function ('mnn_file_utils.c'),"\
              " magic_number != expected_magic_number", 
              magic_number == expected_magic_number);

    /* Get number of labels */
    fread ((char *) &n_items, sizeof (int), 1, fp);
    n_items = reverse_int (n_items);
    __assert ("'load_labels' function ('mnn_file_utils.c'),"\
              " n_items != expected_n_items", 
              n_items == expected_n_items);

    /* Allocate labels array */
    labels = (int *) malloc (sizeof (int) * n_items);
    if (!labels)
        __exit ("'load_labels' function ('mnn_file_utils.c'),"\
              " impossibile to allocate labels");

    /* Get labels from file */
    counter_labels = 0;
    while (fread ((unsigned char *) &label_x, sizeof (label_x), 1, fp) > 0) 
    {
        __assert ("'load_labels' function ('mnn_file_utils.c'),"\
              " label_x incorrect value", 
                  label_x >= 0 && label_x < 10);

        labels[counter_labels++] = label_x;
    }
    fclose (fp);

    __assert ("'load_labels' function ('mnn_file_utils.c'),"\
              " counter_labels != expected_n_items", 
              counter_labels == expected_n_items);

    return labels;
}

/*加载训练矩阵：28*28*/
mnn_matrix*
load_training_data (void)
{
    __assert ("'load_training_data' function ('mnn_file_utils.c'),"\
              " file does not exist", 
              file_exists (PATH_TRAINING_DATA));

    return load_data (PATH_TRAINING_DATA);
}

/*加载测试矩阵：28*28*/
mnn_matrix*
load_test_data (void)
{
    __assert ("'load_test_data' function ('mnn_file_utils.c'),"\
              " file does not exist", 
              file_exists (PATH_TEST_DATA));

    return load_data (PATH_TEST_DATA);
}

/*加载矩阵：28*28*/
mnn_matrix*
load_data (const char* file)
{
    int k, 
        magic_number,  //magic number
        n_items,  //个数
        n_rows,  //行
        n_cols,  //列
        counter_pixels, //像素点计数器
        rows, //行
        cols, //列
        image_k,  //
        expected_magic_number, //期望的magic number 2051
        expected_n_items; //期望的个数
    FILE* fp;
    unsigned char pixel;//读取的28*28中的一个像素点
    mnn_matrix* images;

    /* Get expected values */
    expected_magic_number = 2051;
    expected_n_items      = (!strcmp (file, PATH_TRAINING_DATA)) ? 60000 : 10000;

    /* File format for "Images" */
    /* [offset] [type]          [value]          [description] */
    /* 0000     32 bit integer  0x00000803(2051) magic number */
    /* 0004     32 bit integer  60000            number of images */
    /* 0008     32 bit integer  28               number of rows */
    /* 0012     32 bit integer  28               number of columns */
    /* 0016     unsigned byte   ??               pixel */
    /* 0017     unsigned byte   ??               pixel */
    /* ........ */
    /* xxxx     unsigned byte   ??               pixel */
    /* Pixels are organized row-wise. 
       Pixel values are 0 to 255. 
                        0 means background (white), 
                      255 means foreground (black). */
    fp = fopen (file, "rb"); /* We already check if file exists */

    /* Get magic number */
    fread ((char *) &magic_number, sizeof (magic_number), 1, fp);
    magic_number = reverse_int (magic_number);
    __assert ("'load_data' function ('mnn_file_utils.c'),"\
              " magic_number != expected_magic_number", 
              magic_number == expected_magic_number);

    /* Get number of "images" */
    fread ((char *) &n_items, sizeof (int), 1, fp);
    n_items = reverse_int (n_items);
    __assert ("'load_data' function ('mnn_file_utils.c'),"\
              " n_items != expected_n_items", 
              n_items == expected_n_items);

    /* Get number of rows of the images */
    fread ((char *) &n_rows, sizeof (int), 1, fp);
    n_rows = reverse_int (n_rows);
    __assert ("'load_data' function ('mnn_file_utils.c'),"\
              " n_rows != N_ROWS_IMAGE", 
              n_rows == N_ROWS_IMAGE);

    /* Get number of columns of the images */
    fread ((char *) &n_cols, sizeof (int), 1, fp);
    n_cols = reverse_int (n_cols);
    __assert ("'load_data' function ('mnn_file_utils.c'),"\
              " n_cols != N_COLS_IMAGE", 
              n_cols == N_COLS_IMAGE);

    /* Allocate data */
    images = (mnn_matrix *) malloc (sizeof (mnn_matrix) * n_items);
    if (!images)
        __exit ("'load_data' function ('mnn_file_utils.c'),"\
                " impossible to allocate images");

    for (k = 0; k < n_items; k++)
        images[k] = allocate_matrix (N_ROWS_IMAGE, N_COLS_IMAGE);

    /* Get pixels */
    counter_pixels = 0;
    rows = 0;
    cols = 0;
    image_k = 0;
    while (fread ((unsigned char *) &pixel, sizeof (pixel), 1, fp) > 0) 
    {
        __assert ("'load_data' function ('mnn_file_utils.c'),"\
                  " pixel incorrect value", 
                    (double) pixel >= 0.0 && (double) pixel <= 255.0);

        images[image_k].values[rows][cols++] = (double) pixel / 255.0;
        if (cols == 28) 
        {
            cols = 0;

            if (++rows == 28) {
                rows = cols = 0;

                image_k++;
            }
        }
        counter_pixels++;
    }
    fclose (fp);

    __assert ("'load_data' function ('mnn_file_utils.c'),"\
              " image_k != expected_n_items", 
              image_k == expected_n_items);
    __assert ("'load_data' function ('mnn_file_utils.c'),"\
              " counter_pixels incorrect value",
        (counter_pixels / (N_ROWS_IMAGE * N_COLS_IMAGE)) == expected_n_items
    );

    return images;
}

/*判断文件是否存在*/
int
file_exists (const char* file)
{
    FILE* fp;

    if (!(fp = fopen (file, "r")))
        return 0;

    fclose (fp);

    return 1;
}
