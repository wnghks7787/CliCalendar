#include <stdio.h>
#include <time.h>
#include "selection.h"

void printSelect();

int main()
{
    int select = 0;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int year;
    int month;

    do
    {
        printSelect();

        printf("Insert your active: ");
        scanf("%d", &select);

        switch(select)
        {
            case TODAY:
                calendar(tm.tm_year + 1900, tm.tm_mon + 1);
                todo_show(tm.tm_year + 1900, tm.tm_mon + 1);
                break;
            
            case CALENDAR:
                printf("Year and month : ");
                scanf("%d %d", &year, &month);
                calendar(year, month);
                break;

            case MAKE_TODO_LIST:
                printf("Year and month : ");
                scanf("%d %d", &year, &month);
                todo_make(year, month);
                break;
            
            case SHOW_TODO_LIST:
                printf("Year and month : ");
                scanf("%d %d", &year, &month);
                todo_show(year, month);
                break;
            
            case EXIT:
                printf("Program shutdown...\n");
                break;
            
            default:
                printf("ERROR! PLEASE INPUT 1 to 5\n");
                break;
        }
        printf("\n\n");
    } while (select != EXIT);

    return 0;
    
}

void printSelect()
{
    printf("\t 1. Show Today's calendar and Todo-list.\n");
    printf("\t 2. Show calendar where you want.\n");
    printf("\t 3. Make Todo-list\n");
    printf("\t 4. Show Todo-list where you want.\n");
    printf("\t 5. EXIT\n");
}