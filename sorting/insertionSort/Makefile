# compile and link the insertionSort program

insertionSort: main.o insertionSort.o
	gcc -o insertionSort main.o insertionSort.o
	rm *.o

main.o: main.c insertionSort.h
	gcc -c main.c

insertionSort.o: insertionSort.c insertionSort.h
	gcc -c insertionSort.c

clean:
	rm insertionSort