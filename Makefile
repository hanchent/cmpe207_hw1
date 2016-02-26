all: 72_HW1_Q1.o 72_HW1_Q2.o sum.o

72_HW1_Q1.o: 72_HW1_Q1.c
	gcc 72_HW1_Q1.c -o 72_HW1_Q1.o
sum.o: sum.c
	gcc sum.c -o sum.o
72_HW1_Q2.o: 72_HW1_Q2.c
	gcc 72_HW1_Q2.c -o 72_HW1_Q2.o
clean: 
	rm *o *_result
