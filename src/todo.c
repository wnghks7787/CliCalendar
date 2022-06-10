#include <stdio.h>
#include <string.h>
#include "todo.h"

#define FIRSTLINE "TODO_LIST"
#define FILENAME ".list.csv"

int todo_show(int year, int month)
{
    FILE *list;

    char check[64];

    list = fopen(FILENAME, "r");
    if((list == NULL) || fgetc(list) == EOF)
    {
        todoLine(list);
        return 0;
    }

    printf("<TODO LIST IN %d_%d>\n", year, month);
    check_date(list, year, month);

    fclose(list);

    return 1;

}

void todo_make(int year, int month)
{
    FILE *list;

    list = fopen(FILENAME, "r");
    if((list == NULL) || fgetc(list) == EOF)
        todoLine(list);
    else if(fgetc(list) == EOF)
    {
        todoLine(list);
        fclose(list);
    }

    list = fopen(FILENAME, "a");

    fputc('\n', list);
    printf("Enter what you want to write : ");
    makeTodo(list, year, month);

    printf("Save!!\n");

    fclose(list);
}

void todo_init()
{
    FILE* list;
    todoLine(list);
}