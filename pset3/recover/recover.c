#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    FILE *image = fopen(argv[1], "r");
    int i, j = 0, k = 0;
    while((i = getc(image)) != EOF)
    {
        if (j == 0xff && i == 0xd8)
            k++;
        j = i;
        // printf("%x", i);

    }
    printf("Number of jpgegs: %d\n", k);
}
