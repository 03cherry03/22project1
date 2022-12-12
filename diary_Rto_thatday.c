#include <stdio.h>
#include<time.h>
#include<unistd.h>
#include "diary.h"

void Rto_thatday(int year, int month, int day) {
        FILE *fp;
        char thatday[100];
        int et, open;

        sprintf(thatday, "%d%d%d.txt", year, month, day);
        et = access(thatday, F_OK) + 1;

        if( et == 1 ) { //파일이 있으면 읽기 모드로 파일을 열어 출력한다
                printf(" %4d년%2d월%2d일 \n", year, month, day);
                fp = fopen(thatday, "r");
                while( ( open=getc(fp) ) != EOF )
                        putchar(open);
                fclose(fp);
                printf(" *========================================================================* \n");
        }
        if( et == 0 ) //파일이 없으면 아래와 같은 메세지를 출력후 아무것도 열지 않고 끝낸다
                printf("File not existence!\n");

}