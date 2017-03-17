/**
 * bmp.h
 *
 * Computer Science 50
 * Problem Set 4
 *
 * BMP-related data types based on Microsoft's own.
 */

#include <stdint.h>

/**
 * Common Data Types 
 *
 * The data types in this section are essentially aliases for C/C++ 
 * primitive data types.
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/cc230309.aspx.
 * See http://en.wikipedia.org/wiki/Stdint.h for more on stdint.h.
 */
typedef uint8_t  BYTE; //unsigned char
typedef uint32_t DWORD; //unsigned long
typedef int32_t  LONG;  //common long
typedef uint16_t WORD; //unsigned sort

/**
 * BITMAPFILEHEADER
 *
 * The BITMAPFILEHEADER structure contains information about the type, size,
 * and layout of a file that contains a DIB [device-independent bitmap].
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/dd183374(VS.85).aspx.
 */
typedef struct 
{ 
    WORD   bfType; 	//1byte
    DWORD  bfSize;  	//32 bits or 4 bytes
    WORD   bfReserved1; //16bits or 2 bytes
    WORD   bfReserved2; //16bits or 2 bytes
    DWORD  bfOffBits;  	//32 bits or 4 bytes
} __attribute__((__packed__)) 
BITMAPFILEHEADER; 

/**
 * BITMAPINFOHEADER
 *
 * The BITMAPINFOHEADER structure contains information about the 
 * dimensions and color format of a DIB [device-independent bitmap].
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/dd183376(VS.85).aspx.
 */
typedef struct
{
    DWORD  biSize; 		//4 bytes
    LONG   biWidth; 		//4 bytes
    LONG   biHeight; 		//4 bytes
    WORD   biPlanes; 		//1 byte
    WORD   biBitCount; 		//1 byte
    DWORD  biCompression; 	//4 bytes
    DWORD  biSizeImage; 	//4 bytes
    LONG   biXPelsPerMeter; 	//4 bytes
    LONG   biYPelsPerMeter; 	//4 bytes
    DWORD  biClrUsed; 		//4 bytes
    DWORD  biClrImportant; 	//4 bytes
} __attribute__((__packed__))
BITMAPINFOHEADER; 

/**
 * RGBTRIPLE
 *
 * This structure describes a color consisting of relative intensities of
 * red, green, and blue.
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/aa922590.aspx.
 */
typedef struct
{
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
    //BYTE  reserved;
} __attribute__((__packed__))
RGBTRIPLE;
