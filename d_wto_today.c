//20221791 박수현 ver.1
#include <stdio.h>
#include<time.h>
#include<unistd.h>
#include "diary.h"

void Wto_today(int year, int month, int day) {

        FILE *fp;
        char today[100];
        int open, write;

        sprintf(today, "%d%d%d.txt", year, month, day);
        printf(" *%4d년%2d월%2d일=========If you want to stop read diary, enter the ctrl+D!* \n", year, month, day);
        fp = fopen(today, "w");
        while( ( write=getchar() ) != EOF)
                putc(write, fp);
        fclose(fp);
        printf("end \n");
}