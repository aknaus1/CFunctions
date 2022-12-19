# compile and link the countingSort program

countingSort: main.o countingSort.o
	gcc -o countingSort main.o countingSort.o
	rm *.o

main.o: main.c countingSort.h
	gcc -c main.c

countingSort.o: countingSort.c countingSort.h
	gcc -c countingSort.c

clean:
	rm countingSort