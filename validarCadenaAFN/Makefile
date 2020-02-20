afd.o: afd.cpp
	g++ afd.cpp -c 
main.o: main.cpp
	g++ main.cpp -c 

a.out: main.o afd.o
	g++ main.o afd.o

run: a.out
	./a.out

clean:
	rm -f *.o a.out