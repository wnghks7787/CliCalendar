#include <stdio.h>
#include "calendar.h"

int main()
{
    int year, month;
    int day = 1;
    int t;                    // tab
    int weektab;
    int dayall;               // 해당하는 달의 총 일수
    int week;


    printf("Year and Month : ");
    scanf("%d %d", &year, &month);      // 변수 입력

    if(!(month >= 1 && month <= 12))
    {
        printf("ERROR\n");
        return 0;
    }

    printf("%d ", year);
    monthname(month);
    printf("SUN\tMON\tTUE\tWED\tTHR\tFRI\tSAT\n");      // 일요일~토요일까지 출력
    printf("---\t---\t---\t---\t---\t---\t---\n");

    week = weekcal(year, month);
    weektab = week;
    if(week == 0)
        week = 7;

    // 한 달에 들어있는 총 날짜 계산
    dayall = daycount(year, month);

    for(; day <= dayall ; day++)       // 실제 숫자 출력(dayall값보다 작은 경우에만 출력 가능)
    {
        while(t < weektab)               // week 만큼 tab
        {
        printf("\t");
        t++;
        }
        printf("%-3d\t", day);

        if(day % 7 == 7 - week)      // 7 - week에 한번씩 줄바꿈
        printf("\n");
    }
    printf("\n");

    return 0;
}