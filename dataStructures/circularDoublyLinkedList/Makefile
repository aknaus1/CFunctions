# compile and link the circularDoublyLinkedList program

circularDoublyLinkedList: main.o circularDoublyLinkedList.o
	gcc -o circularDoublyLinkedList main.o circularDoublyLinkedList.o
	rm *.o

main.o: main.c circularDoublyLinkedList.h
	gcc -c main.c

circularDoublyLinkedList.o: circularDoublyLinkedList.c circularDoublyLinkedList.h
	gcc -c circularDoublyLinkedList.c

clean:
	rm circularDoublyLinkedList