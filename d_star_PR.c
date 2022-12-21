//20221791 박수현 ver.1
#include <stdio.h>
#include<time.h>
#include<unistd.h>
#include "diary.h"

void Star_PR(int year, int month, int day) {
        char mabi[100];
        sprintf(mabi, "%d%d%d.txt", year, month, day);
        if( (access(mabi, F_OK) + 1) == 1 ) 
                printf("*"); 
        else
                printf(" ");
}