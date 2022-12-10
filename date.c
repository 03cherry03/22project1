#include<stdio.h>
#include<time.h>
#include<unistd.h>

int Allday(int year);
void Feb_PM(int year);
void Year_MF(int year);
void Month_MF(int year, int month);
void Star_PR(int year, int month, int day);
void Rto_thatday(int year, int month, int day);
void Wto_today(int year, int month, int day);
void Wto_thatday(int year, int month, int day);

int lastday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void)
{
        time_t now;
        struct tm *tp;
        char c;
         int spa, year, month, day, rec, dev1 = 0, dev2 = 0, dev3 = 0;

        //시작시 오늘의 년월일을 출력
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

//일년의 달력을 출력하는 함수. Zterm크기에 맞춰서 비쥬얼이나 다른 곳에서는 밀려서 출력됨.
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

//한달달력을 출력하는 함수 일년달력 출력과 비슷한 원리
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

//일기가 있는 날에는 별을 찍어 표시한다
void Star_PR(int year, int month, int day) {
        char mabi[100];
        sprintf(mabi, "%d%d%d.txt", year, month, day);
        if( (access(mabi, F_OK) + 1) == 1 ) //access함수는 파일이 있는지 검사하여 있으면 0, 없으면 -1값을 반환한다
                printf("*"); //일반적인 경우와는 달라 오해의 소지가 있어 1을 더했다[..]
        else //여기에서는 안해도 상관없는 사족이기도하다;
                printf(" ");
}
//입력한 날의 일기를 읽어 출력하는 함수
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
//e만 입력했을 시 오늘의 일기를 쓰는 함수, e를 눌러 오늘의 일기를 쓰면 글을 처음부터 다시 쓸 수 있다.
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

//e년월일을 입력했을 시 그날의 일기를 쓰는 함수. 예전에 썼던 일기를 출력하고 수정할 수 없다. 추가쓰기는 가능.
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

        if( et == 0 ) { //파일이 없을 경우 쓰기모드로 파일을 열어(파일이 자동생성된다)일기를 쓴다
                printf(" *%4d년%2d월%2d일=========일기쓰기를 끝내고 싶다면 ctrl+D를 누르세요!* \n",
                       year, month, day);
                fp = fopen(thatday, "w");
                while( ( write=getchar() ) != EOF )
                        putc(write, fp);
                fclose(fp);
                printf("end\n");
        }
}