//20221791 박수현 ver.1
#include <stdio.h>
#include<time.h>
#include<unistd.h>
#include "diary.h"

void Star_PR(int year, int month, int day) {
        char mabi[100];
        sprintf(mabi, "%d%d%d.txt", year, month, day);
        if( (access(mabi, F_OK) + 1) == 1 ) //access함수는 파일이 있는지 검사하여 있으면 0, 없으면 -1값을 반환한다
                printf("*"); //일반적인 경우와는 달라 오해의 소지가 있어 1을 더했다[..]
        else //여기에서는 안해도 상관없는 사족이기도하다;
                printf(" ");
}