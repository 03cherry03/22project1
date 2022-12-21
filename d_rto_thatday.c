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

        if( et == 1 ) { //파일 출력
                printf(" %4d년%2d월%2d일 \n", year, month, day);
                fp = fopen(thatday, "r");
                while( ( open=getc(fp) ) != EOF )
                        putchar(open);
                fclose(fp);
                printf(" *========================================================================* \n");
        }
        if( et == 0 ) 
                printf("File not existence!\n");

}