//20221791 박수현 ver.1
#include <stdio.h>
#include<time.h>
#include<unistd.h>
#include "diary.h"

int Allday(int year) { //이것 역시 윤년을 생각. 4년마다 윤년이지만 100년마다는 아니고 400년마다는 윤년이다
        year = (year-1) * 365 + (year-1) / 4 - (year-1)/100 + (year-1)/400 + 1;
        return year;
}