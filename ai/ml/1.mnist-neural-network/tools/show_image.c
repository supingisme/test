/**
 * 显示图片
 *
 * 
 *
 */
#include <stdio.h>
#include <stdlib.h>

#include "cv.h"
#include "highgui.h"

#define WIDTH 28
#define HEIGHT 28
#define SIZE_IMAGE WIDTH * HEIGHT

void help (char* argv_0);

int
main (int argc, char** argv)
{
    FILE* fp;
    IplImage* img;
    int index, res_read;
    double value_pixel;
    uchar* u_image;

    if (argc != 3 || (strcmp (argv[1], "--png-file") != 0 && strcmp (argv[1], "--numeric-values") != 0))
        help (argv[0]);

    ;
    if (!(fp = fopen (argv[2], "r"))) {
        printf ("  File \"%s\" does not exist.\n", argv[2]);

        exit (-1);
    }
    fclose (fp);

    img = 0;
    if (!strcmp (argv[1], "--png-file"))
        img = cvLoadImage (argv[2], CV_LOAD_IMAGE_COLOR);
    else {
        /* 28 x 28 is the size of images in accordint to MNIST dataset */
        u_image = (uchar *) malloc (sizeof (uchar) * 28 * 28);

        if (u_image == NULL) {
            printf ("  Impossibile to allocate u_image pointer.\n");

            exit (-1);
        }

        index = 0;

        fp = fopen (argv[2], "r");
        while ((res_read = fscanf (fp, "%lf", &value_pixel)) != EOF) {
            if (res_read == 0) {
                printf ("  Format of the file is not correct.\n");

                fclose (fp); exit (-1);
            }
            else if (res_read == 1) {
                if (index == SIZE_IMAGE) {
                    printf ("  Maximum size for the image is 28x28.\n");

                    fclose (fp); exit (-1);
                }

                u_image[index++] = (uchar) (value_pixel * 255.0);
            }
            else {
                printf ("  res_read incorrect value (%d).\n", res_read);

                fclose (fp); exit (-1);
            }
        }
        fclose (fp);

        if (index != SIZE_IMAGE) {
            printf ("  Assert fail! Message:  index != SIZE_IMAGE (%d != %d).\n", index, SIZE_IMAGE);

            exit (-1);
        }

        img = cvCreateImage (cvSize (WIDTH, HEIGHT), IPL_DEPTH_8U, 1);

        cvSetData (img, u_image, WIDTH);
    }

    cvNamedWindow ("Image", CV_WINDOW_AUTOSIZE);
    cvShowImage ("Image", img);
    cvWaitKey (0);
    cvReleaseImage (&img);
    cvDestroyAllWindows ();

    return 0;
}

void
help (char* argv_0)
{
    printf ("  Usage: %s [--png-file | --numeric-values] <path image>\n", argv_0);

    exit (-1);
}
