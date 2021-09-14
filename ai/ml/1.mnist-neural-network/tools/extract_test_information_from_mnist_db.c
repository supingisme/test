/**
 * 读取训练数据
 *
 * 并输出为txt的ascii文件
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH_TEST_DATA   "../data/mnist-database-test/t10k-images-idx3-ubyte"
#define PATH_TEST_LABELS "../data/mnist-database-test/t10k-labels-idx1-ubyte"

/* Directory must be empty */
#define FILE_K_th "../data/mnist-test-images-to-file/%d_%d.txt"

#define TOTAL_IMAGES 10000
#define SIZE_IMAGE 784

#define ROWS_IMAGE 28
#define COLS_IMAGE 28

void __exit (const char* message);

void __assert (const char* message, int condition);

int* get_labels (void);

double** get_data (void);

int reverse_int (int n);

int
main (int argc, char** argv)
{
    FILE* fp_data,
        * fp_labels,
        * fp_image_k;

    int k, j, sum, len;
    int* labels,
       * occurrences;
    double** data;
    char file_name_k[1024];

    fp_data   = fopen (PATH_TEST_DATA, "r");
    fp_labels = fopen (PATH_TEST_LABELS, "r");

    if (!fp_data || !fp_labels) {
        printf ((!fp_data)   ? "Data test file does not exist.\n"   : "");
        printf ((!fp_labels) ? "Data labels file does not exist.\n" : "");

        exit (-1);
    }

    labels = get_labels ();
    data   = get_data ();

    /*
    Files will be saved into OUTPUT_DIR specified at line 7
    Each file will have this convention for its name:
        [0-9]-[0-9].txt where:
            - first range contains the number that the file represents;
            - second range contains number of occurrence since in 10.000 there is necessarily a repetition for all numbers.
    So, this program will generate 10.000 (test file in MNIST database are 10.000) files each contains 784 values
    and each value is a number between 0 and 1
    */
    occurrences = (int *) malloc (sizeof (int) * 10);
    if (!occurrences)
        __exit ("Impossible to allocate occurrences");

    for (k = 0; k < 10; k++)
        occurrences[k] = 0;

    for (k = 0; k < TOTAL_IMAGES; k++) {
        sprintf (file_name_k, FILE_K_th, labels[k], occurrences[labels[k]]);

        /* We assume that if the first file exists, dir is not empty */
        if (k == 0) {
            if ((fp_image_k = fopen (file_name_k, "r"))) {
                printf ("  [Exit] \"%s\" already exists. Clear the content of the dir.\n", file_name_k);

                fclose (fp_image_k); break; /* Implicit 'goto' to 'Free pointers' */
            }
        }
        if (!(fp_image_k = fopen (file_name_k, "w"))) {
            printf ("  [Exit] Impossible to open \"%s\" file.\n", file_name_k);

            break; /* Implicit 'goto' to 'Free pointers' */
        }

        /* Write values into file of the k-th image */
        for (j = 0; j < SIZE_IMAGE; j++)
            fprintf (fp_image_k, "%f\n", data[k][j]);
        fclose (fp_image_k);

        occurrences[labels[k]]++;
    }

    /* Print some info */
    if (k == TOTAL_IMAGES) { /* We do not use 'break' */
        printf ("  The files were created successfully.\n");
        for (k = 0, sum = 0; k < 10; k++) {
            printf ("  %d occurrences:  %d.\n", k, occurrences[k]);

            sum += occurrences[k];
        }
        __assert ("main (), sum != TOTAL_IMAGES", sum == TOTAL_IMAGES);
    }

    /* Free pointers */
    free (labels);

    for (k = 0; k < TOTAL_IMAGES; k++)
        free (data[k]);
    free (data);

    return 0;
}

void
__exit (const char* message)
{
    printf ("  [Exit] Message:  %s.\n", message);
}

void
__assert (const char* message, int condition)
{
    if (!condition) {
        printf ("  [Assert Fail] Message:  %s.\n", message);

        exit (-1);
    }
}

