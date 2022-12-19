# compile and link the mergeSort program

mergeSort: main.o mergeSort.o
	gcc -o mergeSort main.o mergeSort.o
	rm *.o

main.o: main.c mergeSort.h
	gcc -c main.c

mergeSort.o: mergeSort.c mergeSort.h
	gcc -c mergeSort.c

clean:
	rm mergeSort