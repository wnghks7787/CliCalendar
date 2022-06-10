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

    int yearI;
    int monthI;
    int count = 0;

    char* ln = (char*)malloc(sizeof(char) * line);
    
    fseek(fp, 0, SEEK_SET);
    while(!feof(fp))
    {
        fgets(ln, LEN, fp);

        split = strtok(ln, ",");
        yearI = atoi(split);

        if(yearI == year)
        {
            split = strtok(NULL, ",");
            monthI = atoi(split);

            if(monthI == month)
            {
                count++;
                split = strtok(NULL, ",");
                printf("%d. %s", count, split);
            }
        }
    }

    if(count == 0)
        printf("\nThere is no list in this month!\n");
}

void makeTodo(FILE* fp, int year, int month)
{
    int len;
    char input[LEN];

    fgets(input, LEN, stdin);
    len = strlen(input);

    input[len - 1] = '\0';

    fprintf(fp, "%d,%02d,%s", year, month, input);
}

void todoLine(FILE* list)
{
    printf("\nTODO LIST : EMPTY\n");

    list = fopen(".list.csv", "w");
    fputs(FIRSTLINE, list);
    fputc('\n', list);

    fclose(list);
}