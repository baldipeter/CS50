#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

const int BLOCK_SIZE = 512;

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check for correct form
    if (argc != 2)
    {
        printf("Correct format: ./recover forensic_image.raw\n");
        return 1;
    }

    // Save file name
    char *infile = argv[1];

    // Open file, if possible
    FILE *raw_file = fopen(infile, "r");
    if (raw_file == NULL)
    {
        printf("Could not open file: %s\n", infile);
        return 1;
    }

    // Create variables
    BYTE *buffer = malloc(BLOCK_SIZE);
    char *name = malloc(8);
    int file_num = 0;
    FILE *jpeg = NULL;

    // Iterate through the file in FAT blocks and check for JPEG headers, than save them to a file
    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(name, "%03i.jpg", file_num);
            if (jpeg != NULL)
            {
                fclose(jpeg);
            }
            jpeg = (fopen(name, "w"));
            if (jpeg == NULL)
            {
                printf("Could not create file.\n");
                return 1;
            }
            file_num++;
        }
        if (jpeg != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, jpeg);
        }
    }

    // Close files, free memory
    free(buffer);
    free(name);
    fclose(jpeg);
    fclose(raw_file);
}