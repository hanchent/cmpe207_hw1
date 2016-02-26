all: 72_HW1_Q1.o 72_HW1_Q2.o sum.o 72_HW1_Q4_tcp_client.o 72_HW1_Q4_tcp_server.o

72_HW1_Q1.o: 72_HW1_Q1.c
	gcc 72_HW1_Q1.c -o 72_HW1_Q1.o
sum.o: sum.c
	gcc sum.c -o sum.o
72_HW1_Q2.o: 72_HW1_Q2.c
	gcc 72_HW1_Q2.c -o 72_HW1_Q2.o
72_HW1_Q4_tcp_client.o: 72_HW1_Q4_tcp_client.c
	gcc 72_HW1_Q4_tcp_client.c -o 72_HW1_Q4_tcp_client.o
72_HW1_Q4_tcp_server.o: 72_HW1_Q4_tcp_server.c
	gcc 72_HW1_Q4_tcp_server.c -o 72_HW1_Q4_tcp_server.o
clean: 
	rm *o *_result
