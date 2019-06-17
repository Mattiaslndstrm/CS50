#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    FILE *image = fopen(argv[1], "r"), *out;
    if (image == NULL)
    {
        fprintf(stderr, "Can't open forensic image %s\n", argv[1]);
        return 2;
    }
    int i, j = 0, k = 0;
    bool writing = false;
    char filename[7 + 1];
    while((i = getc(image)) != EOF)
    {
        if (j == 0xff && i == 0xd8)
        {
            writing = true;
            sprintf(filename, k > 9 ? "0%d.jpg" : "00%d.jpg", k);
            out = fopen(filename, "w");
            fputc(0xff, out);
            k++;
        }
        if (writing)
            fputc(i, out);

        j = i;

    }
    printf("Number of jpgegs: %d\n", k);
}
