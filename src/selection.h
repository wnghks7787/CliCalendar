#ifndef __SELECTION_H__
#define __SELECTION_H__

enum select
{
    DEFAULT = 0,
    TODAY,
    CALENDAR,
    MAKE_TODO_LIST,
    SHOW_TODO_LIST,
    EXIT
};

void calendar(int year, int month);

void todo_show(int year, int month);

void todo_make(int year, int month);

#endif