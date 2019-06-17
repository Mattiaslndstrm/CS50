#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void print_jpegs(FILE *image);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    FILE *image = fopen(argv[1], "r");
    if (image == NULL)
    {
        fprintf(stderr, "Can't open forensic image %s\n", argv[1]);
        return 2;
    }
    print_jpegs(image);
}

void print_jpegs(FILE *image)
{
    FILE *out;
    int i, j = 0, k = 0;
    bool writing = false;
    char filename[7 + 1];
    // Iterates through image until end of file and assigns the currenct char
    // to i
    while((i = getc(image)) != EOF)
    {
        // If the current and previous character is a jpeg-header it sets
        // writing to true, creates a new filename from k, open it and increases
        // k
        if (j == 0xff && i == 0xd8)
        {
            writing = true;
            sprintf(filename, k < 9 ? "00%d.jpg" : k < 100 ? "0%d.jpg" : "%d.jpg", k);
            out = fopen(filename, "w");
            k++;
        }
        // Writes the previous character to the file out if writing is true.
        if (writing)
            fputc(j, out);
        // Assigns the previous char to j
        j = i;
    }
    putc(j, out);
}
