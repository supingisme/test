/**
 * 
 * 图像像素显示到屏幕上
 * 
 *
 */
#include <stdio.h>
#include <stdlib.h>

#include "cv.h"
#include "highgui.h"

int
main (int argc, char** argv)
{
    FILE* fp;

    IplImage* grayscale_img;

    int k, j, response;

    if (argc != 2) {
        printf ("  Usage: %s <path image> \n", argv[0]);

        exit (-1);
    }

    if (!(fp = fopen (argv[1], "r"))) {
        printf ("  Error! File \"%s\" does not exist.\n", argv[1]);

        exit (-1);
    }
    fclose (fp);

    if (!(grayscale_img = cvLoadImage (argv[1], CV_LOAD_IMAGE_GRAYSCALE)) ){
        printf ("  Error! Impossible to load image \"%s\".\n", argv[1]);

        exit (-1);
    }

    if (grayscale_img->width != 28 || grayscale_img->height != 28) {
        response = 0;
        do {
            printf ("  Warning! Source image should be 28x28, instead of %dx%d. Do you want to get the values anyway [y/n]?   ",
                    grayscale_img->width, grayscale_img->height);
            response = getchar ();
        } while (response != 'y' && response != 'n');
    }

    for (k = 0; k < grayscale_img->width; k++)
        for (j = 0; j < grayscale_img->height; j++)
            printf ("%u\n", CV_IMAGE_ELEM (grayscale_img, unsigned char, k, j));

    cvReleaseImage (&grayscale_img);

    return 0;
}
