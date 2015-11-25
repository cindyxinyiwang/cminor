cminor: scanner.c token.o
	gcc scanner.c token.o -o cminor -ll

# This pattern indicates that any .o file depends
# upon the .c file of the same name, and all of the .h files.
# So, if a .o file is needed, it is built automatically.

%.o: %.c *.h
	gcc -Wall -c $< -o $@

scanner.c: scanner.l token.o
	flex -oscanner.c scanner.l

clean:
	rm *.o cminor scanner.c
