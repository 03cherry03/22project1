all: d_main.c d_allday.c d_lastday.c d_star_PR.c d_rto_thatday.c d_wto_today.c d_wto_thatday.c
	gcc -c d_main.c
	gcc -c d_allday.c
	gcc -c d_lastday.c
	gcc -c d_star_PR.c
	gcc -c d_rto_thatday.c
	gcc -c d_wto_today.c
	gcc -c d_wto_thatday.c
	gcc -o d_main d_main.o d_allday.o d_lastday.o d_star_PR.o d_rto_thatday.o d_wto_today.o d_wto_thatday.o
clean:
	rm *.o d_main