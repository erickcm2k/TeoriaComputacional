afd.o: afd.c
	gcc afd.c -c -Wall
main.o: main.c
	gcc main.c -c -Wall

a.out: main.o afd.o
	gcc main.o afd.o

run: a.out
	./a.out

clean:
	rm -f *.o a.out