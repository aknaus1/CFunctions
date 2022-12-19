# compile and link the array program

array: main.o array.o
	gcc -o array main.o array.o
	rm *.o

main.o: main.c array.h
	gcc -c main.c

array.o: array.c array.h
	gcc -c array.c

clean:
	rm array