//20221791 박수현 ver.1

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX_COUNT 12
#include "diary.h"

int lastday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void)
{
        int count=0;
        int tmp_lastday = 0;

        struct node* new_node; 
        struct node* list_head = NULL; 

        while (count < MAX_COUNT) {
                tmp_lastday = lastday[count];

        new_node = (struct node*) malloc (sizeof(struct node));
        new_node->month_lastday = tmp_lastday;

        new_node->next = list_head;
        list_head = new_node;
        count++;
        } //동적할당과 연결리스트 사용
        
        void (*pf)(int, int, int);
        pf = Wto_today; //함수 포인터 인자

        time_t now;
        struct tm *tp; //struct를 활용하여 자료구조 설계
        char c;
         int spa, year, month, day, rec, dev1 = 0, dev2 = 0, dev3 = 0;

        now = time(NULL);
        tp = localtime(&now);
        printf("Today : %d %d %d\n", tp->tm_year + 1900, tp->tm_mon + 1, tp->tm_mday) ;
                while ( (dev2 != 1) && (dev3 != 1) ) { //end명령어가 들어올 때까지 실행
                        spa = 0, year = 0, month = 0, day = 0, rec = 0, dev1 = 0, dev2 = 0, dev3 = 0;
                        printf("Input : ");

                while( ( c = getchar() ) != '\n' ) {

                                if ( c == 'e' ) {
                                        dev1 = 1; --spa; 
                                }

                else if ( (dev1 == 1) && (c == 'n') )
                    dev2 = 1;
                else if ( (dev1 == 1) && (dev2 == 1) && (c == 'd') )
                    dev3 = 1;
                else if ( (c >= '0') && (c <= '9') && (spa == 0) ) 
                    year = year * 10 + ( c - '0' );
                else if ( (c >= '0') && (c <= '9') && (spa == 1) )
                    month = month * 10 + ( c - '0');
                else if ( (c >= '0') && (c <= '9') && (spa == 2) )
                    day = day * 10 + ( c - '0');
                else if ( c == ' ') 
                    ++spa;
                else { 
                                        printf("Error!\n"); fflush(stdin); rec = 1; break;
                       }
                }


                if( dev1 == 0 ) {
                if( year != 0 && month == 0 && day == 0 ) 
                        Year_MF(year);
                if( year != 0 && month != 0 && day == 0 ) 
                        Month_MF(year, month);
                if( year != 0 && month != 0 && day != 0 )
                        Rto_thatday(year, month, day);
                }

                if( dev1 == 1 && dev2 != 1 && dev3 != 1 && rec == 0 ) { 
                        if( year == 0 && month == 0 && day == 0 ) //e만 입력시 오늘의 일기 작성
                                pf(tp->tm_year + 1900, tp->tm_mon + 1, tp->tm_mday); //함수 포인터를 인자로 전달하는 구현 방법 사용
                        if( year != 0 && month != 0 && day != 0 ) //e년월일 입력시 그날의 일기 작성
                                Wto_thatday(year, month, day);
                        }
                }
                return 0;
}