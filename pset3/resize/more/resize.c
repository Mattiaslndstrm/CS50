// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

void update_info_header(BITMAPINFOHEADER *bi, double factor);
void update_file_header(BITMAPFILEHEADER *bf, DWORD biSizeImage,
                        LONG biHeight, int padding);

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize factor infile outfile\n");
        return 1;
    }

    // assigns the factor argument converted to  a double to factor
    double factor = atof(argv[1]);
    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER and copy it to bf_out
    BITMAPFILEHEADER bf, bf_out;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bf_out = bf;

    // read infile's BITMAPINFOHEADER and copy it to bi_out
    BITMAPINFOHEADER bi, bi_out;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    bi_out =  bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    #ifdef DEBUG
    printf("BITMAPFILEHEADER:\nbfType: %x\nbfSize: %d\n \n", bf.bfType, bf.bfSize);
    printf("BITMAPINFOHEADER:\nbiSize: %d\nbiWidth: %d\nbiHeight:%d\n"
           "biSizeImage: %d\n", bi.biSize, bi.biWidth, bi.biHeight, bi.biSizeImage);
    #endif
    update_info_header(&bi_out, factor);

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    update_file_header(&bf_out, bi_out.biSizeImage, bi_out.biHeight, padding);

    #ifdef DEBUG
    printf("BITMAPFILEHEADER:\nbfType: %x\nbfSize: %d\n \n", bf.bfType, bf.bfSize);
    printf("BITMAPINFOHEADER:\nbiSize: %d\nbiWidth: %d\nbiHeight:%d\n"
           "biSizeImage: %d\n", bi.biSize, bi.biWidth, bi.biHeight, bi.biSizeImage);
    #endif

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_out, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_out, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}

void update_info_header(BITMAPINFOHEADER *bi, double factor)
{
    bi->biWidth = bi->biWidth * factor;
    bi->biHeight = bi->biHeight * factor;
    bi->biSizeImage = abs(bi->biWidth * bi->biHeight);
}

void update_file_header(BITMAPFILEHEADER *bf, DWORD biSizeImage,
                        LONG biHeight, int padding)
{
    bf->bfSize = biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)
                 + biHeight * padding;
}
