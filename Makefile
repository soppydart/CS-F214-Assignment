# -*- Makefile -*-

exec: main.o infixToPrefix.o draw.o parser.o prefin.o height.o judge.o freee.o
	gcc -o exec main.o infixToPrefix.o draw.o parser.o prefin.o height.o judge.o freee.o -lm
	./exec

main.o: main.c Task1/infixToPrefix.h Miscellaneous/node.h Miscellaneous/draw.h Task2/parser.h Task3/prefin.h Task4/height.h Task5/judge.h 
	gcc -c main.c -o main.o

infixToPrefix.o: Task1/infixToPrefix.h Task1/infixToPrefix.c
	gcc -c Task1/infixToPrefix.c -o infixToPrefix.o

draw.o: Miscellaneous/node.h Miscellaneous/draw.h Miscellaneous/draw.c
	gcc -c Miscellaneous/draw.c -o draw.o

parser.o: Miscellaneous/node.h Task2/parser.h Task2/parser.c
	gcc -c Task2/parser.c -o parser.o

prefin.o: Miscellaneous/node.h Task3/prefin.h Task3/prefin.c
	gcc -c Task3/prefin.c -o prefin.o

height.o: Miscellaneous/node.h Task4/height.h Task4/height.c
	gcc -c Task4/height.c -o height.o

judge.o: Miscellaneous/node.h Task5/judge.h Task5/judge.c
	gcc -c Task5/judge.c -o judge.o

freee.o: Miscellaneous/node.h Miscellaneous/freee.h Miscellaneous/freee.c
	gcc -c Miscellaneous/freee.c -o freee.o

clean:
	rm *.o
	rm exec