main: main.c
	clang -g -Wall main.c -o main
test:
	./main
