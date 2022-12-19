# compile and link the quickSort program

quickSort: main.o quickSort.o
	gcc -o quickSort main.o quickSort.o
	rm *.o

main.o: main.c quickSort.h
	gcc -c main.c

quickSort.o: quickSort.c quickSort.h
	gcc -c quickSort.c

clean:
	rm quickSort