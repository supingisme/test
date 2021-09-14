/**
 * 把图像调整为28*28大小
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

    IplImage* src_image,
            * dest_img;

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
        response = 0;
        do {
            printf ("  File \"%s\" already exists. Do you want to overwrite [y/n]?   ", argv[2]);
            response = getchar ();
            printf("\n");
        } while (response != 'y' && response != 'n');
        if (response != 'y')
            exit (-1);
    }
    //fclose (fp);
    src_image = cvLoadImage (argv[1], CV_LOAD_IMAGE_COLOR);
    cvNamedWindow ("Original image", CV_WINDOW_AUTOSIZE);
    cvShowImage ("Original image", src_image);

    dest_img = cvCreateImage (cvSize (28, 28), src_image->depth, src_image->nChannels);
    cvResize (src_image, dest_img, CV_INTER_LINEAR);
    cvNamedWindow ("Resized image", CV_WINDOW_AUTOSIZE);
    cvShowImage ("Resized image", dest_img);

    cvWaitKey (0);

    params_save_function = (int *) malloc (sizeof (int) * 3);
    params_save_function[0] = CV_IMWRITE_PNG_COMPRESSION;
    params_save_function[1] = 3;
    cvSaveImage (argv[2], dest_img, params_save_function);

    cvReleaseImage (&src_image);
    cvReleaseImage (&dest_img);
    cvDestroyAllWindows ();

    return 0;
}