int* get_labels (void)
{
    int magic_number, n_items, counter_label, expected_magic_number, expected_n_items;

    int* labels;

    FILE* fp;

    unsigned char label_x;

    /* Get expected values */
    expected_magic_number = 2049;
    expected_n_items      = 10000;

    /*
    File format for "Labels"
    [offset] [type]          [value]          [description]
    0000     32 bit integer  0x00000801(2049) magic number (MSB first)
    0004     32 bit integer  60000            number of items
    0008     unsigned byte   ??               label
    0009     unsigned byte   ??               label
    ........
    xxxx     unsigned byte   ??               label
    The labels values are 0 to 9.
    */
    fp = fopen (PATH_TEST_LABELS, "rb"); /* We already check if file exists */

    /* Get magic number */
    fread ((char *) &magic_number, sizeof (magic_number), 1, fp);
    magic_number = reverse_int (magic_number);
    __assert ("get_labels (), magic_number != expected_magic_number", magic_number == expected_magic_number);

    /* Get number of labels */
    fread ((char *) &n_items, sizeof (int), 1, fp);
    n_items = reverse_int (n_items);
    __assert ("get_labels (), n_items != expected_n_items", n_items == expected_n_items);

    /* Allocate labels array */
    labels = (int *) malloc (sizeof (int) * n_items);
    if (!labels)
        __exit ("get_labels (), impossibile to allocate labels");

    /* Get labels from file */
    counter_label = 0;
    while (fread ((unsigned char *) &label_x, sizeof (label_x), 1, fp) > 0) {
        __assert ("get_labels ()", label_x >= 0 && label_x < 10);

        labels[counter_label++] = label_x;
    }
    fclose (fp);

    __assert ("get_labels (), counter_label != expected_n_items", counter_label == expected_n_items);

    return labels;
}

double** get_data (void)
{
    int k, magic_number, n_items, n_rows, n_cols, counter_pixels,
        index, image_k, expected_magic_number, expected_n_items;

    FILE* fp;

    unsigned char pixel;

    double** images;

    /* Get expected values */
    expected_magic_number = 2051;
    expected_n_items      = 10000;

    /*
    File format for "Images"
    [offset] [type]          [value]          [description]
    0000     32 bit integer  0x00000803(2051) magic number
    0004     32 bit integer  60000            number of images
    0008     32 bit integer  28               number of rows
    0012     32 bit integer  28               number of columns
    0016     unsigned byte   ??               pixel
    0017     unsigned byte   ??               pixel
    ........
    xxxx     unsigned byte   ??               pixel
    Pixels are organized row-wise. Pixel values are 0 to 255. 0 means background (white), 255 means foreground (black).
    */
    fp = fopen (PATH_TEST_DATA, "rb"); /* We already check if file exists */

    /* Get magic number */
    fread ((char *) &magic_number, sizeof (magic_number), 1, fp);
    magic_number = reverse_int (magic_number);
    __assert ("get_data (), magic_number != expected_magic_number", magic_number == expected_magic_number);

    /* Get number of "images" */
    fread ((char *) &n_items, sizeof (int), 1, fp);
    n_items = reverse_int (n_items);
    __assert ("get_data (), n_items != expected_n_items", n_items == expected_n_items);

    /* Get number of rows of the images */
    fread ((char *) &n_rows, sizeof (int), 1, fp);
    n_rows = reverse_int (n_rows);
    __assert ("get_data (), n_rows != ROWS_IMAGE", n_rows == ROWS_IMAGE);

    /* Get number of columns of the images */
    fread ((char *) &n_cols, sizeof (int), 1, fp);
    n_cols = reverse_int (n_cols);
    __assert ("get_data (), n_cols != COLS_IMAGE", n_cols == COLS_IMAGE);

    /* Allocate data */
    images = (double **) malloc (TOTAL_IMAGES * sizeof (double *));
    if (!images)
        __exit ("get_data (), impossible to allocate images");

    for (k = 0; k < TOTAL_IMAGES; k++) {
        images[k] = (double *) malloc (SIZE_IMAGE * sizeof (double));

        if (!images[k])
            __exit ("get_data (), impossible to allocate images[k]");
    }

    /* Get pixels */
    counter_pixels = index = image_k = 0;
    while (fread ((unsigned char *) &pixel, sizeof (pixel), 1, fp) > 0) {
        __assert ("get_data (), pixel incorrect value", (double) pixel >= 0.0 && (double) pixel <= 255.0);

        images[image_k][index++] = (double) pixel / 255.0;

        if (index == SIZE_IMAGE) {
            index = 0;
            image_k++;
        }

        counter_pixels++;
    }
    fclose (fp);

    __assert ("get_data (), image_k != expected_n_items", image_k == expected_n_items);
    __assert ("get_data (), counter_pixels incorrect value", (counter_pixels / (ROWS_IMAGE * COLS_IMAGE)) == expected_n_items);

    return images;
}

int
reverse_int (int n)
{
    /*
    Thanks for the reverse_int function:
        http://stackoverflow.com/questions/8286668/how-to-read-mnist-data-in-c/10409376#10409376
    */
    unsigned char c1, c2, c3, c4;

    c1 = n & 255;
    c2 = (n >> 8) & 255;
    c3 = (n >> 16) & 255;
    c4 = (n >> 24) & 255;

    return ((int) c1 << 24) + ((int) c2 << 16) + ((int) c3 << 8) + c4;
}
