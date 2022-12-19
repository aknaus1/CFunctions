# compile and link the binaryTree program

binaryTree: main.o binaryTree.o
	gcc -o binaryTree main.o binaryTree.o
	rm *.o

main.o: main.c binaryTree.h
	gcc -c main.c

binaryTree.o: binaryTree.c binaryTree.h
	gcc -c binaryTree.c

clean:
	rm binaryTree