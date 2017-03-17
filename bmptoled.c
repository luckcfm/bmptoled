/*
*
	CREATED BY LUCAS MEDEIROS
	WITH A LITTLE HELP FROM CC50 AND REDDIT :P


	TODO: Discover why while printing the image is partially cut.

*
*/



#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    int size = atoi(argv[3]);
    char matrix[size][size];   //here is a matrix to store where our leds state
    if (argc != 3) //ensure that the user set the right params
    {
        printf("Usage: ./bmptoled infile img_size_px\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[1];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }


    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    printf("Compression:%d\n\n\n\n\n", bi.biSize);

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;
	    //Here we're reading the colors, since we are working only with black and white, we are only interested in 
	    //not white pixels.
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
	    if((int)triple.rgbtRed == 255 && (int)triple.rgbtBlue == 255 && (int)triple.rgbtGreen == 255)
	    {
	          matrix[i][j] ='.';
	    }
	    else{
		  matrix[i][j] ='|';
	    }
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    int biHeight = abs(bi.biHeight);
    //Here we print the generated image.
    for (int i = biHeight; i > 0; i--)
    {
	    for (int j = bi.biWidth; j > 0; j--)
	    {
		printf("%c ",matrix[i][j]);

	    }
	    printf("\n");
    }
    // close infile
    fclose(inptr);

    return 0;
}
