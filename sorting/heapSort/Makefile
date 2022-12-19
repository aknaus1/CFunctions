# compile and link the heapSort program

heapSort: main.o heapSort.o
	gcc -o heapSort main.o heapSort.o
	rm *.o

main.o: main.c heapSort.h
	gcc -c main.c

heapSort.o: heapSort.c heapSort.h
	gcc -c heapSort.c

clean:
	rm heapSort