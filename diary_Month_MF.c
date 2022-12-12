#include <stdio.h>
#include<time.h>
#include<unistd.h>
#include "diary.h"

int lastday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Month_MF(int year, int month) {
        int i, j, k, yoil, line, nao;
        int onemon[6][7];

        printf(" *========%4d년%2d월========* \n", year, month);
        printf(" sun mon tue wed thu fri sat\n");

        nao = year;
        Feb_PM(year);
        year = Allday(year);

        for( i=0 ; i<6 ; i++ ) //이차원배열 초기화
                for ( j=0 ; j<7 ; j++)
                        onemon[i][j] = 0;

    for( i=1 ; i<month ; i++)
                year += lastday[i-1];
        yoil = year % 7;
        line = 0;

        for( j=1 ; j<=lastday[month-1] ; j++ ) {
                onemon[line][yoil++] = j;
                if( yoil >= 7) {
                        yoil=0; line+=1;
                }
        }

        for( i=0 ; i<6 ; i++) {
                for( j=0 ; j<7 ; j++) {
                        if(onemon[i][j] != 0) {
                                printf("%3d", onemon[i][j]);
                                Star_PR(nao, month, onemon[i][j]);
                        }
                        else
                                printf("    ");
                }
                printf("\n");
        }
        printf(" *======================end* \n");
}