#include <stdio.h>
#include<time.h>
#include<unistd.h>
#include "diary.h"

int lastday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Feb_PM(int year) {
        if( (year % 400 == 0) || ((year % 4 == 0) && (year % 100 !=0)) )
        //400년의 배수는 무조건 윤년임을 주의(단축평가)
                lastday[1] = 29; //윤년일 경우에 전역변수배열 2월의 날짜를 29로 변경경시킨다
        else
                lastday[1] = 28;
}