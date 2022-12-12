#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "diary.h"

int lastday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Year_MF(int year) {
        int k, i, j, l, yoil, line, nao;
        int tremon[3][6][7];

        printf("%4d \n", year);

        nao = year;
        Feb_PM(year);
        year = Allday(year);

        //달력을 세개씩 묶어서 출력
    for( k=1 ; k<12 ; k+=3 ) { //12달중 왼쪽에 오는 달은 1,4,7,10달 이므로
        printf("            %3d월                          %3d월                         %3d월\n", k, k+1, k+2);
        printf(" sun mon tue wed thu fri sat    sun mon tue wed thu fri sat    sun mon tue wed thu fri sat \n");

        //배열을 초기화
        for( i=0 ; i<3 ; i++ )
                        for( j=0 ; j<6 ; j++ )
                                for( l=0 ; l<7 ; l++ )
                                        tremon[i][j][l] = 0;
        for( i=0 ; i<3 ; i++ ) { //세개씩 묶어 돌렸으므로
                        if( k + i - 2 >= 0 ) //1월일 경우 전년도까지의 날수만 필요하므로 더할 필요가 없다
                                year = year + lastday[k+i-2];
            yoil = year % 7;  //7로 나누어 0이면 일요일 1이면 월요일...
            line = 0;

            for ( j=1 ; j<=lastday[k+i-1] ; j++ ) {
                                tremon[i][line][yoil++] = j;
                if ( yoil >= 7 ) {
                                        yoil=0; line+=1;
                                }
                        }
                }

                for( i=0 ; i<6 ; i++) {
                        for( j=0 ; j<3 ; j++) {
                                for( l=0 ; l<7 ; l++) {
                                        if(tremon[j][i][l] != 0){
                                                printf("%3d",tremon[j][i][l]);
                                                Star_PR(nao, k+j, tremon[j][i][l]); //일기가 있을때, 별표시를 하는 함수 호출
                                        }
                    else
                                                printf("    ");
                                }
                printf("   ");
                        }
            printf("\n");
                }
        printf("\n");
        }
    printf("end \n");
}
