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

        printf("\nInsert your active: ");
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
                if(month > 12 || month < 1)
                {
                    printf("Enter right month!\n");
                    break;
                }
                calendar(year, month);
                printf("\n");
                todo_show(year, month);
                break;

            case MAKE_TODO_LIST:
                printf("Year and month : ");
                scanf("%d %d", &year, &month);
                getchar();
                if(month > 12 || month < 1)
                {
                    printf("Enter right month!\n");
                    break;
                }
                printf("\n");
                todo_make(year, month);
                break;
            
            case SHOW_TODO_LIST:
                printf("Year and month : ");
                scanf("%d %d", &year, &month);
                if(month > 12 || month < 1)
                {
                    printf("Enter right month!\n");
                    break;
                }
                printf("\n");
                todo_show(year, month);
                break;

            case TODO_INIT:
                todo_init();
                printf("Initialize complete!\n");
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
    printf("\n");
    printf("\t\t <CLI CALENDAR>\n");
    printf("\t 1. Show Today's calendar and Todo-list.\n");
    printf("\t 2. Show calendar where you want.\n");
    printf("\t 3. Make Todo-list\n");
    printf("\t 4. Show Todo-list where you want.\n");
    printf("\t 5. Initialize Todo-list\n");
    printf("\t 6. EXIT\n");
}