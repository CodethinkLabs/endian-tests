multifile: caller.c callee.c callee.h
	$(CC) $(CFLAGS) -c -o caller.o caller.c
	$(CC) $(CFLAGS) -c -o callee.o callee.c
	$(CC) $(CFLAGS) -o multifile caller.o callee.o

clean:
	rm -f *.o multifile
