/**
 * 读取训练数据
 *
 * 并输出为txt的ascii文件
 *
 */
#include <stdio.h>
#include <stdlib.h>

#include "cv.h"
#include "highgui.h"

#define WIDTH 28
#define HEIGHT 28
#define SIZE_IMAGE WIDTH * HEIGHT


void usage (char* argv_0);

/*
    Steps:
        - RGB to Grayscale image;
        - resize the image (28x28 as MNIST dataset);
        - output values of image (28x28 = 784 values).
*/
int
main (int argc, char** argv)
{
    FILE* fp;

    IplImage* grayscale_img,
            * resized_img;

    int k, j;

    if (argc != 2 && argc != 3)
        usage (argv[0]);

    if (!(fp = fopen (argv[1], "r"))) {
        printf ("  Error! File \"%s\" does not exist.\n", argv[1]);

        exit (-1);
    }
    fclose (fp);

    if (!(grayscale_img = cvLoadImage (argv[1], CV_LOAD_IMAGE_GRAYSCALE)) ){
        printf ("  Error! Impossible to load image \"%s\".\n", argv[1]);

        exit (-1);
    }

    resized_img = cvCreateImage (cvSize (WIDTH, HEIGHT), IPL_DEPTH_8U, 1);
    cvResize (grayscale_img, resized_img, CV_INTER_AREA);

    if (argc == 3 && !strcmp (argv[2], "--show-ascii-image")) {
        for (k = 0; k < resized_img->width; k++) {
            printf ((k > 0) ? "\n" : "");
            for (j = 0; j < resized_img->height; j++)
                printf ((((double) CV_IMAGE_ELEM (resized_img, unsigned char, k, j) / 255.0) > 0) ? "#" : ".");
        }
        printf ("\n");
    }
    else {
        for (k = 0; k < resized_img->width; k++)
            for (j = 0; j < resized_img->height; j++)
                printf ("%f\n", (double) CV_IMAGE_ELEM (resized_img, unsigned char, k, j) / 255.0);

        if (argc == 3 && !strcmp (argv[2], "--show-image")) {
            cvNamedWindow ("Image", CV_WINDOW_AUTOSIZE);
            cvShowImage ("Image", resized_img);
            cvWaitKey (0);
            cvDestroyAllWindows ();
        }
    }

    cvReleaseImage (&grayscale_img);
    cvReleaseImage (&resized_img);

    return 0;
}

void
usage (char* argv_0)
{
    printf ("  Usage: %s <path image> [--show-image | --show-ascii-image]\n", argv_0);

    exit (-1);
}
