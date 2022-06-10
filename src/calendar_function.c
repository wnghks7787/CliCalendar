#include <stdio.h>
#include <math.h>
#include "calendar.h"

void monthname(int month)
{
    char name[64];
	
	switch(month) // 월 표시
    {
        case 1:
            printf("January\n");
            break;

        case 2:
            printf("Febuary\n");
            break;

        case 3:
            printf("March\n");
            break;

        case 4:
            printf("April\n");
            break;

        case 5:
            printf("May\n");
            break;

        case 6:
            printf("June\n");
            break;

        case 7:
            printf("July\n");
            break;
 
		case 8:
            printf("August\n");
            break;

        case 9:
            printf("Septmeber\n");
            break;

	 case 10:
            printf("October\n");
            break;

	 case 11:
            printf("November\n");
            break;

	 case 12:
            printf("December\n");
            break;
 	}
	return;
 }

int daycount(int year, int month) // 각 달별로 일 수 확인. 만약 일 수가 일치하지 않으면 에러 표시
{
    int dayall;

    if(month == 4 || month == 6 || month == 9 || month == 11)
        dayall = 30;

    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        dayall = 31;

    else if(month == 2)
    {
        if(year % 4 == 0)
            dayall = 29;

        else
            dayall = 28;
    }

    else
        printf("error");

    return dayall;
}

int weekcal(int year, int month) // 날짜 계산
{
    int week;

    week = (year - 1922) * 365 + (month - 1) * 30;
    
    if(month > 2)
        week -= 2;
    if(month > 3)
        week++;
    if(month > 5)
        week++;
    if(month > 7)
        week++;
    if(month > 8)
        week++;
    if(month > 10)
        week++;
    if(month != 1)
        week++;
    if(year >= 1924)            // 윤년 계산
    {
        for(int i = 1 ; i <= floor(year / 4) - 480 ; i++)
            week++;
        if(year % 4 == 0 && month <= 2)     // 윤년 1월은 하루를 빼야 정확한 날짜 계산이 맞음
            week--;
    }
    week = week % 7;

    return week;
}