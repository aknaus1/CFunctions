# compile and link the bubbleSort program

bubbleSort: main.o bubbleSort.o
	gcc -o bubbleSort main.o bubbleSort.o
	rm *.o

main.o: main.c bubbleSort.h
	gcc -c main.c

bubbleSort.o: bubbleSort.c bubbleSort.h
	gcc -c bubbleSort.c

clean:
	rm bubbleSort