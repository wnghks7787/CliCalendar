#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 65536

void check_date(FILE *fp, int year, int month)
{

    int line = 100;
    char c;
    char* split;
    int todo = 0;
    // char* ln;

    // while(fgetc(fp) != EOF)
    // {
    //     if(c == '\n')
    //         line++;
    // }

    // fseek(fp, 0, SEEK_SET);

    char* ln = (char*)malloc(sizeof(char) * line);
    
    for(;;)
    {
        fgets(ln, LEN, fp);
        if(feof(fp))
            break;

        split = strtok(ln, ",");

        while(split != NULL)
        {
            if(todo >= 2)
                printf("%s\n", split);

            split = strtok(NULL, ",");
            todo++;
        }
        todo = 0;
    }
}