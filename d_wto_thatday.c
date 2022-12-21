//20221791 박수현 ver.1
#include <stdio.h>
#include<time.h>
#include<unistd.h>
#include "diary.h"

void Wto_thatday(int year, int month, int day) {
        FILE *fp;
        char thatday[100];
        int et, open, write;

        sprintf(thatday, "%d%d%d.txt", year, month, day);
        et = access(thatday, F_OK) + 1;

        if( et == 1 ) {
                printf("already esistence!\n");
                printf(" *%4d년%2d월%2d일=========일기쓰기를 끝내고 싶다면 ctrl+D를 누르세요!* \n", year, month, day);
                fp = fopen(thatday, "r");
                while( ( open=getc(fp) ) != EOF )
                        putchar(open);
                fclose(fp);
                fp = fopen(thatday, "a");
                while( ( write=getchar() ) != EOF)
                        putc(write, fp);
                fclose(fp);
                printf("end \n");
        }

        if( et == 0 ) { //파일이 없을 경우 쓰기모드로 txt 자동 생성 후 파일을 열어 일기 작성
                printf(" *%4d년%2d월%2d일=========일기쓰기를 끝내고 싶다면 ctrl+D를 누르세요!* \n",
                       year, month, day);
                fp = fopen(thatday, "w");
                while( ( write=getchar() ) != EOF )
                        putc(write, fp);
                fclose(fp);
                printf("end\n");
        }
}