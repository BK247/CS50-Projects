#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    // OPEN FILE IF THERE IS ONE, OTHERWISE DECLARE ERROR
    FILE *input = fopen("card.raw", "r");
    if (input == NULL || argc != 2)
    {
        printf("Could not open card.raw.\n");
        return 1;
    }

    // SET VARIABLES - COUNTER FOR FILES, BUFFER
    int filecount = 0;
    unsigned char buffer[BUFFER_SIZE];
    FILE *picture = NULL;
    int jpg = 0;

    // RUN THE LOOP LOOKING FOR JPG
    while (fread(buffer, BUFFER_SIZE, 1, input) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (jpg == 1)
            {
                fclose(picture);
            }
            else
            {
                jpg = 1;
            }

            char filename[8];
            sprintf(filename, "%03d.jpg", filecount);
            picture = fopen(filename, "a");
            filecount++;
        }

        if (jpg == 1)
        {
            fwrite(&buffer, BUFFER_SIZE, 1, picture);
        }
    }
    fclose(input);
    fclose(picture);
    return 0;

}