//20221791 박수현 ver.1
#include <stdio.h>
#include<time.h>
#include<unistd.h>
#include "diary.h"

int Allday(int year) {
        year = (year-1) * 365 + (year-1) / 4 - (year-1)/100 + (year-1)/400 + 1;
        return year;
}