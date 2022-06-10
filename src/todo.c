#include <stdio.h>
#include <string.h>
#include "todo.h"

int todo_show(int year, int month)
{
    FILE *list;

    char* first_line = "TODO_LIST";
    char check[64];

    list = fopen(".list.csv", "r");
    if((list == NULL) || fgetc(list) == EOF)
    {
        printf("\nTODO LIST : EMPTY\n");

        list = fopen(".list.csv", "w");
        fputs(first_line, list);

        return 0;
    }

    check_date(list, year, month);

    printf("file open!\n");

    fclose(list);

    return 1;

}

void todo_make(int year, int month)
{
    FILE *list;

    list = fopen("list.csv", "a");
    // check_date(list, year, month);
}