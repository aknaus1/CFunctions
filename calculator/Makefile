# compile and link the calculator program

calculator: main.o calculator.o
	gcc -o calculator main.o calculator.o
	rm *.o

main.o: main.c calculator.h
	gcc -c main.c

calculator.o: calculator.c calculator.h
	gcc -c calculator.c

clean:
	rm calculator