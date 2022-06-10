#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIRSTLINE "TODO_LIST"

#define LEN 65536

void check_date(FILE *fp, int year, int month)
{

    int line = 100;
    char c;
    char* split;
    int todo = 0;

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

void makeTodo(FILE* fp, int year, int month)
{
    char* input;
    fgets(input, LEN, stdin);

    fputc('\n', fp);
    fputs(input, fp);
}

void todoLine(FILE* list)
{
    printf("\nTODO LIST : EMPTY\n");

    list = fopen(".list.csv", "w");
    fputs(FIRSTLINE, list);
}