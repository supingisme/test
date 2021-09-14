/**
 * 
 *
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

    IplImage* rgb_img,
            * grayscale_img;

    int response;

    int* params_save_function;

    if (argc != 3) {
        printf ("  Usage: %s <path source image> <path destination image>\n", argv[0]);

        exit (-1);
    }

    if (!(fp = fopen (argv[1], "r"))) {
        printf ("  File \"%s\" does not exist.\n", argv[1]);

        exit (-1);
    }
    fclose (fp);

    if ((fp = fopen (argv[2], "r"))) {
        do {
            printf ("  File \"%s\" already exists. Do you want to overwrite [y/n]?   ", argv[2]);
            response = getchar ();
        } while (response != 'y' && response != 'n');

        if (response != 'y')
            exit (-1);
    }
    fclose (fp);

    rgb_img = cvLoadImage (argv[1], CV_LOAD_IMAGE_COLOR);

    if (rgb_img->width != 28 || rgb_img->height != 28) {
        response = 0;
        do {
            printf ("  Warning! Source image should be 28x28, instead of %dx%d. Do you want to resize it [y/n]?   ", rgb_img->width, rgb_img->height);
            response = getchar ();
        } while (response != 'y' && response != 'n');
    }

    cvNamedWindow ("RGB image", CV_WINDOW_AUTOSIZE);
    cvShowImage ("RGB image", rgb_img);

    grayscale_img = cvCreateImage (
        cvSize (response == 'y' ? 28 : rgb_img->width, response == 'y' ? 28 : rgb_img->height),
        IPL_DEPTH_8U,
        1
    );

    if (response == 'y')
        cvResize (rgb_img, grayscale_img, CV_INTER_LINEAR);

    cvCvtColor (rgb_img, grayscale_img, CV_RGB2GRAY);
    cvNamedWindow ("Grayscale image", CV_WINDOW_AUTOSIZE);
    cvShowImage ("Grayscale image", grayscale_img);

    cvWaitKey (0);

    params_save_function = (int *) malloc (sizeof (int) * 3);
    params_save_function[0] = CV_IMWRITE_PNG_COMPRESSION;
    params_save_function[1] = 3;
    cvSaveImage (argv[2], grayscale_img, params_save_function);

    cvReleaseImage (&rgb_img);
    cvReleaseImage (&grayscale_img);
    cvDestroyAllWindows ();

    return 0;
}
