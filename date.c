#include<stdio.h>
#include<time.h>
#include<unistd.h>

int lastday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void)
{
        time_t now;
        struct tm *tp;
        char c;
         int spa, year, month, day, rec, dev1 = 0, dev2 = 0, dev3 = 0;

        //시작시 현재의 년월일을 출력한다

        now = time(NULL);
        tp = localtime(&now);

        printf("Today : %d %d %d\n", tp->tm_year + 1900, tp->tm_mon + 1, tp->tm_mday) ;

                while ( (dev2 != 1) && (dev3 != 1) ) { //end명령어가 들어올 때까지 돌린다

                        spa = 0, year = 0, month = 0, day = 0, rec = 0, dev1 = 0, dev2 = 0, dev3 = 0;
                        printf("Input : ");

                while( ( c = getchar() ) != '\n' ) {
                                if ( c == 'e' ) {
                                        dev1 = 1; --spa; //e명령어 사용 시 공백이 하나 더 들어오게 되므로
                                }

                else if ( (dev1 == 1) && (c == 'n') )
                    dev2 = 1;
                else if ( (dev1 == 1) && (dev2 == 1) && (c == 'd') ) //end를 순서에 맞게 치면 프로그램 종료
                    dev3 = 1;
                else if ( (c >= '0') && (c <= '9') && (spa == 0) ) //char형으로 받은 문자를 int형으로 수정
                    year = year * 10 + ( c - '0' );
                else if ( (c >= '0') && (c <= '9') && (spa == 1) )
                    month = month * 10 + ( c - '0');
                else if ( (c >= '0') && (c <= '9') && (spa == 2) )
                    day = day * 10 + ( c - '0');
                else if ( c == ' ') //년월일을 공백으로 구분
                    ++spa;
                else { //계획에 없던 인풋들을 처리. rec값을 변화 시키는 것은 특히 e로 사작하는 인풋을 위한것
                                        printf("Error!\n"); fflush(stdin); rec = 1; break;
                       }
                }

                if( dev1 == 0 ) { //그냥 날짜만 입력했을경우를 처리한다
                if( year != 0 && month == 0 && day == 0 ) //년도만 입력했을경우 그 년도의 달력을 출력한다
                        Year_MF(year);

                if( year != 0 && month != 0 && day == 0 ) //년월을 입력했을경우 그 년월의 달력을 출력한다
                        Month_MF(year, month);

                if( year != 0 && month != 0 && day != 0 ) //년월일을 입력했을 경우 그날의 일기를 읽는다
                        Rto_thatday(year, month, day);
                }

                if( dev1 == 1 && dev2 != 1 && dev3 != 1 && rec == 0 ) { //e명령어를 처리한다
                        if( year == 0 && month == 0 && day == 0 ) //e만 입력시 오늘의 일기를 쓴다
                                Wto_today(tp->tm_year + 1900, tp->tm_mon + 1, tp->tm_mday);
                        if( year != 0 && month != 0 && day != 0 ) //e년월일 입력시 그날의 일기를 쓴다
                                Wto_thatday(year, month, day);
                        }
                }

                return 0;

}



//전년도 이전의 날수를 계산하는 함수

int Allday(int year) { //이것 역시 윤년을 생각. 4년마다 윤년이지만 100년마다는 아니고 400년마다는 윤년이다

        year = (year-1) * 365 + (year-1) / 4 - (year-1)/100 + (year-1)/400 + 1;

        return year;

}



//윤년일 경우 2월의 마지막일수를 바꿔주는 함수

void Feb_PM(int year) {

        if( (year % 400 == 0) || ((year % 4 == 0) && (year % 100 !=0)) )

        //400년의 배수는 무조건 윤년임을 주의(단축평가)

                lastday[1] = 29; //윤년일 경우에 전역변수배열 2월의 날짜를 29로 변경경시킨다

        else

                lastday[1] = 28;

}